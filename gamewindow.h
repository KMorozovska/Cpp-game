#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

class QPushButton;
class GameWindow : public QWidget
{
 Q_OBJECT
public:
 explicit GameWindow(QWidget *parent = 0);
private slots:
 void slotMainButtonClicked(bool checked);
public slots:

private:

 QPushButton *mainButton;

};


#endif // GAMEWINDOW_H


