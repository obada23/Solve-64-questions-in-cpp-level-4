#pragma once
#include <iostream>
using namespace std;
namespace myLib
{
    

    struct stDate
    {   
        short day;
        short year;
        short month;
    };

    stDate readFullDate()
    {
        stDate date;
        date.day = readShortNumber("Please enter a day? ");
        date.month = readShortNumber("Please enter a month? ");
        date.year = readShortNumber("Please enter a year? ");
        return date;
    }

    

    int readNumber(string message)
    {
        int number;
        do
        {
            cout << message;
            cin >> number;
            cout << endl;
    
        } while (number<0);
        return number;
    }

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

    short numberOfDaysInYear(short year)
    {
        return (isLeapYear(year)) ? 366 : 365;
    }

    int numberOfHoursInYear(short year)
    {
        return (isLeapYear(year)) ? 366*24 : 365*24;
    }

    int numberOfMinutesInYear(short year)
    {
        return (isLeapYear(year)) ? 366*24*60 : 365*24*60;
    }

    int numberOfSecondsInYear(short year)
    {
        return (isLeapYear(year)) ? 366*24*60*60 : 365*24*60*60;
    }

    short numberOfDaysInMonth(short year, short month)
    {   
        if (month<1||month>12)
            return 0;
        
        short numberOfDays[] = {31,0,31,30,31,30,31,31,30,31,30,31};
        return (month==2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month-1];
    }

    int numberOfHoursInMonth(short year, short month)
    {
        return numberOfDaysInMonth(year,month)*24;
    }

    int numberOfMinutesInMonth(short year, short month)
    {
        return numberOfDaysInMonth(year,month)*24*60;
    }

    int numberOfSecondsInMonth(short year, short month)
    {
        return numberOfDaysInMonth(year,month)*24*60*60;
    }

    short dayOrderInWeaks(short year, short month, short day)
    {

        short a = ((14-month)/12);
        short y = year - a;
        short m = month + 12*a - 2;
        short d = (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

        return d;
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

    void calender(short year)
    {
        string months[13] = { "","Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

        cout << "___________________________________________________" << endl << endl;
        cout << "\t\t  Calender - " << year << endl;
        cout << "___________________________________________________" << endl << endl;

        for(int month=1;month<=12;month++)
        {
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

    stDate dateAddDays(short days,stDate date)
    {
        short remainingDays = days + numberOfDaysFromTheBeginingOfTheYear(date.year,date.month,date.day);
        short monthDays = 0;
        date.month = 1;
        while(true)
        {
            monthDays = numberOfDaysInMonth(date.year,date.month);
            if(remainingDays > monthDays)
            {
                remainingDays -= monthDays;
                date.month++;
                if(date.month > 12)
                {
                    date.month = 1;
                    date.year++;
                }
            }
            else
                break;
        
        }
        date.day = remainingDays;
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

    int getDifferenceInDays(stDate date1, stDate date2, bool includeEndDays = false)
    {
        bool check;
        if(checkIsDate1LessThanDate2(date1,date2))
            check = true;
        else
            check = false;

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
            if(date2.year < date1.year)
            {
                for(int month=1;month<=12;month++)
                {
                    result += numberOfDaysInMonth(date2.year,month);
                }
                date2.year++;
            
            }
            else if(date1.year == date2.year)
            {
                result+= numberOfDaysFromTheBeginingOfTheYear(date2.year,date2.month,date2.day) - numberOfDaysFromTheBeginingOfTheYear(date1.year,date1.month,date1.day);
                break;
            }
            
        }
        if(check)
            return includeEndDays==true ? result+1 : result;
        else
            return includeEndDays==true ? -1*(result+1) : -1*result; 
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

    stDate increaseDateByXDays(stDate date,short days)
    {
        for(short i=1;i<=days;i++)
        {
            date = increaseDateByOneDay(date);
        }
        return date;
    }

    stDate increaseDateByOneWeak(stDate date)
    {
        for(short i=1;i<=7;i++)
        {
            date = increaseDateByOneDay(date);  
        }
        return date;
    }

    stDate increaseDateByXWeeks(stDate date,short weeks)
    {
        for(short i=1;i<=weeks;i++)
        {
            date = increaseDateByOneWeak(date);
        }
        return date;
    }

    stDate increaseDateByOneMonth(stDate date)
    {

        short days = numberOfDaysInMonth(date.year,date.month);

        for(short i=1;i<=days;i++)
        {
            date = increaseDateByOneDay(date);
        }
        return date;
    }

    stDate increaseDateByXMonths(stDate date,short months)
    {
    
        for(short i=1;i<=months;i++)
        {
            date = increaseDateByOneMonth(date);
        }
        return date;
    }

    stDate increaseDateByOneYear(stDate date)
    {
        date.year++;
        return date;
    }

    stDate increaseDateByXYears(stDate date,short years)
    {
        for(short i=1;i<=years;i++)
            date = increaseDateByOneYear(date);
        return date;
    }

    stDate increaseDateByXYearsFaster(stDate date,short years)
    {
        date.year += years;
        return date;
    }

    stDate increaseDateByOneDecade(stDate date)
    {
        date.year += 10;
        return date;
    }

    stDate increaseDateByXDecade(stDate date,short decade)
    {
        for(int i=1;i<=decade;i++)
            date = increaseDateByOneDecade(date);
        return date;
    }

    stDate increaseDateByXDecadeFaster(stDate date,short decade)
    {
        date.year += 10*decade;
        return date;
    }

    stDate increaseDateByOneCentury(stDate date)
    {
        date.year += 100;
        return date;
    }

    stDate increaseDateByOneMillennium(stDate date)
    {
        date.year += 1000;
        return date;    
    }


    bool isFirstDayInMonth(stDate date)
    {
        return date.day==1;
    }

    bool isFirstMonthInYear(stDate date)
    {
        return date.month==1;
    }

    stDate decreaseDateByOneDay(stDate date)
    {
        if(isFirstDayInMonth(date))
        {
            if(isFirstMonthInYear(date))
            {
                date.year--;
                date.month=12;
                date.day=numberOfDaysInMonth(date.year,date.month);

            }
            else
            {

                date.month--;
                date.day=numberOfDaysInMonth(date.year,date.month);
            
            }
        }
            else
                date.day--;
            return date;
    }

    stDate decreaseDateByXDays(stDate date,short days)
    {
        for(short i=1;i<=days;i++)
        {
            date = decreaseDateByOneDay(date);
        }
        return date;
    }

    stDate decreaseDateByOneWeak(stDate date)
    {
        for(short i=1;i<=7;i++)
        {
            date = decreaseDateByOneDay(date);  
        }
        return date;
    }

    stDate decreaseDateByXWeeks(stDate date,short weeks)
    {
        for(short i=1;i<=weeks;i++)
        {
            date = decreaseDateByOneWeak(date);
        }
        return date;
    }

    stDate decreaseDateByOneMonth(stDate date)
    {
        if(date.month==1)
        {
            date.month=12;
            date.year--;
        }
        else
            date.month--;

        short days = numberOfDaysInMonth(date.year,date.month);

        if(date.day > days )
            date.day = days;
        return date;
    }

    stDate decreaseDateByXMonths(stDate date,short months)
    {
    
        for(short i=1;i<=months;i++)
        {
            date = decreaseDateByOneMonth(date);
        }
        return date;
    }

    stDate decreaseDateByOneYear(stDate date)
    {
        date.year--;
        return date;
    }

    stDate decreaseDateByXYears(stDate date,short years)
    {
        for(short i=1;i<=years;i++)
            date = decreaseDateByOneYear(date);
        return date;
    }

    stDate decreaseDateByXYearsFaster(stDate date,short years)
    {
        date.year -= years;
        return date;
    }

    stDate decreaseDateByOneDecade(stDate date)
    {
        date.year -= 10;
        return date;
    }

    stDate decreaseDateByXDecade(stDate date,short decade)
    {
        for(int i=1;i<=decade;i++)
            date = decreaseDateByOneDecade(date);
        return date;
    }

    stDate decreaseDateByXDecadeFaster(stDate date,short decade)
    {
        date.year -= 10*decade;
        return date;
    }

    stDate decreaseDateByOneCentury(stDate date)
    {
        date.year -= 100;
        return date;
    }

    stDate decreaseDateByOneMillennium(stDate date)
    {
        date.year -= 1000;
        return date;
    }

    bool isEndOfWeek(string dayName)
    {
        return dayName == "Satarday";
    }

    bool isWeekEnd(string dayName)
    {
        return dayName == "Friday"|| dayName == "Satarday";
    }

    bool isBusinessDay(string dayName)
    {
        return dayName!="Friday";
    }

    short daysUntilTheEndOfWeek(short day)
    {
        short count=0;
        for(int i=day;i<7;i++)
            count++;
        return count;
    }

    short daysUntilTheEndOfMonth(stDate date)
    {
        short count=0;
        short daysInCurrentMonth = numberOfDaysInMonth(date.year,date.month);
        for(short i=date.day;i<=daysInCurrentMonth;i++)
            count++;    
        return count;   
    }

    short daysUntilTheEndOfYear(stDate date)
    {
        short sumOfTheDays=0;
        for(int i=date.month;i<=12;i++)
            sumOfTheDays += numberOfDaysInMonth(date.year,date.month);
        return sumOfTheDays-date.day;
       
    }


    bool checkIsDate1AfterThanDate2(stDate date1, stDate date2)
    {
        return (!checkIsDate1LessThanDate2(date1,date2) && !checkIsDate1EqualsToDate2(date1,date2));
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

    enum enDateCompare{ Before = -1, Equal = 0, After = 1 };

    enDateCompare dateCompare(stDate date1,stDate date2)
    {
        if(checkIsDate1LessThanDate2(date1,date2))
            return Before;
        else if(checkIsDate1EqualsToDate2(date1,date2))
            return Equal;
        else
            return After;
    }

    struct stPeriod
    {
        stDate startDate;
        stDate endDate;
    };

    stPeriod readPeriod()
    {
        stPeriod period;
        cout << "Enter Start Date:\n" << endl;
        period.startDate = readFullDate();

        cout << "\nEnter End Date:\n" << endl;
        period.endDate = readFullDate();

        return period;
    
    }

    bool isOverlap(stPeriod period1, stPeriod period2)
    {
        if
        (
            dateCompare(period2.endDate,period1.startDate) == Before
            ||
            dateCompare(period2.startDate,period1.endDate) == After
        )
            return false;
        else
            return true;
    }


    short periodLengthInDays(stPeriod period,bool includeEndDays = false)
    {
        return getDifferenceInDays(period.startDate,period.endDate,includeEndDays);
    }




}