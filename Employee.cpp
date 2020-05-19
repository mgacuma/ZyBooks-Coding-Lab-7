#include<string>
#include"Employee.h"

using namespace std;

Employee::Employee() {
	salary = 0.0;
	work_email = "work@";
	cnt_sal_changes = 10;
	sal_change_rates = new double[cnt_sal_changes];
}

Employee::~Employee() {
	if (sal_change_rates != nullptr) {
		delete[] sal_change_rates;
		sal_change_rates = nullptr;
	}
}

Employee::Employee(const Employee& clone) {
	work_email = clone.work_email;
	salary = clone.salary;
	cnt_sal_changes = clone.cnt_sal_changes;

	sal_change_rates = new double[cnt_sal_changes];

	for (int i = 0; i < cnt_sal_changes; i++) {
		sal_change_rates[i] = clone.sal_change_rates[i];
	}
}

Employee Employee::operator=(const Employee& rhs) {
	Employee newEmp;

	if (this == &rhs) {
		return *this;
	}

	newEmp.cnt_sal_changes = rhs.cnt_sal_changes;

	for (int i = 0; i < cnt_sal_changes; i++) {
		sal_change_rates[i] = rhs.sal_change_rates[i];
	}

	return newEmp;
}

double Employee::getChangeRate(int i) const {
	if (i < cnt_sal_changes) {
		return sal_change_rates[i];
	}

	else return -1.0;
}

string Employee::getEmail()const {
	return work_email;
}

void Employee::setEmail(string new_email) {
	work_email = new_email;
}

string Employee::getTypeOfObj()const {
	return "Employee";
}

void mixedArray(Person**& arrayPersonEmp, int numPersons, int numEmployees) {

	arrayPersonEmp = new Person* [numPersons + numEmployees];

	for (int i = 0; i < numPersons + numEmployees; i++) {
		if (i < numPersons) {
			arrayPersonEmp[i] = new Person();
			arrayPersonEmp[i]->setEmail("personal@gmail.com");
		}
		else {
			arrayPersonEmp[i] = new Employee();
			arrayPersonEmp[i]->setEmail("work@gmail.com");
		}
	}
}

void deleteMixedArray(Person**& arrayPersonEmp, int size) {

	for (int i = 0; i < size; i++) {
		delete arrayPersonEmp[i];
	}

	delete[] arrayPersonEmp;
	arrayPersonEmp = nullptr;
}
