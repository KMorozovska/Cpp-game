#ifndef IMPORTDATA_H
#define IMPORTDATA_H

#include <questionanswer.h>
#include <vector>

class ImportData
{
private:
    ImportData();
    ImportData( const ImportData & );
    static ImportData* instance;
public:
    static ImportData* getInstance();

public:
    std::vector<QuestionAnswer> dataToLearn;
private:
    QString dataRead;
};

#endif // IMPORTDATA_H
