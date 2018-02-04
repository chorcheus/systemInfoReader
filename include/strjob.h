#ifndef STRJOB_H
#define STRJOB_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//remove spaces, double dots and newline chars
string edited(string s);

//get lines from file
vector<string> getLines(string file);

//writes vector of string to filestream
void write(ofstream & out, vector<string> lines);

//ignore every odd character in string
string notOdd(string s);

//writes corrected vector of string to filestream
void writeCorrect(ofstream & out, vector<string> lines);

//split string into vector of strings
vector<string> splitlines(string text);

#endif

