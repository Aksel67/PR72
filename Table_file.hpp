#ifndef TABLE_FILE_H
#define TABLE_FILE_H
#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Field_type_t.h"

using namespace std;

class Table_file  
{
	private:
		//string fileName;

	public:
		ofstream file;

		Table_file(string fileName);
		Table_file();
		~Table_file();
		bool exists(string fileName);
		void open();
		void close(ofstream file);
		void create(string fileName, string directoryName);
		virtual vector<string> getFile(string table);
		Field_type_t convert(const string& str);
		vector<string> split(const string& sql, const char* delimiter);
};
#endif