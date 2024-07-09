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

short dayOrderInWeaks(short year, short month, short day)
{

    short a = ((14-month)/12);
    short y = year - a;
    short m = month + 12*a - 2;
    short d = (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

    return d;
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
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Satarday" };
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


stDate getSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm* now = localtime(&t);
    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
    
}

bool isEndOfWeek(string dayName)
{
    return dayName == "Satarday";
}

bool isWeekEnd(string dayName)
{
    return dayName == "Friday"|| dayName == "Satarday";
}

bool isBusinessDay(string dayName)
{
    return dayName!="Friday";
}

short daysUntilTheEndOfWeek(short day)
{
    short count=0;
    for(int i=day;i<7;i++)
        count++;
    return count;
}

short daysUntilTheEndOfMonth(stDate date)
{
    short count=0;
    short daysInCurrentMonth = numberOfDaysInMonth(date.year,date.month);
    for(short i=date.day;i<=daysInCurrentMonth;i++)
        count++;    
    return count;
}

short daysUntilTheEndOfYear(stDate date)
{
    short sumOfTheDays=0;
    for(int i=date.month;i<=12;i++)
        sumOfTheDays += numberOfDaysInMonth(date.year,date.month);
    return sumOfTheDays-date.day;
       
}

int main()
{system("clear");
    stDate date;
    date = getSystemDate();
    string dayN = dayName(dayOrderInWeaks(date));
    cout << "Today is " << dayN << " , " << date.day << "/" << date.month << "/" << date.year << endl << endl;

    if(isEndOfWeek(dayN))
        cout << "Yes is end of week.\n\n";
    else
        cout << "No not end of week.\n\n";

    if(isWeekEnd(dayN))
        cout << "Yes is a week end.\n\n";
    else
        cout << "No is not a week end.\n\n";

    if(isBusinessDay(dayN))
        cout << "Is it business day.\n\n";
    else
        cout << "No it is not a business day.\n\n";

    cout << "Days until end of week : " << daysUntilTheEndOfWeek(dayOrderInWeaks(date)) << " Day(s).\n";
    cout << "Days until end of month : " << daysUntilTheEndOfMonth(date) << " Day(s).\n";
    cout << "Days until end of year : " << daysUntilTheEndOfYear(date) << " Day(s).\n";

    


    cout << endl;
    return 0;
}