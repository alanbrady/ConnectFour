#ifndef GAGENERATOR_H
#define GAGENERATOR_H

#include "connectfourgame.h"
#include "gaplayer.h"

#define GEN_SIZE 100

class GAGenerator
{
public:
    GAGenerator();

    void start();
private:
    ConnectFourGame m_connectFour;
    GAPlayer population[GEN_SIZE];
    int m_generation;

    void generatesInitialPopulation();
    void doCrossover(GAPlayer* playerOne, GAPlayer* playerTwo);
    void doMutation(GAPlayer* player);
};

#endif // GAGENERATOR_H
