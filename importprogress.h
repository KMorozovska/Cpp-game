#ifndef IMPORTPROGESS_H
#define IMPORTPROGESS_H


#include <questionanswer.h>
#include <vector>

class ImportProgress
{
private:
    ImportProgress();
    ImportProgress( const ImportProgress & );
    static ImportProgress* instance;
public:
    static ImportProgress* getInstance();

public:
    std::vector<QuestionAnswer> dataToLearn;
private:

    QString dataRead;
};

#endif // IMPORTPROGESS_H
