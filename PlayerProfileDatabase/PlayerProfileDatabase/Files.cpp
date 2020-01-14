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
//Deletes a single player
Player * copySub(Player * player, int * size, int change) {
	Player * otherPlayer = new Player[*size-1];
	for (int i = 0; i < *size-1; i++) {
		if (i < change) {
			otherPlayer[i] = player[i];
		}
		else {
			otherPlayer[i] = player[i + 1];
		}
	}
	deleteArray(player);
	*size -= 1;
	return otherPlayer;
}
//Creates a copy of the array, then adds or subtract
Player * copyPlus(Player * player, int * size, int change) {
	Player * playerTemp = new Player[*size + change];
	for (int i = 0; i < *size + change; i++) {
		if (i < *size) {
			playerTemp[i] = player[i];
		}
		else {
			playerTemp[i].setName("GENERIC_NAME");
			playerTemp[i].setAttack(0);
			playerTemp[i].setHealth(0);
		}
		
	}
	deleteArray(player);
	*size += change;
	return playerTemp;
}
//Copies the array
Player * copyArray(Player * player) {
	return player;
}
Player * purgeArray(int * size) {
	Player * player = new Player[1];
	player[0].setName("GENERIC_NAME");
	player[0].setAttack(0);
	player[0].setHealth(0);
	*size = 1;
	return player;
}
//Deletes the array of players
void deleteArray(Player * player) {
	delete[] player;
}
