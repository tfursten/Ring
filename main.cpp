#include <iostream>
#include <fstream>
#include "xorshift64.h"
#include "ring.h"

using namespace std;
typedef pair<int,int> xyCoord;

inline int xy2i(int x, int y, int mx, int my) {
	return x*my+y;
}


int wrap_around(int x, int w) {
	return ((x % w) + w) % w;
}
int main()
{
    ofstream myfile;
    myfile.open("test.txt");
    xorshift64 myrand;
    myrand.seed(2348585);
    Ring ring;
    double sigma = 2.0;

    ring.initialize(2,0);
    ring.printTables();
    for(int iii=0; iii<100000; iii++)
    {
        xyCoord dXY = ring.disperse(myrand.get_uint64());
        double dX = 10+dXY.first;
        double dY = 10+dXY.second;
        int newX = wrap_around(static_cast<int>(dX), 100);
        int newY = wrap_around(static_cast<int>(dY), 100);
        myfile << newX << "\t" << newY << endl;
    }
    myfile.close();

    return 0;
}
