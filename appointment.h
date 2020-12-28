#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

#include <string>
#include <fstream>

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
		
		void registerAppointment(){
			ofstream appointmentFile;
			
			appointmentFile.open("APPOINTMENTS.csv", ios::app);
			
			appointmentFile << clinic + ",";
			appointmentFile << nameOfDoctor + "," + nameOfPatient + ",";
			appointmentFile << totalValueOfAppointment;
			appointmentFile << "," + dateOfAppointment + "\n";
			
			appointmentFile.close();
		}
};


#endif
