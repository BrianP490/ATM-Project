#include <iostream> //to collect user input (cin >> x)
#include <iomanip>  //for output manipulation (fixed, setprecision)
#include "../headers/atm.h"

void atm()
{
    int pin = 444;    //user's default pin number
    int Chance = 3;
    int PIN_input;      //store the users pin input
    int Choice_Input;       //stores the user's menu choice input
    double Balance = 500.00;
    double Amnt;

    //Print Welcome Message
    std::cout << "Welcome to our ATM Machine\n" << std::endl;
    
    //...User enters their account identifier...

    //Following code attempts to receive the user's PIN number in under 3 attempts
    do
    {
        std::cout << "Please enter your PIN number: (Tries remaining: " << Chance << "): "; 
        std::cin >> PIN_input;
        Chance--;

    } while (PIN_input != pin && Chance != 0);//loop until user runs out of chances or their input matches their PIN number
    
    if(PIN_input == pin)//only access if the user enters the correct PIN number for their account
    {
        std::cout << "Greetings, User. " << std::endl;

        do//do while loop to navigate ATM services
        {   
            std::cout << "\nWhat would you like to do?\nUser Options:\n--------------------\n0. Exit\n1. Deposit\n2. Withdraw\n3. Check Balance\n Enter Choice: ";
            std::cin >> Choice_Input;
            std::cout << std::fixed << std::showpoint << std::setprecision(2) << std::endl;  //make the balances show decimals up to the hundredths place (.00)


            switch (Choice_Input)
            {
            case 0:
                break;
            case 1:
                std::cout<< "Depositing...\nHow much do you want to deposit?: ";
                std::cin >> Amnt;
                Balance += Amnt;
                std::cout << "\nNew Balance: $" << Balance << std::endl;
                break;
            case 2:
                std::cout<< "Withdrawing...\nHow much do you want to withdraw?: ";
                std::cin >> Amnt;

                if(Amnt > Balance) //show that ammount to be withdrawn exceeds the balance
                    std::cout << "\nUnsufficient Funds to withdraw.\n";
                else
                    Balance -= Amnt;  //subtract the amount from the balance
                break;
            case 3:
                std::cout << "Current Balance: $" << Balance << std::endl;
                break;

            default:
                Choice_Input = 0;
                break;
            }
        } while (Choice_Input != 0);

        std::cout << "Thank You for Using The ATM Machine... Good Day!!!" << std::endl << std::endl;
    }
    else//user was not able to access their correct PIN number
    {
        std::cout << "Unable to access account. \nPlease try again in 2 hours.\n-ATM Machine" << std::endl;
    }
}//exits to the main function
