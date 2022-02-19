#ifndef INSERTQUERY_H
#define INSERTQUERY_H
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
#include "Content_file.hpp"
#include <sys/stat.h>
#include <bitset>

using namespace std;

class InsertQuery : public SqlQuery
{

    private:
        string* table;
        string dbPath;
        int length;
        vector<string>* values = new vector<string>();
        vector<string>* champs = new vector<string>();
        vector<string>* record = new vector<string>();
        vector<string>* ordre = new vector<string>();

    public:
        InsertQuery();
        virtual ~InsertQuery();
        void parse(string cmd, DbInfo dbInfo) override;
        void check() override;
        void expand() override;
        void execute() override;
        int fileLonger(string path);

};
#endif