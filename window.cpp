#include "window.h"
#include "gamewindow.h"

#include <QPushButton>
#include <QApplication>
#include <QMessageBox>


Window::Window(QWidget *parent) :
 QWidget(parent)
{
 // Set size of the window
 setFixedSize(100, 50);

 createGUI();

 connect(newGameButton, SIGNAL(clicked(bool)), this, SLOT(openNewGameWindow()));
 connect(newGameButton, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));

 connect(rulesButton, SIGNAL(clicked(bool)), this, SLOT(openRulesDialogue()));

}

void Window::slotButtonClicked(bool checked)
{
 if (checked) {
 newGameButton->setText("Otwarto gre");
 }
}

void Window::openNewGameWindow()
{
    newGameWindow = new GameWindow(); // Be sure to destroy your window somewhere
    newGameWindow->show();
}

void Window::openRulesDialogue()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Zasady gry Supermemo");
    msgBox.setInformativeText("Program Supermemo służy do efektywnej nauki. Od standardowego programu do zapamiętywania różni się jednak algorytmem powtarzania uczonych informacji.");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void Window::createGUI() {

    newGameButton = new QPushButton("Graj od początku", this);
    newGameButton->setGeometry(100, 100, 150, 30);
    newGameButton->setCheckable(true);

    loadGameButton = new QPushButton("Graj dalej", this);
    loadGameButton->setGeometry(100, 200, 150, 30);
    loadGameButton->setCheckable(true);

    rulesButton = new QPushButton("Zasady gry", this);
    rulesButton->setGeometry(100, 300, 150, 30);
    rulesButton->setCheckable(true);
}

