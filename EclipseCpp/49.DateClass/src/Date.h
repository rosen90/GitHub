#ifndef DATE_H_
#define DATE_H_

#endif /* DATE_H_ */

using namespace std;

class Date
{
	private:
		int m_iDay;
		int m_iMonth;
		int m_iYear;

	public:
		Date(int day, int month, int year)
		{
			setDay(day);
			setMonth(month);
			setYear(year);
		}

		void setDay(int sDay)
		{
			if(sDay > 0 && sDay <= 31)
			{
				m_iDay = sDay;
			}
			else
			{
				cout << "Incorrect day" << endl;
				m_iDay = 1;
			}
		}

		int getDay()
		{
			return m_iDay;
		}

		void setMonth(int sMonth)
		{
			if(sMonth > 0 && sMonth <= 12)
			{
				m_iMonth = sMonth;
			}
			else
			{
				cout << "Incorrect month" << endl;
				m_iMonth = 1;
			}
		}

		int getMonth()
		{
			return m_iMonth;
		}

		void setYear(int sYear)
		{
			if(sYear > 0)
			{
				m_iYear = sYear;
			}
			else
			{
				cout << "Incorrect year" << endl;
				m_iYear = 1;
			}
		}

		int getYear()
		{
			return m_iYear;
		}

		void displayDate()
		{
			cout << m_iDay << "/" << m_iMonth << "/" << m_iYear << endl;
		}
};
