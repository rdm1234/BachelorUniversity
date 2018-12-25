#ifndef WORDCLASSTEST_H
#define WORDCLASSTEST_H

#include <QWidget>
#include "StringLibrary/word.h"

namespace Ui {
class WordClassTest;
}

class WordClassTest : public QWidget
{
    Q_OBJECT

public:
    explicit WordClassTest(QWidget *parent = nullptr);
    ~WordClassTest();

private slots:
    void on_textEdit_textChanged();

    void on_pushButton_find_clicked();

    void on_pushButton_replace_clicked();

private:
    Ui::WordClassTest *ui;
};

#endif // WORDCLASSTEST_H
