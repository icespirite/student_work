#define WOLF_NUM 10
#define SHEEP_NUM 10
#define F_WIDTH 15
#define F_HEIGHT 15


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Подгружаем картинки
    p1= new QPixmap(":/new/prefix1/paint1.PNG");
    p2= new QPixmap(":/new/prefix1/paint2.PNG");
    p0= new QPixmap(":/new/prefix1/paint3.PNG");
    ic1= new QIcon(*p1);
    ic2= new QIcon (*p2);
    ic0= new QIcon (*p0);
    // устанавливаем комфортный размер окна

    this->setFixedSize(this->width(),this->height());

     // Создаем игру
     if(F_WIDTH<=0 || F_HEIGHT<=0)
     {
         QMessageBox::information(this,"Warning!", "Wrong field size!Default options.");
         g = new Game(15,15);

     }
     else
     g = new Game(F_WIDTH,F_HEIGHT); // создаем поле

  if(WOLF_NUM < 0 || SHEEP_NUM < 0)

  {
      QMessageBox::information(this,"Warning!", "Animals number<0!Default options.");
      g->add_woolf_S(10);
      g->add_sheep_S(10);
  }
  else
  {
      g->add_woolf_S(WOLF_NUM);
      g->add_sheep_S(SHEEP_NUM);
  }

     z=0; // кол-во текущих ходов

     ui->spinBox->setValue(Game::interval);
    // Отрисовываем иконки
    r=ui->tableWidget->rowCount();
    c=ui->tableWidget->columnCount();
    for (int i=0; i<r ;i++)
    {
        for (int j=0;j<c;j++)
        {
            if( Game::mas[i][j]==0)
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(*ic0,""));
            else if( Game::mas[i][j]==1)
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(*ic1,""));
            else
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(*ic2,""));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent(QTimerEvent *e)
{
    id_timer=e->timerId();

    z++;

    g->step_woolfS(); // ходят волки
    check(); // проверка конца игры
    g->step_sheepS(); // ходят овцы


    ui->label->setText(QString::number(z));
    for (int i=0; i<Game::isize ;i++)
    {
        for (int j=0;j<Game::jsize;j++)
        {
            if( Game::mas[i][j]==0)
                ui->tableWidget->item(i,j)->setIcon(*ic0);
            else if( Game::mas[i][j]==1)
                ui->tableWidget->item(i,j)->setIcon(*ic1);
            else if( Game::mas[i][j]==2)
                ui->tableWidget->item(i,j)->setIcon(*ic2);
        }
    }

}


void MainWindow::on_But_start_clicked()
{
    startTimer(Game::interval);//мл сек

}

void MainWindow::on_But_stop_clicked()
{
     killTimer(id_timer);
}

void  MainWindow::check()
{
    int ret=g->check_end();
     if( ret !=0 )
     {
         killTimer(id_timer);
         if( ret == 1 )
            QMessageBox::information(this,"Warning!", "Wolf lose!");
         else if( ret == 2)
              QMessageBox::information(this,"Warning!", "Wolf wins!");
         else if( ret == 3) // нет ходов - пат
             QMessageBox::information(this,"Warning!", "Drow!");
         while (!this->close()) {};
     }

}


void MainWindow::on_But_save_clicked()
{
    QString str = QFileDialog::getSaveFileName(0, "Save game state", "", "*.txt");

    QFile file(str);
    QTextStream out(&file);
    if(file.open(QIODevice::WriteOnly))
    {
        out<<Game::isize<<" "<<Game::jsize<<" "<<z<<" \n";

        for (int i=0; i<Game::isize ;i++)
        {
            for (int j=0;j<Game::jsize;j++)
            {
                out<<Game::mas[i][j]<<" ";
            }
            out<<"\n";
        }
    }
    file.close();
    QMessageBox::information(this,"Warning!", "Saved!");
}


void MainWindow::on_But_load_clicked()
{
    delete g;

    QString str = QFileDialog::getOpenFileName(0, "Open game state", "", "*.txt");

    QFile file(str);
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly))
    {
        in>>Game::isize;
        in>>Game::jsize;
        if(Game::isize<=0 || Game::jsize<=0)
        {
        QMessageBox::information(this,"Warning!", "Wrong open file.");
        this->close();
        }
        in>>z;

        g = new Game(Game::isize,Game::jsize);

        for (int i=0; i<Game::isize;i++) {
            for (int j=0;j<Game::jsize;j++) {
                in>>Game::mas[i][j];
                //QMessageBox::information(this,"Warning!", QString::number(Game::mas[i][j]));
                if (Game::mas[i][j]==1) {
                    Woolf it(-1, i, j);
                    g->woolf.push_back(it);
                } else
                if (Game::mas[i][j]==2) {
                    Sheep it(-2, i, j);
                    g->sheep.push_back(it);
                }
            }
        }

    } else {
        QMessageBox::information(this,"Warning!", "Error loadind!");
        return;
    }
    file.close();
    QMessageBox::information(this,"Warning!", "Loaded!");
    startTimer(Game::interval);//мл сек
}

void MainWindow::on_spinBox_valueChanged(int )
{
    Game::interval = ui->spinBox->value();
}
