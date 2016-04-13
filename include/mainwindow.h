#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <iostream>
#include <stdio.h>
#include <QComboBox>
#include <QScrollBar>

#include "../ui_mainwindow.h"
#include "../include/ChatHistory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void setNewMessage(bool set);
    void setNewCurrentUser(QString set);
	bool getNewMessage();
    QString getNewCurrentUser();
    QString getNewestMessage();
    void toDisplay();
    void addNewUser(QString newUser);
    void removeUser(int index);


private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow ui;
    bool newMessage;
    QString newCurrentUser;
    ChatHistory myChatHistory;
    
    QString newestMessage;
};

#endif // MAINWINDOW_H
