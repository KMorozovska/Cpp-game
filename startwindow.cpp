#include "startwindow.h"
#include "gamewindow.h"

#include <QPushButton>
#include <QApplication>
#include <QMessageBox>


StartWindow::StartWindow(QWidget *parent) :
 QWidget(parent)
{
 // Set size of the window
 setFixedSize(100, 50);

 createGUI();

 connect(newGameButton, SIGNAL(clicked(bool)), this, SLOT(openNewGameWindow()));
 connect(newGameButton, SIGNAL (clicked(bool)), this, SLOT (slotButtonNewClicked(bool)));
 connect(loadGameButton, SIGNAL(clicked(bool)), this, SLOT(openExistingGameWindow()));
 connect(loadGameButton, SIGNAL (clicked(bool)), this, SLOT (slotButtonLoadClicked(bool)));

 connect(rulesButton, SIGNAL(clicked(bool)), this, SLOT(openRulesDialogue()));

}

void StartWindow::slotButtonNewClicked(bool checked)
{
 if (checked) {
 newGameButton->setText("Otwarto gre");
 newGameButton->setEnabled(false);
 loadGameButton->setEnabled(false);
 }
}

void StartWindow::slotButtonLoadClicked(bool checked)
{
 if (checked) {
 loadGameButton->setText("Otwarto gre");
 loadGameButton->setEnabled(false);
 newGameButton->setEnabled(false);
 }
}

void StartWindow::openNewGameWindow()
{
    newGameWindow = new GameWindow(true); // Be sure to destroy your window somewhere
    newGameWindow->show();
}

void StartWindow::openExistingGameWindow()
{
    newGameWindow = new GameWindow(false); // Be sure to destroy your window somewhere
    newGameWindow->show();
}

void StartWindow::openRulesDialogue()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Zasady gry Supermemo");
    msgBox.setInformativeText("Program Supermemo służy do efektywnej nauki. Od standardowego programu do zapamiętywania różni się jednak algorytmem powtarzania uczonych informacji.");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void StartWindow::createGUI() {

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

