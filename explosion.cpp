#include "explosion.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <tuple>

Explosion::Explosion(QString bomb, double population, int speedOfWind, QString directionOfWind)

{
    calculateEffects(bomb, population, speedOfWind, directionOfWind);
}

Explosion::~Explosion()
{
}

double Explosion::getFatalityCount()
{
    return m_fatalityCount;
}

double Explosion::getInjuryCount()
{
    return m_injuryCount;
}

double Explosion::getShelterCount()
{
    return m_shelterCount;
}

std::tuple<int, int, int, int, int, int, int> Explosion::calculateEffects(QString bomb, double population, int speedOfWind, QString directionOfWind)
{

    if(bomb=="10t"){
        double affectedPopulationPercentage = 0.006;
        double yield = 0.01;
        fireballRadius = 50;
        heavyBlastDamageRadius = 50;
        radiationRadius = 380;
        thermalRadiationRadius = 120;
        double dispersionFactor = 1.0;  // Default dispersion factor
        double fireSpreadFactor = 1.0;  // Default fire spread factor
        double structuralDamageFactor = 1.0;  // Default structural damage factor

        // Adjust dispersion factor based on wind speed
        if (speedOfWind >= 50 && speedOfWind < 100) {
            dispersionFactor = 0.8;
        } else if (speedOfWind >= 100) {
            dispersionFactor = 0.6;
        }

        // Adjust fire spread factor based on wind direction

        if (directionOfWind == "north") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "south") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "east") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "west") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "north-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "north-west") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-west") {
            fireSpreadFactor = 0.8;
        }

        // Adjust structural damage factor based on wind speed and direction

        if (speedOfWind >= 100 && (directionOfWind == "north" || directionOfWind == "south")) {
            structuralDamageFactor = 0.8;
        } else if (speedOfWind >= 100 && (directionOfWind == "east" || directionOfWind == "west")) {
            structuralDamageFactor = 0.6;
        } else if (speedOfWind >= 100 && (directionOfWind == "north-east" || directionOfWind == "north-west" ||
                                          directionOfWind == "south-east" || directionOfWind == "south-west")) {
            structuralDamageFactor = 0.7;
        }

        // Apply the wind influence to the explosion effects
        fireballRadius *= fireSpreadFactor;
        heavyBlastDamageRadius *= dispersionFactor;
        radiationRadius *= structuralDamageFactor;
        thermalRadiationRadius *= dispersionFactor;
        m_fatalityCount=0.025 * pow(yield, 0.4) * population;
        m_injuryCount=0.11 * pow(yield, 0.4) * population;
        m_shelterCount = (population * affectedPopulationPercentage) / 600;
    }
    else if(bomb=="10kt"){
        double affectedPopulationPercentage = 0.025;
        double yield=10.0;
        fireballRadius = 200;
        heavyBlastDamageRadius = 470;
        radiationRadius = 1520;
        thermalRadiationRadius = 1250;
        double dispersionFactor = 1.0;  // Default dispersion factor
        double fireSpreadFactor = 1.0;  // Default fire spread factor
        double structuralDamageFactor = 1.0;  // Default structural damage factor

        // Adjust dispersion factor based on wind speed
        if (speedOfWind >= 50 && speedOfWind < 100) {
            dispersionFactor = 0.8;
        } else if (speedOfWind >= 100) {
            dispersionFactor = 0.6;
        }

        // Adjust fire spread factor based on wind direction

        if (directionOfWind == "north") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "south") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "east") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "west") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "north-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "north-west") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-west") {
            fireSpreadFactor = 0.8;
        }

        // Adjust structural damage factor based on wind speed and direction

        if (speedOfWind >= 100 && (directionOfWind == "north" || directionOfWind == "south")) {
            structuralDamageFactor = 0.8;
        } else if (speedOfWind >= 100 && (directionOfWind == "east" || directionOfWind == "west")) {
            structuralDamageFactor = 0.6;
        } else if (speedOfWind >= 100 && (directionOfWind == "north-east" || directionOfWind == "north-west" ||
                                          directionOfWind == "south-east" || directionOfWind == "south-west")) {
            structuralDamageFactor = 0.7;
        }


        // Apply the wind influence to the explosion effects
        fireballRadius *= fireSpreadFactor;
        heavyBlastDamageRadius *= dispersionFactor;
        radiationRadius *= structuralDamageFactor;
        thermalRadiationRadius *= dispersionFactor;
        m_fatalityCount=0.025 * pow(yield, 0.4) * population;
        m_injuryCount=0.11 * pow(yield, 0.4) * population;
        m_shelterCount = (population * affectedPopulationPercentage) / 600;
    }
    else if(bomb=="10mt"){
        double affectedPopulationPercentage = 0.3;
        double yield=10000.0;
        fireballRadius = 3150;
        heavyBlastDamageRadius = 3370;
        radiationRadius = 4690;
        thermalRadiationRadius = 30700;
        double dispersionFactor = 1.0;  // Default dispersion factor
        double fireSpreadFactor = 1.0;  // Default fire spread factor
        double structuralDamageFactor = 1.0;  // Default structural damage factor

        // Adjust dispersion factor based on wind speed
        if (speedOfWind >= 50 && speedOfWind < 100) {
            dispersionFactor = 0.8;
        } else if (speedOfWind >= 100) {
            dispersionFactor = 0.6;
        }

        // Adjust fire spread factor based on wind direction

        if (directionOfWind == "north") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "south") {
            fireSpreadFactor = 0.9;
        } else if (directionOfWind == "east") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "west") {
            fireSpreadFactor = 0.7;
        } else if (directionOfWind == "north-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "north-west") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-east") {
            fireSpreadFactor = 0.8;
        } else if (directionOfWind == "south-west") {
            fireSpreadFactor = 0.8;
        }

        // Adjust structural damage factor based on wind speed and direction

        if (speedOfWind >= 100 && (directionOfWind == "north" || directionOfWind == "south")) {
            structuralDamageFactor = 0.8;
        } else if (speedOfWind >= 100 && (directionOfWind == "east" || directionOfWind == "west")) {
            structuralDamageFactor = 0.6;
        } else if (speedOfWind >= 100 && (directionOfWind == "north-east" || directionOfWind == "north-west" ||
                                          directionOfWind == "south-east" || directionOfWind == "south-west")) {
            structuralDamageFactor = 0.7;
        }


        // Apply the wind influence to the explosion effects
        fireballRadius *= fireSpreadFactor;
        heavyBlastDamageRadius *= dispersionFactor;
        radiationRadius *= structuralDamageFactor;
        thermalRadiationRadius *= dispersionFactor;
        m_fatalityCount=0.025 * pow(yield, 0.4) * population;
        m_injuryCount=0.11 * pow(yield, 0.4) * population;
        m_shelterCount = (population * affectedPopulationPercentage) / 600;
    }

    return std::make_tuple(fireballRadius, heavyBlastDamageRadius, radiationRadius, thermalRadiationRadius, m_fatalityCount, m_injuryCount, m_shelterCount);
}
