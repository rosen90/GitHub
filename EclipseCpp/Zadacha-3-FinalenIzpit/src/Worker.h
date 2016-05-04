#ifndef WORKER_H_
#define WORKER_H_

#endif /* WORKER_H_ */

using namespace std;

class Worker
{
	private:
		string m_sName;
		string m_sFamilyName;
		string m_sEGN;
		int m_iSales;
		float m_fCommision = 4; // Const value;
		float m_fSalary;

	public:
		Worker(string name, string familyName, string egn, int sales, float salary)
			{
				setName(name);
				setFamilyName(familyName);
				setENG(egn);
				setSales(sales);
				setSalary(salary);
			}

		void setName(string sName)
		{
			m_sName = sName;
		}
		string getName()
		{
			return m_sName;
		}

		void setFamilyName(string sFamilyName)
		{
			m_sFamilyName = sFamilyName;
		}
		string getFamilyName()
		{
			return m_sFamilyName;
		}

		void setENG(string iEGN)
		{
			m_sEGN = iEGN;
		}
		string getENG()
		{
			return m_sEGN;
		}

		void setSales(int iSales)
		{
			if(iSales > 0)
			{
				m_iSales = iSales;
			}
			else
			{
				m_iSales = 0;
			}

		}
		int getSales()
		{
			return m_iSales;
		}

		float getCommision()
		{
			return m_fCommision;
		}

		void setSalary(float fSalary)
		{
			if(fSalary > 0)
			{
				m_fSalary = fSalary;
			}
			else
			{
				fSalary = 0;
			}

		}
		float getSalary()
		{
			return m_fSalary;
		}

		float calculateSalary()
		{
			float bonus = m_iSales * (m_fCommision/100);
			m_fSalary += bonus;
			return m_fSalary;
		}

		void workerInformation()
		{
			cout << "Name: " << m_sName << " " << m_sFamilyName << endl;
			cout << "EGN: " << m_sEGN << endl;
			cout << "Sales: " << m_iSales << endl;
			cout << "Commision: " << m_fCommision <<"%" <<  endl;
			cout << "Salary: " << m_fSalary << endl;

		}
};
