#include <QApplication>
#include <QPushButton>
#include "startwindow.h"

/**
 * Wywołanie okna początkowego.
 */

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 StartWindow window;
 window.setFixedSize(300, 400);
 window.setWindowTitle("Supermemo");

 window.show();

 return app.exec();
}
