// Белоушко Елизавета ПИ 1 курс
// Вариант 15

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Employee.h"
using namespace std;

double calcAverageExperience(vector<Employee>& employees, int currentYear) {
	int totalExperience = 0;
	for (const auto& emp : employees) {
		totalExperience += emp.getExperience(currentYear);
	}
	if (employees.empty()) {
		return 0.0;
	}
	// static_cast<double> преобразует в double
	return static_cast<double>(totalExperience) / employees.size(); // employees.size() = количество сотрудников
}

int main() {
	setlocale(LC_ALL, "rus");

	ifstream in("Input.txt");
	ofstream out("Output.txt");

	in.open("Input.txt");
	out.open("Output.txt");
	if (!in.is_open()) {
		cout << "Невозможно открыть файл Input.txt.";
	}
	if (!out.is_open()) {
		cout << "Невозможно открыть файл Output.txt.";
	}

	vector<Employee> employees;
	int currentYear = 2024;
	double averageExperience = calcAverageExperience(employees, currentYear);

	out << "Средний стаж работы сотрудников: " << averageExperience << endl;

	in.close();
	out.close();
	system("pause");
	return 0;
}