#ifndef IMPORTPROGESS_H
#define IMPORTPROGESS_H


#include <questionanswer.h>
#include <vector>

class ImportProgess
{
private:
    ImportProgess();
    ImportProgess( const ImportProgess & );
    static ImportProgess* instance;
public:
    static ImportProgess* getInstance();

public:
    std::vector<QuestionAnswer> get_dataToLearn();
private:
    std::vector<QuestionAnswer> dataToLearn;
    QString dataRead;
};

#endif // IMPORTPROGESS_H
