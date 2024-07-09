#include <iostream>
using namespace std;
int readNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
        cout << endl;

    } while (number<=0);
    
    return number;
}

short dayName(short year, short month, short day)
{
    short a = (14-month)/12;
    short y = year-a;
    short m = month+(12*a)-2;
    short d = (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;
    return d;
}


int main()
{system("clear");
    string name[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    short year = readNumber("Please enter a year? ");
    short month = readNumber("Please enter a month? ");
    short day = readNumber("Please enter a day? ");
    int daysNumber = dayName(year,month,day);
    cout << "Date      : " << day << "/" << month << "/" << year << endl;
    cout << "Day Order : " << daysNumber << endl;
    cout << "Day Name  : " << name[daysNumber] << endl; 
    
    
    cout << endl;

    
    return 0;
}