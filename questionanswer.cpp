#include "questionanswer.h"

QuestionAnswer::QuestionAnswer()
{




}

QuestionAnswer::QuestionAnswer(QString q, QString a)
{
    question = q;
    answer = a;
}

QuestionAnswer::QuestionAnswer(const QuestionAnswer &wzor) {
    question = wzor.question;
    answer = wzor.answer;
    responseOfUser = wzor.responseOfUser;
    levelOfKnowledge = wzor.levelOfKnowledge;
}

QString QuestionAnswer::getQuestion(){
    return question;
}

QString QuestionAnswer::getAnswer(){
    return answer;
}

void QuestionAnswer::setResponseOfUser(int resp){
    responseOfUser = resp;
}
