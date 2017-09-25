#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QSqlDatabase>
#include <QtWidgets>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>
#include <QString>
#include <QDate>

class ModelLogin 
{
public:
	bool insertLoginTable(const QString &user, const QString &pass, const QString &role);
	//bool insertLoginTable(QSqlQuery &query, const QString &user, const QString &pass, const QString &role);

	bool createLoginTable();

	bool deleteLoginTable();

	bool updateLoginTable();

	bool selectLoginTable(const QString &user);

	QString getUsername(void);
	QString getPassword(void);
	QString getRole(void);
	QString getDate(void);

private:
	QString username;
	QString password;
	QString role;
	QString dateStart;
};

#endif