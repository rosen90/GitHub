#ifndef CLASSES_H_
#define CLASSES_H_


#endif /* CLASSES_H_ */

using namespace std;

class Classes
{
	private:

		string m_sClass;

	public:

		Classes(string className)
		{
			setClass(className);
		}

		void setClass(string nameOfClass)
		{
			m_sClass = nameOfClass;
		}

		string getClass()
		{
			return m_sClass;
		}
};
