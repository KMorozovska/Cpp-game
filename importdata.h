#ifndef IMPORTDATA_H
#define IMPORTDATA_H

#include <questionanswer.h>
#include <list>

class ImportData
{
public:
    ImportData();
private:
    std::list<QuestionAnswer> dataToLearn;
    QString dataRead;
};

#endif // IMPORTDATA_H
