/* Name: Thammasorn Brown
	Date: 3/20/2025
	Objective: Input book data from a text file into class variables and then output the book data.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

class Booktype{
	
	public:	// Can be acessed anywhere in the program
		
	//Constructors
	Booktype() : title(""), ISBN(""), price(0.0), numCopies(0){	//default constructor
	}
	
	Booktype(string title, string ISBN, string author,double price, int numCopies) : title(title), ISBN(ISBN), author(author),price(price), numCopies(numCopies)
        {
		
	}
	
	//Member functions
	void bookInfo(){
		cout << endl << "Title: " << title << endl;
		cout << "ISBN: " << ISBN << endl;
		cout << "Author: " << author << endl;
		cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Copies: " << numCopies << endl;
	}
	
	private:
		string title, author, ISBN;
		int numCopies;
		double price;

};


int main(){
	int MAX_BOOKS = 100, i = 0;
	Booktype book[MAX_BOOKS];
	int debugCount = 0;
	
   			
	//Input book information from file
	ifstream myfile("Unit_10Data.txt");
	
	if (myfile.is_open()) {
		
    	while (i < MAX_BOOKS) {
    		//Declaration of member variables inside loop
    		string title, author, ISBN;
    		int numCopies;
    		string line;
   			double price;
   			
   			getline(myfile, line);
   			
            //Conditionals
            if (myfile.eof()) {
                break; 
            }
           	
            if (!myfile.good()) {
                break;
            }

            if (line.find("Book ") == 0) { // Check if line starts with "Book "
                continue; // Skip this line
            }
        	
        	//
        	
            if (line.find("Title: ") == 0) {
                title = line.substr(7); // Extract title
                getline(myfile, line); // Read ISBN and Author line
			
			
        
           		size_t authorPos = line.find("Author: ");
                if (authorPos != string::npos) {
                    ISBN = line.substr(6, authorPos - 6);
                    author = line.substr(authorPos + 8);
                }
    		
    		 getline(myfile, line); // Read Price line
                if (line.find("Price: ") == 0) {
                    stringstream ss(line.substr(7));
                    ss >> price;
                }

                getline(myfile, line); // Read Copies line
                if (line.find("Copies: ") == 0) {
                    stringstream ss(line.substr(8));
                    ss >> numCopies;
                }
                
                
            book[i] = Booktype(title, ISBN, author,price, numCopies);
            book[i].bookInfo();
            std::cout << "--------------------" << std::endl;
                  
        }
           
           
            
            
            i++;
           
            
        }
   	
    				
        
		myfile.close();	
	
		//Print data to verify
    /*	for (i = 0; i < MAX_BOOKS; i++) {
            book[i].bookInfo();
            std::cout << "--------------------" << std::endl;
        }
    */
    
	}
	else {
    cout << "Error: Unable to open file Unit_10Data.txt" << endl;
    cout << "Possible issues:" << endl << "1. File is not in same directory as program" << endl << "2. File extension is not txt" << endl;
    return 1; // Exit with an error code
	}
    
        

	return 0;
}
