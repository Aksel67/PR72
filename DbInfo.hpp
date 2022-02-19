#ifndef DBINFO_H
#define DBINFO_H
#pragma once
 
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class DbInfo
{
	private:
        string currentDB;

    protected:

	public:

        DbInfo();
        ~DbInfo();
        void setDbPath(const string& path);
        string getDbPath();
        
};
#endif