#include <iostream>
using namespace std;

class student {
    string name;
    int age;
    int phonenumber;
	string specialization;
public:
    student() :name("no name"), age(0), phonenumber(0), specialization("no specialization") {}
    student(string n, int a, int p, string spec) :name(n), age(a), phonenumber(p), specialization(spec) {}
	string getname()const
    {
        return this->name;
    }
	float getage()const
    {
        return this->age;
    }
	float getphonenumber()const
    {
        return this->phonenumber;
    }
	string getspecialization()const
    {
        return this->specialization;
    }
    void Print()const
    {
        cout << "Name :" << name << endl;
        cout << "Age :" << age << endl;
        cout << "Phone Number :" << phonenumber << endl;
        cout << "Specialization :" << specialization << endl;
    }
	student createstudent(string n, int a, int p, string spec)
	{
		student s(n, a, p, spec);
		return s;
	}
	student createstudentself()
	{
		cout << "Enter name: "; string n; cin >> n;
		cout << "Enter age: "; int a; cin >> a;
		cout << "Enter phone number: "; int p; cin >> p;
		cout << "Enter specialization: "; string spec; cin >> spec;
		student s(n, a, p, spec);
		return s;
	}


};
class aspirant: public student
{
	string themeofwork;
    float sheetswrited;
public:
    aspirant() :themeofwork("no theme"), sheetswrited(0), student() {}
    aspirant(string n, int a, int p, string spec,string theme, float s) :themeofwork(theme), sheetswrited(s), student(n, a, p, spec) {}

    void Print()const
    {
        cout << "----------------------Aspirant-----------------" << endl;
        student::Print();
		cout << "Sheets writed :" << sheetswrited << endl;
		cout << "Theme of work :" << themeofwork << endl;
    }
	aspirant createaspirant(string n, int a, int p, string spec, float s, string theme)
	{
		aspirant aspirant(n, a, p, spec,theme, s);
		return aspirant;
	}
	aspirant createaspirantofstudent(student student, float s, string theme)
	{
		aspirant a(student.getname(),student.getage(),student.getphonenumber(),student.getspecialization(), s, theme);
		
		return a;
	}
	void createaspirantself()
	{
		createstudentself();
		cout << "Enter sheets writed: "; float s; cin >> s;
		cout << "Enter theme of work: "; string theme; cin >> theme;
		aspirant a(getname(),getage(),getphonenumber(),getspecialization(), s);
		a.setthemeofwork(theme);
	}
	void setthemeofwork(string theme)
	{
		themeofwork = theme;
	}
	void setsheets(float sheets)
	{
		sheetswrited = sheets;
	}
	void writedesertation(float sheets)
	{
		cout << "Aspirant writed desertation" << endl;
		this->sheetswrited += sheets;
	}
	void writedesertationself()
	{
		cout << "Enter number of sheets writed: "; float s; cin >> s;
		this->sheetswrited += s;
	}
	void defenddesertation()
	{
		if (sheetswrited >= 500)
			cout << "Aspirant defended desertation" << endl;
		else
			cout << "Aspirant didn't defend desertation" << endl;
			cout << "wua wua wua wuuuuuuaaaaaaaaa :(" << endl;
	}
};
class passport {
	string name;
	int age;
	int phonenumber;


public:
	passport() :name("no name"), age(0), phonenumber(0) {}
	passport(string n, int a, int p) :name(n), age(a), phonenumber(p) {}
	void Print()const
	{
		cout << "Name :" << name << endl;
		cout << "Age :" << age << endl;
		cout << "Phone Number :" << phonenumber << endl;
	}
	passport createpassport(string name, int age, int phonenumber)
	{
		passport passport(name, age, phonenumber);
		return passport;
	}
	passport createpassportself()
	{
		cout << "Enter name: "; string name; cin >> name;
		cout << "Enter age: "; int age; cin >> age;
		cout << "Enter phone number: "; int phonenumber; cin >> phonenumber;
		passport passport(name, age, phonenumber);
		return passport;
	}


};
class unboardpassport: public passport
{
	bool visa;
	float number;
public:
	unboardpassport() :number(0), passport() {}
	unboardpassport(string n, int a, int p):number(0), passport(n, a, p) {}

	void Print()const
	{
		cout << "----------------------Unboard Passport-----------------" << endl;
		passport::Print();
		cout << "Number :" << number << endl;
		if (visa)
			cout << "You have a visa" << endl;
		else
			cout << "You don't have a visa" << endl;
	}
	void SetVisa(bool v)
	{
		visa = v;
	}
	void SetVisaself()
	{
		cout << "Do you have a visa?: ";string v; cin >> v;
		if (v == "yes" || v == "Yes")
			visa = true;
		else if (v == "no" || v == "No")
			visa = false;
		else
			cout << "error 404" << endl;
	}
};


int main()
{
	student student1;
	student1.createstudentself();
	student.Print();

}