#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include <string>
#include <fstream>

using namespace std;

class Doctor{
	public:
		string name;
		string occupation;
		string clinic;
		Doctor(string c, string o, string n){
			name = n;
			occupation = o;
			clinic = c;
		}
		
		void registerDoctor(){
			cout<< "registrando doutor...";
			ofstream file;
			
			file.open("DOCTORS.csv", ios::app);
			
			file << this->clinic + "," + this->occupation + "," + this->name +"\n";
			
			file.close();
		}
};

#endif
