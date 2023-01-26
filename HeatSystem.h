//
// Created by asaggu on 12/4/2022.
//

#ifndef HEATEQU2D_HEATSYSTEM_H
#define HEATEQU2D_HEATSYSTEM_H

#include <cmath>
#include <fstream>
#include <vector>

class HeatSystem
        {
        private:
            int plate_length = 5;   // 1
            int max_iter_time = 10; // 2
            double alpha = 2.0;      // 3
            double delta_x = 1.0;    // 4
            double u_initial = 0;    // 5
            double u_top = 100.0;    // 6
            double u_left = 0.0;     // 7
            double u_bottom = 0.0;   // 8
            double u_right = 0.0;    // 9
            double delta_t = pow(delta_x,2) / (4 * alpha);
            double gamma = (alpha * delta_t) / pow(delta_x,2);


        public:
            std::vector<std::vector<std::vector<double>>> vector_3d;
            //double a_vector_3d = new[max_iter_time][plate_length][plate_length];
            HeatSystem();
            ~HeatSystem();
            void changeValue(double value, int c);
            double getValue(int c);
            void calculate();
            void write(std::ofstream &outfile);
            void update();

};


#endif //HEATEQU2D_HEATSYSTEM_H
