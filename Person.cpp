#include<string>
#include"Person.h"

using namespace std;

Person::Person() {
	SSN = 0;
	name = "na";
	personalEmail = "personal@";

	cntPlaces = 10;
	placesVisited = new string[cntPlaces];

	for (int i = 0; i < cntPlaces; i++) {
		placesVisited[i] = "unknown";
	}
}

Person::~Person() {
	if (placesVisited != nullptr) {
		delete[] placesVisited;
		placesVisited = nullptr;
	}
}

Person& Person::operator=(const Person& rhs) {
	Person newPerson;

	if (this == &rhs) {
		return *this;
	}

	newPerson.cntPlaces = rhs.cntPlaces;

	for (int i = 0; i < cntPlaces; i++) {
		placesVisited[i] = rhs.placesVisited[i];
	}

	return newPerson;
}

Person::Person(const Person& clone) {
	SSN = clone.SSN;
	name = clone.name;
	personalEmail = clone.personalEmail;

	cntPlaces = clone.cntPlaces;
	placesVisited = new string[cntPlaces];

	for (int i = 0; i < clone.cntPlaces; i++) {
		placesVisited[i] = clone.placesVisited[i];
	}
}

string Person::getPlace(int i) const {
	if (i < cntPlaces) {
		return placesVisited[i];
	}

	else return "out-of-boundary";
}

string Person::getEmail() const {
	return personalEmail;
}

void Person::setEmail(string new_email){
	personalEmail = new_email;
}

string Person::getTypeOfObj() const {
	return "Person";
}



