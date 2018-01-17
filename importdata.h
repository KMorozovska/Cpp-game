#ifndef IMPORTDATA_H
#define IMPORTDATA_H

#include <questionanswer.h>
#include <vector>

// to powinien byc singleton !!

class ImportData
{
public:
    ImportData();
public:
    std::vector<QuestionAnswer> get_dataToLearn();
private:
    std::vector<QuestionAnswer> dataToLearn;
    QString dataRead;
};

#endif // IMPORTDATA_H
