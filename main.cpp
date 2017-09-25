/*
#include <QSqlDatabase>
#include <QtWidgets>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>
*/
//#include "md_logintable.h"
#include "md_connectdatabase.h"

#if 1
//#include "vw_loginformadmin.h"
//#include "addressbook.h"
#include "ctr_login_admin.h"
#endif

//#include "vw_loginform.h"
#include "ctr_login.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Connect to database
    QSqlDatabase db;
    bool isConnect = connectDatabase(db, "localhost", "pnthoan", "root", "thoanpn1991");
    if(!isConnect) {
    	return app.exec();
    }

#if 0
    // Create table login
    QSqlQuery query;
    if(!createLoginTable(query)){
    	qDebug("Error cannot create LOGIN_TBL");
    	return app.exec();
    }
    ViewLogin loginForm;
    loginForm.show();    

    ModelLogin modelLogin;
    modelLogin.insertLoginTable("pn2", "thoanpn1991", "admin");
#endif

#if 0
    ControllerLogin controllerLogin;
    controllerLogin.Show();
    if(!controllerLogin.isSuccess())
    {
    	qDebug("Login failed!!");
    	return app.exec();
    }
#endif
    ControllerLoginAdmin controllerLoginAdmin;

#if 0
    ViewLoginAdmin viewLoginAdmin;
    viewLoginAdmin.show();
#endif

    
	// Close database connection
    db.close();
    return app.exec();
}
