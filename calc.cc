#include "calc.h"

bool bin()
{
    while (true)
    {
        int choice;
        cout << "1. ja" << endl
             << "2. nej" << endl
             << "val: ";
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            return true;
        }
        else if (choice == 2)
        {
            return false;
        }
        else
        {
            cout << "inte giltigt val";
        }
    }
}

int menu()
{
    int temp;
    cout << "vad vill du göra?" << endl
         << "1. nytt inlägg" << endl
         << "2. lägg till i existerande inlägg" << endl
         << "0. stäng programmet" << endl
         << "val: ";
    cin >> temp;
    cout << endl;
    return temp;
}

bool calculatefoods(vector<food> foods, string filename)
{
    string ts;
    int ti;
    while (true)
    {
        while (true)
        {
            bool found{false};
            cout << "ange ingrediens: ";
            cin >> ts;
            for (const auto &temp : foods)
            {
                if (temp.name == ts)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
            else
            {
                cout << "ange korrekt ingrediens" << endl;
            }
        }
        while (true)
        {
            cout << "ange vikt i gram: ";
            cin >> ti;
            if (ti < 0 or ti > 2000)
            {
                cout << "ange korrekt vikt i gram" << endl;
            }
            else
            {
                break;
            }
        }
        cout << "du har angivit " << ti << " gram " << ts << ". stämmer det?" << endl;
        bool choice = bin();
        if (choice)
        {
            break;
        }
    }
    float protein, fat, fibre, carbs;
    for (const auto &temp : foods)
    {
        if (temp.name == ts)
        {
            protein = temp.protein * ti;
            cout << ts << " protein " << protein << " gram" << endl;
            fat = temp.fat * ti;
            cout << ts << " fett " << fat << " gram" << endl;
            fibre = temp.fibre * ti;
            cout << ts << " fibrer " << fibre << " gram" << endl;
            carbs = temp.carbs * ti;
            cout << ts << " kolhydrater " << carbs << " gram" << endl
                 << endl;
            break;
        }
    }
    float oldprotein, oldfat, oldfibre, oldcarbs;
    ifstream input(filename);
    if (input.is_open())
    {
        string line;
        while (getline(input, line))
        {
            if (line.find("Protein:") != string::npos)
            {
                oldprotein = stof(line.substr(line.find(":") + 1));
            }
            else if (line.find("Fat:") != string::npos)
            {
                oldfat = stof(line.substr(line.find(":") + 1));
            }
            else if (line.find("Fibre:") != string::npos)
            {
                oldfibre = stof(line.substr(line.find(":") + 1));
            }
            else if (line.find("Carbs:") != string::npos)
            {
                oldcarbs = stof(line.substr(line.find(":") + 1));
            }
        }
        input.close();
    }
    ofstream output(filename, std::ios::trunc);
    output << "Protein: " << oldprotein + protein << "\n";
    output << "Fat: " << oldfat + fat << "\n";
    output << "Fibre: " << oldfibre + fibre << "\n";
    output << "Carbs: " << oldcarbs + carbs << "\n";
    output.close();
    while (true)
    {
        int choice;
        cout << "fler ingredienser?" << endl;
        return bin();
    }
}

bool createentry(string filename)
{
    if (std::filesystem::exists(filename))
    {
        cout << "det finns redan ett inlägg för den här dagen" << endl
             << endl;
        return false;
    }
    else
    {
        ofstream output(filename);
        output << "Protein: 0\n";
        output << "Fat: 0\n";
        output << "Fibre: 0\n";
        output << "Carbs: 0\n";
        output.close();
        return true;
    }
}

string date()
{
    int day, month, year;
    bool leapyear;
    cout << "ange dagens datum" << endl;
    while (true)
    {
        cout << "år: ";
        cin >> year;
        if (year < 2024 or year > 2100)
        {
            cout << "ange giltigt år i formatet xxxx" << endl
                 << endl;
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
        cout << "månad: ";
        cin >> month;
        if (month < 1 or month > 12)
        {
            cout << "ange giltig månad i formatet xx" << endl
                 << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        while (true)
        {
            cout << "dag: ";
            cin >> day;
            if (day < 1 or day > 31)
            {
                cout << "ange giltig dag i formatet xx" << endl
                     << endl;
            }
            else
            {
                if ((month == 4 or month == 6 or month == 9 or month == 11) and day > 30)
                {
                    cout << "ange giltig dag i formatet xx" << endl
                         << endl;
                }
                else if (month == 2 and day > 28)
                {
                    if (!leapyear)
                    {
                        cout << "ange giltig dag i formatet xx" << endl
                             << endl;
                    }
                    else if (leapyear and day > 29)
                    {
                        cout << "ange giltig dag i formatet xx" << endl
                             << endl;
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
        cout << "du har angivit " << year << "-" << month << "-" << day << ". stämmer det?" << endl;
        bool choice = bin();
        if (choice)
        {
            break;
        }
    }
    string filename = "./entries/" + to_string(day) + "-" + to_string(month) + "-" + to_string(year) + ".txt";
    return filename;
}
