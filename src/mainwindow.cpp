#include "../include/mainwindow.h"
#include <vector>
#include "functions.h"

MainWindow::MainWindow(QueueController* queueController, RoutingTable* routingTable, QWidget *parent)
    : queueController(queueController), routingTable(routingTable)
{
    newCurrentUser = "Group";
    ui.setupUi(this);
    newMessage = false;
   
}

MainWindow::~MainWindow()
{

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

// A text message has been sent
void MainWindow::on_lineEdit_returnPressed()
{
    QString self = "me";
    myChatHistory.AddToHistory(self, ui.lineEdit->text(), getNewCurrentUser());
    // This is the text message

    queueController->sendData(ui.lineEdit->text().toStdString(),inet_addr(getNewCurrentUser().toStdString().c_str()));
    ui.lineEdit->clear();
    toDisplay();
    ui.textEdit->verticalScrollBar()->setSliderPosition(ui.textEdit->verticalScrollBar()->maximum());
}

// Display all data of the current user
void MainWindow::toDisplay()
{
    std::vector<ChatMessage> toDisplay = myChatHistory.getChatHistory(getNewCurrentUser());
    QString toDisplayString;
	int i;
	for (i=0;i<toDisplay.size();i++)
	{
        toDisplayString.push_back(toDisplay[i].user);
        toDisplayString.push_back(": ");
        toDisplayString.push_back(toDisplay[i].message);
        toDisplayString.push_back("\n");
	}
    ui.textEdit->setPlainText(toDisplayString);
}

void MainWindow::on_comboBox_activated(int index)
{

}

void MainWindow::on_pushButton_clicked()
{
    std::cout << "REFRESH" << std::endl;
    std::vector<uint32_t> hosts = routingTable->getHosts();

    for (auto element : hosts) {
        QString qstr = QString::fromStdString(printIP(element));
        addNewUser(qstr);
    }
}
