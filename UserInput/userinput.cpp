#include <iostream>
#include <string>
using namespace std;
#include <string>


int main(){
    int menu, choice;
    string name, option, currency, date;
    float cost;
    
    
    do{
        cout << "--------------Main menu--------------" << endl; 
        cout << "1. Edit Expenses" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Exit " << endl;

        do{
            cout << "Enter a menu option: " << endl;
            cin >> menu;    
        }while(menu>4 || menu<1);

        //editing expenses
        if(menu ==1){
            cout << "1. Add expenses \n2. Delete expenses" << endl;
            cin >> choice;
            cout << "Enter name of expense" << endl;
            cin >> name;

            //adding expenses
            if(choice==1){
                cout << "Enter cost of expense: " << endl;
                cin >> cost;

                cout << "Enter currency: " << endl;
                cin >> currency;

                //saving date
                cout << "Would you like to enter a date for the expense? (Enter yes or no): " << endl;
                cin >> option;
                if(option=="no"){
                    //result to default
                }
                else{
                    cout << "Enter date: " << endl;
                    cin >> date;
                    //make sure date is formatted correctly
                }
            }

        }
    }while(menu!=3);
    
    
}
