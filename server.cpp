#include "server.h"
#include "population.h"
#include "explosion.h"
#include <tuple>
#include <QChar>
//Server class implementation
Server::Server(){
    if(this -> listen(QHostAddress::Any, 4040)){
        qDebug()<<"start";
    }
    else{
        qDebug()<<"error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug()<<"client connected"<<socketDescriptor;
}

void Server::slotReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_15);
    if(in.status()==QDataStream::Ok){
        qDebug()<<"read";
        QString str;
        in >> str;
        qDebug()<<str;

        QStringList parts = str.split('q');

        latitude = parts[0].toDouble();
        longitude = parts[1].toDouble();
        bomb = parts[2];
        weatherCondition = parts[3];
        speedOfWind =  parts.size() > 4 ? parts[4].toInt() : 0;
        directionOfWind = parts.size() > 5 ? parts[5] : QString();
        qDebug()<<directionOfWind;
        qDebug()<<speedOfWind;
        Population population(latitude, longitude);
        Explosion effects(bomb, population.getPopulation(), speedOfWind, directionOfWind);
        auto result = effects.calculateEffects(bomb, population.getPopulation(), speedOfWind, directionOfWind);
        QVariant fireballRadius=std::get<0>(result);
        QVariant heavyBlastDamageRadius=std::get<1>(result);
        QVariant radiationRadius=std::get<2>(result);
        QVariant thermalRadiationRadius=std::get<3>(result);
        QVariant m_fatalityCount=std::get<4>(result);
        QVariant m_injuryCount=std::get<5>(result);
        QVariant m_shelterCount=std::get<6>(result);
        QString data = QString("%1 %2 %3 %4 %5 %6 %7")
                          .arg(fireballRadius.toInt())
                          .arg(heavyBlastDamageRadius.toInt())
                          .arg(radiationRadius.toInt())
                          .arg(thermalRadiationRadius.toInt())
                          .arg(m_fatalityCount.toInt())
                          .arg(m_injuryCount.toInt())
                          .arg(m_shelterCount.toInt());
        sendToClient(data);
        qDebug()<<data;
    }else{
        qDebug()<<"QDataStream error";
    }

}

void Server::sendToClient(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    socket = (QTcpSocket*)sender();;
    out.setVersion(QDataStream::Qt_5_15);
    out << str;
    socket->write(Data);
}

