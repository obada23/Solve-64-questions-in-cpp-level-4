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

int getDifferenceInDays(stDate date1, stDate date2, bool includeEndDays = false)
{
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
        else if(date1.year == date2.year)
        {
            result+= numberOfDaysFromTheBeginingOfTheYear(date2.year,date2.month,date2.day) - numberOfDaysFromTheBeginingOfTheYear(date1.year,date1.month,date1.day);
            break;
        }
            
    }
    return includeEndDays==true ? result+1 : result;
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


int main()
{system("clear");

    cout << "Please Enter Your Date Of Birth : " << endl << endl;
    stDate date1 = readFullDate();
    cout << endl;
    stDate date2 = getSystemDate();

    cout << "Your Age Is : " << getDifferenceInDays(date1,date2) << " Day(s)." << endl;


    
    
    cout << endl;

    return 0;
}