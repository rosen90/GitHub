/*УСЛОВИЕ:
Да се дефинира базов клас за електронни компоненти зададени с номенклатурен номер, наименование (например — съпротивление, кондензатор и т.н.),
стойност (например 50,100 и т.н.) и мерна единица (pF, oM и т.н.) и производен клас за конкретен електронен компонент зададен с държава производител
и цена. Класовете да включват конструктори, деструктори и член функции за извеждане. Да се добавят и изтриват елементи. Да се намерят кондензаторите,
които имат стойност в зададени граници и да се изведе на екрана информацията за тези обекти.
Да се предефинира операцията <<, която да се използва за извеждане на данните. Данните да се съхраняват във файл.*/


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
friend class Diode;

static const int LENGHT = 50;
static const int uLENGHT = 5;

private:
    int id;
	int number;
	char name[LENGHT];
	int value;
	char unit[uLENGHT];

public:
Component(int idOfComponent, int numberOfComponent, string nameOfComponent, int valueOfComponent, string unitOfComponent);

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
    cout << fixed << showpoint;
    cout << left << setw(3) << comp.getId() << "  " << left << setw(10) << comp.getNumber() << left << setw(30) << comp.getName() << left << setw(10) <<
            comp.getValue() << left << setw(10) << comp.getUnit() <<  endl;

    return output;
}

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

    cout << fixed << showpoint;
    cout << left << setw(3) << cap.getId() << "  " << left << setw(10) << cap.getNumber() << left << setw(30) << cap.getName() << left << setw(10) <<
            cap.getValue() << left << setw(10) << cap.getUnit() << left << setw(20) << cap.getCountry() << left << "  " << setprecision(2) << cap.getPrice()  << endl;

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

class Diode : public Component
{
    static const int LENGHT = 50;

private:
    char diodeCountry[LENGHT];
    float diodePrice;

public:
    Diode(int id = -1, int numberOfComponent = 0, string nameOfComponent = "" ,
        int valueOfComponent = 0, string unitOfComponent = "", string diodeCountry = "", float diodePrice = 0.0);
    ~Diode();

friend ostream &operator<<(ostream &, const Capacitor &);

    string getDiodeCountry();
    void setDiodeCountry(string country);

    float getDiodePrice();
    void setDiodePrice(float price);
};

Diode::~Diode()
{
}

ostream &operator<<(ostream &output, Diode &diode )
{

     cout << fixed << showpoint;
     cout << left << setw(3) << diode.getId() << "  " << left << setw(10) << diode.getNumber() << left << setw(30) << diode.getName() << left << setw(10) <<
            diode.getValue() << left << setw(10) << diode.getUnit() << left << setw(20) << diode.getDiodeCountry() << left << "  " << setprecision(2) << diode.getDiodePrice()  << endl;

    return output;
}

string Diode::getDiodeCountry()
{
    return diodeCountry;
}

void Diode::setDiodeCountry(string diodeCountry)
{
    int length = diodeCountry.size();
	length = (length < LENGHT ? length : LENGHT - 1);
	diodeCountry.copy(this->diodeCountry, length);
	this->diodeCountry[length] = '\0';
}

float Diode::getDiodePrice()
{
    return diodePrice;
}

void Diode::setDiodePrice(float diodePrice)
{
    this->diodePrice = diodePrice;
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
        cout << "? ";
        cin >> choice;
    }
    while(choice < 1 || choice > 5);

    return choice;
}

void showInformation(fstream &fRef)
{
    Capacitor temp;

    cout << setw(3) << "Id:" << "  " << left << setw(10) << "Number:" << left << setw(30) << "Name:" << left << setw(10) << "Value:" << left << setw(10) << "Unit:"
                << left << setw(20) << "Country:" << left << setw(10) <<"  Price:" << endl;

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
    cout << "\n1.Standart item.\n2.Capacitor.\n3.Diode" << endl;
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
            cin >> name;
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
    float minRange, maxRange;

    cout << "Enter min and max value range: ";
    cin >> minRange >> maxRange;

     cout << setw(3) << "Id:" << "  " << left << setw(10) << "Number:" << left << setw(30) << "Name:" << left << setw(10) << "Value:" << left << setw(10) << "Unit:"
                << left << setw(20) << "Country:" << left << setw(10) <<"  Price:" << endl;

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
