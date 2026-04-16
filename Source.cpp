#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;



void pressEnterToContinue();
bool readFromFile(string filename);
bool readFromCSVFile(string filename);



int main() {
	string datafile;

	cout << "Lab 12 Intro to Text Files!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);

	bool status = readFromCSVFile(datafile);

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

bool readFromCSVFile(string fileName) {
	ifstream inFile;						//Input filestream for reading in our data
	istringstream thisLine;					//One line (a record) of informaion
	string movieInfo;						//Film info
	string movieTitle;						//Film title
	string year;							//Year the film was released
	string director;						//Film director (and co-director)

	inFile.open(fileName);					//Attempt to open the specified text file
	if (inFile.fail()) {					//Then a problem occured, so return the bad news...
		cout << "read error - sorry\n";
		return false;
	}

	//Read in each record of information
	//Format: Film Title, Year of Release, Director <, Co-Director>
	while (true) {
		getline(inFile, movieInfo);			//Read in one record of information
		if (inFile.fail()) break;			//Until there are no lines left
		thisLine.clear();					//Treat the record as an input stream
		thisLine.str(movieInfo);
		getline(thisLine, movieTitle, ',');	//And get first the name of the film
		getline(thisLine, year, ',');		//Followed by its year of release

		vector <string> directorList;		//We'll then use a vector
		string dir;							//to hold the name(s) of the director(s)

		while (getline(thisLine, dir, ','))
			directorList.push_back(dir);

		director = directorList[0];			//There is always at least one director
		for (int i = 1; i < directorList.size(); i++) {
			director = director + " and " + directorList[i];
		}

		cout << movieTitle << " is a " << year << " film directed by " << director << endl;

	}

	//Close the file and return
	inFile.close();
	return true;

}