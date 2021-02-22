#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() { day = month = year = 0; }
    Date(int d, int m, int y) { day = d; month = m; year = y; } 
    ~Date() {} 

    int SetDate(int d, int m, int y) 
    { 
        if ((d < 1 || d > 31) || (m < 1 || m > 12))
        {
            cout << "Incorrectly entered date!!!" << endl;
            system("pause");
            return 0;
        }
        else
            day = d; month = m; year = y;
    }
    
    void Print1() { cout << "Date in format d/m/y: " << day << "/" << month << "/" << year << " ğ." << endl; }
    void Print2() { cout << "Date in format y-m-d: " << year << "-" << month << "-" << day << endl; }

    int Bissextile(int y) { return ((y % 100 != 0) && (y % 4 == 0)) || (y % 400 == 0); }
    int DaysInMonth(int m, int y)
    {
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (Bissextile(y))
                return 29;
            else
                return 28;
            break;
        }
    }
    void DateNext()
    {
        day++;
        if (day > DaysInMonth(month, year))
        {
            day = 1;
            month++;
        }
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
};

int main()
{
    setlocale(LC_ALL,"Ukrainian");
    int day, month, year;
    Date date;
    cout << "\n" << "Enter the day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    date.SetDate(day, month, year);
    date.Print1();
    date.Print2();
    cout << "\n" << "Increment a date by one day: " << endl;
    date.DateNext();
    date.Print1();
    date.Print2();
    system("pause");
    return 0;
}