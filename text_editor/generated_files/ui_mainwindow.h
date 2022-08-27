/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_exit;
    QWidget *central_widget;
    QHBoxLayout *horizontal_layout;
    QPlainTextEdit *plain_text_edit;
    QStatusBar *status_bar;
    QMenuBar *menu_bar;
    QMenu *menu_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../../../Desktop/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        central_widget = new QWidget(MainWindow);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        horizontal_layout = new QHBoxLayout(central_widget);
        horizontal_layout->setSpacing(0);
        horizontal_layout->setObjectName(QString::fromUtf8("horizontal_layout"));
        horizontal_layout->setContentsMargins(0, 0, 0, 0);
        plain_text_edit = new QPlainTextEdit(central_widget);
        plain_text_edit->setObjectName(QString::fromUtf8("plain_text_edit"));
        plain_text_edit->setFrameShape(QFrame::NoFrame);
        plain_text_edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        plain_text_edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        plain_text_edit->setLineWrapMode(QPlainTextEdit::NoWrap);

        horizontal_layout->addWidget(plain_text_edit);

        MainWindow->setCentralWidget(central_widget);
        status_bar = new QStatusBar(MainWindow);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        MainWindow->setStatusBar(status_bar);
        menu_bar = new QMenuBar(MainWindow);
        menu_bar->setObjectName(QString::fromUtf8("menu_bar"));
        menu_bar->setGeometry(QRect(0, 0, 1000, 26));
        menu_bar->setFocusPolicy(Qt::WheelFocus);
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        MainWindow->setMenuBar(menu_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_file->addAction(action_open);
        menu_file->addAction(action_save);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Notepad", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
