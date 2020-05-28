#include <iostream>
#include <cstring>
#include "01_hashtable.h"

using namespace std;

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Coke", 40);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Pizza", 150);
    price_menu.insert("Noodles", 25);

    price_menu.print();

    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not Found";
    }

    else
    {
        cout << "Price is " << price << "\n";
    }
    //map

    //insert
    price_menu["Dosa"] = 60;

    //update
    price_menu["Dosa"] += 10;

    //search
    cout << "Price of Dosa: " << price_menu["Dosa"] << "\n";

    return 0;
}