#include <iostream>
#include <string>
using namespace std;
#include "ExpenseManager.h"
#include <string>
#include <vector>

int main(){
    int menu, choice;
    string name, option, currency, date, category;
    float cost;
    ExpenseManager manager;
    
    cout << "--------------Main menu--------------" << endl; 
    cout << "1. Add Expenses" << endl;
    cout << "2. Add Categories" << endl;
    cout << "3. View Expenses" << endl;
    
    do{
        cout << "Enter a menu option: " << endl;
        cin >> menu;    
    }while(menu>3 || menu<1);
    
    ////adding expenses
    if(menu ==1){
        cout << "Enter name of expense" << endl;
        cin >> name;
        
        cout << "Enter cost of expense: " << endl;
        cin >> cost;
            
        cout << "Enter currency: " << endl;
        cin >> currency;
        
        cout << "Enter date (yyyy-mm-dd): " << endl;
        cin >> date;
        
        cout << "Enter category: " << endl;
        cin >> category;
        
        //saving expense
        manager.addExpense(cost, currency, name, date, category);    
        
    }
    
    else if(menu==2){
        cout << "Enter name of category: " << endl;
        cin >> category;
    }
    
    
}
