#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text_edit->installEventFilter(this);

    status_bar = new StatusBar;
    this->setStatusBar(status_bar);

    connect(ui->action_open,   &QAction   ::triggered,
            this,              &MainWindow::OnActionOpenTriggered);
    connect(ui->action_save,   &QAction   ::triggered,
            this,              &MainWindow::OnActionSaveTriggered);

    connect(ui->action_exit,   &QAction     ::triggered,
            this,              &QApplication::quit);
    connect(ui->action_cut,    &QAction     ::triggered,
            this,              &MainWindow  ::OnActionCutTriggered);
    connect(ui->action_undo,   &QAction     ::triggered,
            this,              &MainWindow  ::OnActionUndoTriggered);
    connect(ui->action_copy,   &QAction     ::triggered,
            this,              &MainWindow  ::OnActionCopyTriggered);
    connect(ui->action_paste,  &QAction     ::triggered,
            this,              &MainWindow  ::OnActionPasteTriggered);
    connect(ui->action_delete, &QAction     ::triggered,
            this,              &MainWindow  ::OnActionDeleteTriggered);

    connect(ui->action_font,                &QAction   ::triggered,
            this,                           &MainWindow::OnActionFontTriggered);
    connect(ui->action_syntax_highlighting, &QAction   ::triggered,
            this,                           &MainWindow::OnActionSyntaxHighlightingTriggered);

    connect(ui->text_edit,   &QTextEdit::undoAvailable,
            ui->action_undo, &QAction  ::setEnabled);
    connect(ui->text_edit,   &QTextEdit::copyAvailable,
            ui->action_cut,  &QAction  ::setEnabled);
    connect(ui->text_edit,   &QTextEdit::copyAvailable,
            ui->action_copy, &QAction  ::setEnabled);

    connect(ui->text_edit, SIGNAL( cursorPositionChanged() ),
            this,          SLOT  ( CurrentCursorPosition() ));
    connect(this,          SIGNAL( cursorPositionChanged           (QTextCursor) ),
            status_bar,    SLOT  ( SetValueForCursorPositionOnLabel(QTextCursor) ));

    connect(status_bar,    SIGNAL( TextEditorZoomSizeChanged (int) ),
            status_bar,    SLOT  ( SetScaleValueForTextEditor(int) ));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete status_bar;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QKeyCombination key_combination = event->keyCombination();

    ZoomInTextEditorScale (key_combination);
    ZoomOutTextEditorScale(key_combination);
}

bool MainWindow::keyPressEvent(QKeyEvent *event, int)
{
    QKeyCombination key_combination = event->keyCombination();

    return ZoomInTextEditorScale (key_combination) | ZoomOutTextEditorScale(key_combination);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->text_edit && event->type() == QEvent::KeyPress)
    {
        if( keyPressEvent(static_cast<QKeyEvent *>(event), int()) )
        {
            return true;
        }

        if( StatusBar::MAX_SCALE_VALUE_FOR_TEXT_EDITOR == status_bar->GetTextEditorScaleValue() |
            StatusBar::MIN_SCALE_VALUE_FOR_TEXT_EDITOR == status_bar->GetTextEditorScaleValue() )
        {
            return true;
        }
    }

    return false;
}

void MainWindow::CurrentCursorPosition()
{
    emit cursorPositionChanged(ui->text_edit->textCursor());
}

void MainWindow::OnActionOpenTriggered()
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

void MainWindow::OnActionSaveTriggered()
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

void MainWindow::OnActionUndoTriggered()
{
    ui->text_edit->undo();
}

void MainWindow::OnActionCutTriggered()
{
    ui->text_edit->cut();
}

void MainWindow::OnActionCopyTriggered()
{
    ui->text_edit->copy();
}

void MainWindow::OnActionPasteTriggered()
{
    ui->text_edit->paste();
}

void MainWindow::OnActionDeleteTriggered()
{
    QKeyEvent *key_press = new QKeyEvent(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier);
    QApplication::postEvent(ui->text_edit, key_press);
}

void MainWindow::OnActionFontTriggered()
{
    bool check{ true };
    ui->text_edit->setCurrentFont( QFontDialog::getFont(&check, QFont(), this, "Font...") );
}

void MainWindow::OnActionSyntaxHighlightingTriggered()
{
    ui->text_edit->setTextColor( QColorDialog::getColor(QColor(), this, "Syntax highlighting") );
}

bool MainWindow::ZoomInTextEditorScale(const QKeyCombination &key_combination)
{
    if(   StatusBar::MAX_SCALE_VALUE_FOR_TEXT_EDITOR > status_bar->GetTextEditorScaleValue()
            &&
        ((key_combination.key() == Qt::Key_Plus) |
         (key_combination.key() == Qt::Key_Equal))
            &&
        ((key_combination.keyboardModifiers() == Qt::ControlModifier) |
         (key_combination.keyboardModifiers() == (Qt::ControlModifier | Qt::KeypadModifier))) )
    {
        ui->text_edit->zoomIn();
        emit status_bar->TextEditorZoomSizeChanged(step_zoom_in);

        return true;
    }

     return false;
}

bool MainWindow::ZoomOutTextEditorScale(const QKeyCombination &key_combination)
{
    if(  StatusBar::MIN_SCALE_VALUE_FOR_TEXT_EDITOR < status_bar->GetTextEditorScaleValue()
            &&
        (key_combination.key() == Qt::Key_Minus)
            &&
        ((key_combination.keyboardModifiers() == Qt::ControlModifier) |
         (key_combination.keyboardModifiers() == (Qt::ControlModifier | Qt::KeypadModifier)) ) )
    {
        ui->text_edit->zoomOut();
        emit status_bar->TextEditorZoomSizeChanged(step_zoom_out);

        return true;
    }

    return false;
}
