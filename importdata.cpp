#include "importdata.h"
#include <QFile>
#include <QTextStream>

ImportData::ImportData()
{
    QFile file(":/dataToLearn.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        dataRead = in.readLine();

        // cpp getline ?

        while (!dataRead.isNull()) {

        }


}
