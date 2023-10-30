#include "csvwriter.h"

void writeLeastSquaresStraightLineToCSV(std::string path, LeastSquaresStraightLine lssl)
{
    std::cout << "\nWriting to: " << path << "\n";
    std::string delim = ",";
    std::string nl = "\n";
    std::ofstream csv;
    csv.open(path);

    csv << delim << "x" << delim << "delta x" << delim << "y" << delim << "delta y" << delim << "x^2" << delim << "xy\n";

    for(int i = 0; i < lssl.numDataPoints(); i++){
        csv << delim << lssl.xAt(i) << delim << lssl.deltaXAt(i) << delim << lssl.yAt(i) << delim << lssl.deltaYAt(i) << delim << lssl.xAt(i) * lssl.xAt(i) << delim << lssl.xAt(i) * lssl.yAt(i) << nl;
    }

    csv << nl << delim << "Sums:" << nl << delim << "x^2" << delim << "x" << delim << "y" << delim << "xy" << nl;
    csv << delim << lssl.getSumXSquared() << delim << lssl.getSumX() << delim << lssl.getSumY() << delim << lssl.getSumXY() << nl << nl;

    csv << delim << "A" << delim << "sigma A" << delim << "B" << delim << "sigma B" << delim << "Delta" << delim << "sigma Y" << nl;
    csv << delim << lssl.getA() << delim << lssl.getSigmaA() << delim << lssl.getB() << delim << lssl.getSigmaB() << delim << lssl.getDelta() << delim << lssl.getSigmaY() << nl;


    csv.close();

    std::cout << "Writing complete!\n";
}