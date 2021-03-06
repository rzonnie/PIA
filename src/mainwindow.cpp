#include "../include/mainwindow.h"
#include <vector>
#include "functions.h"

MainWindow::MainWindow(QueueController* queueController, RoutingTable* routingTable, Settings* settings, ChatHistory* chatHistory, QWidget *parent)
    : queueController(queueController), routingTable(routingTable), settings(settings), chatHistory(chatHistory)
{
    newCurrentUser = "";
    ui.setupUi(this);
    newMessage = false;
    startTimer();
   
}

MainWindow::~MainWindow()
{
    std::cout << "CLOSED MAIN WINDOW" << std::endl;
}


void MainWindow::addNewUser(QString newUser)
{
   ui.comboBox->addItem(newUser);
}

void MainWindow::removeUser(int index)
{
    ui.comboBox->removeItem(index);
}

void MainWindow::setNewMessage(bool set)	//there is a new message
{
	newMessage = set;
}

void MainWindow::setNewCurrentUser(QString set)	//set the new user by his ID
{
	newCurrentUser = set;
}

bool MainWindow::getNewMessage()	//tell if there is a new message to be fetched
{
	return newMessage;
}

QString MainWindow::getNewCurrentUser()	//ask for the current user ID
{
	return newCurrentUser;
}

QString MainWindow::getNewestMessage()	//return the newest message in QString
{
    return newestMessage;
}

// Another user has been selected
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)	// a new current user is chosen
{
    setNewCurrentUser(arg1);
}

void MainWindow::on_comboBox_activated(int index) {

}

// A text message has been sent
void MainWindow::on_lineEdit_returnPressed()
{
    QString self = "me";
    // This is the text message
    if (getNewCurrentUser().toStdString() != "") {
        chatHistory->AddToHistory(self, ui.lineEdit->text(), getNewCurrentUser());
        queueController->sendData(ui.lineEdit->text().toStdString(),inet_addr(getNewCurrentUser().toStdString().c_str()));
        std::cout << "Message has been sent to " << getNewCurrentUser().toStdString() << std::endl;
    }
    ui.lineEdit->clear();
    toDisplay();
}

// Display all data of the current user
void MainWindow::toDisplay()
{
    int temp = ui.textEdit->verticalScrollBar()->sliderPosition();
    std::vector<ChatMessage> toDisplay = chatHistory->getChatHistory(getNewCurrentUser());
    QString toDisplayString;
    size_t i;
	for (i=0;i<toDisplay.size();i++)
	{
        toDisplayString.push_back(toDisplay[i].user);
        toDisplayString.push_back(": ");
        toDisplayString.push_back(toDisplay[i].message);
        toDisplayString.push_back("\n");
	}
    ui.textEdit->setPlainText(toDisplayString);
    ui.textEdit->verticalScrollBar()->setSliderPosition(temp);
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<uint32_t> hosts = routingTable->getHosts();
    ui.comboBox->clear();
    for (auto element : hosts) {
        QString qstr = QString::fromStdString(printIP(element));
        if (element != settings->getLocalIP())
            addNewUser(qstr);
    }
}

void MainWindow::startTimer() {
    // timer in milliseconds
    #if QT_VERSION>=QT_VERSION_CHECK(5,0,0)
        timer.start(500, Qt::CoarseTimer, this);
    #else
        timer.start(500, this);
    #endif
}

void MainWindow::timerEvent(QTimerEvent * ev) {
    toDisplay();
}
