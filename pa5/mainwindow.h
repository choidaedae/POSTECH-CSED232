#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTimer>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtGui>
#include <QString>
#include <QTime>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLabel;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    void updatetime();
    void word_set();
    void word_show();
    void check();
    void updatescore();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QMessageBox quitgame;

    void setmsgbox();
    void endgame();
    void Reloadgame();
    void match();
    bool eventFilter(QObject *watched, QEvent *event);

    bool isfill[6] = {};
    bool iscrazy[6] = {};

    int time = 30;
    int score = 0;
    int word_count = 0;
    int cur_idx = -1;
    QString cur_word=  "";

};




#endif // MAINWINDOW_H
