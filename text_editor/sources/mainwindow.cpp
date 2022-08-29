#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->text_edit,   &QTextEdit::undoAvailable,
            ui->action_undo, &QAction  ::setEnabled);

    connect(ui->text_edit,   &QTextEdit::copyAvailable,
            ui->action_cut,  &QAction  ::setEnabled);

    connect(ui->text_edit,   &QTextEdit::copyAvailable,
            ui->action_copy, &QAction  ::setEnabled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open");
    if(filename.isEmpty())
    {
        return;
    }

    current_filename = filename;
    QFile input_file{ filename };
    if( !input_file.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, "Warning", "Failed to open file for reading data!");
    }

    ui->text_edit->setPlainText( input_file.readAll() );
}

void MainWindow::on_action_save_triggered()
{
    if( current_filename.isEmpty() )
    {
        QString filename = QFileDialog::getSaveFileName(this, "Save");
        if(filename.isEmpty())
        {
            return;
        }

        current_filename = filename;
        QFile output_file{ filename };
        if( !output_file.open(QIODevice::WriteOnly) )
        {
            QMessageBox::warning(this, "Warning", "Could not open file for writing data!");
        }

        output_file.write( ui->text_edit->toPlainText().toLocal8Bit() );
    }
    else
    {
        QFile output_file{ current_filename };
        if( !output_file.open(QIODevice::WriteOnly) )
        {
            QMessageBox::warning(this, "Warning", "Could not open file for writing data!");
        }

        output_file.write( ui->text_edit->toPlainText().toLocal8Bit() );
    }
}

void MainWindow::on_action_exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_undo_triggered()
{
    ui->text_edit->undo();
}

void MainWindow::on_action_cut_triggered()
{
    ui->text_edit->cut();
}

void MainWindow::on_action_copy_triggered()
{
    ui->text_edit->copy();
}

void MainWindow::on_action_paste_triggered()
{
    ui->text_edit->paste();
}

void MainWindow::on_action_delete_triggered()
{
    QKeyEvent *key_press = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier);
    QApplication::postEvent(ui->text_edit, key_press);
}
