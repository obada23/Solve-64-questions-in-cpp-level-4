#include <iostream>
using namespace std;

short readShortNumber(string message)
{
    short number;
    do
    {
        cout << message;
        cin >> number;
        cout << endl;

    } while (number<0);
    return number;
}

bool isLeapYear(short year)
{
    return (year%400==0) || (year%4==0 && year%100!=0); 
}

int main()
{system("clear");
    short year = readShortNumber("Please enter a year to check? ");
    if(isLeapYear(year))
        cout << "Yes, Year [" << year << "] is a leap year.\n\n";
    else
        cout << "No, Year [" << year << "] is not leap year.\n\n";
    
    
    return 0;
}