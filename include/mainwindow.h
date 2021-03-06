#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <iostream>
#include <stdio.h>
#include <QComboBox>
#include <QScrollBar>
#include <QBasicTimer>

#include "../ui_mainwindow.h"
#include "../include/ChatHistory.h"
#include "QueueController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QueueController* queueController, RoutingTable* routingTable, Settings* settings, ChatHistory* chatHistory, QWidget *parent = 0);
    ~MainWindow();

	void setNewMessage(bool set);
    void setNewCurrentUser(QString set);
	bool getNewMessage();
    QString getNewCurrentUser();
    QString getNewestMessage();
    void toDisplay();
    void addNewUser(QString newUser);
    void removeUser(int index);
    void startTimer();
    void timerEvent(QTimerEvent* ev);

private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_returnPressed();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    QBasicTimer timer;
    Ui::MainWindow ui;
    bool newMessage;
    QString newCurrentUser;
    ChatHistory* chatHistory;
    QueueController* queueController;
    RoutingTable* routingTable;
    Settings* settings;
    QString newestMessage;
};

#endif // MAINWINDOW_H
