#include "transactions.h"
#include "ui_transactions.h"
#include "login.h"
#include <sstream>

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
}
void transactions::setWelcomeMessage (QString name)
{
    ui->LabelWel->setText("Welcome "+name);
}

void transactions::setAccountNumber(QString acc){
    ui->LabelAccNum->setText("Account Number: "+acc);
}

transactions::~transactions()
{
    delete ui;
}

void transactions::on_ClearButton_clicked()
{
    ui->AmountLineEdit->setText("");
}


void transactions::on_DepositButton_clicked()
{
    QString amount = ui->AmountLineEdit->text();
    balance += amount.toDouble();
    ui->LabelCurrBal->setText("Current Balance: "+QString::number(balance));
    history +="+";
    history += amount;
    history += "\n";
    ui->StatusLabel->setText("Deposit Completed");
}


void transactions::on_HideHistoryButton_clicked()
{
    ui->HistoryLabel->setText("");
}


void transactions::on_WithdrawButton_clicked()
{
    QString amount = ui->AmountLineEdit->text();

    WithAmount = ui->AmountLineEdit->text();

    if (balance<WithAmount.toDouble()){
        ui->StatusLabel->setText("Not Enough Funds");

    }else {
        balance -= amount.toDouble();
        ui->LabelCurrBal->setText("Current Balance: "+QString::number(balance));
        history +="-";
        history += amount;
        history += "\n";
        ui->StatusLabel->setText("Withdraw Completed");
    }
}


void transactions::on_ShowHistoryButton_clicked()
{
    ui->HistoryLabel->setText(history);
}


void transactions::on_BackButton_clicked()
{
    loginwind = new Login();
    loginwind->show();
    this-> close();
}

