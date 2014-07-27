#include "myfilesyster.h"
#include "ui_myfilesyster.h"
//#include <QProcess>
#include <QFileSystemModel>
#include <QListView>
#include <QMessageBox>


MyFileSyster::MyFileSyster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyFileSyster)
{
    ui->setupUi(this);
    Git = new QProcess(this);
}

MyFileSyster::~MyFileSyster()
{
    delete ui;
}

void MyFileSyster::on_pushButton_Git_clicked()
{
    QString program = "/home/dambra/Programms/GIT_REPO/one_hand_bandit";

    QString argument = "git log --pretty=format:\"%h\"";

    Git->setWorkingDirectory(program);
    Git->setProgram("git");

    Git->start(argument);
    if(!Git->waitForStarted()) return;

    if(!Git->waitForFinished()) return;

    QString data = Git->readAllStandardOutput();
    QString error = Git->readAllStandardError();

    if(!error.isEmpty())
    QMessageBox::warning(this, "Warning", error);

    QStringList hash;
    if(!data.isEmpty())
    {
        hash = data.split("\n");
    }
    else
    {
        QMessageBox::information(this, "Info", "Fail!");
        return;
    }

    stringModel.setStringList(hash);
    ui->listView->setModel(&stringModel);
    ui->tableView->setModel(&stringModel);
}
