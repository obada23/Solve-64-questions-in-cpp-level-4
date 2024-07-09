#include <iostream>
using namespace std;

enum enDateCompare{ Before = -1, Equal = 0, After = 1 };

struct stDate
{   
    short day;
    short year;
    short month;
};

string readString(string message)
{
    string dateString;
    cout << message;
    cin >> dateString;
    return dateString;
}


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

vector<string> splitString(string dateString,string seperator="/")
{
    vector<string> vString;
    string word="";
    for(int i=0;i<dateString.length();i++)
    {
        if(dateString[i] != seperator[0])
        {
            word+=dateString[i];
        }
        else
        {
            vString.push_back(word);
            word="";
        }

    }
    vString.push_back(word);
    return vString;
}

stDate stringToDate(string dateString)
{
    vector<string> vString = splitString(dateString);
    stDate date;
   
    date.day = stoi(vString[0]);
    date.month = stoi(vString[1]);
    date.year = stoi(vString[2]);
    return date;
}

string dateToString(stDate date,string dilm="/")
{
    string dateString="";
    dateString = to_string(date.day) + dilm;
    dateString += to_string(date.month) + dilm;
    dateString += to_string(date.year);
    return dateString;
}


 
int main()
{system("clear");
    
    string dateString = readString("Please Enter Date dd/mm/yyyy? ");
    stDate date = stringToDate(dateString);
    cout << "\nDay : " << date.day << endl;
    cout << "Month : " << date.month << endl;
    cout << "Year : " << date.year << endl << endl;

    dateString="";
    dateString = dateToString(date);
    cout << "You Entered : " << dateString << endl;


    
    
    

    cout << endl << endl << endl;
    return 0;
}