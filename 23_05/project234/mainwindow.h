#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

///////////////////////
#include "game.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPixmap *p1;
    QPixmap *p2;
     QPixmap *p0;
    QIcon *ic1;
    QIcon *ic2;
    QIcon *ic0;
    int r;
    int c;
    int z;
    ~MainWindow();

private slots:

    void on_But_start_clicked();

    void on_But_stop_clicked();

    void on_But_save_clicked();

    void on_But_load_clicked();

private:
    Ui::MainWindow *ui;

    void timerEvent(QTimerEvent *);
       int id_timer;

       Game *g;
       void check();

};

#endif // MAINWINDOW_H
