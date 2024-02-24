#include "calc.h"

int main()
{
    vector<food> foods;
    readfile(foods);
    cout << "MACROKALKYLATORN" << endl;
    while (true)
    {
        int choice = menu();
        if (choice == 0)
        {
            cout << "Stänger programmet!" << endl;
            break;
        }
        else if (choice == 1)
        {
            newentry(foods);
        }
    }
    return 0;
}