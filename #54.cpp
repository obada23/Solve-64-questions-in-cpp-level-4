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

bool isWeekEnd(string dayName)
{
    return dayName == "Friday"|| dayName == "Satarday";
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

bool checkIsDate1LessThanDate2(stDate date1,stDate date2)
{
    return date1.year<date2.year ? true
    : (date1.year==date2.year ? date1.month < date2.month ? true
    : (date1.month==date2.month ? date1.day < date2.day ? true
    : false : false) : false);
}

short actucalVacationDays(stDate dateStart,stDate dateEnd)
{
    short days=0;
    while(checkIsDate1LessThanDate2(dateStart,dateEnd))
    {
        if(!isWeekEnd(dayName(dayOrderInWeaks(dateStart))))
            days++;
        dateStart = increaseDateByOneDay(dateStart);
    }
    return days;

}

int main()
{system("clear");
    
    cout << "Vacation Starts : \n";
    stDate dateStart = readFullDate();
    cout << endl;
    cout <<  "Vacation Ends :\n";
    stDate dateEnd = readFullDate();
    cout << endl;

    cout << "Vacation From : " << dayName(dayOrderInWeaks(dateStart)) << " , " << dateStart.day << "/" << dateStart.month << "/" << dateStart.year << endl;
    cout << "Vacation To : " << dayName(dayOrderInWeaks(dateEnd)) << " , " << dateEnd.day << "/" << dateEnd.month << "/" << dateEnd.year << endl << endl;

    cout << "Actucal Vacation Days Is : " << actucalVacationDays(dateStart,dateEnd) << endl << endl;




    


    cout << endl;
    return 0;
}