#ifndef CTR_LOGIN_ADMIN_H
#define CTR_LOGIN_ADMIN_H

#include <QObject>

#include "vw_loginformadmin.h"
#include "md_loginfinddialog.h"

class ControllerLoginAdmin : public QObject
{
	Q_OBJECT
public:
	ControllerLoginAdmin();

private:
    //LoginData loginData;
    ViewLoginAdmin viewLoginAdmin;
    FindDialog dialog;

private slots:
    void ctrlSubmitContactTask(LoginData &logindata);
    void ctrlRemoveContactTask(LoginData &logindata);
    void ctrlFindContactTask();
    void ctrlNextTask(LoginData &logindata);
    void ctrlPreviousTask(LoginData &logindata);
};

#endif