#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    :QDialog(parent)
    ,ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //connect(1:发射信号的对象的名称,2:信号，特殊的函数,3:接收信号的对象的名称,4:槽函数
    connect(ui->radioBlack,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(ui->radioRed,  SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(ui->radioBlue, SIGNAL(clicked()),this,SLOT(do_setFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBoxUnder_clicked(bool checked)
{// Underline 复选框
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxItalic_clicked(bool checked)
{ //Italic复选框
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxBold_clicked(bool checked)
{//Bold复选框
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}




void Dialog::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::do_setFontColor()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->radioBlue->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue); //设置字体为蓝色
    }else if(ui->radioRed->isChecked()){
         plet.setColor(QPalette::Text,Qt::red); //设置字体为红色
    }else if(ui->radioBlack->isChecked()){
          plet.setColor(QPalette::Text,Qt::black); //设置字体为黑色
    }else{
          plet.setColor(QPalette::Text,Qt::black);//设置字体为黑色
    }

    ui->plainTextEdit->setPalette(plet);
}

