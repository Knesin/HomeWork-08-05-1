#include "stopwatch.h"

QString Stopwatch::time_to_string_(unsigned int time)
{
    QString result = "";
    int ms_ = time % 10;
    int ss_ = (time/10) % 60;
    int mm_ = (time/10) / 60;

    if (mm_ <10){
        result = "0" + QString::number(mm_) + ":";
    }else{
        result = QString::number(mm_) + ":";
    };
    if (ss_ <10){
        result += "0" + QString::number(ss_) + ":";
    }else{
        result += QString::number(ss_) + ":";
    };
    result += QString::number(ms_);
    return result;
}

void Stopwatch::add_time()
{
    ++time_;
    ++lap_time_;
    emit sig_change();
};

void Stopwatch::clear_time()
{
    time_ = 0;
    last_lap_time_ = 0;
    lap_time_ = 0;
    count_lap_ = 0;
    emit sig_change();
};

void Stopwatch::lap()
{
    ++count_lap_;
    last_lap_time_ = lap_time_;
    lap_time_ = 0;
};

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}, time_{0}, lap_time_{0}, last_lap_time_{0}, count_lap_{0}
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &Stopwatch::add_time);//увеличение времяни
    connect(this, &Stopwatch::sig_start, this, [this](){timer_->start(100);});
    connect(this, &Stopwatch::sig_stop, this, [this](){timer_->stop();});
    connect(this, &Stopwatch::sig_lap, this, &Stopwatch::lap);
    connect(this, &Stopwatch::sig_clear, this, &Stopwatch::clear_time);
}

QString Stopwatch::get_time()
{
    return time_to_string_(time_);
}

QString Stopwatch::get_time_lap()
{
    return time_to_string_(last_lap_time_);
}

int Stopwatch::get_lap_count()
{
    return count_lap_;
}
