#include "headers/main_window.h"
#include "ui_main_window.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text_edit->viewport()->installEventFilter(this);

    status_bar = new StatusBar;
    this->setStatusBar(status_bar);

    shortcut_ctrl_plus              = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus) , this);
    shortcut_alternative_ctrl_plus  = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Equal), this);
    shortcut_ctrl_minus             = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus), this);

    connect(ui->action_new,    &QAction   ::triggered,
            this,              &MainWindow::OnActionNewTriggered);
    connect(ui->action_open,   &QAction   ::triggered,
            this,              &MainWindow::OnActionOpenTriggered);
    connect(ui->action_save,   &QAction   ::triggered,
            this,              &MainWindow::OnActionSaveTriggered);

    connect(ui->action_exit,   &QAction     ::triggered,
            this,              &QApplication::quit);
    connect(ui->action_cut,    &QAction     ::triggered,
            this,              &MainWindow  ::OnActionCutTriggered   );
    connect(ui->action_undo,   &QAction     ::triggered,
            this,              &MainWindow  ::OnActionUndoTriggered  );
    connect(ui->action_copy,   &QAction     ::triggered,
            this,              &MainWindow  ::OnActionCopyTriggered  );
    connect(ui->action_paste,  &QAction     ::triggered,
            this,              &MainWindow  ::OnActionPasteTriggered );
    connect(ui->action_delete, &QAction     ::triggered,
            this,              &MainWindow  ::OnActionDeleteTriggered);

    connect(ui->action_font,                &QAction   ::triggered,
            this,                           &MainWindow::OnActionFontTriggered              );
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

    connect(shortcut_ctrl_plus,             &QShortcut ::activated,
            this,                           &MainWindow::ZoomInTextEditorScale );
    connect(shortcut_alternative_ctrl_plus, &QShortcut ::activated,
            this,                           &MainWindow::ZoomInTextEditorScale );
    connect(shortcut_ctrl_minus,            &QShortcut ::activated,
            this,                           &MainWindow::ZoomOutTextEditorScale);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *wheel_event)
{
    if(wheel_event->modifiers() == Qt::ControlModifier)
    {
        if(wheel_event->angleDelta().ry() > 0)
        {
            ZoomInTextEditorScale();
        }
        else
        {
            ZoomOutTextEditorScale();
        }
    }
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    QWheelEvent *wheel_event = static_cast<QWheelEvent *>(event);

    if(object                   == ui->text_edit->viewport() &&
       event->type()            == QEvent::Wheel             &&
       wheel_event->modifiers() == Qt::ControlModifier          )
    {
        wheelEvent(wheel_event);
        return true;
    }

    return false;
}

void MainWindow::CurrentCursorPosition()
{
    emit cursorPositionChanged(ui->text_edit->textCursor());
}

void MainWindow::OnActionNewTriggered()
{
    ui->text_edit->clear();
    this->setWindowTitle("Untitled - Notepad");
    current_filename.clear();
}

void MainWindow::OnActionOpenTriggered()
{
    QString path_to_file = QFileDialog::getOpenFileName(this, "Open");
    if(path_to_file.isEmpty())
    {
        return;
    }

    current_filename = path_to_file;
    QFile input_file{ path_to_file };
    if( !input_file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QMessageBox::warning(this, "Warning", "Failed to open file for reading data: " +
                                    input_file.errorString());
    }


    ui->text_edit->setPlainText( input_file.readAll() );

    int position = path_to_file.lastIndexOf(QChar('/')) + 1;
    QString filename = path_to_file.right(path_to_file.size() - position);
    this->setWindowTitle(filename + " - Notepad");
}

void MainWindow::OnActionSaveTriggered()
{
    if( current_filename.isEmpty() )
    {
        QString path_to_file = QFileDialog::getSaveFileName(this, "Save");
        if(path_to_file.isEmpty())
        {
            return;
        }

        current_filename = path_to_file;
        QFile output_file{ path_to_file };
        if( !output_file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            QMessageBox::warning(this, "Warning", "Could not open file for writing data: " +
                                        output_file.errorString());
        }

        output_file.write( ui->text_edit->toPlainText().toLocal8Bit() );
    }
    else
    {
        QFile output_file{ current_filename };
        if( !output_file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            QMessageBox::warning(this, "Warning", "Could not open file for writing data: " +
                                        output_file.errorString());
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
    QFont font = QFontDialog::getFont(&check, QFont(), this, "Font...");

    if(check)
    {
        ui->text_edit->setCurrentFont(font);
    }
}

void MainWindow::OnActionSyntaxHighlightingTriggered()
{
    ui->text_edit->setTextColor( QColorDialog::getColor(QColor(), this, "Syntax highlighting") );
}

void MainWindow::ZoomInTextEditorScale()
{
    if( StatusBar::MAX_SCALE_VALUE_FOR_TEXT_EDITOR > status_bar->GetTextEditorScaleValue() )
    {
        ui->text_edit->zoomIn();
        emit status_bar->TextEditorZoomSizeChanged(step_zoom_in);
    }
}

void MainWindow::ZoomOutTextEditorScale()
{
    if( StatusBar::MIN_SCALE_VALUE_FOR_TEXT_EDITOR < status_bar->GetTextEditorScaleValue() )
    {
        ui->text_edit->zoomOut();
        emit status_bar->TextEditorZoomSizeChanged(step_zoom_out);
    }
}
