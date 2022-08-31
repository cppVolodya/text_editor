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
    void keyPressEvent(QKeyEvent *     )  override;
    bool keyPressEvent(QKeyEvent *, int);

    bool eventFilter  (QObject *, QEvent *) override;

signals:
    void cursorPositionChanged(const QTextCursor &);

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

private:
    static constexpr int step_zoom_in  = +10;
    static constexpr int step_zoom_out = -10;

private:
    bool ZoomInTextEditorScale (const QKeyCombination &);
    bool ZoomOutTextEditorScale(const QKeyCombination &);

private:
    Ui::MainWindow *ui        ;
    StatusBar      *status_bar;

    QString current_filename;
};

#endif // MAINWINDOW_H
