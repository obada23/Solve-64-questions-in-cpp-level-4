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



int main()
{system("clear");

    stDate date1 = readFullDate();
    cout << endl;
    stDate date2 = readFullDate();
    cout << endl;

    cout << "Compare Result = " << dateCompare(date1,date2) << endl;
    
    
    cout << endl;
        
        
    

    cout << endl << endl << endl;
    return 0;
}