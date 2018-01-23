#ifndef HEADER_FENCODEGENERE
#define HEADER_FENCODEGENERE

#include <QtWidgets>

class FenCodeGenere : public QDialog
{
	public:
		FenCodeGenere(QString &code, QWidget *parent);

	private:
        QTextEdit *codeGenere;
        QPushButton *fermer;
};


#endif
