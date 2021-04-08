#ifndef WORDPARSERFINDER_MAINWINDOW_H
#define WORDPARSERFINDER_MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "../Headers/ahoKorasik.h"

class MainWindow : public QWidget {
public:
    MainWindow(QWidget *parent = nullptr);
public slots:
    void rememberWordsForString();
private:
    void addToResult(const std::string &calculatedWord);
    void checkAllDict();
    void finished();
    QLineEdit *wroteWords;
    QTextEdit *foundResult;
    QPushButton *confirmButton;
    std::string words;
    QLabel *status;
};

#endif //WORDPARSERFINDER_MAINWINDOW_H
