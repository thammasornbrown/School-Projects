/* Name: Thammasorn Brown
	Date: 3/8/2025
	Objective: Read book entries from a text file and store them into class variables.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Booktype{
	
	public:	// Can be acessed anywhere in the program
	/*	string title, author;
		int numCopies, numAuthors;
		long long int ISBN;
		double price;*/
		
	//Constructors
	Booktype() : title(""), ISBN(0), numCopies(0), price(0.0){	//default constructor
	}
	
	Booktype(string title, int ISBN, string author,double price, int numCopies) : title(title), ISBN(ISBN), author(author),price(price), numCopies(numCopies)
        {
	//loop body here
		
	}
	
	//Member functions
	void bookInfo(){
		cout << "Title: " << title << endl;
		cout << "ISBN: " << ISBN << endl;
		cout << "Author: " << author << endl;
		cout << "Price: $" << price << endl;
        cout << "Copies: " << numCopies << endl;
	}
	
	private:
		string title, author;
		int numCopies;
		long long int ISBN;
		double price;

};


int main(){
	int size = 100, i = 0;
	string line;
	int number;
	Booktype book[size];
	
	
	//Input book information from file
	ifstream myfile("Unit_10Data.txt");
	
	if (myfile.is_open()) {
		
    	while (i < size) {
    		//Declaration of member variables inside loop
    		string title, author;
    		int numCopies;
    		long long int ISBN;
   			double price;
   			
   			getline(myfile, line);
   			
            //Conditionals
            if (myfile.eof()) {
                break; 
            }
            
            if (line.find("Book ") == 0) { // Check if line starts with "Book "
                continue; // Skip this line
            }
            
            // read the data
            myfile >> ISBN >> price >> numCopies;
            
            title = line;

        	getline(myfile, title);
        	
            getline(myfile, author, '\n');
           
            
            myfile.ignore();
           
            
            book[i] = Booktype(title, ISBN, author,price, numCopies);
            i++;
        }
   	
    	cout << "index" <<  i << endl;			
        
		myfile.close();	
	
		//Print data to verify
    	for (i = 0; i < size; ++i) {
            book[i].bookInfo();
            std::cout << "--------------------" << std::endl;
        }
    
	}
	else {
    cout << "Error: Unable to open file Unit_10Data.txt" << endl;
    return 1; // Exit with an error code
	}
    
        

	return 0;
}

