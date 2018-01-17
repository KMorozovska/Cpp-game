#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "gamewindow.h"

class QPushButton;
class Window : public QWidget
{
 Q_OBJECT
public:
 explicit Window(QWidget *parent = 0);
private slots:
 void slotButtonClicked(bool checked);
public slots:
   void openNewGameWindow();
   void openRulesDialogue();
private:
 GameWindow *newGameWindow;
 QPushButton *newGameButton;
 QPushButton *loadGameButton;
 QPushButton *rulesButton;
};

#endif // WINDOW_H
