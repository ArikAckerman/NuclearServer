#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDataStream>

class Server: public QTcpServer{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;
    double latitude;
    double longitude;
    QString bomb;
    QString weatherCondition;
    QString directionOfWind = "null";
    int speedOfWind = 0;
private:
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    void sendToClient(QString str);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
