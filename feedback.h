#ifndef FEEDBACK_H_INCLUDED
#define FEEDBACK_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Feedback{
	public:
		string name;
		string text;
		Feedback(string n, string t){
			name = n;
			text = t;
		}
		
		void registerText(){
			ofstream textFile;
			
			textFile.open("FEEDBACKS.txt", ios::app);
			
			textFile << name + " disse: \n";
			textFile << "- " + text << '\n';
			textFile << "----------------------\n";
			textFile.close();
			 
		}
};

#endif
