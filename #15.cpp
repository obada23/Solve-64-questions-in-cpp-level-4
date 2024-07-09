#include <iostream>
using namespace std;

struct stDate
{   
    short day;
    short year;
    short month;
};

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

stDate readFullDate()
{
    stDate date;
    date.day = readShortNumber("Please enter a day? ");
    date.month = readShortNumber("Please enter a month? ");
    date.year = readShortNumber("Please enter a year? ");
    return date;
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


bool isLastDayInMonth(stDate date)
{
    return numberOfDaysInMonth(date.year,date.month) == date.day;
}

bool isLastMonthInYear(stDate date)
{
    return date.month == 12;
}



int main()
{system("clear");

    stDate date = readFullDate();
    if(isLastDayInMonth(date))
        cout << "Yes, Day " << date.day << " is Last Day in Month." << endl;
    else
        cout << "No, Day " << date.day << " is Not Last Day in Month." << endl;
    
    if(isLastMonthInYear(date))
        cout << "Yes, Month " << date.month << " is Last Month in Year." << endl;
    else
        cout << "No, Month " << date.month << " is Not Last Month in Year." << endl;

    cout << endl;
    



    return 0;
}