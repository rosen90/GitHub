
#ifndef SCHOOL_H_
#define SCHOOL_H_


#endif /* SCHOOL_H_ */

using namespace std;

class School
{
	private:

		string m_sSchoolName;

	public:

		School(string schoolName)
		{
			setSchoolName(schoolName);
		}

		void setSchoolName(string name)
		{
			m_sSchoolName = name;
		}

		string getSchoolName()
		{
			return m_sSchoolName;
		}


};
