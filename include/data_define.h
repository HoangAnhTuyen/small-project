#ifndef DATA_DEF_H
#define DATA_DEF_H

#include <QString>

typedef struct loginData_t
{
	QString username;
	QString password;
	QString role;
	QString dateStart;
} LoginData;

enum Mode { NavigationMode, AddingMode, EditingMode };

#endif