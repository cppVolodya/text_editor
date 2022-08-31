#include "status_bar.h"


StatusBar::StatusBar(QWidget *parrent) :
    QStatusBar(parrent),
    text_editor_scale_value(100)
{
    emptiness_label         = new QLabel(             );
    cursor_position_label   = new QLabel("Ln 1, Col 1");
    text_editor_scale_label = new QLabel("100%"       );

    this->addPermanentWidget(emptiness_label        , 10);
    this->addPermanentWidget(cursor_position_label  ,  1);
    this->addPermanentWidget(text_editor_scale_label,  1);
}

StatusBar::~StatusBar()
{
    delete emptiness_label        ;
    delete cursor_position_label  ;
    delete text_editor_scale_label;
}

void StatusBar::SetValueForCursorPositionOnLabel(const QTextCursor& text_cursor)
{
    this->cursor_position_label->setText("Ln "    + QString::number(text_cursor.blockNumber () + 1) +
                                         ", Col " + QString::number(text_cursor.columnNumber() + 1) );
}

void StatusBar::SetScaleValueForTextEditor(const int value)
{
    text_editor_scale_value += value;
    text_editor_scale_label->setText(QString::number(text_editor_scale_value) + "%");
}
