#include "md_logintable.h"

bool ModelLogin::insertLoginTable(const QString &user, const QString &pass, const QString &role) 
{
	bool result = true;
	QSqlQuery query;
	query.prepare("INSERT INTO LOGIN_TBL (LOGIN_USER, LOGIN_PASS, LOGIN_ROLE, LOGIN_START) VALUES (?, ?, ?, NOW())");
	query.addBindValue(user);
	query.addBindValue(pass);
	query.addBindValue(role);
	result = query.exec();
	return result;
}

bool ModelLogin::createLoginTable()
{
	bool result = true;
	QSqlQuery query;
	QString isLoginTbl = "select * from LOGIN_TBL";
	if(!query.exec(isLoginTbl)) {
		result = query.exec("create table LOGIN_TBL(LOGIN_USER VARCHAR(100) NOT NULL, LOGIN_PASS VARCHAR(100) NOT NULL, LOGIN_ROLE VARCHAR(100) NOT NULL, LOGIN_START DATE not null);");
		// Add admin 
		if (result) {
			insertLoginTable("pn", "thoanpn1991", "admin");	
		}
	}
    
    return result;
}

bool ModelLogin::deleteLoginTable()
{
	bool result = true;

	return result;
}

bool ModelLogin::updateLoginTable() 
{
	bool result = true;
	
	return result;
}

bool ModelLogin::selectLoginTable(const QString &user)
{
	bool result = false;
	QSqlQuery query;
	query.prepare("select * from LOGIN_TBL where LOGIN_USER = ?");
	query.addBindValue(user);
	query.exec();

	if(query.size() > 0) {

#if 01
	QSqlRecord rec = query.record();
	
    while (query.next()) {
        this->username = query.value(rec.indexOf("LOGIN_USER")).toString();
        this->password = query.value(rec.indexOf("LOGIN_PASS")).toString();
		this->role = query.value(rec.indexOf("LOGIN_ROLE")).toString();
		this->dateStart = query.value(rec.indexOf("LOGIN_START")).toString();
    }

	qDebug() << "-----------------------";
	qDebug() << this->username;
	qDebug() << this->password;
	qDebug() << this->role;
	qDebug() << this->dateStart;
	qDebug() << "-----------------------";

#endif
		result = true;
	}

	return result;
}

QString ModelLogin::getRole(void)
{
	return this->role;
}

QString ModelLogin::getDate(void)
{
	return this->dateStart;
}

QString ModelLogin::getUsername(void)
{
	return this->username;
}

QString ModelLogin::getPassword(void)
{
	return this->password;
}