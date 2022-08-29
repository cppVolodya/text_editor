#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtWidgets>


class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget* parent = nullptr);

    ~StatusBar() = default;

public slots:
    void SetValueForLineAndColumn(const QTextCursor&);

private:
    QLabel *emptiness      ;
    QLabel *line_and_column;

};

#endif // STATUSBAR_H
