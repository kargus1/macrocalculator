#ifndef CALC_H
#define CALC_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct food
{
    std::string name;
    float protein;
    float fibre;
    float fat;
};

vector<food> readfile(vector<food> &foods);
int menu();
void newentry(vector<food> &foods);
void createentry(int day, int month, int year);
void enterfoods(vector<food> &foods);

#endif