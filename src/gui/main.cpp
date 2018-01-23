#include <QApplication>
#include "FenPrincipale.h"

int main(int argc, char* argv[])
{
  // UTF-8 Encoding

    QApplication app(argc, argv);

    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();
}
