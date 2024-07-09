#include <iostream>
using namespace std;

enum enDateCompare{ Before = -1, Equal = 0, After = 1 };

struct stDate
{   
    short day;
    short year;
    short month;
};

struct stPeriod
{
    stDate startDate;
    stDate endDate;
};

short readShortNumber(string message)
{
    short number;
    do
    {
        cout << message;
        cin >> number;

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

stPeriod readPeriod()
{
    stPeriod period;
    cout << "Enter Start Date:\n" << endl;
    period.startDate = readFullDate();

    cout << "\nEnter End Date:\n" << endl;
    period.endDate = readFullDate();

    return period;
    
}

short dayOrderInWeaks(stDate date)
{
    short a = ((14-date.month)/12);
    short y = date.year - a;
    short m = date.month + 12*a - 2;
    short d = (date.day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

    return d;
}

string dayName(short d)
{
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satarday" };
    return days[d];
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

stDate increaseDateByOneDay(stDate &date)
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

bool checkIsDate1LessThanDate2(stDate date1,stDate date2)
{
    return date1.year<date2.year ? true
    : (date1.year==date2.year ? date1.month < date2.month ? true
    : (date1.month==date2.month ? date1.day < date2.day ? true
    : false : false) : false);
}

bool checkIsDate1EqualsToDate2(stDate date1,stDate date2)
{
    return date1.year==date2.year && date1.month == date2.month && date1.day == date2.day;
}

bool checkIsDate1AfterThanDate2(stDate date1, stDate date2)
{
    return (!checkIsDate1LessThanDate2(date1,date2) && !checkIsDate1EqualsToDate2(date1,date2));
}

enDateCompare dateCompare(stDate date1,stDate date2)
{
    if(checkIsDate1LessThanDate2(date1,date2))
        return Before;
    else if(checkIsDate1EqualsToDate2(date1,date2))
        return Equal;
    else
        return After;
}

bool isOverlap(stPeriod period1, stPeriod period2)
{
    if
    (
        dateCompare(period2.endDate,period1.startDate) == Before
        ||
        dateCompare(period2.startDate,period1.endDate) == After
    )
        return false;
    else
        return true;
}




int main()
{system("clear");
    
    cout << "Enter Period 1:" << endl;
    stPeriod period1 = readPeriod();

    cout << "\nEnter Period 2:" << endl;
    stPeriod period2 = readPeriod();

    if(isOverlap(period1,period2))
        cout << "\nYes, Periods Overlap" << endl;
    else
        cout << "\nNo, Periods Is Not Overlap" << endl;

    
    

    cout << endl << endl << endl;
    return 0;
}