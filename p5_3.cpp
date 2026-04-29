#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void addItem()
{
    ofstream file("inventory.txt", ios::app); 

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string name;
    int qty;
    float price;

    cout << "Enter item name: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "Enter quantity: ";
    cin >> qty;

    cout << "Enter price: ";
    cin >> price;
    file << name << "," << qty << "," << price << endl;

    file.close();
    cout << "Item added successfully.\n";
}

void viewItems()
{
    ifstream file("inventory.txt");

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    cout << "\n--- Inventory List ---\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}


void searchItem()
{
    ifstream file("inventory.txt");

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string searchName;
    cout << "Enter item name to search: ";
    cin.ignore();
    getline(cin, searchName);

    string line;
    bool found = false;

    while (getline(file, line))
    {
        string name = "";
        int i = 0;
        while (i < line.length() && line[i] != ',')
        {
            name += line[i];
            i++;
        }

        if (name == searchName)
        {
            cout << "\nItem Found:\n" << line << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Item not found.\n";
    }

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            viewItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
