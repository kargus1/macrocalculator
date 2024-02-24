#include "calc.h"

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

int menu()
{
    int temp;
    cout << "Vad vill du göra?" << endl
         << "1. Nytt inlägg" << endl
         << "0. Stäng programmet" << endl;
    cin >> temp;
    return temp;
}

void enterfoods(vector<food> &foods)
{
    vector<pair<string, int>> food;
    string ts;
    int ti;
    while (true)
    {
        cout << "Ange ingrediens: ";
        cin >> ts;
        for (const auto &temp : foods)
        {
            if (temp.name == ts)
            {
                break;
            }
            else
            {
                cout << "Ange korrekt ingrediens" << endl;
                break;
            }
        }
        break;
    }
    while (true)
    {
        cout << "Ange vikt i gram: ";
        cin >> ti;
        if (ti < 0 or ti > 2000)
        {
            cout << "Ange korrekt vikt i gram" << endl;
        }
        else
        {
            break;
        }
    }

    // FORTSÄTT HÄR !!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void createentry(int day, int month, int year, vector<food> &foods)
{
    string filename = "./entries/" + to_string(day) + "-" + to_string(month) + "-" + to_string(year) + ".txt";
    ofstream output(filename);
    output.close();
    // LÄGG TILL OM DAGEN REDAN FINNS
    enterfoods(foods);
}

void newentry(std::vector<food> &foods)
{
    int day, month, year;
    bool leapyear;
    cout << "Ange dagens datum" << endl;
    while (true)
    {
        cout << "År: ";
        cin >> year;
        if (year < 2024 or year > 2100)
        {
            cout << "Ange giltigt år i formatet xxxx" << endl;
        }
        else
        {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                leapyear = true;
            }
            else
            {
                leapyear = false;
            }
            break;
        }
    }
    while (true)
    {
        cout << "Månad: ";
        cin >> month;
        if (month < 1 or month > 12)
        {
            cout << "Ange giltig månad i formatet xx" << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Dag: ";
        cin >> day;
        if (day < 1 or day > 31)
        {
            cout << "Ange giltig dag i formatet xx" << endl;
        }
        else
        {
            if (month == 4 or month == 6 or month == 9 or month == 11 and day > 30)
            {
                cout << "Ange giltig dag i formatet xx" << endl;
            }
            else if (month == 2 and day > 28)
            {
                if (!leapyear)
                {
                    cout << "Ange giltig dag i formatet xx" << endl;
                }
                else if (leapyear and day > 29)
                {
                    cout << "Ange giltig dag i formatet xx" << endl;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    createentry(day, month, year, foods);
}
