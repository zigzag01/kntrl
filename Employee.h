#pragma once
#include <string>
#include <fstream>
using namespace std;

class Employee {
private:
	string surname;
	int department;
	int year;
	string education;
public:
	Employee() {};
	Employee(string& s, int dep, int y, string& edu) :
		surname(s),
		department(dep),
		year(y),
		education(edu)
	{}

	int getExperience(int currentYear) const { // const нужен для работы emp.getExperience(currentYear)
		return currentYear - year;
	}

	friend istream& operator>>(istream& in, Employee& emp) {
		in >> emp.surname >> emp.department >> emp.year >> emp.education;
		return in;
	}
	friend ostream& operator<<(ostream& out, Employee& emp) {
		out << emp.surname << " " << emp.department << " " << emp.year << " " << emp.education;
		return out;
	}

	string getSurname()const {
		return surname;
	}
	string getEducation()const {
		return education;
	}
	int getYear()const {
		return year;
	}
	int getDepartment()const {
		return department;
	}
};