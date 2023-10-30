#include <iostream>
#include <iomanip>
#include <string>
#include "leastsquaresstraightline.h"
#include "csvwriter.h"

const std::string usageMessage = "Provide an output .csv file, the number of points, N, you'd like to input, and N space-seperated lines containing x, y, error in x, and error in y.\n\nOr, type \"EXIT\" to quit.";

int main(int argc, char *argv[]){

    std::cout << usageMessage << '\n';

    int numPoints;
    double x, y, dx, dy;
    std::string outputPath;
    LeastSquaresStraightLine lssl;

    std::cin >> outputPath;

    if(outputPath == "EXIT"){
        std::cout << "Exiting...";
        return 0;
    }

    std::cin >> numPoints;

    while(numPoints--){
        std::cin >> x >> y >> dx >> dy;
        lssl.addData(x, y, dx, dy);
    }

    lssl.calculateLine();

    std::cout << std::setprecision(10) << "\ny = A + Bx\ny = " << lssl.getA() << " + " << lssl.getB() << "x\n";
    std::cout << "\nError: \nA: " << lssl.getSigmaA() << "\nB: " << lssl.getSigmaB() << "\ny: " << lssl.getSigmaY();

    writeLeastSquaresStraightLineToCSV(outputPath, lssl);
}