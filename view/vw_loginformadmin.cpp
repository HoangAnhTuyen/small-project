#include <QtWidgets>
#include <QDebug>
#include <QSpacerItem>

#include "vw_loginformadmin.h"

ViewLoginAdmin::ViewLoginAdmin(QDialog *parent) 
	: QDialog(parent)
{
// Initialize numberAccount
	numberAccount = 0;
//View
	QLabel *usernameLable = new QLabel(tr("Username"));
    usernameLine = new QLineEdit;
    usernameLine->setReadOnly(true);

    QLabel *passwordLable = new QLabel(tr("Password"));
    passwordLine = new QLineEdit;
    passwordLine->setReadOnly(true);

    QLabel *roleLable = new QLabel(tr("Role"));
    roleLine = new QLineEdit;
    roleLine->setReadOnly(true);

    QLabel *dateLable = new QLabel(tr("Date begin"));
    startDateLable = new QLabel();
	//startDateLable->setFrameStyle(QFrame::Panel | QFrame::Sunken);

// Action
	addButton = new QPushButton(tr("&Add"));

    editButton = new QPushButton(tr("&Edit"));
    editButton->setEnabled(false);

    removeButton = new QPushButton(tr("&Remove"));
    removeButton->setEnabled(false);

    findButton = new QPushButton(tr("&Find"));
    findButton->setEnabled(false);

    submitButton = new QPushButton(tr("&Submit"));
    submitButton->hide();

    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->hide();

    nextButton = new QPushButton(tr("&Next"));
    nextButton->setEnabled(false);

    previousButton = new QPushButton(tr("&Previous"));
    previousButton->setEnabled(false);

// Connection
    connect(addButton, SIGNAL(clicked()), this, SLOT(vwAddContactSlot()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(vwSubmitContactSlot()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(vwEditContactSlot()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(vwCancelSlot()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(vwRemoveContactSlot()));
    connect(findButton, SIGNAL(clicked()), this, SLOT(vwFindContactSlot()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(vwNextSlot()));
    connect(previousButton, SIGNAL(clicked()), this, SLOT(vwPreviousSlot()));
//Layout
    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton);
    buttonLayout1->addWidget(editButton);
    buttonLayout1->addWidget(removeButton);
    buttonLayout1->addWidget(findButton);
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addStretch();

    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(previousButton);
    buttonLayout2->addWidget(nextButton);

    QGridLayout *gridLayout = new QGridLayout;
    
    gridLayout->addWidget(usernameLable, 0, 0);
    gridLayout->addWidget(usernameLine, 0, 1);
    gridLayout->addWidget(passwordLable, 1, 0, Qt::AlignTop);
    gridLayout->addWidget(passwordLine, 1, 1);
    gridLayout->addWidget(roleLable, 2, 0);
    gridLayout->addWidget(roleLine, 2, 1);
    gridLayout->addWidget(dateLable, 3, 0);
    gridLayout->addWidget(startDateLable, 3, 1);
    gridLayout->addLayout(buttonLayout2, 4, 1);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(gridLayout);
	mainLayout->addLayout(buttonLayout1);

    setLayout(mainLayout);
    setWindowTitle(tr("Account Information"));
}

void ViewLoginAdmin::changeNumAccount(int value)
{
	this->numberAccount = value;
}

Mode ViewLoginAdmin::getCurrentMode(void)
{
	return currentMode;
}

void ViewLoginAdmin::setLoginData(LoginData &logindata)
{
	usernameLine->setText(logindata.username);
    passwordLine->setText(logindata.password);
    roleLine->setText(logindata.role);
	startDateLable->setText(logindata.dateStart);
}

void ViewLoginAdmin::vwAddContactSlot()
{
	oldData.username = usernameLine->text();
	oldData.password = passwordLine->text();
	oldData.role = roleLine->text();
	oldData.dateStart = startDateLable->text();

    usernameLine->clear();
    passwordLine->clear();
    roleLine->clear();
    startDateLable->setText("");

    updateInterface(AddingMode);
}

void ViewLoginAdmin::vwEditContactSlot() 
{
	oldData.username = usernameLine->text();
	oldData.password = passwordLine->text();
	oldData.role = roleLine->text();
	oldData.dateStart = startDateLable->text();

	updateInterface(EditingMode);
}

void ViewLoginAdmin::vwSubmitContactSlot()
{
	// Get current data
	currentData.username = usernameLine->text();
	currentData.password = passwordLine->text();
	currentData.role = roleLine->text();
	currentData.dateStart = startDateLable->text();

	emit submitContactSig(currentData);
}

void ViewLoginAdmin::vwCancelSlot()
{
	setLoginData(oldData);
	updateInterface(NavigationMode);
}

void ViewLoginAdmin::vwRemoveContactSlot()
{
	// Get current data
	currentData.username = usernameLine->text();
	currentData.password = passwordLine->text();
	currentData.role = roleLine->text();
	currentData.dateStart = startDateLable->text();

	emit removeContactSig(currentData);
}

void ViewLoginAdmin::vwFindContactSlot()
{
	emit findContactSig();
}

void ViewLoginAdmin::vwNextSlot()
{
	// Get current data
	currentData.username = usernameLine->text();
	currentData.password = passwordLine->text();
	currentData.role = roleLine->text();
	currentData.dateStart = startDateLable->text();

	emit nextSig(currentData);
}

void ViewLoginAdmin::vwPreviousSlot()
{
	// Get current data
	currentData.username = usernameLine->text();
	currentData.password = passwordLine->text();
	currentData.role = roleLine->text();
	currentData.dateStart = startDateLable->text();

	emit previousSig(currentData);
}

// Update task
void ViewLoginAdmin::vwRemoveContactTask()
{
	vwPreviousSlot();
}


void ViewLoginAdmin::updateInterface(Mode mode)
{
    currentMode = mode;

    switch (currentMode) {
    case AddingMode:
    case EditingMode:
        usernameLine->setReadOnly(false);
        usernameLine->setFocus(Qt::OtherFocusReason);
        passwordLine->setReadOnly(false);
        passwordLine->setFocus(Qt::OtherFocusReason);
        roleLine->setReadOnly(false);
        roleLine->setFocus(Qt::OtherFocusReason);

        addButton->hide();
        editButton->hide();
        removeButton->hide();
        findButton->hide();

        nextButton->setEnabled(false);
        previousButton->setEnabled(false);

        submitButton->show();
        cancelButton->show();
        break;

    case NavigationMode:
        if (this->numberAccount == 0) {
            usernameLine->clear();
            passwordLine->clear();
            roleLine->clear();
            startDateLable->setText("");
        }
       
        editButton->setEnabled(this->numberAccount >= 1);
        removeButton->setEnabled(this->numberAccount >= 1);
        findButton->setEnabled(this->numberAccount > 2);
        nextButton->setEnabled(this->numberAccount > 1);
        previousButton->setEnabled(this->numberAccount > 1);

    	usernameLine->setReadOnly(true);
        passwordLine->setReadOnly(true);
        roleLine->setReadOnly(true);

    	addButton->show();
    	addButton->setEnabled(true);

        editButton->show();
        removeButton->show();
        findButton->show();

        submitButton->hide();
        cancelButton->hide();

        break;
    }
}


