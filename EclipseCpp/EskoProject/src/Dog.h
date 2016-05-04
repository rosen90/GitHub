#include <iostream>

using namespace std;

class Dog {

public:

	Dog();
	Dog(int age, string type, bool gender);
	~Dog();

	int getAge();
	void setAge( int );

	string getType();
	void setType( string );

	bool getGender();
	void setGender( bool );

	string GetName();
	void SetName( string );

	void dogVoice();

	void fuck(Dog);
	bool isIsPregnant() const;
	void SetIsPregnant(bool isPregnant);

private:

	string name;
	int age;
	string type;
	bool gender;
	bool isPregnant;



};
