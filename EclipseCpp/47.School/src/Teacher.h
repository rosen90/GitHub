#ifndef TEACHER_H_
#define TEACHER_H_

#endif /* TEACHER_H_ */

using namespace std;

class Teacher
{
	private:
		string m_sTeacherName;
		string m_sTitle;

	public:

		Teacher(string teacherName, string title)
		{
			setTeacherName(teacherName);
		}

		void setTeacherName(string name)
		{
			m_sTeacherName = name;
		}

		string getTeacherName()
		{
			return m_sTeacherName;
		}

		void setTeacherTitle(string title)
		{
			m_sTitle = title;
		}

		string getTeacherTitle()
		{
			return m_sTitle;
		}

};
