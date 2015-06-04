/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 4. Jun 14:06:55 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *But_start;
    QPushButton *But_stop;
    QLabel *label_2;
    QPushButton *But_save;
    QPushButton *But_load;
    QSpinBox *spinBox;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 868);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/paint1.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 15)
            tableWidget->setColumnCount(15);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 100, 771, 761));
        tableWidget->setAutoScroll(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setIconSize(QSize(30, 30));
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(15);
        tableWidget->setColumnCount(15);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setHighlightSections(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(242, 46, 46, 13));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        But_start = new QPushButton(centralWidget);
        But_start->setObjectName(QString::fromUtf8("But_start"));
        But_start->setGeometry(QRect(10, 10, 121, 51));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        But_start->setFont(font1);
        But_stop = new QPushButton(centralWidget);
        But_stop->setObjectName(QString::fromUtf8("But_stop"));
        But_stop->setGeometry(QRect(10, 60, 121, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 40, 46, 21));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        But_save = new QPushButton(centralWidget);
        But_save->setObjectName(QString::fromUtf8("But_save"));
        But_save->setGeometry(QRect(332, 26, 121, 23));
        But_load = new QPushButton(centralWidget);
        But_load->setObjectName(QString::fromUtf8("But_load"));
        But_load->setGeometry(QRect(332, 50, 121, 23));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(599, 23, 101, 51));
        QFont font3;
        font3.setPointSize(11);
        spinBox->setFont(font3);
        spinBox->setCursor(QCursor(Qt::ArrowCursor));
        spinBox->setMinimum(100);
        spinBox->setMaximum(5000);
        spinBox->setSingleStep(100);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(483, 40, 101, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\320\276\320\273\320\272\320\270 \320\277\321\200\320\276\321\202\320\270\320\262 \320\276\320\262\320\265\321\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        But_start->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\215\320\274\321\203\320\273\321\217\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        But_stop->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\245\320\276\320\264:", 0, QApplication::UnicodeUTF8));
        But_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", 0, QApplication::UnicodeUTF8));
        But_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", 0, QApplication::UnicodeUTF8));
        spinBox->setSuffix(QApplication::translate("MainWindow", " ms", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\215\320\274\321\203\320\273\321\217\321\206\320\270\320\270:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
