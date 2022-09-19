#ifndef RSS_FEED_READER_MAIN_WINDOW_H
#define RSS_FEED_READER_MAIN_WINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

};

#endif //RSS_FEED_READER_MAIN_WINDOW_H
