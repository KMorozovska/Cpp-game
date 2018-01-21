#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "gamewindow.h"

class QPushButton;
class StartWindow : public QWidget
{
 Q_OBJECT
public:
 explicit StartWindow(QWidget *parent = 0);
 void createGUI();
private slots:
 void slotButtonNewClicked(bool checked);
 void slotButtonLoadClicked(bool checked);
public slots:
   void openNewGameWindow();
   void openExistingGameWindow();
   void openRulesDialogue();
public:
   void refreshButtons();
private:
 GameWindow *newGameWindow;
 QPushButton *newGameButton;
 QPushButton *loadGameButton;
 QPushButton *rulesButton;
};

#endif // STARTWINDOW_H
