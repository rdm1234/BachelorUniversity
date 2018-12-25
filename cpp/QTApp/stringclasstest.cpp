#include "stringclasstest.h"
#include "ui_stringclasstest.h"

StringClassTest::StringClassTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StringClassTest)
{
    ui->setupUi(this);
    ui->textEdit->textChanged();
}

StringClassTest::~StringClassTest()
{
    delete ui;

}

void StringClassTest::on_pushButton_find_clicked()
{
    ui->textBrowser_found->clear();
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    mystr::Vector<int> result(a.find(ui->lineEdit_find->text().toStdString().c_str()));

    for(int i = 0; i < result.getSize(); i++){
        ui->textBrowser_found->append(QString(QString::number(result[i])));
    }
    ui->lcdNumber_found->display(QString(QString::number(a.find_amount(ui->lineEdit_find->text().toStdString().c_str()))));

}

void StringClassTest::on_pushButton_replace_clicked()
{

    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    int result = a.replace(ui->lineEdit_find_2->text().toStdString().c_str(), ui->lineEdit_place->text().toStdString().c_str());
    ui->textEdit->clear();
    ui->textEdit->setText(QString(a.getCPtr()));
    ui->lcdNumber_replacements->display(result);
}

void StringClassTest::on_pushButton_getSize_clicked()
{
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    ui->lcdNumber_strSize->display(QString(QString::number(a.getSize())));
}

void StringClassTest::on_textEdit_textChanged()
{
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    ui->lcdNumber_strSize->display(QString(QString::number(a.getSize())));

}

void StringClassTest::on_StringClassTest_customContextMenuRequested(const QPoint &pos)
{

}
