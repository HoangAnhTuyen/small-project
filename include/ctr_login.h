#ifndef CTR_LOGIN_H
#define CTR_LOGIN_H
/*
#include <QWidget>
#include <QMap>
*/
#include "vw_loginform.h"
#include "md_logintable.h"

class ControllerLogin
{
public:
	ControllerLogin() {
		loginSuccess = false;
		tryAgain = 3; 
	};

	void Show(void);
	bool isSuccess(void);

	void checkLogin(void);
private:
	ViewLogin viewLogin;
	ModelLogin modelLogin;

	bool loginSuccess;
	int tryAgain;
};

#endif