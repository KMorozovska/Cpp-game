#ifndef QUESTIONANSWER_H
#define QUESTIONANSWER_H

#include <iostream>
#include <QString>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class QuestionAnswer
{
public:
    QuestionAnswer();
    QuestionAnswer(std::string q, std::string a);
    QuestionAnswer(std::string q, std::string a, std::string e);
    QuestionAnswer(const QuestionAnswer &wzor);

    std::string getQuestion();
    std::string getAnswer();
    float getEFactor();
    bool getAlreadyChosen();
    void setEFactor(int resp);
    void setAlreadyChosen(bool b);

private:
    /** słowo po angielsku **/
    std::string question;

    /** odpowiedź - słowo po polsku **/
    std::string answer;

    /** współczynnik nauczenia, potrzebny do algorytmu wybierania częstotliwości **/
    float eFactor;

    /** flaga służąca do sprawdzenia, czy w danym uruchomieniu gry wystąpiło już dane słowo **/
    bool alreadyChosen;
};

#endif // QUESTIONANSWER_H
