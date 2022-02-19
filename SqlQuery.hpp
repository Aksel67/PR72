#ifndef SQLQUERY_H
#define SQLQUERY_H
#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DbInfo.hpp"

using namespace std;

class SqlQuery 
{
	private:

	public:

        SqlQuery();
        ~SqlQuery();
        virtual void parse(string cmd, DbInfo dbInfo);
        virtual void check();
        virtual void expand();
        virtual void execute();

        string upToUppercase(string sql);
        vector<string> split(const string& sql, const char* delimiter);

protected:
        string dbPath;        
};
#endif