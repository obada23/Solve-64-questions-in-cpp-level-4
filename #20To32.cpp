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

stDate increaseDateByXDays(stDate date,short days)
{
    for(short i=1;i<=days;i++)
    {
        date = increaseDateByOneDay(date);
    }
    return date;
}

stDate increaseDateByOneWeak(stDate date)
{
    for(short i=1;i<=7;i++)
    {
        date = increaseDateByOneDay(date);  
    }
    return date;
}

stDate increaseDateByXWeeks(stDate date,short weeks)
{
    for(short i=1;i<=weeks;i++)
    {
        date = increaseDateByOneWeak(date);
    }
    return date;
}

stDate increaseDateByOneMonth(stDate date)
{

    short days = numberOfDaysInMonth(date.year,date.month);

    for(short i=1;i<=days;i++)
    {
        date = increaseDateByOneDay(date);
    }
    return date;
}

stDate increaseDateByXMonths(stDate date,short months)
{
    
    for(short i=1;i<=months;i++)
    {
       date = increaseDateByOneMonth(date);
    }
    return date;
}

stDate increaseDateByOneYear(stDate date)
{
    date.year++;
    return date;
}

stDate increaseDateByXYears(stDate date,short years)
{
    for(short i=1;i<=years;i++)
        date = increaseDateByOneYear(date);
    return date;
}

stDate increaseDateByXYearsFaster(stDate date,short years)
{
    date.year += years;
    return date;
}

stDate increaseDateByOneDecade(stDate date)
{
    date.year += 10;
    return date;
}

stDate increaseDateByXDecade(stDate date,short decade)
{
    for(int i=1;i<=decade;i++)
        date = increaseDateByOneDecade(date);
    return date;
}

stDate increaseDateByXDecadeFaster(stDate date,short decade)
{
    date.year += 10*decade;
    return date;
}

stDate increaseDateByOneCentury(stDate date)
{
    date.year += 100;
    return date;
}

stDate increaseDateByOneMillennium(stDate date)
{
    date.year += 1000;
    return date;
}

int main()
{system("clear");
    stDate date = readFullDate();
    date = increaseDateByOneDay(date);
    cout << "01-Adding one day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short days = 10;
    date = increaseDateByXDays(date,days);
    cout << "02-Adding 10 days is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneWeak(date);
    cout << "03-Adding one week is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short weaks = 10;
    date = increaseDateByXWeeks(date,weaks);
    cout << "04-Adding 10 weeks is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneMonth(date);
    cout << "05-Adding one month is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short months = 5;
    date = increaseDateByXMonths(date,months);
    cout << "06-Adding 5 months is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneYear(date);
    cout << "07-Adding one year is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short years = 10;
    date = increaseDateByXYears(date,years);
    cout << "08-Adding 10 years is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXYearsFaster(date,years);
    cout << "09-Adding 10 years (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneDecade(date);
    cout << "10-Adding one decade is: " << date.day << "/" << date.month << "/" << date.year << endl;

    short decade = 10;
    date = increaseDateByXDecade(date,years);
    cout << "11-Adding 10 decade is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXDecadeFaster(date,years);
    cout << "12-Adding 10 decade (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneCentury(date);
    cout << "13-Adding one century is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = increaseDateByOneMillennium(date);
    cout << "14-Adding one millennium is: " << date.day << "/" << date.month << "/" << date.year << endl;











    cout << endl << endl << endl;
    return 0;
}