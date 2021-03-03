#include "wordclasstest.h"
#include "ui_wordclasstest.h"

WordClassTest::WordClassTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordClassTest)
{
    ui->setupUi(this);
    ui->textEdit->textChanged();
}

WordClassTest::~WordClassTest()
{
    delete ui;
}

void WordClassTest::on_pushButton_find_clicked()
{
    ui->textBrowser_found->clear();
    mystr::Word a(ui->textEdit->toPlainText().toStdString().c_str());
    mystr::Vector<int> result(a.find(ui->lineEdit_find->text().toStdString().c_str()));

    for(int i = 0; i < result.getSize(); i++){
        ui->textBrowser_found->append(QString(QString::number(result[i])));
    }
    ui->lcdNumber_found->display(QString(QString::number(result.getSize())));
}

void WordClassTest::on_pushButton_replace_clicked()
{
    mystr::Word a(ui->textEdit->toPlainText().toStdString().c_str());
    int result = a.replace(ui->lineEdit_find_2->text().toStdString().c_str(), ui->lineEdit_place->text().toStdString().c_str());
    ui->textEdit->clear();
    ui->textEdit->setText(QString(a.getCPtr()));
    ui->lcdNumber_replacements->display(result);
}

void WordClassTest::on_textEdit_textChanged()
{
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    ui->lcdNumber_strSize->display(QString(QString::number(a.getSize())));
}
