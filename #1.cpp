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
    } while (number<0);
    
    return number;
}

string numberToText(int number)
{
    if(number == 0)
        return "";
    else if(number>0 && number <20)
    {
        string arr[] = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Elven", "Twelve", "thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventen", "Eighteen", "Nineteen"};
        return arr[number] + " ";
    }

    else if(number >=20 && number < 100)
    {
        string arr[] = {"","","Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[number/10] + " " + numberToText(number%10);
    }
    
    else if(number >=100 && number <200)
    {
        return "One Hundred " + numberToText(number%100);
    }

    else if(number >=200 && number <=999)
    {
        return numberToText(number/100) + "Hundreds " + numberToText(number%100);
    }

    else if(number >=1000 && number <2000)
    {
        return "One Thousand " + numberToText(number%1000);
    }

    else if(number >=2000 && number <1000000)
    {
        return numberToText(number/1000) + "Thousands " + numberToText(number%1000);
    }

    else if(number >= 1000000 && number < 2000000)
    {
        return "One Million " + numberToText(number%1000000);
    }
    else if(number >=2000000 && number <1000000000)
    {
        return numberToText(number/1000000) + "Millions " + numberToText(number%1000000);
    }
    else if(number >=1000000000 && number <2000000000)
    {
        return "One Billion " + numberToText(number%1000000000);
    }
    else
    {
        return numberToText(number/1000000000) + "Billions " + numberToText(number%1000000000);
    }
    return "";

}

int main()
{system("clear");
    cout << numberToText(readNumber("Enter a Number? ")) << endl<<endl;
    
    return 0;
}