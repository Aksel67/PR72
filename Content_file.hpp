#ifndef CONTENT_FILE_H
#define CONTENT_FILE_H
#pragma once
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdint>
#include <bitset>

#include "Table_file.hpp"
#include "Definition_file.hpp"

using namespace std;

class Content_file : public Table_file
{

    private:
    string dbPath;
    int length;

public:
    Content_file(string dbPath);
    Content_file();
    ~Content_file();
    vector<uint8_t> read_record(uint16_t length, uint32_t offset);
    void write_record(const vector<string> &record, uint32_t offset, vector<string> ordre);


};

#endif