#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>

class QPushButton;
class GameWindow : public QWidget
{
 Q_OBJECT
public:
 explicit GameWindow(QWidget *parent = 0);
private slots:
 void slotMainButtonClicked(bool checked);
 void slotNumberChosen1(bool checked);
 void slotNumberChosen2(bool checked);
 void slotNumberChosen3(bool checked);
 void slotNumberChosen4(bool checked);
 void slotNumberChosen5(bool checked);
public slots:

private:

 QPushButton *mainButton;
 QLabel *label;
 QLabel *label2;
 QGroupBox *groupBox;
 QVBoxLayout *windowLayout;

};


#endif // GAMEWINDOW_H


