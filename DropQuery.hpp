#ifndef DROPQUERY_H
#define DROPQUERY_H
#pragma once

#include "SqlQuery.hpp"
 
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class DropQuery : public SqlQuery
{
	private:
        vector<string>* element = new vector<string>();
        string dbPath;

    protected:

	public:

        DropQuery();
        virtual ~DropQuery();
        void parse(string cmd, DbInfo dbInfo) override;
        void check() override;
        void expand() override;
        void execute();
        
};
#endif