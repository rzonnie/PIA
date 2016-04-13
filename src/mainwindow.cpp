#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QString>
#include <stdio.h>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
{
    ui->setupUi(this);
    newMessage = false;
    newCurrentUser = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TextMessage_returnPressed()
{
    newestMessage = ui->TextMessage->text();
    setNewMessage(true);
}

void MainWindow::addNewUser(const QString newUser)
{
   ui->comboBox->addItem(newUser);
}

void MainWindow::setNewMessage(bool set)
{
	newMessage = set;
}

void MainWindow::setNewCurrentUser(int set)
{
	newCurrentUser = set;
}

bool MainWindow::getNewMessage()
{
	return newMessage;
}

int MainWindow::getNewCurrentUser()
{
	return newCurrentUser;
}

void MainWindow::toDisplay(QString QStringIn)
{
    ui->dialogueBox->setPlainText(QStringIn);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    setNewCurrentUser(true);
}
