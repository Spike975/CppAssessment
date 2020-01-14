#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
using namespace std;

void write(string file, string add);
void write(string file, Player * p,size_t size);
void clear(string file);
void addTo(string file, string add);
void read(string file);
string getFileData(string file);

Player * copyArray(Player * player);
Player * copySub(Player * player, int * size, int change);
Player * purgeArray(int * size);
Player * copyPlus(Player * player, int * size, int change);
void deleteArray(Player * player);
