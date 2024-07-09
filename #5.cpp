#include <iostream>
using namespace std;
short readNumber(string message)
{
    short number;
    do
    {
        cout << message;
        cin >> number;
        cout << endl;

    } while (number<=0);
    
    return number;
}
bool isALeapYear(short year)
{
    return (year%400==0)||(year%4==0 && year%100!=0) ?  true :  false;
}

short countDaysInMonth(short year,short month)
{
    if(month==2)
        return isALeapYear(year) ? 29 : 28 ;

    short arr31Days[7] = { 1,3,5,7,8,10,12 };

    for(short i=1; i<=7; i++)
        if(arr31Days[i-1]==month)
            return 31;
    
    return 30;
}

int countHoursInMonth(short year,short month)
{
    return countDaysInMonth(year,month)*24 ;
}

int countMinutesInMonth(short year,short month)
{
   return countDaysInMonth(year,month)*24*60 ; 
}

int countSecondsInMonth(short year,short month)
{
    return countDaysInMonth(year,month)*24*60*60 ;
}

int main()
{system("clear");
    
    short year = readNumber("Please enter a year to check? ");
    short month = readNumber("Please enter a month to check? ");
    cout << "Number Of Days    in Month [" << month << "] is " << countDaysInMonth(year,month) << endl;
    cout << "Number Of Hours   in Month [" << month << "] is " << countHoursInMonth(year,month) << endl;
    cout << "Number Of Minutes in Month [" << month << "] is " << countMinutesInMonth(year,month) << endl;
    cout << "Number Of Seconds in Month [" << month << "] is " << countSecondsInMonth(year,month) << endl;
    


    
    return 0;
}