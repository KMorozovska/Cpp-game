#include "questionanswer.h"

QuestionAnswer::QuestionAnswer() { }

QuestionAnswer::QuestionAnswer(std::string q, std::string a)
{
    question = q;
    answer = a;
    qualityOfResponse = 0;
    eFactor = 1.3;
    eFactorString = " ";
}

QuestionAnswer::QuestionAnswer(const QuestionAnswer &wzor) {
    question = wzor.question;
    answer = wzor.answer;
    qualityOfResponse = wzor.qualityOfResponse;
    eFactor = wzor.eFactor;
    eFactorString = wzor.eFactorString;
}

std::string QuestionAnswer::getQuestion(){
    return question;
}

std::string QuestionAnswer::getAnswer(){
    return answer;
}

void QuestionAnswer::setQualityOfResponse(int resp){
    qualityOfResponse = resp;
}

