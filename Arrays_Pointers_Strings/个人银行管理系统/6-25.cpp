// 6-25.cpp
#include "date.h"
#include "account.h"
#include <iostream>

using namespace std;

int main(){
    Date date(2007,8,6);

    SavingAccount accounts[]={
        SavingAccount(date,"#2012001",0.015),
        SavingAccount(date,"#2012002",0.015),
        SavingAccount(date,"#2012003",0.015)
    };

    const int n = sizeof (accounts)/sizeof(SavingAccount);

    accounts[0].deposit(Date(2007,8,6),1000,"salary");
    accounts[1].deposit(Date(2007,8,30),2000,"sell stock 0323");

    accounts[0].deposit(Date(2007,9,6),1000,"salary");
    accounts[1].withdraw(Date(2007,9,6),500,"buy a new phone");

    cout<<endl;

    for (int i=0;i<n;i++){
        accounts[i].settle(Date(2007,12,31));
        accounts[i].show();
        cout<<endl;
    }
    cout<<"Total:"<<SavingAccount::getTotal()<<endl;
    return 0;

}