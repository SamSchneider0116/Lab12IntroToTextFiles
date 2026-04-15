#include <iostream>
#include <fstream>
#include <string>


using namespace std;



void pressEnterToContinue();
bool readFromFile(string filename);



int main() {
	string datafile;

	cout << "Lab 12 Intro to Text Files!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);

	bool status = readFromFile(datafile);

	if (status) cout << "Success!\n";
	else cout << "failure :-(\n";

	pressEnterToContinue();
}



void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string fileName) {
	ifstream inFile;						//Input filestream for reading in our data
	string movieTitle;						//Film title
	int year;								//Year the film was released
	inFile.open(fileName);					//Attempt to open the specified text file

	if (inFile.fail()) {					//Then a problem occured, so return the bad news...
		cout << "read error - sorry\n";
		return false;
	}

	//If here, then read in data until we're done
	while (true) {
		inFile >> movieTitle >> year;
		if (inFile.fail()) break;				//then no more data to read
		
		cout << movieTitle << ": " << year << endl;

	}

	//Close the file and return
	inFile.close();
	return true;
}