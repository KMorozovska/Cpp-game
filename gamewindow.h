#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "questionanswer.h"
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <vector>


class QPushButton;
class GameWindow : public QWidget
{
 Q_OBJECT
public:
 explicit GameWindow(QWidget *parent = 0);
 int generateNextWord();
 void createGUI();
 void setSignals();
 void refresh(int chosenValue);

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
 QRadioButton *radio1;
 QRadioButton *radio2;
 QRadioButton *radio3;
 QRadioButton *radio4;
 QRadioButton *radio5;
 QVBoxLayout *windowLayout;
 std::vector<QuestionAnswer> myData;
 int chosenWord;

};


#endif // GAMEWINDOW_H


