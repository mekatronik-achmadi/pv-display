#ifndef TESTSIM_H
#define TESTSIM_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

#define n_data 16

namespace Ui {
class testsim;
}

class testsim : public QMainWindow
{
    Q_OBJECT

public:
    explicit testsim(QWidget *parent = 0);
    ~testsim();

private slots:
    void on_btnOpen_clicked();

    void on_chkData_1_clicked();

    void on_chkData_2_clicked();

    void on_chkData_3_clicked();

    void on_chkData_4_clicked();

    void on_chkData_5_clicked();

    void on_btnSend_clicked();

private:
    Ui::testsim *ui;
    QSerialPort* my_port;

};

#endif // TESTSIM_H
