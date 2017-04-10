#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>

#include "matrix.h"
using namespace std;

void main(int argc, char* argv[])
{
	system("color b5");

	const int initialYear = 1869;
	string line;
	char dash;
	string author;
	int counter = 0;
	//const int maxQuotes = 2000;
	int j = 0;

	//Menu
	char replay = 'y';
	char Menu='*'; // Declares the character Menu
	string choice; //Declares the character Choice


	ifstream inData;
	//inData.open(argv[1]);

	//Reading from the file and creating the matrix instance

	Matrix weather(144, 12);
	weather.read(argv[1]);
	
	
	
	while (replay == 'y' || replay == 'Y')
	{
		
		j = 0;
		counter = 0;
		int year = 0;
		int month = 0;
		cout << "\t\t" << setw(56) << setfill(Menu) << right << "\n"; //Fill the 56 spaces with the chosen character stored in Menu
		cout << "\t\t" << Menu << "\t\t\tWelcome!" << setfill(' ') << setw(23) << Menu << endl;
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << "\t\t\t\t\t\t      " << Menu << "\n";
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";



		cout << "\t\t" << Menu << " Please choose from the following options:           " << Menu << "\n";// Prompts the user to choose one
		// of the following options
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << "\t\t" << "Year Range : 1869 - 2012" << "\t      " << Menu << endl;
		cout << "\t\t" << Menu << "\t\t" << "Month Range : 01 - 12" << "\t\t      " << Menu << endl;
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << "\t  1. Average temperature for a given year     " << Menu << "\n"//Proposition number 1
			<< "\t\t" << Menu << "\t  2. Highest temperature for a given year     " << Menu << "\n"//Proposition number 2
			<< "\t\t" << Menu << "\t  3. Average temperature for a given month    " << Menu << "\n"//Proposition number 3
			<< "\t\t" << Menu << "\t  4. Highest temperature for a given month    " << Menu << "\n"//Proposition number 4
			<< "\t\t" << Menu << "\t  5. Exit \t\t\t\t      " << Menu << "\n";//Proposition number 4
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";
		cout << "\t\t" << Menu << setw(54) << setfill(' ') << Menu << "\n";//Fill the 
		//56 spaces with the chosen character stored in Menu


		cout << "\t\t" << setw(56) << setfill(Menu) << right << "\n";
		cin >> choice; //Affects the user's input (1,2,3,or 4) to the variable Choice



		if (choice == "1")
		{
			cout << endl << "Enter the year or 0 to go back to the menu: ";
			cin >> year;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "PLEASE TYPE IN A PROPER NUMBER" << endl;
				cout << endl << "PLEASE TYPE IN A CORRECT YEAR" << endl;
				cin >> month;
			}

			while (year != 0)
			{
				while (!(year >= 1869 && year <= 2012))
				{
					cout << "ERROR PLEASE CHECK YOUR INPUT!" << endl;
					cout << endl << "Enter the year properly: ";
					cin >> year;
				}


				cout << endl << weather.avgRow(year - initialYear) << endl;
				cout << endl << "Enter the year or 0 to go back to the menu: ";
				cin >> year;

			}
			
		}
		else if (choice == "2")
		{
			
			cout << endl << "Enter the year or 0 to go back to the menu: ";
			cin >> year;

			while (year != 0)
			{
				while (!(year >= 1869 && year <= 2012))
				{
					cout << "ERROR PLEASE CHECK YOUR INPUT!" << endl;
					cout << endl << "Enter the year properly : ";
					cin >> year;
				}


				cout << endl << weather.highestForRow(year - initialYear) << endl;
				cout << endl << "Enter the year or 0 to go back to the menu: ";
				cin >> year;

			}
		}
			
		else if (choice == "3")
		{

			cout << endl << "Enter the month or 0 to go back to the menu: ";
			cin >> month;

			while (month != 0)
			{
				while (!(month >= 1 && month <= 12))
				{
					cout << "ERROR PLEASE CHECK YOUR INPUT!" << endl;
					cout << endl << "Enter the month properly: ";
					cin >> month;
				}


				cout << weather.avgCol(month - 1) << endl;
				cout << endl << "Enter the month or 0 to go back to the menu: ";
				cin >> month;

			}
		}


		else if (choice == "4")
		{
			cout << endl << "Enter the month or 0 to go back to the menu: ";
			cin >> month;

			while (month != 0)
			{
				while (!(month >= 1 && month <= 12))
				{
					cout << "ERROR PLEASE CHECK YOUR INPUT!" << endl;
					cout << endl << "Enter the month properly: ";
					cin >> month;
				}


				cout << weather.highestForCol(month - 1) << endl;
				cout << endl << "Enter the month or 0 to go back to the menu: ";
				cin >> month;

			}
		}

			
		


		else if (choice == "5")


		{
			cout << "-----------------------" << endl << endl << "Thank you for using our search service!" << endl << endl;
			return;
		}
		else
			cout << "ERROR IN INPUT PLEASE CHOOSE FROM THE MENU AGAIN " << endl << endl;
		







		/*cout << endl << "-------------------------------" << endl << endl << "Do you want to go back to the main menu?\n\n Enter y for yes, n for no: ";
		cin >> replay;
		while (!(replay == 'y' || replay == 'Y' || replay == 'n' || replay == 'N'))
		{
			cout << endl << "Incorrect input, try again ('y' or 'n'): ";//If the input is not y or n, asks for another input
			cin >> replay;
		}*/


		

	}
	cout << "-----------------------" << endl << endl << "Thank you for using our search service!" << endl << endl;
	return;
}