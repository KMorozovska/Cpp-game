#ifndef QUESTIONANSWER_H
#define QUESTIONANSWER_H

#include <iostream>
#include <QString>

class QuestionAnswer
{
public:
    QuestionAnswer();
    QuestionAnswer(QString q, QString a);
    QuestionAnswer(const QuestionAnswer &wzor);

    QString getQuestion();

private:
    QString question;
    QString answer;
    int responseOfUser;         //feedback od użytkownika (skala 1-5)
    int levelOfKnowledge;       //dla algorytmu do wybierania częstotliwości
};

#endif // QUESTIONANSWER_H
