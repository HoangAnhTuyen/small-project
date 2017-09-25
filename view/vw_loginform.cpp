#include <QtWidgets>
#include <QDebug>
#include <QSpacerItem>
#include "vw_loginform.h"

ViewLogin::ViewLogin(QDialog *parent) : QDialog(parent)
{
    QLabel *userNameLabel = new QLabel(tr("User name:"));
    userNameLine = new QLineEdit;

    QLabel *passwordLabel = new QLabel(tr("Password:"));
    passwordLine = new QLineEdit;
    passwordLine->setEchoMode(QLineEdit::Password);
    passwordLine->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    signInButton = new QPushButton(tr("&Sign In"));
    cancelButton = new QPushButton(tr("&Cancel"));

    connect(signInButton, SIGNAL(clicked()), this, SLOT(signInTask()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelTask()));

    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    buttonLayout1->addStretch(1); 
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addWidget(signInButton);
    
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(userNameLabel, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(userNameLine, 0, 1);
    mainLayout->addWidget(passwordLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(passwordLine, 1, 1);
    mainLayout->addLayout(buttonLayout1, 2, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Login"));

    // status login or cancel 
    status = true;
}

void ViewLogin::signInTask()
{
	qDebug("signInTask function");
    this->username = userNameLine->text();
    this->password = passwordLine->text();
    this->close();
}

void ViewLogin::cancelTask()
{
	qDebug("cancelTask function");
    this->status = false;
	this->close();
}

QString ViewLogin::getUsername()
{
    return this->username;
}

QString ViewLogin::getPassword()
{
    return this->password;
}