#include <iostream>
#include <windows.h>
#include "funtionality.h"

using namespace std;

int main()
{
    bool isActive = true;
    int choice;
    List *bg = NULL;

    do
    {
        system("cls");
        cout<<"\t\tMENU\n";
        cout<<"1. Add new country\n";
        cout<<"2. Add new country on position\n";
        cout<<"3. Delete a country\n";
        cout<<"4. Show countries\n";
        cout<<"5. Get address of the last element\n";
        cout<<"6. Get the number of countries\n";
        cout<<"7. Find a country\n";
        cout<<"8. Edit a country\n";
        cout<<"9. Swap countries\n";
        cout<<"10. Split list into two lists\n";
        cout<<"11. Unite two list into one list\n";
        cout<<"12. Sort countries\n";
        cout<<"13. Write countries to file\n";
        cout<<"14. Read countries from file\n";
        cout<<"15. Eliminate countries\n";
        cout<<"16. Exit\n\n";

        cout<<"Input your choice: ";
        cin>>choice;
        system("cls");

        switch (choice)
        {
        case 1:
        {
            bg = addCountry(bg);
            system("PAUSE");
            break;
        }
        case 2:
        {
            bg = addAtPosition(bg);
            system("PAUSE");
            break;
        }
        case 3:
        {
            bg = deleteCountry(bg);
            system("PAUSE");
            break;
        }
        case 4:
        {
            showCountries(bg);
            system("PAUSE");
            break;
        }
        case 5:
        {
            getAdressOfTheLastElement(bg);
            system("PAUSE");
            break;
        }
        case 6:
        {
            int length = getLength(bg);
            if(length != 0)
            {
                cout<<"The length of list is: "<<length<<"\n\n";
            }
            system("PAUSE");
            break;
        }
        case 7:
        {
            findCountry(bg);
            system("PAUSE");
            break;
        }
        case 8:
        {
            bg = editCountry(bg);
            system("PAUSE");
            break;
        }
        case 9:
        {
            system("PAUSE");
            break;
        }
        case 10:
        {
            system("PAUSE");
            break;
        }
        case 11:
        {
            system("PAUSE");
            break;
        }
        case 12:
        {
            system("PAUSE");
            break;
        }
        case 13:
        {
            system("PAUSE");
            break;
        }
        case 14:
        {
            system("PAUSE");
            break;
        }
        case 15:
        {
            system("PAUSE");
            break;
        }
        case 16:
        {
            isActive = false;
            break;
        }
        default:
        {
            cout<<"Please, input your choice between 1 - 16"<<endl;
            system("PAUSE");
        }
        }
    }
    while(isActive);

    system("cls");
    cout<<"Good bye!"<<endl;
}
