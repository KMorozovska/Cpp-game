#include "importdata.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <fstream>
#include <sstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>
#include "qstringserializer.h"

ImportData::ImportData()
{

        QFile file(":/new/prefix1/dataToLearn.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);

        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            std::string question = fields[0].toUtf8().constData();
            std::string answer = fields[1].toUtf8().constData();
            QuestionAnswer *newElement = new QuestionAnswer(question, answer);

            //newElement.question = fields[0];
            dataToLearn.push_back(*newElement);

            delete newElement;
        }

        file.close();
}

ImportData* ImportData::instance = 0;

ImportData* ImportData::getInstance()
{
    if (instance == 0)
    {
        instance = new ImportData();
    }

    return instance;
}
