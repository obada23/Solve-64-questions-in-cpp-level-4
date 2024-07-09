#include <iostream>
using namespace std;

enum enDateCompare{ Before = -1, Equal = 0, After = 1 };

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



bool IsvalidateDate(stDate date)
{
    return date.month<1 || date.month>12 ? false : date.day > numberOfDaysInMonth(date.year,date.month) || date.day < 1 ? false : true;
}


 
int main()
{system("clear");
    
    stDate date = readFullDate();
    cout << endl;

    if(IsvalidateDate(date))
        cout << "Yes, Date is a valide date." << endl;
    else
        cout << "No, Date is not a valide date." << endl;
    
    
    

    cout << endl << endl << endl;
    return 0;
}