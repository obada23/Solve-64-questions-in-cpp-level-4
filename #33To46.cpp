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

bool checkIsDate1LessThanDate2(stDate date1,stDate date2)
{
    return date1.year<date2.year ? true
    : (date1.year==date2.year ? date1.month < date2.month ? true
    : (date1.month==date2.month ? date1.day < date2.day ? true
    : false : false) : false);
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



int getDifferenceInDays(stDate date1, stDate date2, bool includeEndDays = false)
{
    bool check;
    if(checkIsDate1LessThanDate2(date1,date2))
        check = true;
    else
        check = false;

    int result = 0;
    while (true)
    {
        if(date1.year < date2.year)
        {
            for(int month=1;month<=12;month++)
            {
                result += numberOfDaysInMonth(date1.year,month);
            }
            date1.year++;
            
        }
        if(date2.year < date1.year)
        {
            for(int month=1;month<=12;month++)
            {
                result += numberOfDaysInMonth(date2.year,month);
            }
            date2.year++;
            
        }
        else if(date1.year == date2.year)
        {
            result+= numberOfDaysFromTheBeginingOfTheYear(date2.year,date2.month,date2.day) - numberOfDaysFromTheBeginingOfTheYear(date1.year,date1.month,date1.day);
            break;
        }
            
    }
    if(check)
        return includeEndDays==true ? result+1 : result;
    else
       return includeEndDays==true ? -1*(result+1) : -1*result; 
}

 bool isLastDayInMonth(stDate date)
{
    return numberOfDaysInMonth(date.year,date.month) == date.day;
}

bool isLastMonthInYear(stDate date)
{
    return date.month == 12;
}

bool isFirstDayInMonth(stDate date)
{
    return date.day==1;
}

bool isFirstMonthInYear(stDate date)
{
    return date.month==1;
}

stDate decreaseDateByOneDay(stDate date)
{
    if(isFirstDayInMonth(date))
    {
        if(isFirstMonthInYear(date))
        {
            date.year--;
            date.month=12;
            date.day=numberOfDaysInMonth(date.year,date.month);

        }
        else
        {

            date.month--;
            date.day=numberOfDaysInMonth(date.year,date.month);
            
        }
    }
        else
            date.day--;
        return date;
}

stDate decreaseDateByXDays(stDate date,short days)
{
    for(short i=1;i<=days;i++)
    {
        date = decreaseDateByOneDay(date);
    }
    return date;
}

stDate decreaseDateByOneWeak(stDate date)
{
    for(short i=1;i<=7;i++)
    {
        date = decreaseDateByOneDay(date);  
    }
    return date;
}

stDate decreaseDateByXWeeks(stDate date,short weeks)
{
    for(short i=1;i<=weeks;i++)
    {
        date = decreaseDateByOneWeak(date);
    }
    return date;
}

stDate decreaseDateByOneMonth(stDate date)
{
    if(date.month==1)
    {
        date.month=12;
        date.year--;
    }
    else
        date.month--;

    short days = numberOfDaysInMonth(date.year,date.month);

    if(date.day > days )
        date.day = days;
    return date;
}

stDate decreaseDateByXMonths(stDate date,short months)
{
    
    for(short i=1;i<=months;i++)
    {
       date = decreaseDateByOneMonth(date);
    }
    return date;
}

stDate decreaseDateByOneYear(stDate date)
{
    date.year--;
    return date;
}

stDate decreaseDateByXYears(stDate date,short years)
{
    for(short i=1;i<=years;i++)
        date = decreaseDateByOneYear(date);
    return date;
}

stDate decreaseDateByXYearsFaster(stDate date,short years)
{
    date.year -= years;
    return date;
}

stDate decreaseDateByOneDecade(stDate date)
{
    date.year -= 10;
    return date;
}

stDate decreaseDateByXDecade(stDate date,short decade)
{
    for(int i=1;i<=decade;i++)
        date = decreaseDateByOneDecade(date);
    return date;
}

stDate decreaseDateByXDecadeFaster(stDate date,short decade)
{
    date.year -= 10*decade;
    return date;
}

stDate decreaseDateByOneCentury(stDate date)
{
    date.year -= 100;
    return date;
}

stDate decreaseDateByOneMillennium(stDate date)
{
    date.year -= 1000;
    return date;
}

int main()
{system("clear");
    stDate date = readFullDate();
    date = decreaseDateByOneDay(date);
    cout << "01-Subtracting one day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short days = 10;
    date = decreaseDateByXDays(date,days);
    cout << "02-Subtracting 10 days is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneWeak(date);
    cout << "03-Subtracting one week is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short weaks = 10;
    date = decreaseDateByXWeeks(date,weaks);
    cout << "04-Subtracting 10 weeks is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneMonth(date);
    cout << "05-Subtracting one month is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short months = 5;
    date = decreaseDateByXMonths(date,months);
    cout << "06-Subtracting 5 months is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneYear(date);
    cout << "07-Subtracting one year is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short years = 10;
    date = decreaseDateByXYears(date,years);
    cout << "08-Subtracting 10 years is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = decreaseDateByXYearsFaster(date,years);
    cout << "09-Subtracting 10 years (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneDecade(date);
    cout << "10-Subtracting one decade is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short decade = 10;
    date = decreaseDateByXDecade(date,years);
    cout << "11-Subtracting 10 decade is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = decreaseDateByXDecadeFaster(date,years);
    cout << "12-Subtracting 10 decade (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneCentury(date);
    cout << "13-Subtracting one century is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = decreaseDateByOneMillennium(date);
    cout << "14-Subtracting one millennium is: " << date.day << "/" << date.month << "/" << date.year << endl;











    cout << endl << endl << endl;
    return 0;
}