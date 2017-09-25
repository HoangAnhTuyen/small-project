#include <QDebug>
#include <QtWidgets>
#include "ctr_login_admin.h"

ControllerLoginAdmin::ControllerLoginAdmin()
{
	connect(&viewLoginAdmin, SIGNAL(submitContactSig(LoginData&)), this, SLOT(ctrlSubmitContactTask(LoginData&)));
	connect(&viewLoginAdmin, SIGNAL(removeContactSig(LoginData&)), this, SLOT(ctrlRemoveContactTask(LoginData&)));
	connect(&viewLoginAdmin, SIGNAL(findContactSig()), this, SLOT(ctrlFindContactTask()));
	connect(&viewLoginAdmin, SIGNAL(nextSig(LoginData&)), this, SLOT(ctrlNextTask(LoginData&)));
	connect(&viewLoginAdmin, SIGNAL(previousSig(LoginData&)), this, SLOT(ctrlPreviousTask(LoginData&)));
	viewLoginAdmin.show();
}

void ControllerLoginAdmin::ctrlSubmitContactTask(LoginData &logindata)
{
	/*
	if (name.isEmpty() || address.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a name and address."));
        return;
    }

    if (currentMode == AddingMode) {

        if (!contacts.contains(name)) {
            contacts.insert(name, address);
            QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" has been added to your address book.").arg(name));
        } else {
            QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("Sorry, \"%1\" is already in your address book.").arg(name));
        }
    } else if (currentMode == EditingMode) {

        if (oldName != name) {
            if (!contacts.contains(name)) {
                QMessageBox::information(this, tr("Edit Successful"),
                    tr("\"%1\" has been edited in your address book.").arg(oldName));
                contacts.remove(oldName);
                contacts.insert(name, address);
            } else {
                QMessageBox::information(this, tr("Edit Unsuccessful"),
                    tr("Sorry, \"%1\" is already in your address book.").arg(name));
            }
        } else if (oldAddress != address) {
            QMessageBox::information(this, tr("Edit Successful"),
                tr("\"%1\" has been edited in your address book.").arg(name));
            contacts[name] = address;
        }
    }
*/
	viewLoginAdmin.updateInterface(NavigationMode);
}

void ControllerLoginAdmin::ctrlRemoveContactTask(LoginData &logindata)
{
/*
	if (contacts.contains(name)) {

        int button = QMessageBox::question(this,
            tr("Confirm Remove"),
            tr("Are you sure you want to remove \"%1\"?").arg(name),
            QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::Yes) {

           // previous(); 
            viewLoginAdmin.vwRemoveContactTask();
            contacts.remove(name);

            QMessageBox::information(this, tr("Remove Successful"),
                tr("\"%1\" has been removed from your address book.").arg(name));
        }
    }

*/
	viewLoginAdmin.updateInterface(NavigationMode);
}

void ControllerLoginAdmin::ctrlFindContactTask()
{
/*
 	dialog->show();

    if (dialog->exec() == 1) {
        QString contactName = dialog->getFindText();

        if (contacts.contains(contactName)) {
            nameLine->setText(contactName);
            addressText->setText(contacts.value(contactName));

        } else {
            QMessageBox::information(this, tr("Contact Not Found"),
                tr("Sorry, \"%1\" is not in your address book.").arg(contactName));
            return;
        }
    }
*/
	viewLoginAdmin.updateInterface(NavigationMode);
}

void ControllerLoginAdmin::ctrlNextTask(LoginData &logindata)
{
	LoginData tmpData;
/*
    QString name = nameLine->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    if (i != contacts.end())
        i++;

    if (i == contacts.end())
        i = contacts.begin();
*/
	viewLoginAdmin.setLoginData(tmpData);
}

void ControllerLoginAdmin::ctrlPreviousTask(LoginData &logindata)
{
	LoginData tmpData;
/*
  QString name = nameLine->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    if (i == contacts.end()) {
        nameLine->clear();
        addressText->clear();
        return;
    }

    if (i == contacts.begin())
        i = contacts.end();

    i--;
*/
	viewLoginAdmin.setLoginData(tmpData);
}
