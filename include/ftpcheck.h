#ifndef FTPCHECK_H
#define FTPCHECK_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream> 

using namespace std;

//downloads file from url
void download(string fileurl, string outfilename);

//get content of the file on url
string getContent(string stringurl);

//reads version of the file on url
double getVersion(string filename);

#endif
