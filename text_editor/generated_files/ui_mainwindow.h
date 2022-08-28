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
    QAction *action_undo;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_paste;
    QAction *action_delete;
    QAction *action_font;
    QAction *action_syntax_highlighting;
    QWidget *central_widget;
    QHBoxLayout *horizontal_layout;
    QPlainTextEdit *plain_text_edit;
    QStatusBar *status_bar;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QMenu *menu_edit;
    QMenu *menu_format;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/.ico/main_window_title.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_undo = new QAction(MainWindow);
        action_undo->setObjectName(QString::fromUtf8("action_undo"));
        action_undo->setIconVisibleInMenu(false);
        action_cut = new QAction(MainWindow);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        action_cut->setEnabled(false);
        action_copy = new QAction(MainWindow);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        action_copy->setEnabled(false);
        action_paste = new QAction(MainWindow);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        action_delete = new QAction(MainWindow);
        action_delete->setObjectName(QString::fromUtf8("action_delete"));
        action_font = new QAction(MainWindow);
        action_font->setObjectName(QString::fromUtf8("action_font"));
        action_syntax_highlighting = new QAction(MainWindow);
        action_syntax_highlighting->setObjectName(QString::fromUtf8("action_syntax_highlighting"));
        central_widget = new QWidget(MainWindow);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        horizontal_layout = new QHBoxLayout(central_widget);
        horizontal_layout->setSpacing(0);
        horizontal_layout->setObjectName(QString::fromUtf8("horizontal_layout"));
        horizontal_layout->setContentsMargins(0, 0, 0, 0);
        plain_text_edit = new QPlainTextEdit(central_widget);
        plain_text_edit->setObjectName(QString::fromUtf8("plain_text_edit"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(11);
        plain_text_edit->setFont(font);
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
        menu_edit = new QMenu(menu_bar);
        menu_edit->setObjectName(QString::fromUtf8("menu_edit"));
        menu_format = new QMenu(menu_bar);
        menu_format->setObjectName(QString::fromUtf8("menu_format"));
        MainWindow->setMenuBar(menu_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_bar->addAction(menu_edit->menuAction());
        menu_bar->addAction(menu_format->menuAction());
        menu_file->addAction(action_open);
        menu_file->addAction(action_save);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_edit->addAction(action_undo);
        menu_edit->addSeparator();
        menu_edit->addAction(action_cut);
        menu_edit->addAction(action_copy);
        menu_edit->addAction(action_paste);
        menu_edit->addAction(action_delete);
        menu_format->addAction(action_font);
        menu_format->addAction(action_syntax_highlighting);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Notepad", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        action_undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        action_cut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        action_copy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        action_paste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        action_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        action_font->setText(QCoreApplication::translate("MainWindow", "Font...", nullptr));
        action_syntax_highlighting->setText(QCoreApplication::translate("MainWindow", "Syntax highlighting", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menu_edit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menu_format->setTitle(QCoreApplication::translate("MainWindow", "Format", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
