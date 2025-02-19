#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int main() {
	double principal, newPrincipal, annualinterRate, monthlyPayment, monthlyinterRate, interest;
	int months=0;
	
	//Gather user input
	cout << "Input loan amount: $";
	cin >> principal;
	cout << endl;
	cout << "Input the interest rate per year as a percentage: ";
	cin >> annualinterRate;
	cout << endl;
	cout << "Input the monthly payment amount: $";
	cin >> monthlyPayment;
	cout << endl;
	
	//Calcaute & convert monthly interest rate
	monthlyinterRate = (annualinterRate / 12.0) / 100.0;
	
	//Do the loan calculations until principal reaches 0
	while(principal > 0){
		
	interest = principal * monthlyinterRate;	// Get interest each month
	monthlyPayment = monthlyPayment - interest;  // Subtract interest from payment
    principal = principal - monthlyPayment; // Reduce principal

    
    if (monthlyPayment < interest) { // Check if monthly payment is less than interest.
        cout << "Error: Monthly payment is too low. Cannot repay loan." << endl;
        break; 
    }
    else if (principal < 0 ) { // Check if near zero
        principal = 0; // Set to exactly zero to remove negative principal
	}	
		months++;
		/*optional output to check principal each iteration/month.
		cout << "Month: " << months << endl;
    	cout << "New principal: $" << principal << endl << endl;*/	
	}
	
	//Conditional to prevent output when loop breaks from error.
	if (principal == 0 ){
	
	cout << "To repay the loan, it will take: " << months << " months." << endl;
	}
    return 0;
}
