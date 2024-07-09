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

stDate increaseDateByOneDay(stDate date)
{
    if(isLastDayInMonth(date))
    {
        if(isLastMonthInYear(date))
        {
            date.year++;
            date.month=1;
            date.day=1;

        }
        else
        {
            date.day=1;
            date.month++;
        }
    }
    else
        date.day++;
    return date;
}



int main()
{system("clear");

    stDate date = readFullDate();
    date = increaseDateByOneDay(date);
    cout << "Date after adding one day is : " << date.day << "/" << date.month << "/" << date.year << endl << endl;
    


    return 0;
}