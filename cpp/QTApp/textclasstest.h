#ifndef TEXTCLASSTEST_H
#define TEXTCLASSTEST_H

#include <QWidget>
#include "StringLibrary/text.h"

namespace Ui {
class TextClassTest;
}

class TextClassTest : public QWidget
{
    Q_OBJECT

public:
    explicit TextClassTest(QWidget *parent = nullptr);
    ~TextClassTest();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_clicked();

    void on_comboBoxAddString_currentIndexChanged(int index);

    void on_pushButton_addString_clicked();

    void on_pushButton_replace_clicked();

    void on_comboBoxText_editTextChanged(const QString &arg1);

private:
    Ui::TextClassTest *ui;
};

#endif // TEXTCLASSTEST_H
