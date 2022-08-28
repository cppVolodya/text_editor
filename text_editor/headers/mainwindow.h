#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>


namespace Ui
{
    class MainWindow;
}

class MainWindow :public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_open_triggered();
    void on_action_save_triggered();
    void on_action_exit_triggered();

private:
    Ui::MainWindow *ui;

    QString current_filename;

};

#endif // MAINWINDOW_H
