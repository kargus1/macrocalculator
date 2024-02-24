#ifndef CALC_H
#define CALC_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

struct food
{
    std::string name;
    float protein;
    float fibre;
    float fat;
};

void readfile(const std::vector<food> &foods);

#endif