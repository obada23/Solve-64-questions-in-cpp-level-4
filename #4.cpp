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

short numberOfDays(short year)
{
    return (isLeapYear(year)) ? 366 : 365;
}

int numberOfHours(short year)
{
    return (isLeapYear(year)) ? 366*24 : 365*24;
}

int numberOfMinutes(short year)
{
    return (isLeapYear(year)) ? 366*24*60 : 365*24*60;
}

int numberOfSeconds(short year)
{
    return (isLeapYear(year)) ? 366*24*60*60 : 365*24*60*60;
}

int main()
{system("clear");
    short year = readShortNumber("Please enter a year? ");
    cout << "Number of Days    in Year[" << year << "] is " << numberOfDays(year) << endl;
    cout << "Number of Hours   in Year[" << year << "] is " << numberOfHours(year) << endl;
    cout << "Number of Minutes in Year[" << year << "] is " << numberOfMinutes(year) << endl;
    cout << "Number of Second  in Year[" << year << "] is " << numberOfSeconds(year) << endl;
    
    

    
    return 0;
}