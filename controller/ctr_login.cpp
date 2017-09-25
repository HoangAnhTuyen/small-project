#include "ctr_login.h"

#include <QDebug>
#include <iostream>

void ControllerLogin::Show()
{
	/*
	* Check from database
	* Notify to user message box
	* Try again 3 times
	*/ 
	qDebug("ControllerLogin:Show()");
	while(!loginSuccess) {
		if(viewLogin.status == true) {
			viewLogin.exec();	
		}
		else {
			break;
		}

	
		checkLogin();

		tryAgain--;
		if(tryAgain == 0) {
			break;
		}
	}
}

bool ControllerLogin::isSuccess()
{
	return loginSuccess;
}

void ControllerLogin::checkLogin()
{
	QString username = viewLogin.getUsername();
	if(!modelLogin.selectLoginTable(username)){
		return;
	}
	
/*
	qDebug() << modelLogin.getUsername();
	qDebug() << modelLogin.getPassword();
	qDebug() << viewLogin.getPassword();
	qDebug() << viewLogin.getUsername();
*/	
	if(viewLogin.getUsername() == modelLogin.getUsername() && viewLogin.getPassword() == modelLogin.getPassword()) {
		loginSuccess = true;
	}
}