#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtWidgets>


class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    static constexpr int MIN_SCALE_VALUE_FOR_TEXT_EDITOR =  10;
    static constexpr int MAX_SCALE_VALUE_FOR_TEXT_EDITOR = 500;

private:
    QLabel *emptiness_label        ;
    QLabel *cursor_position_label  ;
    QLabel *text_editor_scale_label;

    int text_editor_scale_value;

public:
    explicit StatusBar(QWidget *parent = nullptr);

    inline int GetTextEditorScaleValue() const
    {
        return text_editor_scale_value;
    }

signals:
    void TextEditorZoomSizeChanged(const int);

public slots:
    void SetValueForCursorPositionOnLabel(const QTextCursor&);

    void SetScaleValueForTextEditor(const int);

};

#endif // STATUSBAR_H
