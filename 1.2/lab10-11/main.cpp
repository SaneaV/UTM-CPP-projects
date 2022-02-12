#include <iostream>
#include "funtionality.h"

using namespace std;

int main() {
    bool isActive = true;
    int choice;
    Node *head = nullptr;

    do {
        cout << "\t\tMENU\n";
        cout << "1. Input number\n";
        cout << "2. Show numbers (from smallest to biggest)\n";
        cout << "3. Show numbers (from biggest to smallest)\n";
        cout << "4. Find a node\n";
        cout << "5. Number of nods\n";
        cout << "6. Tree height\n";
        cout << "7. Eliminate memory\n";
        cout << "8. Exit\n\n";

        cout << "Input your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "How do you want to input?\n";
                cout << "1. With recursion\n";
                cout << "2. With iteration\n\n";
                do {
                    cout << "Input your choice: ";
                    cin >> choice;
                } while (choice < 1 || choice > 2);

                char *message = "for input";
                choice == 1 ? insertRecursive(head, inputNumberFor(message)) :
                insertIterative(head, inputNumberFor(message));
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                cout << "How do you want to find a number?\n";
                cout << "1. With recursion\n";
                cout << "2. With iteration\n\n";
                do {
                    cout << "Input your choice: ";
                    cin >> choice;
                } while (choice < 1 || choice > 2);

                char *message = "for search";
                choice == 1 ? searchRecursive(head, inputNumberFor(message), nullptr) :
                searchIterative(head, inputNumberFor(message));
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                isActive = false;
                break;
            }
            default: {
                cout << "Please, input your choice between 1 - 8" << endl;
            }
        }

    } while (isActive);
    return 0;
}
