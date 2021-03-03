#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Открывает окно для тестирования класса String
void MainWindow::on_StringClassTest_clicked()
{
    StringClassTest *frm = new StringClassTest;
    frm->show();
}

// Открывает окно для тестирования класса Text
void MainWindow::on_TextClassTest_clicked()
{
    TextClassTest *frm = new TextClassTest;
    frm->show();
}

// Открывает окно для тестирования класса Word
void MainWindow::on_WordClassTest_clicked()
{
    WordClassTest *frm = new WordClassTest;
    frm->show();
}
