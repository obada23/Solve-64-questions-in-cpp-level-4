#include <iostream>
using namespace std;

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

short dayOrderInWeaks(short year, short month, short day)
{

    short a = ((14-month)/12);
    short y = year - a;
    short m = month + 12*a - 2;
    short d = (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

    return d;
}

string dayName(short d)
{
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Satarday" };
    return days[d];
}

void calender(short year, short month)
{
    string months[13] = { "","Jan", "Feb", "Mar", "May","Apr", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

    
    cout << "______________________" << months[month] << "__________________________\n" << endl;
    cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
    int numberOfDays = numberOfDaysInMonth(year,month);
    int current = dayOrderInWeaks(year,month,1);
    
    int i;
    for(i=0;i<current;i++)
        cout << "\t";
    for(int j=1;j<=numberOfDays;j++)
    {
        cout << j << "\t";
        if(++i==7)
        {
            i=0;
            cout << endl;
        }
    }
    cout << "\n___________________________________________________\n\n\n\n";
    
        



}



int main()
{system("clear");
    short year = readShortNumber("Please enter a year? ");
    short month = readShortNumber("Please enter a month? ");
    calender(year,month);

    
     
    return 0;
}