#ifndef WORDPARSERFINDER_LOOKFORMATCHESTHREAD_H
#define WORDPARSERFINDER_LOOKFORMATCHESTHREAD_H
#include <QThread>
#include "ahoKorasik.h"
#include <fstream>

class WorkerThread : public QThread {
    Q_OBJECT

public:
    WorkerThread(const std::string &s);
    void run();

    signals:
        void foundWords(QString line);
        void startCalculating();
        void finishedCalculating();
private:
    std::string words;
};


#endif //WORDPARSERFINDER_LOOKFORMATCHESTHREAD_H
