
#ifndef STUDENT_H_
#define STUDENT_H_

#endif /* STUDENT_H_ */

using namespace std;

class Student
{
	private:

		string m_sStudentName;
		int m_iNumber;

	public:

		Student(string studentName, int number)
		{
			setStudentName(studentName);
		}

		void setStudentName(string name)
		{
			m_sStudentName = name;
		}

		string getStudentName()
		{
			return m_sStudentName;
		}

		void setStudentNumber(int number)
		{
			m_iNumber = number;
		}

		int getStudentNumber()
		{
			return m_iNumber;
		}


};
