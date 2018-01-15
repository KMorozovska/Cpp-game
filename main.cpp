#include <QApplication>
#include <QPushButton>
#include "window.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Window window;
 window.setFixedSize(300, 400);
 window.setWindowTitle("Supermemo");

 window.show();

//QPushButton button ("Hello world !");
//button.show();

 return app.exec();
}
