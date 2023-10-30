#include "leastsquaresstraightline.h"

LeastSquaresStraightLine::LeastSquaresStraightLine() : A(0), B(0), delta(0), sumXSquared(0), sumX(0), sumY(0), sumXY(0) , sigmaA(0), sigmaB(), sigmaY(0) {}

int LeastSquaresStraightLine::numDataPoints()
{
    return data.size();
}

double LeastSquaresStraightLine::xAt(int i)
{
    return data[i].x;
}

double LeastSquaresStraightLine::yAt(int i)
{
    return data[i].y;
}

double LeastSquaresStraightLine::deltaXAt(int i)
{
    return data[i].deltaX;
}

double LeastSquaresStraightLine::deltaYAt(int i)
{
    return data[i].deltaY;
}

DataPoint LeastSquaresStraightLine::dataAt(int i)
{
    return data[i];
}

double LeastSquaresStraightLine::getSumXSquared()
{
    return sumXSquared;
}

double LeastSquaresStraightLine::getSumX()
{
    return sumX;
}

double LeastSquaresStraightLine::getSumY()
{
    return sumY;
}

double LeastSquaresStraightLine::getSumXY()
{
    return sumXY;
}

double LeastSquaresStraightLine::getA()
{
    return A;
}

double LeastSquaresStraightLine::getB()
{
    return B;
}

double LeastSquaresStraightLine::getDelta()
{
    return delta;
}

double LeastSquaresStraightLine::getSigmaY()
{
    return sigmaY;
}

double LeastSquaresStraightLine::getSigmaA()
{
    return sigmaA;
}

double LeastSquaresStraightLine::getSigmaB()
{
    return sigmaB;
}

void LeastSquaresStraightLine::addData(DataPoint dp)
{
    data.push_back(dp);
    sumXSquared += dp.x * dp.x;
    sumX += dp.x;
    sumY += dp.y;
    sumXY += dp.x * dp.y;
}

void LeastSquaresStraightLine::addData(double x, double y, double deltaX, double deltaY)
{
    DataPoint dp;
    dp.x = x;
    dp.y = y;
    dp.deltaX = deltaX;
    dp.deltaY = deltaY;
    addData(dp);
}

void LeastSquaresStraightLine::calculateLine()
{
    delta = (double)numDataPoints() * sumXSquared - (sumX * sumX);
    A = ((sumXSquared * sumY) - (sumX * sumXY)) / delta;
    B = (((double)numDataPoints() * sumXY) - (sumX * sumY)) / delta;

    calculateSigmas();
}

std::string LeastSquaresStraightLine::toString()
{
    return "y = A + Bx\n  = " + std::to_string(A) + " + " + std::to_string(B) + "x";
}

void LeastSquaresStraightLine::calculateSigmas()
{
    sigmaY = 0.0;
    double term;

    for(int i = 0; i < numDataPoints(); i++){
        term = yAt(i) - getA() - getB() * xAt(i);
        term *= term;
        sigmaY += term;
    }

    sigmaY = sqrt(sigmaY / ((double)numDataPoints() - 2.0));

    sigmaA = sigmaY * sqrt(sumXSquared / delta);
    sigmaB = sigmaY * sqrt((double)numDataPoints() / delta);
}
