#include<iostream>
using namespace std;
class Date
{
public:

	bool Isvaliddate()
	{
		if((_year<1900)||(_month>12||_month<1)||_day>Dayinmonth()||_day<1)
		{
			return true;
		}
		return false;
	}
	void print()
	{
		cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
		//cout<<"this:"<<this<<endl;
		//cout<<this->_year<<endl;
	}
	void setdate(int year=1900,int month=1,int day=1)
	{
		_year=year;
		_month=month;
		_day=day;
	}
	Date(int year=1900,int month=1,int day=1)
		/*:_year(year)
		,_month(month)
		,_day(day*/
	{
		_year=year;
		_month=month;
		_day=day;
	}
	void Tocorrectdate()
	{
		while(_day<0)
		{
			if(_month==1)
			{
				_month=12;
				_year-=1;
			}
			else
			{
				_month-=1;
				_day+=Dayinmonth();
			}
		}
		while(_day>Dayinmonth())
		{
			_day-=Dayinmonth();
			if(_month==12)
			{
				_year+=1;
				_month=1;
			}
			else
				_month+=1;
		}
	}
	Date operator=(const Date &d)
	{
		//if(this!=d._year)
	}
	Date operator+(int day)
	{
		Date d(*this);
		d._day+=day;
		d.Tocorrectdate();
		return *this;
	}
	Date operator-(int day)
	{
		Date d(*this);
		d._day=day;
		d.Tocorrectdate();
		return *this;
	}
	bool Isleapyear()
	{
		if((_year%4==0&&_year%100!=0)||(_year%400==0))
			return true;
		else
			return false;
	}

	int Dayinmonth()
	{
		int Days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(Isleapyear())
			return Days[2]+=1;
		else
			return 0;
	}


private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	
	Date date;
	//Date(2016,7,23);
	//Date(2016,7,23);
	date.setdate(2016,7,23);
	date+(12);
	date.print();
	//cout<<"&date:"<<&date<<endl;
	getchar();
	
	return 0;
}
