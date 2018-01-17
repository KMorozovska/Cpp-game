#include "importdata.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ImportData::ImportData()
{

        QFile file("dataToLearn.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);

        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            QuestionAnswer *newElement = new QuestionAnswer(fields[0], fields[1]);

            //newElement.question = fields[0];
            dataToLearn.push_back(*newElement);

            delete newElement;
        }

        file.close();
}

std::vector<QuestionAnswer> ImportData::get_dataToLearn() {
    return dataToLearn;
}
