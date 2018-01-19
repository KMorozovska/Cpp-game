#include "gamewindow.h"
#include "window.h"
#include "importdata.h"
#include "questionanswer.h"

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>


GameWindow::GameWindow(QWidget *parent) :
 QWidget(parent)
{

 ImportData *loadData = new ImportData();
 myData = loadData->get_dataToLearn();
 chosenWord = generateNextWord();

 createGUI();
 setLayout(windowLayout);
 setSignals();

}

void GameWindow::setSignals() {
    connect(mainButton, SIGNAL (clicked(bool)), this, SLOT (slotMainButtonClicked(bool)));
    connect(radio1, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen1(bool)));
    connect(radio2, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen2(bool)));
    connect(radio3, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen3(bool)));
    connect(radio4, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen4(bool)));
    connect(radio5, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen5(bool)));
}

int GameWindow::generateNextWord(){

    return 1;
}

void GameWindow::refresh(int chosenValue) {

    myData[chosenWord].setResponseOfUser(chosenValue);
    chosenWord = generateNextWord();

    delete label;
    delete mainButton;
    delete groupBox;
    delete windowLayout;

    createGUI();
    setLayout(windowLayout);
    setSignals();

}

void GameWindow::slotMainButtonClicked(bool checked)
{
 if (checked) {
    mainButton->setText(myData[chosenWord].getAnswer());
    windowLayout->addWidget(groupBox);

 }
}

 void GameWindow::slotNumberChosen1(bool checked)
 {
  if(checked) {
      refresh(1);
  }
 }
 void GameWindow::slotNumberChosen2(bool checked)
 {
  if(checked) {
      refresh(2);
  }
 }
 void GameWindow::slotNumberChosen3(bool checked)
 {
  if(checked) {
      refresh(3);
  }
 }
 void GameWindow::slotNumberChosen4(bool checked)
 {
  if(checked) {
      refresh(4);
  }
 }
 void GameWindow::slotNumberChosen5(bool checked)
 {
  if(checked) {
      refresh(5);
  }
 }

 void GameWindow::createGUI() {

     windowLayout = new QVBoxLayout;

     label = new QLabel(this);
     label->setText("Oto pierwsze pytanie\nOdpowiedz na nie w głowie\nNaciśnij kiedy będziesz chciał poznać odpowiedź");
     label->setGeometry(30,30,300,50);

     mainButton = new QPushButton(myData[chosenWord].getQuestion(), this);
     mainButton->setGeometry(0, 100, 200, 200);
     mainButton->setCheckable(true);

     groupBox = new QGroupBox(tr("Odpowiedz na ile dobrze pamietałes tą odpowiedź:"));

     radio1 = new QRadioButton(tr("1"));
     radio2 = new QRadioButton(tr("2"));
     radio3 = new QRadioButton(tr("3"));
     radio4 = new QRadioButton(tr("4"));
     radio5 = new QRadioButton(tr("5"));

     QHBoxLayout *buttonsLayout = new QHBoxLayout;
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
