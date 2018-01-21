#include "importprogress.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

/**
 * Klasa typu Singleton służąca do zaimportowania danych z pliku postępów
 * i wpisania ich do wektora dataToLearn, wykorzystywanego w klasie GameWindow.
 */

ImportProgress::ImportProgress()
{
    QFile file(":/new/prefix1/dataProgress.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QuestionAnswer *newElement = new QuestionAnswer(fields[0].toUtf8().constData(), fields[1].toUtf8().constData(), fields[2].toUtf8().constData());

        dataToLearn.push_back(*newElement);
        delete newElement;
    }
    file.close();
}

ImportProgress* ImportProgress::instance = 0;

ImportProgress* ImportProgress::getInstance()
{
if (instance == 0) {
    instance = new ImportProgress();
}
  return instance;
}


