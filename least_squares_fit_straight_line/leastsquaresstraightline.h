#ifndef LEAST_SQUARES_STRAIGHT_LINE_H
#define LEAST_SQUARES_STRAIGHT_LINE_H

#include <vector>
#include <string>
#include <cmath>
#include "datapoint.h"

class LeastSquaresStraightLine{

    private:
    double A;
    double B;
    double delta;
    double sumXSquared;
    double sumX;
    double sumY;
    double sumXY;
    double sigmaA;
    double sigmaB;
    double sigmaY;
    std::vector<DataPoint> data;

    public:
    LeastSquaresStraightLine();

    public:
    int numDataPoints();
    double xAt(int i);
    double yAt(int i);
    double deltaXAt(int i);
    double deltaYAt(int i);
    DataPoint dataAt(int i);
    double getSumXSquared();
    double getSumX();
    double getSumY();
    double getSumXY();
    // [(sum(X^2))(sumY) - (sumX)(sumXY)] / Delta
    double getA();
    // [N(sumXY) - (sumX)(sumY)] / Delta
    double getB();
    // N(sum(x^2)) - (sumX)^2
    double getDelta();
    double getSigmaY();
    double getSigmaA();
    double getSigmaB();   

    void addData(DataPoint dp);
    void addData(double x, double y, double deltaX = 0, double deltaY = 0);

    void calculateLine();
    std::string toString();

    private:
    void calculateSigmas();

};

#endif // LEAST_SQUARES_STRAIGHT_LINE_H 
