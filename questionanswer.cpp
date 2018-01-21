#include "questionanswer.h"

/**
 * Klasa przechowująca dane do nauki.
 * Opis parametrów w pliku .h
 */

QuestionAnswer::QuestionAnswer() { }

/**
 * Konstruktor dwuargumentowy dla danych wczytywanych z początkowego pliku.
 * Wartość eFactor ustawiona na 2.5 według opisu ze strony https://www.supermemo.com/english/ol/sm2.htm
 */
QuestionAnswer::QuestionAnswer(std::string q, std::string a)
{
    question = q;
    answer = a;
    eFactor = 2.5;
    alreadyChosen = false;
}

/**
 * Konstruktor trzyparametrowy dla danych wczytywanych z pliku zawierającego postępy użytkownika.
 * Wartość eFactor jest dzielona przez 1000000, ponieważ przed wpisaniem zostały pomnożone przez 1000000
 * - bez tego wartości były zaokrąglane do wartości całkowitych.
 */
QuestionAnswer::QuestionAnswer(std::string q, std::string a, std::string e)
{
    question = q;
    answer = a;
    eFactor = std::stof(e.c_str())/1000000;
    alreadyChosen = false;
}

/**
 * Konstruktor kopiujący
 */

QuestionAnswer::QuestionAnswer(const QuestionAnswer &wzor) {
    question = wzor.question;
    answer = wzor.answer;
    eFactor = wzor.eFactor;
    alreadyChosen = wzor.alreadyChosen;
}

std::string QuestionAnswer::getQuestion(){
    return question;
}

std::string QuestionAnswer::getAnswer(){
    return answer;
}

float QuestionAnswer::getEFactor(){
    return eFactor;
}

bool QuestionAnswer::getAlreadyChosen() {
    return alreadyChosen;
}

/**
 * Metoda ustawiająca parametr EFactor.
 * Formuła oparta na wzorze ze strony https://www.supermemo.com/english/ol/sm2.htm
 * @param q - odpowiedź użytkownika na pytanie "Jak dobrze pamiętałeś tę odpowiedź?"
 */

void QuestionAnswer::setEFactor(int q){
    float newEFactor;
    newEFactor = this->eFactor+(0.1-(5-q)*(0.08+(5-q)*0.02));      // formula from SuperMemo

    if(newEFactor>1.3) {
        eFactor = newEFactor;
    } else { eFactor = 1.3; }
}

void QuestionAnswer::setAlreadyChosen(bool b) {
    alreadyChosen = b;
}
