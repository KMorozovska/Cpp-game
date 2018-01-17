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

 //layout

 windowLayout = new QVBoxLayout;

 // Set size of the window
 setFixedSize(500, 500);
 setWindowTitle("Graj - supermemo");
 setLayout(windowLayout);

 label = new QLabel(this);
 label->setText("Oto pierwsze pytanie\nOdpowiedz na nie w głowie\nNaciśnij kiedy będziesz chciał poznać odpowiedź");
 label->setGeometry(30,30,300,50);

 mainButton = new QPushButton("tutaj bedzie slowo do klikniecia", this);
 mainButton->setGeometry(0, 100, 200, 200);
 mainButton->setCheckable(true);

 groupBox = new QGroupBox(tr("Odpowiedz na ile dobrze pamietałes tą odpowiedź:"));

 QRadioButton *radio1 = new QRadioButton(tr("1"));
 QRadioButton *radio2 = new QRadioButton(tr("2"));
 QRadioButton *radio3 = new QRadioButton(tr("3"));
 QRadioButton *radio4 = new QRadioButton(tr("4"));
 QRadioButton *radio5 = new QRadioButton(tr("5"));

 QHBoxLayout *buttonsLayout = new QHBoxLayout;
 buttonsLayout->addWidget(radio1);
 buttonsLayout->addWidget(radio2);
 buttonsLayout->addWidget(radio3);
 buttonsLayout->addWidget(radio4);
 buttonsLayout->addWidget(radio5);
 groupBox->setLayout(buttonsLayout);


 windowLayout->addWidget(label);
 windowLayout->addWidget(mainButton);

 connect(mainButton, SIGNAL (clicked(bool)), this, SLOT (slotMainButtonClicked(bool)));
 connect(radio1, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen1(bool)));
 connect(radio2, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen2(bool)));
 connect(radio3, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen3(bool)));
 connect(radio4, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen4(bool)));
 connect(radio5, SIGNAL (clicked(bool)), this, SLOT (slotNumberChosen5(bool)));

}

void GameWindow::slotMainButtonClicked(bool checked)
{
 if (checked) {
 mainButton->setText("pojawia sie odpowiedz");

 windowLayout->addWidget(groupBox);
 }
}

 void GameWindow::slotNumberChosen1(bool checked)
 {
  if(checked) {
      Window *someWindow = new Window();

      ImportData *loadData = new ImportData();

      std::vector<QuestionAnswer> myData = loadData->get_dataToLearn();

      someWindow->setWindowTitle(myData[1].getQuestion());
      someWindow->show();
  }
  }
 void GameWindow::slotNumberChosen2(bool checked)
 {
  if(checked) {
      Window *someWindow = new Window();
      someWindow->setWindowTitle("2");
      someWindow->show();
  }
  }
 void GameWindow::slotNumberChosen3(bool checked)
 {
  if(checked) {
      Window *someWindow = new Window();
      someWindow->setWindowTitle("3");
      someWindow->show();
  }
  }
 void GameWindow::slotNumberChosen4(bool checked)
 {
  if(checked) {
      Window *someWindow = new Window();
      someWindow->setWindowTitle("4");
      someWindow->show();
  }
  }
 void GameWindow::slotNumberChosen5(bool checked)
 {
  if(checked) {
      Window *someWindow = new Window();
      someWindow->setWindowTitle("5");
      someWindow->show();
  }
  }
