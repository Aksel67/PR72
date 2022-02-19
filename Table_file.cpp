#include "Table_file.hpp" 
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

//string* fileName;
//ofstream file;

using namespace std;

Table_file::Table_file()
{
    //create(fileName);
	
}


Table_file::Table_file(string fileName)
{
	
}
	
Table_file::~Table_file()
{
	
}

bool Table_file::exists(string file)
{
    ifstream ifile;
    ifile.open(file);
    if(ifile){
        return true;
    }else{
        return false;
    }
}

void Table_file::open(){

}

void Table_file::close(ofstream file){
    file.close();
}

void Table_file::create(string fileName, string directoryName){
    bool fileExist = exists(directoryName+fileName);
    if(!fileExist){
       ofstream File(directoryName+fileName); 
    }
}

vector<string> Table_file::getFile(string table){

}

Field_type_t Table_file::convert(const string& str){
    if (str == "TEXT") return TEXT;
    else if(str == "INT") return INT;
    else if(str == "PRIMARY") return PRIMARY;
    else if(str == "FLOAT") return FLOAT;
}


//split method
vector<string> Table_file::split(const string& sql, const char* delimiter){
    //const char* delimiter = " ";
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(sql);
    while(getline(tokenStream, token, *delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}