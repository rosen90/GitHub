#ifndef DISCIPLINE_H_
#define DISCIPLINE_H_


#endif /* DISCIPLINE_H_ */

using namespace std;

class Discipline
{
	private:
		string m_sDisciplineName;
		int m_iLectures;
		int m_iExercises;

	public:

		Discipline(string disciplineName, int lectures, int exercises)
		{
			setDisciplineName(disciplineName);
			setLectures(lectures);
			setExercises(exercises);
		}

		void setDisciplineName(string name)
		{
			m_sDisciplineName = name;
		}

		string getDiscliplineName()
		{
			return m_sDisciplineName;
		}

		void setLectures(int lectures)
		{
			m_iLectures = lectures;
		}

		int getLectures()
		{
			return m_iLectures;
		}

		void setExercises(int exercises)
		{
			m_iExercises = exercises;
		}

		int getExercises()
		{
			return m_iExercises;
		}
};
