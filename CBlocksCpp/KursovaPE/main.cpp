#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;


/* BASE CLASS COMPOMENT */
class Component {

friend class Capacitor;

static const int LENGHT = 50;
static const int uLENGHT = 5;

private:
    int id;
	int number;
	char name[LENGHT];
	int value;
	char unit[uLENGHT];

public:
Component(int id, int numberOfComponent, string nameOfComponent, int valueOfComponent, string unitOfComponent);

~Component();

friend ostream &operator<<(ostream &, const Component &);

string getName();
void setName(string name);

int getNumber();
void setNumber(int number);

string getUnit();
void setUnit(string unit);

int getValue();
void setValue(int value);

int getId();
void setId(int id);
};

Component::Component(int id = -1 , int numberOfComponent = 0, string nameOfComponent = "",
        int valueOfComponent = 0, string unitOfComponent = "")
{
    setId(id);
    setNumber(numberOfComponent);
    setName(nameOfComponent);
    setValue(valueOfComponent);
    setUnit(unitOfComponent);

}
Component::~Component()
{
}

ostream &operator<<(ostream &output, Component &comp )
{
    output << comp.getId() <<
    "\t\t" << comp.getNumber() <<
    "\t\t" << comp.getName() <<
    "\t\t" << comp.getValue() <<
    "\t\t" << comp.getUnit() << endl;

    return output;
}
/* GETTERS AND SETTERS */
string Component::getName()  {
	return name;
}

void Component::setName(string name) {
	int length = name.size();
	length = (length < LENGHT ? length : LENGHT - 1);
	name.copy(this->name, length);
	this->name[length] = '\0';
}

int Component::getNumber()  {
	return number;
}

void Component::setNumber(int number) {
	this->number = number;
}

string Component::getUnit()  {
	return unit;
}

void Component::setUnit(string unit) {
	int length = unit.size();
	length = (length < uLENGHT ? length : uLENGHT - 1);
	unit.copy(this->unit, length);
	this->unit[length] = '\0';
}

int Component::getValue()  {
	return value;
}

void Component::setValue(int value) {
	this->value = value;
}

int Component::getId() {
    return id;
}

void Component::setId(int id) {
    this->id = id;
}

class Capacitor : public Component {

static const int LENGHT = 50;

private:
    char country[LENGHT];
    float price;

public:
    Capacitor(int id = -1, int numberOfComponent = 0, string nameOfComponent = "" ,
        int valueOfComponent = 0, string unitOfComponent = "", string country = "", float price = 0.0);
    ~Capacitor();

friend ostream &operator<<(ostream &, const Capacitor &);

    string getCountry();
    void setCountry(string country);

    float getPrice();
    void setPrice(float price);
};

Capacitor::Capacitor(int idOfComponent ,int numberOfComponent, string nameOfComponent,
        int valueOfComponent, string unitOfComponent, string country, float price) : Component (idOfComponent,numberOfComponent, nameOfComponent,
               valueOfComponent, unitOfComponent)
   {
        setCountry(country);
        setPrice(price);
   }

Capacitor::~Capacitor()
{
}

ostream &operator<<(ostream &output, Capacitor &cap )
{
    output << cap.getId() <<
    "\t\t" << cap.getNumber() <<
    "\t\t" << cap.getName() <<
    "\t\t" << cap.getValue() <<
    "\t\t" << cap.getUnit() <<
    "\t\t" << cap.getCountry() <<
    "\t\t" << cap.getPrice() << endl;

    return output;
}

string Capacitor::getCountry()
{
    return country;
}

void Capacitor::setCountry(string country)
{
    int length = country.size();
	length = (length < LENGHT ? length : LENGHT - 1);
	country.copy(this->country, length);
	this->country[length] = '\0';
}

float Capacitor::getPrice()
{
    return price;
}

void Capacitor::setPrice(float price)
{
    this->price = price;
}

void initializeFile(fstream &);
void insertItem(fstream &);
void deleteItem(fstream &);
void showInformation(fstream &);
void showSpecInfo(fstream &);
int instructions();

int main()
{
    int choice;

    fstream file("Components.dat", ios::in | ios::out);

    void (*f[])(fstream & ) = {insertItem, deleteItem, showInformation, showSpecInfo};

    if(!file)
    {
        cout << "File could not be open!" << endl;
        exit(1);
    }

    initializeFile(file);
   //insertItem(file);
    //deleteItem(file);

   // Component object(1, 2, "Diod", 12, "F");
    //cout << object;


    //showInformation(file);

    while((choice = instructions()) != 5)
    {
        ( *f[choice - 1]) (file);
        file.clear();
    }

    return 0;
}

int instructions()
{
    int choice;

    cout << "\nEnter a choice:\n1 Insert an item."
            << "\n2.Delete an item." << "\n3.Show all items."
            <<"\n4.Show specific items." << "\n5.End program.\n";

    do
    {
        cout << "\nPlease, enter your choice: ";
        cin >> choice;
    }
    while(choice < 1 || choice > 5);

    return choice;
}

void showInformation(fstream &fRef)
{
    Capacitor temp;

    cout << "Id" << "\t\tNumber" << "\t\tName"
        << "\t\tValue" << "\t\tUnit" << "\t\tCountry" << "\t\tPrice" << endl;

        for(int counter = 0; counter <= 100 && !fRef.eof(); counter++)
        {
            fRef.seekg(counter * sizeof(Capacitor)); //seekg tyrsi i namira baita ot koito zapochva da zapisva(0,1,2 .. )
            fRef.read(reinterpret_cast< char * >(&temp), sizeof(Capacitor));

            if(temp.getId() >= 0 && temp.getId() <= 100)
            {
                cout << temp;
            }
        }
}

void initializeFile(fstream &fRef)
{
    Capacitor blankItem;

    for(int i = 0; i <= 100; i++)
    {
        fRef.write(reinterpret_cast< char * >(&blankItem), sizeof(Capacitor));
    }
}

void insertItem(fstream &fRef)
{
    Capacitor temp;

    int id;
    int number;
    string name;
    int value;
    string unit;
    string country;
    float price;

    int choice;
    cout << "\n1.Standart item.\n2.Capacitor." << endl;
    cin >> choice;

    if(choice == 1)
    {
        cout << "Enter the item's id (0 - 100): ";
        cin >> id;

        fRef.seekg(id * sizeof(Capacitor));
        fRef.read(reinterpret_cast< char * >(&temp), sizeof(Capacitor));

        if(temp.getId() == -1)
        {
            cout << "Enter item's number: ";
            cin >> number;
            temp.setNumber(number);
            temp.setId(id);


            cout <<  "Enter item's name: ";
            cin.ignore();
            getline(cin,name);
            temp.setName(name);

            cout <<  "Enter item's value: ";
            cin >> value;
            temp.setValue(value);

            cout <<  "Enter item's unit: ";
            cin >> unit;
            temp.setUnit(unit);

            fRef.seekp(temp.getId() * sizeof(Capacitor));//namira reda

            fRef.write(reinterpret_cast< char * >(&temp), sizeof(Capacitor));//zapisva vyv faila

        }
        else
        {
            cout << "Cannot insert! The record contains information!\n";
        }

    }
    else
    {
        cout << "Enter the item's id (0 - 100): ";
        cin >> id;

        fRef.seekg(id * sizeof(Capacitor));
        fRef.read(reinterpret_cast< char * >(&temp), sizeof(Capacitor));

        if(temp.getId() == -1)
        {
            cout << "Enter item's number: ";
            cin >> number;
            temp.setNumber(number);
            temp.setId(id);


            cout <<  "Enter item's name: ";
            cin >> name;
            temp.setName(name);

            cout <<  "Enter item's value: ";
            cin >> value;
            temp.setValue(value);

            cout <<  "Enter item's unit: ";
            cin >> unit;
            temp.setUnit(unit);

            cout << "Enter item's country: ";
            cin >> country;
            temp.setCountry(country);

            cout << "Enter item's price: ";
            cin >> price;
            temp.setPrice(price);

            fRef.seekp(temp.getId() * sizeof(Capacitor));//namira reda

            fRef.write(reinterpret_cast< char * >(&temp), sizeof(Capacitor));//zapisva vyv faila

        }
        else
        {
            cout << "Cannot insert! The record contains information!\n";
        }
    }
}

void deleteItem(fstream &fRef)
{
    Capacitor blankItem;
    Capacitor temp;

    int id;

    cout << "Please,enter the id of the item you want to delete: ";
    cin >> id;

    fRef.seekg(id * sizeof(Capacitor));
    fRef.read(reinterpret_cast< char * >(&temp), sizeof(Capacitor));

    if(temp.getId() != -1)
    {
        fRef.seekp(id * sizeof(Capacitor));
        fRef.write(reinterpret_cast< char * >(&blankItem), sizeof(Capacitor));

        cout << "Item deleted.\n";
    }
    else
    {
        cout << "Cannot delete! The record is empty.\n";
    }
}

void showSpecInfo(fstream &fRef)
{
    Capacitor temp;
    int minRange, maxRange;

    cout << "Enter min and max value range: ";
    cin >> minRange >> maxRange;

    cout << "Id" << "\t\tNumber" << "\t\tName"
        << "\t\tValue" << "\t\tUnit" << "\t\tCountry" << "\t\tPrice" << endl;


    for(int i = 0; i <= 100 && !fRef.eof(); i++)
    {
        fRef.seekg(i * sizeof(Capacitor));
        fRef.read(reinterpret_cast< char * >(&temp),sizeof(Capacitor));

        if(temp.getValue() >= minRange && temp.getValue() <= maxRange)
        {
            cout << temp;
        }
    }
}
