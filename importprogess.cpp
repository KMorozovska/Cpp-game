#include "importprogess.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ImportProgess::ImportProgess()
{
    QFile file(":/new/prefix1/dataProgress.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QuestionAnswer *newElement = new QuestionAnswer(fields[0].toUtf8().constData(), fields[1].toUtf8().constData());

        dataToLearn.push_back(*newElement);
        delete newElement;
    }
    file.close();
}

ImportProgess* ImportProgess::instance = 0;

ImportProgess* ImportProgess::getInstance()
{
if (instance == 0) {
    instance = new ImportProgess();
}
  return instance;
}

std::vector<QuestionAnswer> ImportProgess::get_dataToLearn() {
return dataToLearn;
}
