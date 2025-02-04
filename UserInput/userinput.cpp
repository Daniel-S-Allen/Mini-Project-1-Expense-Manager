#include <iostream>
#include <string>
using namespace std;
#include "ExpenseManager.h"
#include <string>

int main(){
    int menu, choice;
    string name, option, currency, date;
    float cost;
    ExpenseManager manager;
    
    cout << "--------------Main menu--------------" << endl; 
    cout << "1. Add Expenses" << endl;
    cout << "2. Edit Budgets" << endl;
    cout << "3. View Expenses" << endl;
    
    do{
        cout << "Enter a menu option: " << endl;
        cin >> menu;    
    }while(menu>3 || menu<1);
    
    //editing expenses
    if(menu ==1){
        cout << "Enter name of expense" << endl;
        cin >> name;
        
        //adding expenses
        cout << "Enter cost of expense: " << endl;
        cin >> cost;
            
        cout << "Enter currency: " << endl;
        cin >> currency;
            
        //saving date
        cout << "Enter date (yyyy-mm-dd): " << endl;
        cin >> date;
    
        
        manager.addExpense(cost, currency, name, date);
        
        //saving expense

    }
    
}
