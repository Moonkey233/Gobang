#ifndef JOINROOMDIALOG_H
#define JOINROOMDIALOG_H

#include <QDialog>

namespace Ui {
class JoinRoomDialog;
}

class JoinRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JoinRoomDialog(QWidget *parent = nullptr);
    ~JoinRoomDialog();

private:
    Ui::JoinRoomDialog *ui;

private:
    void onJoinBtnClicked();
    void onCancelBtnClicked();

Q_SIGNALS:
    void sigJoinRoom(const QString &roomId);

};

#endif // JOINROOMDIALOG_H
