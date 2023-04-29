#include <QThread>
#include <QString>
#include <QProcess>
#include <QDebug>
#include "src/controlwindow.h"
#include <QTextBrowser>
class qt_node_thread:public QThread
{
    Q_OBJECT
public:
    QString* output = new QString();
    QString* nodeStartCommand = new QString();
    QString  NodeName;
    QString  NodePackage;
    QString  Output;
    QStringList Arguments;
    QTextBrowser* OutputRegion;//input output region parameter
    void start()
    //start process 
    {
        run();
    }
    qt_node_thread(QTextBrowser* browser)
    {
        this->OutputRegion = browser;
        // connect(this,SIGNAL(processStarted()),this,SLOT(readBashStandardOutput()));
    }
    void setNodeName(const QString str)
    {
        this->NodeName = str;
    }
    void setNodePackage(const QString str)
    {
        this->NodePackage = str;
    }
    void setArguments(const QStringList Arguments)
    {
        this->Arguments = Arguments;
    }

private:
    QProcess* myProcess;
    void runROSNode()
    {
        QProcess* process = new QProcess();
        
        this->myProcess = process;//To pass this process to the QProcess constructor

        QString command = QString("rosrun ")+this->NodePackage+QString(" ")+this->NodeName;
        
        process->start(command);
        this->OutputRegion->append(QString(this->NodeName)+QString(" ")+QString("is opened"));
        this->OutputRegion->append(QString(process->readAll()));

    }
protected:
    void run()
    {
        runROSNode();
    }
};