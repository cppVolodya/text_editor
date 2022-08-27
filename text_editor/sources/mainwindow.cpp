#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open");
    if(filename.isEmpty())
        return;

    QFile input_file{ filename };
    if( !input_file.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, "Warning", "Failed to open file for reading data!");
    }

    QString text_data = input_file.readAll();
    ui->plain_text_edit->setPlainText(text_data);
}
