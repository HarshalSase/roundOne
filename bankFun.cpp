/*
You are supposed to implement the requirements provided below by creating a cli application in a
programming language you choose.
You will be building a banking application. The user will be able to perform the following actions along with
the needed Input
*/

#include <bits/stdc++.h>
using namespace std;

//creating map to store all the records i.e. code , name , amount.

map<string, pair<string, int>> customerData;

//fuction to create a 0 balance account

void createAccount(string code, string name)
{
    customerData[code] = {name, 0};
}

// function to deposit the amount in account

void depositAmount(string code, int amount)
{
    // creating iterator using auto keyword which is directing to value of key "code";
    auto it = customerData.find(code);
    it->second.second += amount;
}

//function to withdraw amount from account

void withdrawAmount(string code, int amount)
{
    // creating iterator using auto keyword which is directing to value of key "code";
    auto it = customerData.find(code);
    //checking for sufficient Balance
    if(it->second.second>=amount){
    it->second.second -= amount;
    }
    else{
        cout<<"Insufficient Balance";
    }
}

// function to show available amount

void showBalance(string code)
{
    auto it = customerData.find(code);
    cout << it->second.first << " " << it->second.second;
}

int main()
{
    //input for actions
    string choice;
    
    //to converting actions into numbers
    int caseInt;
    
    do
    {
        cin >> choice;
        
        //converting actions into numbers
        
        if (choice == "CREATE")
        {
            caseInt = 1;
        }
        else if (choice == "DEPOSIT")
        {
            caseInt = 2;
        }
        else if (choice == "WITHDRAW")
        {
            caseInt = 3;
        }
        else if (choice == "BALANCE")
        {
            caseInt = 4;
        }
        else{
            caseInt = 0;
        }

        switch (caseInt)
        {
        case 1:
        {
            string code, name;
            cin >> code >> name;
            createAccount(code, name);
            break;
            
        }
        case 2:
        {
            string code;
            int amount;
            cin >> code >> amount;
            depositAmount(code, amount);
            break;
        }
        case 3:
        {
            string code;
            int amount;
            cin >> code >> amount;
            withdrawAmount(code, amount);
            break;
            
        }
        case 4:
        {
            string code;
            cin >> code;
            showBalance(code);
            break;
            
        }
        default:
        {
            cout << "Invalid Input !!!";
            break;
        }
        }
        
        //to terminate the number press any word , letter or numbr other than actions
        
    } while (caseInt != 0);
}
