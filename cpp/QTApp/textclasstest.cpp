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
    // Создаётся объект класса Text и в него добавляются все строки из comboBoxText
    mystr::Text tempText;
    mystr::String tempStr;

    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }

    // Объекту типа Vector<Vector<int>> присваиватеся результат выполнения метода find()
    auto result = tempText.find(ui->lineEdit_find->text().toStdString().c_str());

    // Очищается прошлый вывод данного метода
    ui->textBrowser_found->clear();

    // Выводятся полученные индексы
    for (int i = 0; i < result.getSize(); ++i) {
        for (int j = 0; j < result[i].getSize(); j++){
            ui->textBrowser_found->append(QString(QString::number(i) + QString(": ") + QString::number(result[i][j])));
        }
    }

    // Считается и выводится количество совпадений
    int g = 0;
    for (int i = 0; i < result.getSize(); i++){
        g+=result[i].getSize();
    }

    ui->lcdNumber_found->display(g);
}

// Удаление строк
void TextClassTest::on_pushButton_clicked()
{
    // Удаляется строка, которая выбрана в данный момент в comboBoxText
    ui->comboBoxText->removeItem(ui->comboBoxText->currentIndex());

    mystr::Text tempText;
    mystr::String tempStr;

    // В объект tempText добавляются элементы текста с помощью метода вектора push_back()
    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }

    // На lcd панель выводится длина текста
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

// Добавление строк
void TextClassTest::on_pushButton_addString_clicked()
{
    /* Проверяется включён ли comboBoxAddIndex (в котором выбирается
     * индекс для добавления строк), если да, то строка добавляется по
     * выбранному индексу (comboBoxAddIndex автоматически изменяет при
     * изменении выбранного элемента в comboBoxAddString (в нём
     * выбирается куда добавить элемент))*/
    if(ui->comboBoxAddIndex->isEnabled()){
        ui->comboBoxText->insertItem(ui->comboBoxAddIndex->currentIndex(), ui->lineEditAddString->text());
    }
    // Если добавление происходит не по индексу
    else{
        if(ui->comboBoxAddString->currentIndex() == 1){
            ui->comboBoxText->addItem(ui->lineEditAddString->text());
        }
        else {
           ui->comboBoxText->insertItem(0, ui->lineEditAddString->text());
        }
    }

    // Если пользователь выбирал индекс, то очищается поле с выбором индекса
    if (ui->comboBoxAddString->currentIndex() == 2){
        ui->comboBoxAddIndex->clear();
        for(int i = 0; i < ui->comboBoxText->count(); i++){
            ui->comboBoxAddIndex->addItem(QString(QString::number(i)));
        }
    }

    // Пересчитывается и выводится длина текста
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
    // Создаётся объект класса Text и в него добавляются все строки из comboBoxText
    mystr::Text tempText;
    mystr::String tempStr;

    for (auto i = 0; i < ui->comboBoxText->count(); ++i) {
        tempStr = ui->comboBoxText->itemText(i).toStdString().c_str();
        tempText.text.push_back(tempStr);
    }

    // Переменной result присваивается результат выполнения метода replace()
    int result = tempText.replace(ui->lineEdit_find_2->text().toStdString().c_str(), ui->lineEdit_place->text().toStdString().c_str());

    // Очищается comboBoxText
    ui->comboBoxText->clear();

    for(int i = 0; i < tempText.text.getSize(); i++){
        ui->comboBoxText->addItem(QString(tempText.text[i].getCPtr()));
    }

    // выводится количество замен
    ui->lcdNumber_replacements->display(result);

    // обновляется информация о тексте
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
