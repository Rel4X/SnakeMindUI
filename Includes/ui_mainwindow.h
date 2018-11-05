/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLineEdit *lineEdit_training_generation;
    QLabel *label_training_filename;
    QLineEdit *lineEdit_training_filename;
    QLabel *label_training_generation;
    QCheckBox *checkBox_training_infinite;
    QPushButton *pushButton_training_go;
    QLCDNumber *lcdNumber_score;
    QLCDNumber *lcdNumber_gencount;
    QPushButton *pushButton_training_stop;
    QLabel *label_training_gencount;
    QLabel *label_training_score;
    QLCDNumber *lcdNumber_max_score;
    QLabel *label_training_maxscore;
    QPushButton *pushButton_training_save;
    QWidget *tab_2;
    QLabel *label_playing_file;
    QPushButton *pushButton_playing_play;
    QLineEdit *lineEdit_playing_filename;
    QPushButton *pushButton_playing_playlast;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(757, 457);
        QIcon icon;
        icon.addFile(QStringLiteral("brain.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 731, 421));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        lineEdit_training_generation = new QLineEdit(tab_1);
        lineEdit_training_generation->setObjectName(QStringLiteral("lineEdit_training_generation"));
        lineEdit_training_generation->setGeometry(QRect(20, 110, 161, 23));
        lineEdit_training_generation->setFrame(true);
        label_training_filename = new QLabel(tab_1);
        label_training_filename->setObjectName(QStringLiteral("label_training_filename"));
        label_training_filename->setGeometry(QRect(20, 20, 81, 16));
        lineEdit_training_filename = new QLineEdit(tab_1);
        lineEdit_training_filename->setObjectName(QStringLiteral("lineEdit_training_filename"));
        lineEdit_training_filename->setGeometry(QRect(20, 40, 113, 23));
        label_training_generation = new QLabel(tab_1);
        label_training_generation->setObjectName(QStringLiteral("label_training_generation"));
        label_training_generation->setGeometry(QRect(20, 90, 111, 16));
        checkBox_training_infinite = new QCheckBox(tab_1);
        checkBox_training_infinite->setObjectName(QStringLiteral("checkBox_training_infinite"));
        checkBox_training_infinite->setGeometry(QRect(30, 140, 88, 21));
        pushButton_training_go = new QPushButton(tab_1);
        pushButton_training_go->setObjectName(QStringLiteral("pushButton_training_go"));
        pushButton_training_go->setGeometry(QRect(30, 200, 241, 71));
        lcdNumber_score = new QLCDNumber(tab_1);
        lcdNumber_score->setObjectName(QStringLiteral("lcdNumber_score"));
        lcdNumber_score->setGeometry(QRect(480, 180, 231, 61));
        lcdNumber_score->setDigitCount(6);
        lcdNumber_gencount = new QLCDNumber(tab_1);
        lcdNumber_gencount->setObjectName(QStringLiteral("lcdNumber_gencount"));
        lcdNumber_gencount->setGeometry(QRect(480, 70, 231, 61));
        lcdNumber_gencount->setDigitCount(6);
        pushButton_training_stop = new QPushButton(tab_1);
        pushButton_training_stop->setObjectName(QStringLiteral("pushButton_training_stop"));
        pushButton_training_stop->setGeometry(QRect(30, 280, 241, 81));
        label_training_gencount = new QLabel(tab_1);
        label_training_gencount->setObjectName(QStringLiteral("label_training_gencount"));
        label_training_gencount->setGeometry(QRect(480, 50, 161, 21));
        label_training_score = new QLabel(tab_1);
        label_training_score->setObjectName(QStringLiteral("label_training_score"));
        label_training_score->setGeometry(QRect(480, 160, 61, 15));
        lcdNumber_max_score = new QLCDNumber(tab_1);
        lcdNumber_max_score->setObjectName(QStringLiteral("lcdNumber_max_score"));
        lcdNumber_max_score->setGeometry(QRect(480, 300, 231, 61));
        lcdNumber_max_score->setDigitCount(6);
        label_training_maxscore = new QLabel(tab_1);
        label_training_maxscore->setObjectName(QStringLiteral("label_training_maxscore"));
        label_training_maxscore->setGeometry(QRect(480, 280, 111, 16));
        pushButton_training_save = new QPushButton(tab_1);
        pushButton_training_save->setObjectName(QStringLiteral("pushButton_training_save"));
        pushButton_training_save->setGeometry(QRect(140, 40, 201, 23));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_playing_file = new QLabel(tab_2);
        label_playing_file->setObjectName(QStringLiteral("label_playing_file"));
        label_playing_file->setGeometry(QRect(20, 120, 91, 16));
        pushButton_playing_play = new QPushButton(tab_2);
        pushButton_playing_play->setObjectName(QStringLiteral("pushButton_playing_play"));
        pushButton_playing_play->setGeometry(QRect(20, 190, 271, 61));
        lineEdit_playing_filename = new QLineEdit(tab_2);
        lineEdit_playing_filename->setObjectName(QStringLiteral("lineEdit_playing_filename"));
        lineEdit_playing_filename->setGeometry(QRect(20, 150, 161, 23));
        pushButton_playing_playlast = new QPushButton(tab_2);
        pushButton_playing_playlast->setObjectName(QStringLiteral("pushButton_playing_playlast"));
        pushButton_playing_playlast->setGeometry(QRect(20, 270, 271, 61));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mind UI", Q_NULLPTR));
        lineEdit_training_generation->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        label_training_filename->setText(QApplication::translate("MainWindow", "Filename", Q_NULLPTR));
        lineEdit_training_filename->setText(QApplication::translate("MainWindow", "Brain.save", Q_NULLPTR));
        label_training_generation->setText(QApplication::translate("MainWindow", "Generation", Q_NULLPTR));
        checkBox_training_infinite->setText(QApplication::translate("MainWindow", "Infinite", Q_NULLPTR));
        pushButton_training_go->setText(QApplication::translate("MainWindow", "Go !", Q_NULLPTR));
        pushButton_training_stop->setText(QApplication::translate("MainWindow", "Stoooop !", Q_NULLPTR));
        label_training_gencount->setText(QApplication::translate("MainWindow", "Generation Count", Q_NULLPTR));
        label_training_score->setText(QApplication::translate("MainWindow", "Score", Q_NULLPTR));
        label_training_maxscore->setText(QApplication::translate("MainWindow", "Max Score", Q_NULLPTR));
        pushButton_training_save->setText(QApplication::translate("MainWindow", "Save !!", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Training", Q_NULLPTR));
        label_playing_file->setText(QApplication::translate("MainWindow", "Brain File", Q_NULLPTR));
        pushButton_playing_play->setText(QApplication::translate("MainWindow", "Go Play", Q_NULLPTR));
        lineEdit_playing_filename->setText(QApplication::translate("MainWindow", "Brain.save", Q_NULLPTR));
        pushButton_playing_playlast->setText(QApplication::translate("MainWindow", "Play Last Brain", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Playing", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
