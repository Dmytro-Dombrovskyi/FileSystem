#ifndef MYFILESYSTER_H
#define MYFILESYSTER_H
#include <QProcess>
#include <QDialog>
#include <QtGui>
namespace Ui {
class MyFileSyster;
}

class MyFileSyster : public QDialog
{
    Q_OBJECT

public:
    explicit MyFileSyster(QWidget *parent = 0);
    ~MyFileSyster();

private slots:
    void on_pushButton_Git_clicked();

private:
    Ui::MyFileSyster *ui;
    QProcess * Git;

    QStringListModel stringModel;
};

#endif // MYFILESYSTER_H
