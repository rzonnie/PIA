#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
//#include <QString>

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
	void setNewCurrentUser(int set);
	bool getNewMessage();
	int getNewCurrentUser();

private slots:
    void on_lineEdit_returnPressed();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_TextMessage_returnPressed();

    void addNewUser(const QString newUser);

private:
    Ui::MainWindow *ui;
    bool newMessage;
    int newCurrentUser;
    
    QString newestMessage;
};

#endif // MAINWINDOW_H
