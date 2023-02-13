#include <iostream>
#include <iomanip> 

std::string id= "12345";
std::string password="12345";

void showBalance(double balance)
{
    std::cout <<"\nYour balance is $"<< std::setprecision(2)<< std::fixed << balance; // $43.00 shows two decimal points.
}
double deposit()
{
    double amount;
    std::cout <<"Enter amount to be deposited: ";
    std::cin >> amount;

    if(amount <= 0)
    {
        std::cout <<"That's not a valid amount !";
        return 0;
    }
    else
    {
        return amount;
    }
}
double withdraw(double balance)
{
    double withdraw;
    std::cout <<"Enter amount to be withdrawed: ";
    std::cin >> withdraw;
    if(withdraw > balance)
    {
        std::cout <<"The amount for withdrawing can't be more than balance !";
        return 0;
    }
    else if(withdraw < 0)
    {
        std::cout <<"The amount can't be less than zero !";
        return 0;
    }
    else
    {
        return withdraw;
    }
}

int main()
{
    std::string userid;
    std::string userpassword;
    int decision;
    double balance = 43;

    std::cout << "********************\n\nWELCOME TO BANKBANK\n\n********************"<<"\nEnter your id: ";
    std::cin >> userid;

    std::cout << "\nEnter your password: ";
    std::cin >> userpassword;

    if(password != userpassword || id != userid)
    {
        std::cout<<"\nYour password or id is invalid.";
    }
    else
    {
        do{    
        std::cout << "\n********************\n\n1-Deposit\n2-Show Balance\n3-Withdraw\n4-Exit\n\n********************" << "\nTransaction(press '1','2' or '3'): ";
        std::cin >> decision;
        switch(decision){
            case 1: balance += deposit();
                    showBalance(balance);
                break;
            case 2: showBalance(balance);
                break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                break;
            case 4: std::cout <<"Thanks for using our app.";
                break;
            default: std::cout <<"\nInvalid choice !";
                break;
            }
        }while(decision!=4);
    }


    
    
    
}