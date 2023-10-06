#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QString>

class Stopwatch : public QObject
{
    Q_OBJECT
private:
    unsigned int time_;
    unsigned int lap_time_;
    unsigned int last_lap_time_;
    unsigned int count_lap_;
    QTimer *timer_;
    QString time_to_string_(unsigned int t);
private slots:
    void add_time(); //добавить время
    void clear_time();//сброс времяни
    void lap();
public:
    explicit Stopwatch(QObject *parent = nullptr);
    QString get_time();
    QString get_time_lap();
    int get_lap_count();
signals:
    void sig_start();
    void sig_stop();
    void sig_change();
    void sig_lap();
    void sig_clear();
};

#endif // STOPWATCH_H
