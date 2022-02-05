#include <iostream>

using namespace std;

struct Country
{
    char name[50];
    char capital[50];
    int area;
    int population;
    int grossDomesticProduct;
};

struct List
{
    struct Country *country;
    List *next;
};

List* createList();
List* addCountry(List *bg);
Country* inputCountryData();
List *getLastCountry(List *bg);
List *getPenultimateCountry(List *bg);
int getLength(List *bg);

List* addAtPosition(List *bg);
List* addAtFirstPosition(List *bg, struct Country *country);

void showCountries(List *cr);

List* deleteCountry(List *bg);

void getAdressOfTheLastElement(List *bg);

void findCountry(List *bg);
void showCountry(Country *cntr);

List* editCountry(List *bg);

List* swapCountries(List *bg);
