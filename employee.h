#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>
#include <fstream>

using namespace std;
/*
class Appointment{
	public:
		string clinic;
		string dateOfAppointment;
		string id;
		string nameOfPatient;
		string nameOfDoctor;
		float totalValueOfAppointment;
		Appointment(string c,string d, string p, string doc, float tot){
			clinic = c;
			dateOfAppointment = d;
			nameOfPatient = p;
			nameOfDoctor = doc;
			totalValueOfAppointment = tot;
		}
};
*/
class Employee{
	public:
		string name;
		string occupation;
		string clinic;
		Employee(string n, string o, string c){
			name = n;
			occupation = o;
			clinic = c;
		}
		
		
		void registerEmployee(){
			//cout << "Registrando funcionário...";
			ofstream file;
			
			file.open("EMPLOYEE.csv", ios::app);
			
			file << this->clinic + "," + this->occupation + "," + this->name +"\n";
			
			file.close();
		}
};

#endif
