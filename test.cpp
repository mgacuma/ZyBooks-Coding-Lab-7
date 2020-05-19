#include<string>
#include "Person.h"
#include "Employee.h"

using namespace std;



int main() {

	Person me;
	Person* meptr=&me;
	
	cout << me.getEmail() << endl << me.getPlace(5) << endl << me.getPlace(11) << endl << me.getTypeOfObj() << endl;

	

	return 0;
}