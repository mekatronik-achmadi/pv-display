#include "testsim.h"
#include "ui_testsim.h"

testsim::testsim(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testsim)
{
    ui->setupUi(this);

    my_port= new QSerialPort(this);
}

testsim::~testsim()
{
    delete ui;
}

void testsim::on_btnOpen_clicked()
{

    QString dev_name="/dev/";
    dev_name += ui->cmbPort->currentText();

    QSerialPort::BaudRate dev_baud = QSerialPort::Baud9600;

    int baud_index=ui->cmbBaud->currentIndex();

    switch(baud_index){
    case 0: dev_baud=QSerialPort::Baud9600;break;
    case 1: dev_baud=QSerialPort::Baud38400;break;
    case 2: dev_baud=QSerialPort::Baud57600;break;
    case 3: dev_baud=QSerialPort::Baud115200;break;
    }

    if(ui->btnOpen->text()=="Open"){

        my_port->setPortName(dev_name);

        if(my_port->open(QIODevice::ReadWrite)){
            my_port->setBaudRate(dev_baud,QSerialPort::AllDirections);
            my_port->setDataBits(QSerialPort::Data8);
            my_port->setStopBits(QSerialPort::OneStop);
            my_port->setFlowControl(QSerialPort::NoFlowControl);
            my_port->setParity(QSerialPort::NoParity);
//            QMessageBox::information(this,"success","port success on "+dev_name );
            ui->btnOpen->setText("Close");
            ui->btnSend->setEnabled(true);
        }
        else{
            QMessageBox::critical(this,"Failed","port failed on "+dev_name);
            ui->btnOpen->setText("Open");
            ui->btnSend->setEnabled(false);
        }
    }
    else{
        if(my_port->isOpen()){
            my_port->close();
        }
        ui->btnOpen->setText("Open");
        ui->btnSend->setEnabled(false);
    }
}

void testsim::on_chkData_1_clicked()
{
    if(ui->chkData_1->isChecked()){ui->txtData_1->setEnabled(true);}
    else{ui->txtData_1->setEnabled(false);}
}

void testsim::on_chkData_2_clicked()
{
    if(ui->chkData_2->isChecked()){ui->txtData_2->setEnabled(true);}
    else{ui->txtData_2->setEnabled(false);}
}

void testsim::on_chkData_3_clicked()
{
    if(ui->chkData_3->isChecked()){ui->txtData_3->setEnabled(true);}
    else{ui->txtData_3->setEnabled(false);}
}

void testsim::on_chkData_4_clicked()
{
    if(ui->chkData_4->isChecked()){ui->txtData_4->setEnabled(true);}
    else{ui->txtData_4->setEnabled(false);}
}

void testsim::on_chkData_5_clicked()
{
    if(ui->chkData_5->isChecked()){ui->txtData_5->setEnabled(true);}
    else{ui->txtData_5->setEnabled(false);}
}

void testsim::on_btnSend_clicked()
{
     if(!my_port->isOpen()){return;}

    QString dataStr;

    dataStr += ui->txtData_1->text();
    dataStr += ui->txtData_2->text();
    dataStr += ui->txtData_3->text();
    dataStr += ui->txtData_4->text();
    dataStr += ui->txtData_5->text();

    dataStr += "\r";

    if(dataStr.length() != (n_data+1)){
        QMessageBox::critical(this,"Failed","current supported data is "+ QString::number(n_data) + " but your is " + QString::number(dataStr.length()-1));
        return;
    }

    QByteArray dataByte = dataStr.toUtf8();

    my_port->write(dataByte);
}
