#include <iostream>
#include "HeatSystem.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    HeatSystem sys;

    std::ofstream outfile;
    outfile.open("HeatSystem.txt");

    /*for (int j = 0; j < sys.getValue(1); j++)
    {
        sys.vector_3d[0][0][j] = sys.getValue(6);
    }*/

    //sys.calculate();

    sys.write(outfile);

    outfile.close();

    return 0;
}

/*
 * index for changeValue and getValue
int plate_length = 50;   // 1
int max_iter_time = 750; // 2
double alpha = 2.0;      // 3
double delta_x = 1.0;    // 4
double u_initial = 0;    // 5
double u_top = 100.0;    // 6
double u_left = 0.0;     // 7
double u_bottom = 0.0;   // 8
double u_right = 0.0;    // 9
 */