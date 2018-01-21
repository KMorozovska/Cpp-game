#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "questionanswer.h"
#include "importdata.h"
#include "importprogress.h"
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QProcess>
#include <vector>


class QPushButton;
class GameWindow : public QWidget
{
 Q_OBJECT
public:
 explicit GameWindow(bool isNewGame = true, QWidget *parent = 0);
 int generateNextWord();
 void createGUI();
 void setSignals();
 void refreshWindow(int chosenValue);
 void showInfoWindow(QString t, QString m);

protected:
 void closeEvent(QCloseEvent *event) override;

signals:
 void finished(int exitCode, QProcess::ExitStatus exitStatus);

private slots:
 void slotMainButtonClicked(bool checked);
 void slotNumberChosen0(bool checked);
 void slotNumberChosen1(bool checked);
 void slotNumberChosen2(bool checked);
 void slotNumberChosen3(bool checked);
 void slotNumberChosen4(bool checked);
 void slotNumberChosen5(bool checked);
 void refreshProgress();

public slots:

private:
 QPushButton *mainButton;
 QLabel *label;
 QLabel *label2;
 QGroupBox *groupBox;
 QRadioButton *radio0;
 QRadioButton *radio1;
 QRadioButton *radio2;
 QRadioButton *radio3;
 QRadioButton *radio4;
 QRadioButton *radio5;
 QVBoxLayout *windowLayout;
 std::vector<QuestionAnswer> myData;
 int chosenWord;
 ImportData *importDataObject;
 ImportProgress *importProgressObject;
};


#endif // GAMEWINDOW_H


