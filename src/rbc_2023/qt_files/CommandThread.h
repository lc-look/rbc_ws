#include <QThread>
#include <QString>
#include <QProcess>
#include <QDebug>
#include "src/controlwindow.h"
#include <QTextBrowser>
#include <QString>
#include <QProcess>
#include <QDebug>
#include "src/controlwindow.h"
#include <QTextBrowser>

class CommandThread : public QThread
{
    Q_OBJECT
public:

    QString command;

    CommandThread(QString command)
    {
        this->command = command;
    }
    void execute()
    {
        QProcess *process = new QProcess();
        process->setReadChannelMode(process->MergedChannels);
        process->start(QString("bash"));
        process->waitForStarted();
        char* ch;
        QByteArray ba = this->command.toLatin1();
        ch = ba.data();
        process->write("ls\n");
        
        this->output = process->readAll();
        
        qDebug() << "结束节点命令完成"<<endl;
        qDebug() << QString::fromLocal8Bit(process->readAllStandardOutput())<<endl;
        qDebug() << process->readAll()<<endl;
    }
    QString getOutput()
    {
        return QString(this->output);
    }
private:
    QByteArray output;
};