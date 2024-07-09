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

short numberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
{
    short totalDays = 0;
    for(int i=1;i<month;i++)
    {
        totalDays+=numberOfDaysInMonth(year,i);
    }
    totalDays+=day;
    return totalDays;
    
}




int main()
{system("clear");
    
    short day = readShortNumber("Please enter a day? ");
    short month = readShortNumber("Please enter a month? ");
    short year = readShortNumber("Please enter a year? ");
    cout << "Number of Days from the begining of the year is " << numberOfDaysFromTheBeginingOfTheYear(year,month,day)<< endl << endl;     
     
    return 0;
}