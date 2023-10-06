#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopW  = new Stopwatch(this);

    ui->gb_Box_1->setTitle("Время");
    ui->gb_Box_2->setTitle("Время куруга");
    ui->pb_StartStop->setText("Старт");
    ui->pb_Clear->setText("Отчистить");
    ui->pb_Lap->setText(" Круг");
    ui->pb_Lap->setDisabled(true);
    QFont f;
    f.setPointSize(48);
    f.setBold(true);
    ui->l_Time->setFont(f);
    ui->l_Time->setText("00:00:0");

    connect(ui->pb_StartStop, &QPushButton::clicked, this, &MainWindow::pb_StartStop_click);
    connect(ui->pb_Lap, &QPushButton::clicked, this, &MainWindow::pb_Lap_click);
    connect(ui->pb_Clear, &QPushButton::clicked, this, &MainWindow::pb_Clear_click);
    connect(stopW, &Stopwatch::sig_change, this, [this](){ui->l_Time->setText(stopW->get_time());});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pb_StartStop_click()
{
    if(ui->pb_StartStop->text() == "Старт"){
        ui->pb_StartStop->setText("Стоп");
        ui->pb_Lap->setDisabled(false);
        emit stopW->sig_start();
    }else{
        ui->pb_StartStop->setText("Старт");
        ui->pb_Lap->setDisabled(true);
        emit stopW->sig_stop();
    }
}

void MainWindow::pb_Lap_click()
{
    emit stopW->sig_lap();
    ui->te_TimeLap->append("Круг "+ QString::number(stopW->get_lap_count()) +", время: " + stopW->get_time_lap());
}

void MainWindow::pb_Clear_click()
{
    emit stopW->sig_clear();
    ui->te_TimeLap->clear();
}

