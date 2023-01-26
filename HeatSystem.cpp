//
// Created by asaggu on 12/4/2022.
//

#include <iostream>
#include "HeatSystem.h"

HeatSystem::HeatSystem()
{
    // initialize elements
    for(int k=0;k<max_iter_time-1;k++)
    {
        std::vector<std::vector<double>> v2d;
        for(int i=0;i<plate_length;i++)
        {
            std::vector<double> v1d;
            for(int j=0;j<plate_length;j++)
            {
                v1d.push_back(j);
            }
            v2d.push_back(v1d);
            v1d.clear();
            v1d.shrink_to_fit();
        }
        vector_3d.push_back(v2d);
        //v2d.clear();
        //v2d.shrink_to_fit();
    }
}

HeatSystem::~HeatSystem()
{
    std::cout << "\nDestructor called." << std::endl;
}


void HeatSystem::calculate()
{
    for (int k = 1; k < max_iter_time-1; k++)
    {
        for (int i = 1; i < plate_length-1; i++)
        {
            for (int j = 1; j < plate_length-1; j++)
            {
                vector_3d[k+1][i][j] = gamma * (vector_3d[k][i+1][j] + vector_3d[k][i-1][j] + vector_3d[k][i][j+1] + vector_3d[k][i][j-1] - 4*vector_3d[k][i][j]) + vector_3d[k][i][j];
            }
        }

    }
}

void HeatSystem::write(std::ofstream &outfile)
{
    // print the start and '#' so python ignores line
    outfile << "# Start @ 0" << std::endl;

    for (int k = 0; k < max_iter_time; k++)
    {
        for (int i = 0; i < plate_length; i++)
        {
            for (int j = 0; j < plate_length; j++)
            {
                outfile << vector_3d[k][i][j] << " ";
            }
            //time_elapsed += dt;
            //total_runs++;
            //outfile << "#" << time_elapsed << std::endl;
            outfile << "\n#\n";
        }

    }

}

void HeatSystem::update()
{

}


void HeatSystem::changeValue(double value, int c)
{
    switch (c)
    {
        case 1:
        {
            plate_length = (int)value;
            break;
        }
        case 2:
        {
            max_iter_time = (int)value;
            break;
        }
        case 3:
        {
            alpha = value;
            break;
        }
        case 4:
        {
            delta_x = value;
            break;
        }
        case 5:
        {
            u_initial   = value;
            break;
        }
        case 6:
        {
            u_top   = value;
            break;
        }
        case 7:
        {
            u_left   = value;
            break;
        }
        case 8:
        {
            u_bottom   = value;
            break;
        }
        case 9:
        {
            u_right   = value;
            break;
        }
        default:
        {std::cout << "Default Error, Goodbye! \n";break;}
    }
}

double HeatSystem::getValue(int c)
{
    switch (c)
    {
        case 1:
        {
            return plate_length;
            break;
        }
        case 2:
        {
            return max_iter_time;
            break;
        }
        case 3:
        {
            return alpha;
            break;
        }
        case 4:
        {
            return delta_x;
            break;
        }
        case 5:
        {
            return u_initial;
            break;
        }
        case 6:
        {
            return u_top;
            break;
        }
        case 7:
        {
            return u_left;
            break;
        }
        case 8:
        {
            return u_bottom;
            break;
        }
        case 9:
        {
            return u_right;
            break;
        }
        default:
        {std::cout << "Default Error, Goodbye! \n"; return 0;}
    }
}
