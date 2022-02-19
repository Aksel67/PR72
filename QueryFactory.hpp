#ifndef QUERYFACTORY_H
#define QUERYFACTORY_H
#pragma once

#include <iostream>
#include <stdio.h>
#include "SqlQuery.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "SelectQuery.hpp"
#include "CreateQuery.hpp"
#include <memory>
#include <vector>
#include <sstream>
#include <ostream>
#include "DropQuery.hpp"
#include "InsertQuery.hpp"

using namespace std;

class QueryFactory  
{
	private:
        string* type = NULL;

	public:

        QueryFactory();
        ~QueryFactory();
        SqlQuery* query = NULL;
        enum SQLType{};
        SqlQuery* getQuery(int type);
        unique_ptr<SqlQuery> generateQuery(string sql);
        string upToUppercase(string sql);
        vector<string> split(const string& sql);

};
#endif