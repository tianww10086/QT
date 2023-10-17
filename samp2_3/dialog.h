#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QCheckBox>
#include<QRadioButton>
#include<QPushButton>
#include<qplaintextedit.h>
#include<QHBoxLayout>
class Dialog
   : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;   /*三个复选框*/
    QRadioButton *radioBlack;
    QRadioButton *radioBlue;
    QRadioButton *radioRed;  //三个单选框
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose; //三个按钮
    QPlainTextEdit *txtEdit;  //文本框
    void iniUI();   //UI创建与初始化
    void iniSignalSlots();    //初始化信号与槽的连接

private slots:
    void do_chkBoxUnder(bool checked);    //Underline复选框
    void do_chkBoxItalic(bool checked);   //Italic复选框
    void do_chkBoxBold(bool checked);   //Bold复选框
    void do_setFontColor();   //设置文字演示


public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
