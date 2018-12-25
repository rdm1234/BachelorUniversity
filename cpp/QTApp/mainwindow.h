#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stringclasstest.h"
#include "textclasstest.h"
#include "wordclasstest.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StringClassTest_clicked();

    void on_TextClassTest_clicked();

    void on_WordClassTest_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
