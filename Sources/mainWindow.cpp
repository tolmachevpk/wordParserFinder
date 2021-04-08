#include "../Headers/mainWindow.h"
#include <QGridLayout>
#include <QMessageBox>
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QLabel *nameLabel = new QLabel(tr("Write words:"));
    wroteWords = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Result:"));
    foundResult = new QTextEdit;
    foundResult->setReadOnly(true);

    status = new QLabel(tr("Ready!"));

    confirmButton = new QPushButton(tr("&Confirm"));
    confirmButton->show();
    connect(confirmButton, &QPushButton::clicked, this, &MainWindow::rememberWordsForString);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(wroteWords, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(foundResult, 1, 1);
    mainLayout->addWidget(confirmButton, 1, 2, Qt::AlignTop);
    mainLayout->addWidget(status, 0, 2);

    resize(1000, 700);
    setLayout(mainLayout);
    setWindowTitle(tr("Word Finder"));
}

void MainWindow::rememberWordsForString() {
    words = wroteWords->text().toStdString();
    if (words.length() == 0) {
        QMessageBox::information(this, tr("Empty Field"), tr("Please enter words"));
        return;
    }
    wroteWords->setReadOnly(true);
    confirmButton->setEnabled(false);
    status->setText("Calculating...");
    status->show();
    checkAllDict();
}

void MainWindow::checkAllDict() {
    std::fstream fin;
    fin.open("../words.txt");

    AhoKorasik *g = new AhoKorasik(words);

    std::string line;
    while (fin >> line) {
        std::string result;
        result = g->algorithmRealization(line);
        if (result != "-1") {
            addToResult(result);
        }
    }
    fin.close();
    std::cout << "ОН ВСЕ ПРОЧИТАЛ!" << std::endl;
    finished();
    foundResult->show();
}

void MainWindow::finished() {
    status->setText("Finished.");
}

void MainWindow::addToResult(const std::string &calculatedWord) {
    foundResult->moveCursor(QTextCursor::End);
    foundResult->insertPlainText(QString::fromStdString(calculatedWord));
    foundResult->moveCursor(QTextCursor::End);
    foundResult->insertPlainText("   ");
}
