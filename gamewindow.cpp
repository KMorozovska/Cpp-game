#include "gamewindow.h"

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

GameWindow::GameWindow(QWidget *parent) :
 QWidget(parent)
{


 // Set size of the window
 setFixedSize(500, 600);
 setWindowTitle("Graj - supermemo");

 QLabel *label = new QLabel(this);
 label->setText("Oto pierwsze pytanie\nOdpowiedz na nie w głowie\nNaciśnij kiedy będziesz chciał poznać odpowiedź");
 label->setGeometry(100,30,300,50);

 //QVBoxLayout *vbl = new QVBoxLayout(this);
 //vbl->addWidget(&i_label);
 //vbl->addWidget(&Bu_Quit);

 mainButton = new QPushButton("tutaj bedzie slowo do klikniecia", this);
 mainButton->setGeometry(150, 100, 200, 200);
 mainButton->setCheckable(true);

 connect(mainButton, SIGNAL (clicked(bool)), this, SLOT (slotMainButtonClicked(bool)));

}

void GameWindow::slotMainButtonClicked(bool checked)
{
 if (checked) {
 mainButton->setText("pojawia sie odpowiedz");

 QLabel *label2 = new QLabel(this);
 label2->setText("Odpowiedz na ile dobrze pamietałes tą odpowiedź:");
 label2->setGeometry(50,50,300,50);


 }

}
