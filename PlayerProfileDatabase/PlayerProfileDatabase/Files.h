#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
using namespace std;
using namespace std;

void write(string file, string add);
void write(string file, Player * p,size_t size);
void clear(string file);
void addTo(string file, string add);
void read(string file);
string getFileData(string file);
