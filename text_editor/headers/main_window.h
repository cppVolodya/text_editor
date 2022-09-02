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

protected:
    void wheelEvent(QWheelEvent *) override;

signals:
    void cursorPositionChanged(const QTextCursor &);

private slots:
    void OnActionNewTriggered               ();
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

    void ZoomInTextEditorScale              ();
    void ZoomOutTextEditorScale             ();

private:
    static constexpr int step_zoom_in  = +10;
    static constexpr int step_zoom_out = -10;

private:
    Ui::MainWindow *ui                            ;
    StatusBar      *status_bar                    ;
    QShortcut      *shortcut_ctrl_plus            ;
    QShortcut      *shortcut_alternative_ctrl_plus;
    QShortcut      *shortcut_ctrl_minus           ;

    QString current_filename;
};

#endif // MAINWINDOW_H
