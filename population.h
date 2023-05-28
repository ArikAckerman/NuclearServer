#ifndef POPULATION_H
#define POPULATION_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDataStream>
#include <string>
#include <vector>

class Population {
public:
    Population(double latitude, double longitude);
    ~Population();
    double getPopulation();

private:
    double latitude;
    double longitude;
    std::string url;
    std::vector<char> response;

    void sendRequest();
    double parseResponse();

    double population = 0; // Added default population
};

#endif
