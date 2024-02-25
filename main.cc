#include "calc.h"

int main()
{
    vector<food> foods;
    ifstream file("data/food.txt");
    if (!file.is_open())
    {
        cout << "error" << endl;
    }
    food temp;
    while (file >> temp.name >> temp.protein >> temp.fibre >> temp.fat >> temp.carbs)
    {
        foods.push_back(temp);
    }
    file.close();

    cout << endl
         << "MACROKALKYLATORN" << endl
         << "~~~~~~~~~~~~~~~~" << endl
         << endl;
    while (true)
    {
        int choice = menu();
        if (choice == 0)
        {
            cout << "stänger programmet!" << endl;
            break;
        }
        else if (choice == 1)
        {
            while (true)
            {
                string filename = date();
                bool created = createentry(filename);
                if (created)
                {
                    bool going;
                    while (going)
                    {
                        going = calculatefoods(foods, filename);
                    }
                }
                break;
            }
        }
        else if (choice == 2)
        {
            string filename = date();
            bool going{true};
            while (going)
            {
                going = calculatefoods(foods, filename);
            }
        }
    }
    return 0;
}