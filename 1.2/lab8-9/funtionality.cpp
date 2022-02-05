#include <iostream>
#include <iomanip>
#include <string.h>
#include "funtionality.h"

using namespace std;

List* createList()
{
    return new List;
}

List* addCountry(List *bg)
{
    struct Country *country = inputCountryData();

    if(bg == NULL)
    {
        cout<<"List was created. Country was added!\n\n";
        return addAtFirstPosition(bg, country);
    }
    else
    {
        List *cr = new List;
        List *prv = NULL;

        if(getLength(bg) == 1)
        {
            prv = bg;
        }
        else
        {
            prv = getPenultimateCountry(bg);
        }

        if(cr != NULL)
        {
            cr -> country = country;
            cr -> next = NULL;
            prv -> next = cr;
            cout<<"Country was added!\n\n";
            return bg;
        }

        cout<<"Nothing was added\n\n";
        return bg;
    }
}

List* getLastCountry(List *cr)
{
    if(cr == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        while (cr != NULL)
        {
            cr=cr->next;
        }
        return cr;
    }

    return NULL;
}

List* getPenultimateCountry(List *cr)
{
    if(cr == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        if (getLength(cr) == 1)
        {
            return cr;
        }

        while (cr != NULL)
        {
            cr = cr->next;

            if(cr->next == NULL)
            {
                return cr;
            }
        }
    }

    return NULL;
}

int getLength(List *cr)
{
    if(cr == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        int k = 0;
        while (cr != NULL)
        {
            k++;
            cr = cr -> next;
        }
        return k;
    }

    return 0;
}

Country* inputCountryData()
{
    struct Country *country = new Country;

    cout<<"Input country name: ";
    cin>>country -> name;

    cout<<"Input country capital: ";
    cin>>country -> capital;

    cout<<"Input country area: ";
    cin>>country -> area;

    cout<<"Input country population: ";
    cin>>country -> population;

    cout<<"Input country gross domestic product: ";
    cin>>country -> grossDomesticProduct;

    return country;
}

List* addAtPosition(List *bg)
{
    int position;
    int lastPosition = getLength(bg);

    if(lastPosition == 0)
    {
        cout<<"The element will be added at first position\n\n";
    }
    else
    {
        do
        {
            cout<<"Input position: ";
            cin>>position;
            if(position<=0 || position>lastPosition+1)
            {
                cout<<"Position should be between 1 and "<<lastPosition+1<<"\n\n";
            }
        }
        while(position<=0 || position>lastPosition+1);
    }

    struct Country *country = inputCountryData();

    if(bg==NULL)
    {
        bg = addAtFirstPosition(bg, country);
        cout<<"List was created. Country was added!\n\n";
        return bg;
    }
    else if (position == 1)
    {
        List *newElement = new List;
        newElement -> country = country;
        newElement -> next = bg;
        cout<<"Country was added!\n\n";
        return newElement;
    }
    else if (position == lastPosition+1)
    {
        List *prv = getPenultimateCountry(bg);
        List *newElement = new List;
        newElement -> country = country;
        newElement -> next = NULL;
        prv -> next = newElement;
        cout<<"Country was added!\n\n";
        return bg;
    }
    else
    {
        List *cr = bg, *prv = bg;
        int k = 1;
        while (bg != NULL)
        {
            if(k==position)
            {
                List *newElement = new List;
                newElement -> country = country;
                newElement -> next = cr;
                prv -> next = newElement;
                return bg;
            }

            k++;
            prv = cr;
            cr = cr->next;
        }
        cout<<"Country was added!\n\n";
        return bg;
    }

    return NULL;
}

List* addAtFirstPosition(List *bg, struct Country *country)
{
    bg = createList();
    bg -> country = country;
    bg -> next = NULL;
    return bg;
}

void showCountries(List *cr)
{
    if(cr == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        cout<<"----------------------------------------------------------------------------\n";
        cout<<left<<setw(9)<<"Country\t\t"<<setw(18)<<"Capital\t"<<setw(13)<<"Area\t"<<setw(10)<<"Population\t"<<setw(8)<<"GDP\t"<<endl;
        cout<<"----------------------------------------------------------------------------\n";

        while (cr!=NULL)
        {
            cout<<left<<setw(10)<<cr -> country -> name<<"\t"<<setw(10)<<cr -> country -> capital<<"\t"<<right<<setw(10)<<cr -> country ->area<<"\t"<<
                setw(10)<<cr -> country -> population<<"\t"<<setw(10)<<cr -> country -> grossDomesticProduct<<endl;
            cr=cr->next;
        }

        cout<<"----------------------------------------------------------------------------\n";

    }
}

List* deleteCountry(List *bg)
{
    char searchParam[50];
    cout<<"Input country name or capital name: ";
    cin>>searchParam;

    if(strcmp(bg -> country -> name, searchParam) == 0  || strcmp(bg -> country -> capital, searchParam) == 0)
    {
        List *newBegin = bg -> next;
        delete[] bg->country;
        bg -> country = NULL;
        delete[] bg;
        bg = NULL;
        cout<<"Country was deleted\n\n"<<endl;
        return newBegin;
    }
    else
    {
        List *cr = bg -> next, *prv = bg;

        while(cr!=NULL)
        {
            if(strcmp(cr -> country -> name, searchParam) == 0 || strcmp(cr -> country -> capital,searchParam) == 0)
            {
                prv -> next = cr -> next;
                delete[] cr->country;
                cr -> country = NULL;
                delete[] cr;
                cr = NULL;
                cout<<"Country was deleted\n\n"<<endl;
                return bg;
            }

            prv = cr;
            cr = cr -> next;
        }
    }

    cout<<"Country was not found\n\n"<<endl;
    return bg;
}


void getAdressOfTheLastElement(List *bg)
{
    if(getLength(bg)!=0)
    {
        List *cr = bg;

        while (cr != NULL)
        {
            if(cr-> next == NULL)
            {
                cout<<"The address of the last element is: "<<cr<<"\n\n";

            }
            cr=cr->next;
        }
    }

}

void findCountry(List *bg)
{
    if(bg == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        char searchParam[50];
        cout<<"Input country name or capital name: ";
        cin>>searchParam;
        List *cr = bg;

        while(cr!=NULL)
        {
            if(strcmp(cr -> country -> name, searchParam) == 0 || strcmp(cr -> country -> capital,searchParam) == 0)
            {
                showCountry(cr -> country);
                return;
            }

            cr = cr -> next;
        }

        cout<<"Country was not found\n\n"<<endl;
    }
}

void showCountry(Country *country)
{
    cout<<"----------------------------------------------------------------------------\n";
    cout<<left<<setw(9)<<"Country\t\t"<<setw(18)<<"Capital\t"<<setw(13)<<"Area\t"<<setw(10)<<"Population\t"<<setw(8)<<"GDP\t"<<endl;
    cout<<"----------------------------------------------------------------------------\n";

    cout<<left<<setw(10)<<country -> name<<"\t"<<setw(10)<<country -> capital<<"\t"<<right<<setw(10)<<country ->area<<"\t"<<
        setw(10)<<country -> population<<"\t"<<setw(10)<<country -> grossDomesticProduct<<endl;

    cout<<"----------------------------------------------------------------------------\n";
}

List* editCountry(List *bg)
{
    if(bg == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        char searchParam[50];
        cout<<"Input country name or capital name: ";
        cin>>searchParam;
        List *cr = bg;

        while(cr!=NULL)
        {
            if(strcmp(cr -> country -> name, searchParam) == 0 || strcmp(cr -> country -> capital, searchParam) == 0)
            {
                showCountry(cr -> country);
                delete[] cr->country;
                cr -> country = NULL;
                struct Country *newCountry = inputCountryData();
                cr -> country = newCountry;
                return bg;
            }

            cr = cr -> next;
        }

        cout<<"Country was not found\n\n"<<endl;
    }

    return bg;
}

List* swapCountries(List *bg)
{

    if(bg == NULL)
    {
        cout<<"The list of countries is empty\n\n";
    }
    else
    {
        char firstCountry[50];
        char secondCountry[50];
        cout<<"Input first country name or capital name: ";
        cin>>firstCountry;
        cout<<"Input second country name or capital name: ";
        cin>>secondCountry;
        List *cr = bg;

        List *fCountry = NULL;
        List *sCountry = NULL;

        while(cr -> next!=NULL)
        {
            if(strcmp(cr -> next -> country -> name, firstCountry) == 0 || strcmp(cr -> next -> country -> capital, firstCountry) == 0)
            {
                fCountry = cr;
            }
            if(strcmp(cr -> next -> country -> name, secondCountry) == 0 || strcmp(cr -> next -> country -> capital, secondCountry) == 0)
            {
                sCountry = cr;
            }

            cr = cr -> next;
        }

        if(fCountry!=NULL && sCountry!=NULL)
        {
            List *fTemp = fCountry -> next -> next;
            cout<<"fTemp = "<<fTemp -> country -> name<<endl;
            cout<<"fCountry -> next -> next = "<<fCountry -> next -> next -> country -> name<<endl;
            List *sTemp = sCountry -> next -> next;
            cout<<"sTemp = "<<sTemp -> country -> name<<endl;
            cout<<"sCountry -> next -> next = "<<sCountry -> next -> next -> country -> name<<endl;

            List *tTemp = fCountry -> next;
            cout<<"tTemp = "<<tTemp -> country -> name<<endl;
            cout<<"fCountry -> next = "<<fCountry -> next -> country -> name<<endl;
            fCountry -> next = sCountry -> next;
            cout<<"fCountry -> next = "<<fCountry -> next -> country -> name<<endl;
            cout<<"sCountry -> next = "<<sCountry -> next -> country -> name<<endl;
            sCountry -> next = tTemp;
            cout<<"sCountry -> next = "<<sCountry -> next -> country -> name<<endl;
            cout<<"tTemp = "<<tTemp -> country -> name<<endl;

            fCountry -> next -> next = sTemp;
            cout<<"fCountry -> next -> next = "<<fCountry -> next -> next -> country -> name<<endl;
            cout<<"sTemp = "<<sTemp -> country -> name<<endl;
            sCountry -> next -> next = fTemp;
            cout<<"sCountry -> next -> next = "<<sCountry -> next -> next -> country -> name<<endl;
            cout<<"fTemp = "<<fTemp -> country -> name<<endl;
        }
        else
        {
            cout<<"Countries were not found\n\n"<<endl;
        }

    }

    return bg;
}
