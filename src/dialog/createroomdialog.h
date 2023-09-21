#ifndef CREATEROOMDIALOG_H
#define CREATEROOMDIALOG_H

#include <QDialog>

namespace Ui {
class CreateRoomDialog;
}

class CreateRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRoomDialog(const QString &userName, QWidget *parent = nullptr);
    ~CreateRoomDialog();

private:
    Ui::CreateRoomDialog *ui;

private:
    void onCreateBtnClicked();
    void onCancelBtnClicked();

Q_SIGNALS:
    void sigCreateRoom(const QString &roomName, const QString &chessType, const QString &isPublic);

};

#endif // CREATEROOMDIALOG_H
