#include "strjob.h"

string edited(string s){
    string result = "";
    for(int i(0); i!=s.size(); ++i){
        string nc; nc = s[i];
        if(nc!=" " && nc!=":" && nc!="\n") result += nc;
    }
    return result;
}

vector<string> getLines(string file){
    ifstream in;
    in.open(file.c_str());
    vector<string> lines;
    for(int i(0);i!=1;){
        string line;
        getline(in,line);
        if(in.eof()) i = 1;
        else lines.push_back(line); 
    }
    in.close();
    return lines;
}

void write(ofstream & out, vector<string> lines){
    for(int i(0); i!=lines.size();++i){
        out << lines[i] << "\n";
    }
    out << "===================\n";
}

string notOdd(string s){
    string result = "";
    for(int i(1); i<s.size(); i+=2){
        result += s[i];
    }
    return result;
}

void writeCorrect(ofstream & out, vector<string> lines){
    for(int i(2); i!=lines.size();++i){
        string text;
        text = lines[i];
        out << notOdd(text) << "\n";
    }
    out << "===================\n";
}

vector<string> splitlines(string text){
    vector<string> res;
    string a="";
    for(int i(0); i!=text.size();++i){
        if(text[i]!='\r' && text[i]!='\n') a+=text[i];
        else if(a.size()>0) {
            res.push_back(a);
            a = "";
        }
    }
    res.push_back(a);
    return res;
}
