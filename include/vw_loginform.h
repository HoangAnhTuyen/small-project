#ifndef VIEW_LOGIN_H
#define VIEW_LOGIN_H

#include <QDialog>
//#include <QDate>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

class ViewLogin : public QDialog {
    Q_OBJECT

public:
	ViewLogin(QDialog *parent = 0);
	//void getCurrentAccount(QString &user, QString &pass, QString &role);
	QString getUsername();
	QString getPassword();
	bool status;  // login or cancel
public slots:
	void signInTask(); // When signInButton clicked
	void cancelTask(); // When cancelButton clicked

private:
	QPushButton *signInButton;
	QPushButton *cancelButton;

	QLineEdit *userNameLine;
	QLineEdit *passwordLine;

	QString username;
	QString password;
};

#endif