/* Name: Thammasorn Brown
	Date: 3/8/2025
	Objective: Read names from a text file and store them in a struct, then utlize the struct across various functions to find the highest score, assign letter grades and output all student names with their relevant test info.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct studentType{
	string FName, LName;
	int testScore;
	char grade;	
};

void display(studentType* studentRecords, int& size, int& savedHighest){
	
	cout << "Test scores: \n" << endl;
	for (int i = 0; i < size; i++){	
		cout << left << studentRecords[i].LName << ", " << studentRecords[i].FName << right << setw(7) <<  studentRecords[i].testScore << "%" << " " <<  setw(1) << studentRecords[i].grade << endl;
		//cout << setw(10) << setfill(' ')  <<  "|" <<  "struct member#" << i << endl; //optional count, remove endl in first output
	}
	cout << endl <<  "Student with the highest score is: " << studentRecords[savedHighest].FName << " " << studentRecords[savedHighest].LName << " with " <<  studentRecords[savedHighest].testScore << "%" << endl;
}

//3. Assign letter grades
void letterGrade(studentType* studentRecords, int& size, int& savedHighest){

	for (int i = 0; i < size; i++){
	
		if(studentRecords[i].testScore <= 100 && studentRecords[i].testScore >= 90){
			studentRecords[i].grade = 'A';
		}
		if(studentRecords[i].testScore < 90 && studentRecords[i].testScore >= 80){
			studentRecords[i].grade = 'B';
		}
		if(studentRecords[i].testScore < 80 && studentRecords[i].testScore >= 70){
			studentRecords[i].grade = 'C';
		}
		if(studentRecords[i].testScore < 70 && studentRecords[i].testScore > 60){
			studentRecords[i].grade = 'D';
		}
		if(studentRecords[i].testScore <= 60){
			studentRecords[i].grade = 'F';
		}
	}
	
	display(studentRecords, size, savedHighest);
}

//2. Find the highest score
void highestScore(studentType* studentRecords, int& size){
	int Highest = 0, i, savedHighest;

	for (i = 0; i < size; i++){
		
		if(studentRecords[i].testScore > Highest){
		Highest = studentRecords[i].testScore;
		savedHighest = i;
		}	
	}

	letterGrade(studentRecords, size, savedHighest); //carry over the index of the highest score 
}


//1. Store data into struct
void dataEntry(){
	srand(time(0));
	int size = 20, i;
	studentType studentRecords[size];
	

	ifstream myfile("UNIT9_Data.txt");
	
	//check for errors in opening file
	if(!myfile.is_open()){
		cerr << "Error: can't open file" << endl;
	}
	
	//store First names into struct
	for (i = 0; i < size; i++){
	
		if(getline(myfile,studentRecords[i].FName)){
		}
		
	}	
	
	//store Last name into struct
	for (i = 0; i < size; i++){
		
		if(getline(myfile,studentRecords[i].LName)){
		}
	}
	
	//Randomly generate test scores between 0 - 100 for 20 students.
	for(int i = 0; i < size; i++){
		studentRecords[i].testScore = rand() % 101; 
	}
	
	myfile.close();
	
	highestScore(studentRecords, size);
}


//Call first function
int main(){
	dataEntry();

	return 0;
}
