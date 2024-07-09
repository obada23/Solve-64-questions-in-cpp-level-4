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




int main()
{system("clear");

    stDate date1 = readFullDate();
    cout << endl;
    stDate date2 = readFullDate();
    cout << endl;

    if(checkIsDate1AfterThanDate2(date1,date2))
        cout << "Yes, Date1 is After Date2.\n";
    else
        cout << "No, Date1 is Not After Date2.\n";
    

    cout << endl << endl << endl;
    return 0;
}