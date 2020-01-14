#include "Files.h"

int main() {

	int * size = new int;
	*size = 5;

	Player * p = new Player[*size];
	int player = 0;
	int place = 0;
	string file = "test.txt";
	string fileData = getFileData(file);
	string temp = "";
	//sets the players data based off the files data
	for (int i = 0; i < fileData.length(); i++) {
		if (fileData[i] == '!') {
			p[player].setName(temp);
			break;
		}
		else if (fileData[i] == ';') {
			if (place == 0) {
				p[player].setHealth(stoi(temp));
				place++;
				temp = "";
			}
			else {
				p[player].setAttack(stoi(temp));
				place--;
				temp = "";
			}
		}
		else if (fileData[i] == ':') {
			p[player].setName(temp);
			player++;
			temp = "";
		}
		else {
			temp += fileData[i];
		}
	}
	//prints the players data
	for (int i = 0; i < *size; i++) {
		cout << p[i].getName() << ", ";
		cout << p[i].getHealth() << ", ";
		cout << p[i].getAttack() << ".\n";
	}
	//Gives the ability to change players data and array
	while (true) {
		int tempInt = 0;

		cout << "What do you want to do?\n[1]   Change Data\n[2]   Add Players\n[3]   Delete Player\n[4]   Clear List\n[5]   Show Players\n";
		cin >> tempInt;
		if (tempInt == 1) {
			while (true) {
				cout << "[1]   Change Health\n[2]   Change Attack\n[3]   Change Name\n[4]   Done\n";
				cin >> tempInt;
				if (tempInt == 1) {
					if (size != 0) {
						cout << "Which player(out of" << size << "):\n";
						cin >> tempInt;
						if (tempInt == 1) {
							int tempHealth = 0;
							cout << "Change health to:\n";
							cin >> tempHealth;
							p[tempInt - 1].setHealth(tempHealth);
						}
						else if (tempInt == 2) {
							int tempHealth = 0;
							cout << "Change health to:\n";
							cin >> tempHealth;
							p[tempInt - 1].setHealth(tempHealth);
						}
						else if (tempInt == 3) {
							int tempHealth = 0;
							cout << "Change health to:\n";
							cin >> tempHealth;
							p[tempInt - 1].setHealth(tempHealth);
						}
						else if (tempInt == 4) {
							int tempHealth = 0;
							cout << "Change health to:\n";
							cin >> tempHealth;
							p[tempInt - 1].setHealth(tempHealth);
						}
						else if (tempInt == 5) {
							int tempHealth = 0;
							cout << "Change health to:\n";
							cin >> tempHealth;
							p[tempInt - 1].setHealth(tempHealth);
						}
						else {
							cout << "Please enter again:\n";
						}
					}
					else {
						cout << "Not enough people\n";
					}
				}
				else if (tempInt == 2) {
					cout << "Which player(out of" << size << "):\n";
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
				else if (tempInt == 3) {
					string tempName = "";
					cout << "Which player(out of" << size << "):\n";
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
		}
		else if (tempInt == 2) {
			cout << "How many players would you like to add:\n";
			cin >> tempInt;
			p = copyPlus(p, size, tempInt);
		}
		else if (tempInt == 3) {
			for (int i = 0; i < *size; i++) {
				cout << "[" << i + 1 << "]  " << p[i].getName() << ", " << p[i].getHealth() << ", " << p[i].getAttack() << ".\n";
			}
			cout << "Which Player would you like to delete?\n";
			cin >> tempInt;
			p = copySub(p, size, tempInt);
		}
		else if (tempInt == 4) {
			cout << "Are you sure?\n[1]   Yes\n[2]   No\n";
			while (true) {
				cin >> tempInt;
				if (tempInt == 1) {
					p = purgeArray(size);
					cout << "Array purged";
				}
				else if (tempInt == 2) {
					cout << "Back to start";
					break;
				}
				else {
					cout << "Enter again";
				}
			}
		}
		else if (tempInt == 5) {
			for (int i = 0; i < *size; i++) {
				cout << "[" << i + 1 << "]  " << p[i].getName() << ", " << p[i].getHealth() << ", " << p[i].getAttack() << ".\n";
			}
		}
		else {
			cout << "NOT FINISHED";
		}

	}
	write(file, p, 5);
	read(file);
	deleteArray(p);
	delete size;
	return 0;
}