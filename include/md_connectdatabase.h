#include <QSqlDatabase>
#include <QtWidgets>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>


bool connectDatabase(QSqlDatabase &db, const QString &host, const QString &dbName, const QString &userName, const QString &passWord);
