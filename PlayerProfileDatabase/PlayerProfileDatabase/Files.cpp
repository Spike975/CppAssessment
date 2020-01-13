#include "Files.h"

//Writes to the file
void write(string file, string add) {
	ofstream files(file);
	if (files.is_open()) {
		files << add << "\n";
		files.close();
	}
	else {
		cout << "No File as specified point";
	}
}
//Writes to the file using the player data
void write(string file, Player * p,size_t size) {
	ofstream files(file);
	if (files.is_open()) {
		for (int i = 0; i < size; i++) {
			files << p[i].getHealth() << ";";
			files << p[i].getAttack() << ";";
			files << p[i].getName();
			if (i==size-1) {
				files << '!';
			}
			else {
				files << ":";
			}
		}
		files.close();
	}
	else {
		cout << "No File as specified point";
	}
}
//Adds strings to the file on a separate line
void addTo(string file, string add) {
	string all;
	string line;
	ifstream fileI(file);
	if (fileI.is_open()) {
		while (getline(fileI, line))
		{
			all += line + '\n';
		}
		fileI.close();
		ofstream fileO(file);
		fileO << all;
		fileO << add;
		fileO.close();
	}
	else {
		cout << "no file foud\n";
	}
}
//Gets the data inside the file and returns it in a string
string getFileData(string file) {
	string s="";
	ifstream files(file);
	if (files.is_open()) {
		string line;
		while (getline(files, line))
		{
			s += line;
		}
	}
	return s;
}
//Clears the files current data
void clear(string file) {
	ofstream files(file);
	if (files.is_open()) {
		files.clear();
		files.close();
	}
	else {
		cout << "No file found\n";
	}
}
//Reads the data in the given file
void read(string file) {
	ifstream files(file);
	string line;
	if (files.is_open()) {
		while (getline(files, line))
		{
			cout << line << '\n';
		}
		files.close();
	}
	else {
		cout << "No File as specified point";
	}
}