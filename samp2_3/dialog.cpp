#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog()
{
}

void Dialog::iniUI(){
    //创建三个复选框，并水平布局
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chkBoxBold = new QCheckBox("Bold");
    QHBoxLayout *HLay1 = new QHBoxLayout();  //创建水平布局对象
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);  //把三个复选框对象传入水平布局的addWidget函数里

    //创建Black,Red, Blue三个单选按钮，并水平布局
    radioBlack = new QRadioButton("Black");
    radioBlue = new QRadioButton("Blue");
    radioRed = new QRadioButton("Red");
    QHBoxLayout *HLay2 = new QHBoxLayout();
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioBlue);
    HLay2->addWidget(radioRed);

    //创建“确定” “取消” "退出" 3个按钮，并水平布局
    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLay3 = new QHBoxLayout();
    HLay3->addStretch(); //添加一个弹性空间
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);


    //创建文本框，并设置初始字体
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World\n手工创建");   //设置初始文字
    QFont font = txtEdit->font();  //获取字体
    font.setPointSize(20);   //修改字体大小为20
    txtEdit->setFont(font);  //设置字体;

    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay = new QVBoxLayout(this);
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}


void Dialog::iniSignalSlots(){
    //3个设置演示的单选按钮
    connect(radioBlue,SIGNAL(clicked()),this, SLOT(do_setFontColor()));
     connect(radioRed,SIGNAL(clicked()),this, SLOT(do_setFontColor()));
     connect(radioBlack,SIGNAL(clicked()),this, SLOT(do_setFontColor()));

     //设置字体的复选框
     connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxUnder(bool)));
     connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxItalic(bool)));
     connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxBold(bool)));

     //3个按钮与窗口的槽函数关联
     connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
     connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
     connect(btnClose,SIGNAL(clicked()),this,SLOT(close));
}


//定义槽函数，当点击按钮时给文本框的文本添加下划线
void Dialog::do_chkBoxUnder(bool cheked1){
     QFont font = txtEdit->font();  //获取文本框的字体，存在font对象里
     font.setUnderline(cheked1); //当点击这个按钮后，就会把设置下划线想信息传给font对象
     txtEdit->setFont(font); //设置txtEdit的字体
}

//定义槽函数，当点击按钮时给文本框的文本变为斜体
void Dialog::do_chkBoxItalic(bool cheked){
     QFont font = txtEdit->font(); //获取文本框的文字信息。
     font.setItalic(cheked);
     txtEdit->setFont(font);
}
//定义槽函数，当点击按钮时给文本框的文本加粗
void Dialog::do_chkBoxBold(bool checked)
{
     QFont font = txtEdit->font();
     font.setBold(checked);
     txtEdit->setFont(font);
}

void Dialog::do_setFontColor(){
     //获取的调色板信息被分配给名为 plet
     QPalette plet = txtEdit->palette(); //palette()方法返回控件的当前调色板（颜色方案）信息。txtEdit 是一个指向文本编辑器控件的指针。
     if(radioBlue->isChecked()) //这是一个条件语句，它检查名为 radioBlue 的单选按钮是否处于选中状态。
         plet.setColor(QPalette::Text,Qt::blue); //如果 radioBlue 被选中，那么在调色板中将文本颜色（QPalette::Text）设置为蓝色（Qt::blue）
     else if(radioBlack->isChecked())
         plet.setColor(QPalette::Text,Qt::black);
     else if(radioRed->isChecked())
         plet.setColor(QPalette::Text,Qt::red);
     else
         plet.setColor(QPalette::Text,Qt::black);
     txtEdit-setPalette(plet);
}

