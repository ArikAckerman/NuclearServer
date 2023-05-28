#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "server.h"
#include <string>
#include <vector>
#include <tuple>
//explosion class
class Explosion {
public:
    Explosion(QString bomb, double population, int speedOfWind, QString directionOfWind);
    ~Explosion();

    double getFatalityCount();
    double getInjuryCount();
    double getShelterCount();
    QString bomb;
    QString weatherCondition;
    QString directionOfWind;
    int speedOfWind;
    int fireballRadius;
    int heavyBlastDamageRadius;
    int radiationRadius;
    int thermalRadiationRadius;
    std::tuple<int, int, int, int, int, int, int> calculateEffects(QString bomb, double population, int speedOfWind, QString directionOfWind);

private:
    Server *server;

    double m_fatalityCount;
    double m_injuryCount;
    double m_shelterCount;

};

#endif
