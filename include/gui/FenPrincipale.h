#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT


    public:
        FenPrincipale();

    private slots:
        void genererCode();

    private:
        QLineEdit *nom;
        QLineEdit *classeMere;
        QCheckBox *protections;
        QCheckBox *genererConstructeur;
        QCheckBox *genererDestructeur;
        QGroupBox *groupCommentaires;
        QLineEdit *auteur;
        QDateEdit *date;
        QTextEdit *role;
        QPushButton *generer;
        QPushButton *quitter;

};

#endif
