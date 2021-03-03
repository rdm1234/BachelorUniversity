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
    // Очищается окно вывода результата
    ui->textBrowser_found->clear();

    // Создаётся объект класса String, в который сразу помещается содержимое textEdit
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());

    // Создаётся объект класса Vector<int>, в него сразу помещается результат метода find()(метод для нахождения индексов)
    mystr::Vector<int> result(a.find(ui->lineEdit_find->text().toStdString().c_str()));

    // Цикл выводящий найденные индексы
    for(int i = 0; i < result.getSize(); i++){
        ui->textBrowser_found->append(QString(QString::number(result[i])));
    }

    // На lcd панель выводится результат метода find_amount()
    ui->lcdNumber_found->display(QString(QString::number(a.find_amount(ui->lineEdit_find->text().toStdString().c_str()))));
}

void StringClassTest::on_pushButton_replace_clicked()
{

    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());

    // переменной result присваивается результат, возвращаемый методом замены элементов
    int result = a.replace(ui->lineEdit_find_2->text().toStdString().c_str(), ui->lineEdit_place->text().toStdString().c_str());

    // очищается textEdit, чтобы поместить туда изменённый текст
    ui->textEdit->clear();

    // выводит изменённый текст
    ui->textEdit->setText(QString(a.getCPtr()));

    // выводит количество замен
    ui->lcdNumber_replacements->display(result);
}

void StringClassTest::on_pushButton_getSize_clicked()
{
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    ui->lcdNumber_strSize->display(QString(QString::number(a.getSize())));
}

void StringClassTest::on_textEdit_textChanged()
{
    // Создаётся объект класса String, в который сразу помещается содержимое textEdit
    mystr::String a(ui->textEdit->toPlainText().toStdString().c_str());
    // на lcdNumber выводится результат метода getSize()
    ui->lcdNumber_strSize->display(QString(QString::number(a.getSize())));

}

void StringClassTest::on_StringClassTest_customContextMenuRequested(const QPoint &pos)
{

}
