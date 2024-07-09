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


stDate dateAddDays(short days,stDate date)
{
    short remainingDays = days + numberOfDaysFromTheBeginingOfTheYear(date.year,date.month,date.day);
    short monthDays = 0;
    date.month = 1;
    while(true)
    {
        monthDays = numberOfDaysInMonth(date.year,date.month);
        if(remainingDays > monthDays)
        {
            remainingDays -= monthDays;
            date.month++;
            if(date.month > 12)
            {
                date.month = 1;
                date.year++;
            }
        }
        else
            break;
        
    }
    date.day = remainingDays;
    return date;
}


int main()
{system("clear");
    
    stDate date = readFullDate();
    short days = readShortNumber("How many days to add? ");
    date = dateAddDays(days,date);
    cout << "Date after adding [" << days << "] days is : " << date.day << "/" << date.month << "/" << date.year << endl << endl;
    return 0;
}