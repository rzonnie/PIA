#include "../include/mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
{
    newCurrentUser = 1;
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

void MainWindow::setNewCurrentUser(int set)	//set the new user by his ID
{
	newCurrentUser = set;
}

bool MainWindow::getNewMessage()	//tell if there is a new message to be fetched
{
	return newMessage;
}

int MainWindow::getNewCurrentUser()	//ask for the current user ID
{
	return newCurrentUser;
}

QString MainWindow::getNewestMessage()	//return the newest message in QString
{
    return newestMessage;
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)	// a new current user is chosen
{
    if(arg1 == "Guido")
    {
        setNewCurrentUser(1);
        toDisplay();
    }
    if(arg1 == "Remi")
    {
        setNewCurrentUser(2);
        toDisplay();
    }
    if(arg1 == "Bart")
    {
        setNewCurrentUser(3);
        toDisplay();
    }
    if(arg1 == "Olaf")
    {
        setNewCurrentUser(4);
        toDisplay();
    }

}
void MainWindow::on_lineEdit_returnPressed()
{
    myChatHistory.AddToHistory("me", ui.lineEdit->text(), getNewCurrentUser());
    ui.lineEdit->clear();
    toDisplay();
    ui.textEdit->verticalScrollBar()->setSliderPosition(ui.textEdit->verticalScrollBar()->maximum());
}
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
