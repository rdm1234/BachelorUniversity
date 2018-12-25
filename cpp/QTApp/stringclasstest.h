#pragma once
#ifndef STRINGCLASSTEST_H
#define STRINGCLASSTEST_H
#include "StringLibrary/string.h"
#include <QWidget>

namespace Ui {
class StringClassTest;
}

class StringClassTest : public QWidget
{
    Q_OBJECT

public:
    explicit StringClassTest(QWidget *parent = nullptr);
    ~StringClassTest();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_replace_clicked();

    void on_pushButton_getSize_clicked();

    void on_textEdit_textChanged();

    void on_StringClassTest_customContextMenuRequested(const QPoint &pos);

private:
    Ui::StringClassTest *ui;
};

#endif // STRINGCLASSTEST_H
