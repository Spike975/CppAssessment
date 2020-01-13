#include "Files.h"

int main() {
	Player * p = new Player[5];
	int player = 0;
	int place = 0;
	string file = "test.txt";
	string fileData = getFileData(file);
	string temp="";
	//sets the players data based off the files data
	for (int i = 0; i < fileData.length();i++) {
		if (fileData[i] == '!') {
			p[player].setName(temp);
			break;
		}
		else if (fileData[i] == ';') {
			if (place == 0) {
				p[player].setHealth( stoi(temp));
				place++;
				temp = "";
			}
			else {
				p[player].setAttack(stoi(temp));
				place++;
				temp = "";
			}
		}
		else if (fileData[i] == ':') {
			p[player].setName(temp);
			player++;
			place = 0;
			temp = "";
		}
		else {
			temp += fileData[i];
		}
	}
	//prints the players data
	for (int i = 0; i < 5; i++) {
		cout << p[i].getName() << ", ";
		cout << p[i].getHealth() << ", ";
		cout << p[i].getAttack() << ".\n";
	}
	//Gives the ability to change the data of the players
	while(true) {
		int tempInt = 0;
		cout << "[1]   Change health\n[2]   Change attack\n[3]   Change name\n[4]   Done\n";
		cin >> tempInt;
		if (tempInt == 1) {
			cout << "Which player(1-5):";
			cin >> tempInt;
			if (tempInt == 1) {
				int tempHealth = 0;
				cout << "Change health to:";
				cin >> tempHealth;
				p[tempInt - 1].setHealth(tempHealth);
			}
			else if(tempInt == 2) {
				int tempHealth = 0;
				cout << "Change health to:";
				cin >> tempHealth;
				p[tempInt - 1].setHealth(tempHealth);
			}
			else if (tempInt == 3) {
				int tempHealth = 0;
				cout << "Change health to:";
				cin >> tempHealth;
				p[tempInt - 1].setHealth(tempHealth);
			}
			else if (tempInt == 4) {
				int tempHealth = 0;
				cout << "Change health to:";
				cin >> tempHealth;
				p[tempInt - 1].setHealth(tempHealth);
			}
			else if (tempInt == 5) {
				int tempHealth = 0;
				cout << "Change health to:";
				cin >> tempHealth;
				p[tempInt - 1].setHealth(tempHealth);
			}
			else {
				cout << "Please enter again:";
			}
		}
		else if (tempInt == 2) {
			cout << "Which player(1-5):";
			cin >> tempInt;
			if (tempInt == 1) {
				int tempAttack = 0;
				cout << "Change attack to:";
				cin >> tempAttack;
				p[tempInt - 1].setAttack(tempAttack);
			}
			else if (tempInt == 2) {
				int tempAttack = 0;
				cout << "Change attack to:";
				cin >> tempAttack;
				p[tempInt - 1].setAttack(tempAttack);
			}
			else if (tempInt == 3) {
				int tempAttack = 0;
				cout << "Change attack to:";
				cin >> tempAttack;
				p[tempInt - 1].setAttack(tempAttack);
			}
			else if (tempInt = 4) {
				int tempAttack = 0;
				cout << "Change attack to:";
				cin >> tempAttack;
				p[tempInt - 1].setAttack(tempAttack);
			}
			else if (tempInt == 5) {
				int tempAttack = 0;
				cout << "Change attack to:";
				cin >> tempAttack;
				p[tempInt - 1].setAttack(tempAttack);
			}
		}	
		else if(tempInt == 3) {
			string tempName= "";
			cout << "Which player(1-5):";
			cin >> tempInt;
			if (tempInt == 1) {
				cout << "Change name to:";
				cin >> tempName;
				p[tempInt - 1].setName(tempName);
			}
			else if (tempInt == 2) {
				cout << "Change name to:";
				cin >> tempName;
				p[tempInt - 1].setName(tempName);
			}
			else if (tempInt == 3) {
				cout << "Change name to:";
				cin >> tempName;
				p[tempInt - 1].setName(tempName);
			}
			else if (tempInt == 4) {
				cout << "Change name to:";
				cin >> tempName;
				p[tempInt - 1].setName(tempName);
			}
			else if (tempInt == 5) {
				cout << "Change name to:";
				cin >> tempName;
				p[tempInt - 1].setName(tempName);
			}
		}
		else if (tempInt == 4) {
			break;
		}
		else {
			cout << "Please enter again:";
		}
	}
	write(file,p,5);
	read(file);
	system("pause");
	delete[] p;
	return 0;
}