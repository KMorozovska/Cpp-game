#ifndef QUESTIONANSWER_H
#define QUESTIONANSWER_H

#include <iostream>
//#include <ostream>
#include <QString>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/serialization/vector.hpp>
#include "qstringserializer.h"

class QuestionAnswer
{
public:
    QuestionAnswer();
    QuestionAnswer(std::string q, std::string a);
    QuestionAnswer(const QuestionAnswer &wzor);

    std::string getQuestion();
    std::string getAnswer();
    void setQualityOfResponse(int resp);

    friend class boost::serialization::access;
    template<class Archieve>
    void serialize(Archieve& ar, const unsigned int version)
    {
            ar& question;
            ar& answer;
            ar& qualityOfResponse;
            ar& eFactor;
            ar& eFactorString;
    }


private:
    std::string question;
    std::string answer;
    int qualityOfResponse;         //feedback od użytkownika (skala 1-5)
    int eFactor;                   //dla algorytmu do wybierania częstotliwości
    std::string eFactorString;
    //int eFactorPrim;
};

#endif // QUESTIONANSWER_H
