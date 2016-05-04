#ifndef EMLOYEE_H_
#define EMLOYEE_H_

#endif /* EMLOYEE_H_ */

using namespace std;

class Employee
{
	private:
		string m_sFirstName;
		string m_sLastName;
		float m_fSalary;

	public:

		Employee(string firstName, string lastName, float salary)
		{
			setFirstName(firstName);
			setLastName(lastName);
			setSalary(salary);
		}

		// setter for First Name
		void setFirstName(string fName)
		{
			m_sFirstName = fName;
		}

		// getter for First Name
		string getFirstName()
		{
			return m_sFirstName;
		}

		// setter for Last Name
		void setLastName(string lName)
		{
			m_sLastName = lName;
		}

		//getter for Last Name
		string getLastName()
		{
			return m_sLastName;
		}

		//setter for salary
		void setSalary(float f_salary)
		{
			if(f_salary > 0)
			{
				m_fSalary = f_salary;
			}
			else
			{
				f_salary = 0;
				cout << "The salary cannot be less than 0" << endl;
			}

		}

		float getSalary()
		{
			return m_fSalary;
		}


};
