#include "textclasstest.h"
#include "ui_textclasstest.h"

TextClassTest::TextClassTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextClassTest)
{
    ui->setupUi(this);
    mystr::Text tempText;
    mystr::String tempStr;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }
    ui->lcdNumber_strSize->display(tempText.get_length());
}

TextClassTest::~TextClassTest()
{
    delete ui;
}

void TextClassTest::on_pushButton_find_clicked()
{
    mystr::Text tempText;
    mystr::String tempStr;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }
    auto result = tempText.find(ui->lineEdit_find->text().toStdString().c_str());
    ui->textBrowser_found->clear();
    for (int i = 0; i < result.getSize(); ++i) {
        for (int j = 0; j < result[i].getSize(); j++){
            ui->textBrowser_found->append(QString(QString::number(i) + QString(": ") + QString::number(result[i][j])));
        }
    }
    int g = 0;
    for (int i = 0; i < result.getSize(); i++){
        g+=result[i].getSize();
    }
    ui->lcdNumber_found->display(g);
}

void TextClassTest::on_pushButton_clicked()
{
    ui->comboBoxText->removeItem(ui->comboBoxText->currentIndex());
    mystr::Text tempText;
    mystr::String tempStr;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }
    ui->lcdNumber_strSize->display(tempText.get_length());
}

void TextClassTest::on_comboBoxAddString_currentIndexChanged(int index)
{
    //mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());

    if (index == 2){
        ui->comboBoxAddIndex->setEnabled(1);
        for(int i = 0; i < ui->comboBoxText->count(); i++){
            ui->comboBoxAddIndex->addItem(QString(QString::number(i)));
        }
    }
    else{
        ui->comboBoxAddIndex->setEnabled(0);
        ui->comboBoxAddIndex->clear();
    }
}

void TextClassTest::on_pushButton_addString_clicked()
{
    if(ui->comboBoxAddIndex->isEnabled()){
        ui->comboBoxText->insertItem(ui->comboBoxAddIndex->currentIndex(), ui->lineEditAddString->text());
    }
    else{
        if(ui->comboBoxAddString->currentIndex() == 1){
            ui->comboBoxText->addItem(ui->lineEditAddString->text());
        }
        else {
           ui->comboBoxText->insertItem(0, ui->lineEditAddString->text());
        }
    }

    if (ui->comboBoxAddString->currentIndex() == 2){
        ui->comboBoxAddIndex->clear();
        for(int i = 0; i < ui->comboBoxText->count(); i++){
            ui->comboBoxAddIndex->addItem(QString(QString::number(i)));
        }
    }
    mystr::Text tempText;
    mystr::String tempStr;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }
    ui->lcdNumber_strSize->display(tempText.get_length());
}

void TextClassTest::on_pushButton_replace_clicked()
{
    mystr::Text tempText;
    mystr::String tempStr;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }
    int result = tempText.replace(ui->lineEdit_find_2->text().toStdString().c_str(), ui->lineEdit_place->text().toStdString().c_str());
    ui->comboBoxText->clear();
    for(int i = 0; i < tempText.text.getSize(); i++){
        ui->comboBoxText->addItem(QString(tempText.text[i].getCPtr()));
    }
    ui->lcdNumber_replacements->display(result);
    mystr::Text tempText2;
    mystr::String tempStr2;
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr2 = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText2.text.push_back(tempStr2);
    }
    ui->lcdNumber_strSize->display(tempText2.get_length());
}

void TextClassTest::on_comboBoxText_editTextChanged(const QString &arg1)
{

}
