#include "login.h"
#include "ui_login.h"
#include "transactions.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}



void Login::on_LoginButton_clicked()
{
    transwindow = new transactions();
    transwindow->setWelcomeMessage(ui->NameBox->text());
    transwindow->setAccountNumber(ui->AccountnumBox->text());
    transwindow->show();
    this->close();
}

