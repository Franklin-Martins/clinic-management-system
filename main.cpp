#include <iostream>
#include <string>
#include <fstream>

#include "patient.h"
#include "doctor.h"
#include "employee.h"
#include "appointment.h"
#include "feedback.h"

using namespace std;

void registerPatient();
void registerAppointment();
void registerDoctor();
void registerEmployee();
void registerFeedback();
void deleteAppointment();
void showPatientReport();
void showClinicThatServesMore();
void showTotalOfClinic();

int main()
{
    char choice;
    
    string loginAuthenticated;
    string passwordAuthenticated;
    
    string login, password, l, p;
    
	cout << "Login: ";
	cin >> login;
	cout << '\n';
	cout << "password: ";
	cin >> password;
	
	ifstream file("login.csv");
	
	while(file.good()){
		getline(file, loginAuthenticated, ',');
		getline(file, passwordAuthenticated, '\n');
		
		l = loginAuthenticated;
		p = passwordAuthenticated;
	}
	if( l != login ){
		cout << "Usuario nao tem permissao";
		return 0;
	} 
	if(p != password){
		cout << "Usuario nao tem permissao";
		return 0;
	}else{
		system("cls");
		cout << "Bem vindo, " << login << '\n';
    do
    {
        // Prompt user to enter package
        do
        {
            cout << "\nDigite o que deseja fazer ou pressione x para sair\n" ;
			cout << "A - Cadastrar Paciente\n";
			cout << "B - Cadastrar Agendamento\n";
			cout << "C - Cadastrar Medico\n";
			cout << "D - Registrar Funcionario\n";
			cout << "E - Feedback do cliente\n";
			cout << "F - Cancelar consulta\n";
			
			cout << "G - Relatorio de paciente por unidade\n";
			cout << "H - Unidade que mais atende\n";
			cout << "I - Total de capital diaria e mensal\n";
			
            cin >> choice;
            cout << endl;

            switch (choice)
            {
                case 'a': 
                    choice = 'A'; 
                case 'A': 
                    registerPatient();
                    break;

                case 'b': 
                    choice = 'B';
                case 'B': 
                    registerAppointment();
                    break;

                case 'c': 
                    choice = 'C';
                case 'C': 
                    registerDoctor();
                    break;

				case 'd': 
                    choice = 'D';
                case 'D': 
                    registerEmployee();
                    break;
                
				case 'e': 
                    choice = 'E';
                case 'E': 
                    registerFeedback();
                    break;
                
                case 'f': 
                    choice = 'F';
                case 'F': 
                    deleteAppointment();
                    break;
                
                case 'g': 
                    choice = 'G';
                case 'G': 
                    showPatientReport();
                    break;
                
                case 'h': 
                    choice = 'H';
                case 'H': 
                    showClinicThatServesMore();
                    break;
                
                case 'i': 
                    choice = 'I';
                case 'I': 
                    showTotalOfClinic();
                    break;
                    
                case 'x':
                case 'X':
                    return 0;

                default:
                    continue;
            }

            break;
        }
        while (true);

        // Prompt user to enter another package
        cout << "Pra continuar pressione Y" << endl;
        cin >> choice;
        system("cls");
    }
    while ((choice == 'y') || (choice == 'Y'));
}
    return 0;
}

void registerPatient(){
	string clinic;
	string name;
	
	cout << "Em qual clinica voce deseja alocar o paciente? \n";
	cin >> clinic;
	cout << "Qual o nome do paciente? \n";
	cin >> name;
	
	Patient *p = new Patient(clinic, name);
	p->registerPatient();
}

void registerAppointment(){
	string clinic;
	string dateOfAppointment;
	string nameOfPatient;
	string nameOfDoctor;
	float totalValueOfAppointment;
	
	cout << "Em qual clinica voce deseja marcar a consulta? \n";
	cin >> clinic;
	
	cout << "Marcar para qual data? \n";
	cin >> dateOfAppointment;
	
	cout << "Qual o nome do paciente? \n";
	cin >> nameOfPatient;
	
	cout << "Qual o nome do doutor? \n";
	cin >> nameOfDoctor;
	
	cout << "Qual o valor da consulta? \n";
	cin >> totalValueOfAppointment;
	
	Appointment *appointment = new Appointment(clinic, dateOfAppointment, nameOfPatient, nameOfDoctor, totalValueOfAppointment);
	appointment->registerAppointment();
}

void registerDoctor(){
	string clinic;
	string ocuppation;
	string name;
	
	cout << "Em qual clinica voce deseja alocar o doutor? \n";
	cin >> clinic;
	cout << "Qual o nome do Doutor? \n";
	cin >> name;
	cout << "Qual eh a especialidade do Doutor? \n";
	cin >> ocuppation;
	
	Doctor *d = new Doctor(clinic, ocuppation, name);
	d->registerDoctor();
}

void registerEmployee(){
	string name;
	string occupation;
	string clinic;
	
	cout << "Em qual clinica voce deseja alocar o funcionario? \n";
	cin >> clinic;
	cout << "Qual o nome do funcionario? \n";
	cin >> name;
	cout << "Qual eh a ocupacao do funcionario? \n";
	cin >> occupation;
	
	Employee *e = new Employee(name, occupation, clinic);
	e->registerEmployee();
}

void registerFeedback(){
	string name;
	string text;
	
	cout << "Qual o nome do cliente, pode colocar anonimo caso queira? ";
	cin >> name;
	cout << "Digite o comentario: ";
	while(getline(cin, text)){
		if(text != ""){
			break;
		}
	}
	
	Feedback *f = new Feedback(name, text);
	f->registerText();
}
void deleteAppointment(){
	string clinicSelected;
	string dateOfAppointmentSelected;
	string nameOfPatientSelected;
	string nameOfDoctorSelected;
	
	cout << "Em qual clinica voce deseja cancelar a consulta? \n";
	cin >> clinicSelected;
	
	cout << "Qual eh a data da consulta? \n";
	cin >> dateOfAppointmentSelected;
	
	cout << "Qual o nome do paciente? \n";
	cin >> nameOfPatientSelected;
	
	cout << "Qual o nome do doutor? \n";
	cin >> nameOfDoctorSelected;
	
	ifstream file("APPOINTMENTS.csv");
	ofstream appointmentFile;
	
	if (!file.is_open()) std::cout << "Error, arquivo nao pode ser aberto" << '\n';
	
	string nameOfPatient, nameOfDoctor, dateOfAppointment, clinic, price;
	
	while(file.good()){
		getline(file, clinic, ',');
		getline(file, nameOfDoctor, ',');
		getline(file, nameOfPatient, ',');
		getline(file, price, ',');
		getline(file, dateOfAppointment, '\n');
		
		if( (clinic != clinicSelected) && (nameOfDoctor != nameOfDoctorSelected) && (nameOfPatient != nameOfPatientSelected) && (dateOfAppointment != dateOfAppointmentSelected) ){
			appointmentFile.open("NEWAPPOINTMENTS.csv", ios::app);
			appointmentFile << clinic + ",";
			appointmentFile << nameOfDoctor + "," + nameOfPatient + ",";
			appointmentFile << price;
			appointmentFile << "," + dateOfAppointment + "\n";
			appointmentFile.close();
		}
	}
	
	file.close();
}
void showPatientReport(){
	ifstream file("PATIENTS.csv");
	
	if (!file.is_open()) std::cout << "Error, arquivo nao pode ser aberto" << '\n';
	
	string name;
	string clinic;
	
	while(file.good()){
		getline(file, clinic, ',');
		getline(file, name, '\n');
		
		cout << "Clinica: " << clinic << '\n';
		cout << "Nome: " << name << '\n';
		cout<< "------------\n";
	}
	
	file.close();
}

void showClinicThatServesMore(){
	string clinicSelected;
	cout << "Digite a clinica que deseja ver: ";
	cin >> clinicSelected;
	ifstream file("APPOINTMENTS.csv");
	
	if (!file.is_open()) std::cout << "Error, arquivo nao pode ser aberto" << '\n';
	
	string clinic;
	string nameOfDoctor;
	string nameOfPatient;
	string price;
	string dateOfAppointment;
	
	while(file.good()){
		getline(file, clinic, ',');
		getline(file, nameOfDoctor, ',');
		getline(file, nameOfPatient, ',');
		getline(file, price, ',');
		getline(file, dateOfAppointment, '\n');
		
		if(clinicSelected == clinic){
			cout << "Clinica: " << clinic << '\n';
			cout << "Nome: " << nameOfPatient << '\n';
			cout << "Doutor: " << nameOfDoctor << '\n';
			cout << "Data: " << dateOfAppointment << '\n';
			cout << "Valor: " << price << '\n';
			cout<< "------------\n";
		}
	}
}

void showTotalOfClinic(){
	double total;
	double temp;
	string clinicSelected;
	cout << "Digite a clinica que deseja ver: ";
	cin >> clinicSelected;
	ifstream file("APPOINTMENTS.csv");
	
	if (!file.is_open()) std::cout << "Error, arquivo nao pode ser aberto" << '\n';
	
	string clinic;
	string nameOfDoctor;
	string nameOfPatient;
	string price;
	string dateOfAppointment;
	
	while(file.good()){
		getline(file, clinic, ',');
		getline(file, nameOfDoctor, ',');
		getline(file, nameOfPatient, ',');
		getline(file, price, ',');
		getline(file, dateOfAppointment, '\n');
		
		if(clinicSelected == clinic){
			cout << "Valor: " << price << '\n';
			cout<< "------------\n";
			
		}
	}
	file.close();
}
