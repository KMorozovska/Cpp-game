#include "gamewindow.h"
#include "startwindow.h"
#include "importdata.h"
#include "importprogress.h"
#include "questionanswer.h"
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <algorithm>

/**
 * Klasa GameWindow tworzy właściwe okienko gry, w której wyświetlają się kolejne słowa do nauki.
 * @param isNewGame - odpowiada za wybór, czy zaczynamy zupełnie nową naukę na podstawie dokumentu "dataToLearn.txt"
 *                    czy wczytujemy istniejącą grę na podstawie dokumentu "dataProgress.txt"
 **/

GameWindow::GameWindow(bool isNewGame, QWidget *parent) :
 QWidget(parent)
{
 if(isNewGame==true) {
    importDataObject = ImportData::getInstance();
    if(importDataObject->dataToLearn.empty()) {
         showInfoWindow("Błąd", "Niepoprawny import danych");
    }
    myData = importDataObject->dataToLearn;
 }
 if(isNewGame==false) {
     importProgressObject = ImportProgress::getInstance();
     if(importProgressObject->dataToLearn.empty()) {
         showInfoWindow("Błąd", "Niepoprawny import danych");
     }
     myData = importProgressObject->dataToLearn;
 }
 chosenWord = &myData[0];
 createGUI();
 setLayout(windowLayout);
 setSignals();
}

/**
 * Metoda generująca początkowe GUI, które w całości wyświetli się po naciśnięciu głównego przycisku.
 */

void GameWindow::createGUI() {
     windowLayout = new QVBoxLayout;

     label = new QLabel(this);
     label->setText("Oto pierwsze słowo\nOdpowiedz w głowie jak brzmi po polsku\nNaciśnij kiedy będziesz chciał poznać odpowiedź");

     mainButton = new QPushButton(QString::fromStdString(chosenWord->getQuestion()), this);
     const QSize BUTTON_SIZE = QSize(100, 200);
     mainButton->setMinimumSize(BUTTON_SIZE);
     mainButton->setCheckable(true);

     groupBox = new QGroupBox(tr("Odpowiedz na ile dobrze pamietałes to słowo:"));
     radio0 = new QRadioButton(tr("0"));
     radio1 = new QRadioButton(tr("1"));
     radio2 = new QRadioButton(tr("2"));
     radio3 = new QRadioButton(tr("3"));
     radio4 = new QRadioButton(tr("4"));
     radio5 = new QRadioButton(tr("5"));

     QHBoxLayout *buttonsLayout = new QHBoxLayout;
     buttonsLayout->addWidget(radio0);
     buttonsLayout->addWidget(radio1);
     buttonsLayout->addWidget(radio2);
     buttonsLayout->addWidget(radio3);
     buttonsLayout->addWidget(radio4);
     buttonsLayout->addWidget(radio5);

     groupBox->setLayout(buttonsLayout);
     windowLayout->addWidget(label);
     windowLayout->addWidget(mainButton);

     setFixedSize(500, 500);
     setWindowTitle("Graj - supermemo");
 }


/**
 * Metoda umożliwiająca reakcję na kliknięcia użytkownika.
 * Jest osobną metodą, ponieważ jest ponownie wywoływana po każdym odświeżeniu okna po udzielonej odpowiedzi.
 **/

void GameWindow::setSignals() {
    connect(mainButton, SIGNAL (clicked(bool)), this, SLOT (slotMainButtonClicked(bool)));
    connect(radio0, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen0(bool)));
    connect(radio1, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen1(bool)));
    connect(radio2, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen2(bool)));
    connect(radio3, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen3(bool)));
    connect(radio4, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen4(bool)));
    connect(radio5, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen5(bool)));
}

/**
 * Struktura sortująca wektor z danymi do nauki według parametru EFactor.
 */

struct sort_by_EFactor
{
    inline bool operator() (QuestionAnswer& qa1, QuestionAnswer& qa2)
    {
        return (qa1.getEFactor() > qa2.getEFactor());
    }
};

/**
 * Metoda wybierająca kolejne słowo do nauki. Za każdym razem sortuje wektor ze słowami
 * według odświeżanych po każdej odpowiedzi wartości parametru EFactor (ustalanego na podstawie
 * odpowiedzi użytkownika "Jak dobrze pamiętałeś tę odpowiedź?".
 * Słowa o najniższej wartości parametru (najsłabiej pamiętanym) są pokazywane na początku.
 * @return chosenWord - zwraca wybrane słowo
 */

QuestionAnswer* GameWindow::generateNextWord(){
    QuestionAnswer* tempChosen = chosenWord;

    std::sort(myData.begin(), myData.end(), sort_by_EFactor());

    for(int i=0; (unsigned)i<myData.size(); i++) {
        if(myData[i].getAlreadyChosen()==false) {
            if(tempChosen != chosenWord) {
                chosenWord = &myData[i];
            }
            else chosenWord = &myData[i+1];
        }
    }

    return chosenWord;
}

/**
 * Metoda generująca kolejne słowo do nauki i przywracająca pierwotny wygląd okienka.
 * @param chosenValue - wybrana z przycisku odpowiedź na pytanie "Jak dobrze pamiętałeś odpowiedź?"
 */

void GameWindow::refreshWindow(int chosenValue) {
    chosenWord->setEFactor(chosenValue);
    chosenWord->setAlreadyChosen(true);
    chosenWord = generateNextWord();
    delete label;
    delete mainButton;
    delete groupBox;
    delete windowLayout;
    createGUI();
    setLayout(windowLayout);
    setSignals();
}

/**
  * Metoda eksportująca do pliku "dataProgress.txt" postęp użytkownika.
  */

 void GameWindow::exportProgress() {
     std::ofstream ofs;
     ofs.open("dataProgress.txt", std::ofstream::out | std::ofstream::trunc);
     ofs.close();
     std::string filename = "dataProgress.txt";
     std::ofstream out(filename.c_str());
     for (int i=0; (unsigned)i<myData.size();i++) {
         out << myData[i].getQuestion() << ", ";
         out << myData[i].getAnswer() << ", ";
         out << std::to_string(myData[i].getEFactor()*1000000) << "\n";
     }
     out.close();
     showInfoWindow("Wyjście", "Twoje postępy zostały zapisane");
 }

/**
 * Metoda reagująca na sygnał użytkownika, który chce zobaczyć odpowiedź na pytanie z przycisku.
 * Dodaje do okienka możliwość odpowiedzi na pytanie "Jak dobrze pamiętałeś odpowiedź?"
 * @param checked - reaguje na kliknięcie
 */
void GameWindow::slotMainButtonClicked(bool checked)
{
 if (checked) {
    mainButton->setText(QString::fromStdString(chosenWord->getAnswer()));
    windowLayout->addWidget(groupBox);
 }
}
 /**
  * Metody odpowiadające za odbiór sygnałów z poszczególnych przycisków o wartościach 0-5,
  * służacych do wyboru odpowiedzi na pytanie "Jak dobrze pamiętałeś odpowiedź?"
  * @param checked - reaguje na kliknięcie
  **/

 void GameWindow::slotNumberChosen0(bool checked)
 {
  if(checked) {
      refreshWindow(0);
  }
 }
  void GameWindow::slotNumberChosen1(bool checked)
  {
   if(checked) {
       refreshWindow(1);
   }
  }
  void GameWindow::slotNumberChosen2(bool checked)
  {
   if(checked) {
       refreshWindow(2);
   }
  }
  void GameWindow::slotNumberChosen3(bool checked)
  {
   if(checked) {
       refreshWindow(3);
   }
  }
  void GameWindow::slotNumberChosen4(bool checked)
  {
   if(checked) {
       refreshWindow(4);
   }
  }
  void GameWindow::slotNumberChosen5(bool checked)
  {
   if(checked) {
       refreshWindow(5);
   }
  }

  /**
  * Metoda wywoływana w trakcie zamykania okna z grą.
  * Potrzeba do zapisu postępów do pliku.
  */

 void GameWindow::closeEvent(QCloseEvent *event)
 {
     Q_UNUSED(event);
     exportProgress();
 }

  /**
    * Metoda pomocnicza, wyświetlająca okienko z krótką informacją.
    * @param title
    * @param message
    */

   void GameWindow::showInfoWindow(QString title, QString message) {

       QMessageBox msgBox;
       msgBox.setWindowTitle(title);
       msgBox.setInformativeText(message);
       msgBox.setDefaultButton(QMessageBox::Ok);
       msgBox.exec();
   }

