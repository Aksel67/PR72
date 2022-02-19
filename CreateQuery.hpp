#ifndef CREATEQUERY_H
#define CREATEQUERY_H
#pragma once

#include "SqlQuery.hpp"
#include "Definition_file.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include "DbInfo.hpp"
#include "Index_file.hpp"
#include <bitset>

using namespace std;

class CreateQuery : public SqlQuery
{
	private:
        string* table;
        vector<string>* type = new vector<string>();
        vector<string>* champs = new vector<string>();

    protected:

	public:

        CreateQuery();
        virtual ~CreateQuery();
        void parse(string cmd, DbInfo dbInfo) override;
        void check() override;
        void expand() override;
        void execute() override;
        
};
#endif