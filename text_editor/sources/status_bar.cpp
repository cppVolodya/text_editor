#include "status_bar.h"


StatusBar::StatusBar(QWidget* parrent) :
    QStatusBar(parrent)
{
    emptiness   = new QLabel(             );
    line_and_column = new QLabel("Ln 1, Col 1");

    addPermanentWidget(emptiness      , 8);
    addPermanentWidget(line_and_column, 1);
}

void StatusBar::SetValueForLineAndColumn(const QTextCursor& text_cursor)
{
    this->line_and_column->setText("Ln "    + QString::number(text_cursor.blockNumber () + 1) +
                                   ", Col " + QString::number(text_cursor.columnNumber() + 1) );
}
