#include "calc.h"

using namespace std;

vector<food> readfile(vector<food> &foods)
{
    ifstream file("data/food.txt");
    if (!file.is_open())
    {
        cout << "error" << endl;
    }

    food temp;
    while (file >> temp.name >> temp.protein >> temp.fibre >> temp.fat)
    {
        foods.push_back(temp);
    }

    file.close();
    return foods;
}

int main()
{
    while (true)
    {
        vector<food> foods;
        readfile(foods);
        cout << "~~~~~~~~~~ KALKYLATORN ~~~~~~~~~~" << endl;
        /*cout << "ANGE INGREDIENS: ";
        activechoice = true;
        while (activechoice)
        {
            cin >> ingredient;
            activechoice = false;
        }

        cout << "ANGE VIKT: ";
        activechoice = true;
        while (activechoice)
        {
            cin >> weight;
            activechoice = false;
        }

        cout << "DU HAR ANGIVIT " << weight << "g " << ingredient << ". Stämmer det?" << endl;
        cout << "1. Ja" << endl;
        cout << "2. Nej" << endl;
        activechoice = true;
        while (activechoice)
        {
            cin >> choice;
            if (choice == 1)
            {
                for (const auto &food : foods)
                {
                    if (food.name == ingredient)
                    {
                        cout << "PROTEIN: " << food.protein * weight << "g" << endl;
                        cout << "FIBRE: " << food.fibre * weight << "g" << endl;
                        cout << "FAT: " << food.fat * weight << "g" << endl;
                        break;
                    }
                }
                activechoice = false;
            }
            else if (choice == 2)
            {
                activechoice = false;
                break;
            }
            else
            {
                cout << "ANGE KORREKT VAL" << endl;
            }
        }

        active = false;*/
    }
    return 0;
}