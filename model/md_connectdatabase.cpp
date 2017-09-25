#include "md_connectdatabase.h"

bool connectDatabase(QSqlDatabase &db, const QString &host, const QString &dbName, const QString &userName, const QString &passWord) 
{
	// Connect to database
    db = QSqlDatabase::addDatabase("QMYSQL");// Load driver
    db.setHostName(host); 
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(passWord);
    bool ok = db.open();
    if( !ok ) {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
        return false;
    }
    qDebug( "Connected!" );
    return true;
}