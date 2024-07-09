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

short numberOfDaysInMonth(short year, short month)
{   
    if (month<1||month>12)
        return 0;
        
    short numberOfDays[] = {31,0,31,30,31,30,31,31,30,31,30,31};
    return (month==2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month-1];
}

int numberOfHoursInMonth(short year, short month)
{
    return numberOfDaysInMonth(year,month)*24;
}

int numberOfMinutesInMonth(short year, short month)
{
    return numberOfDaysInMonth(year,month)*24*60;
}

int numberOfSecondsInMonth(short year, short month)
{
    return numberOfDaysInMonth(year,month)*24*60*60;
}

int main()
{system("clear");
    short year = readShortNumber("Please enter a year? ");
    short month = readShortNumber("Please enter a month? ");
    cout << "Number of Days    in Month[" << month << "] is " << numberOfDaysInMonth(year,month) << endl;
    cout << "Number of Hours   in Month[" << month << "] is " << numberOfHoursInMonth(year,month) << endl;
    cout << "Number of Minutes in Month[" << month << "] is " << numberOfMinutesInMonth(year,month) << endl;
    cout << "Number of Second  in Month[" << month << "] is " << numberOfSecondsInMonth(year,month) << endl;
    
    

    
    return 0;
}