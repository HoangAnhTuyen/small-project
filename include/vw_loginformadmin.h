#ifndef LOGIN_FORM_EDIT_H
#define LOGIN_FORM_EDIT_H

#include <QDialog>
#include <QMap>

#include "data_define.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class ViewLoginAdmin : public QDialog {
    Q_OBJECT

public:
	ViewLoginAdmin(QDialog *parent = 0);
    void vwRemoveContactTask(void);

    void changeNumAccount(int value);
    Mode getCurrentMode(void);
    void setLoginData(LoginData &logindata);
    void updateInterface(Mode mode);

signals:
    void submitContactSig(LoginData &logindata);
    void removeContactSig(LoginData &logindata);
    void findContactSig();
    void nextSig(LoginData &logindata);
    void previousSig(LoginData &logindata);

private slots:
    void vwAddContactSlot();
    void vwEditContactSlot();
    void vwSubmitContactSlot();
    void vwCancelSlot();
    void vwRemoveContactSlot();
    void vwFindContactSlot();
    void vwNextSlot();
    void vwPreviousSlot();

private:
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *nextButton;
    QPushButton *previousButton;

    QLineEdit *usernameLine;
    QLineEdit *passwordLine;
    QLineEdit *roleLine;
    QLabel *startDateLable;

    LoginData oldData;
    LoginData currentData;

    int numberAccount;
    Mode currentMode;
};
#endif