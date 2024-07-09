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

int main()
{system("clear");

    stDate date1 = readFullDate();
    cout << endl;
    stDate date2 = readFullDate();
    if(checkIsDate1LessThanDate2(date1,date2))
        cout << "Yes, Date1 is Less than Date2." << endl;
    else if(!checkIsDate1LessThanDate2(date1,date2))
        cout << "No, Date1 is Not Less than Date2." << endl;

    cout << endl;



    return 0;
}