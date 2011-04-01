#ifndef GNUFREECALL_H
#define GNUFREECALL_H

#include <QMainWindow>

namespace Ui {
    class GNUFreeCall;
}

class GNUFreeCall : public QMainWindow
{
    Q_OBJECT

public:
    explicit GNUFreeCall(QWidget *parent = 0);
    ~GNUFreeCall();

private slots:
    void pageMain();
    void pageYou();
    void pageFollowGNUs();
    void pageDiscoverHurd();

    void resizeEvent(QResizeEvent *event);

private:
    Ui::GNUFreeCall *ui;
};

#endif // GNUFREECALL_H
