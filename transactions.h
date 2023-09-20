#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>

class Login;

namespace Ui {
class transactions;
}

class transactions : public QDialog
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    void setWelcomeMessage (QString name);
    void setAccountNumber (QString acc);
    ~transactions();
private slots:
    void on_ClearButton_clicked();

    void on_DepositButton_clicked();

    void on_HideHistoryButton_clicked();

    void on_WithdrawButton_clicked();

    void on_ShowHistoryButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::transactions *ui;
    Login*loginwind;
    double balance = 0;
    QString history = "";
    QString WithAmount;
};

#endif // TRANSACTIONS_H

