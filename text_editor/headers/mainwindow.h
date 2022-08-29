#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "status_bar.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void OnActionOpenTriggered              ();
    void OnActionSaveTriggered              ();

    void OnActionCutTriggered               ();
    void OnActionUndoTriggered              ();
    void OnActionCopyTriggered              ();
    void OnActionPasteTriggered             ();
    void OnActionDeleteTriggered            ();

    void OnActionFontTriggered              ();
    void OnActionSyntaxHighlightingTriggered();

    void CurrentCursorPosition              ();

signals:
    void cursorPositionChanged(const QTextCursor&);

private:
    Ui::MainWindow *ui;

    QString current_filename;
};

#endif // MAINWINDOW_H
