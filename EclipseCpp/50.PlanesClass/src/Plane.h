#ifndef PLANE_H_
#define PLANE_H_

#endif /* PLANE_H_ */

using namespace std;

class Plane
{
	private:
		string m_sMaker;
		string m_sModel;
		int m_iYear;
		float m_fAverageFuelWind = 23.7;
		float m_fAverageFuelAganstWind = 46.8;

	public:

		Plane(string maker, string model, int year)
		{
			setMaker(maker);
			setModel(model);
			setYear(year);
		}

		void setMaker(string sMaker)
		{
			m_sMaker = sMaker;
		}

		string getMaker()
		{
			return m_sMaker;
		}

		void setModel(string sModel)
		{
			m_sModel = sModel;
		}

		string getModel()
		{
			return m_sModel;
		}

		void setYear(int iYear)
		{
			if(iYear > 0)
			{
				m_iYear = iYear;
			}
			else
			{
				m_iYear = 1950;
			}

		}

		int getYear()
		{
			return m_iYear;
		}

		float costFuel(int kilometers, char wind)
		{
			if(wind == 'y')
			{
				return kilometers * m_fAverageFuelAganstWind;
			}
			if(wind == 'n')
			{
				return kilometers * m_fAverageFuelWind;
			}

			return m_fAverageFuelWind;

		}
};
