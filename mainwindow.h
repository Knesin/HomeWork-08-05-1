#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pb_StartStop_click();
    void pb_Lap_click();
    void pb_Clear_click();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopW;;
};
#endif // MAINWINDOW_H
