#include<iostream>
using namespace std;

int getMonthDay(int year, int month)
{
	static const int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return arr[month];
	}
}

int main()
{
	int year, month, day;
	while(cin >> year>>month>>day)
    {
        int count = 0;
 
 for (int i = 1; i < month; i++)
   {
       count += getMonthDay(year,i);
   }
   cout << count + day << endl;
    }
   return 0;

}
