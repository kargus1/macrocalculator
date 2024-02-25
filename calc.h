#ifndef CALC_H
#define CALC_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

struct food
{
    std::string name;
    float protein;
    float fibre;
    float fat;
    float carbs;
};

bool bin();
int menu();
string date();
bool createentry(string);
bool calculatefoods(vector<food>, string);

#endif