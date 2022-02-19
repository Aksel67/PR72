#ifndef INDEX_FILE_H
#define INDEX_FILE_H
#pragma once
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdint>

#include "Table_file.hpp"
#include "DbInfo.hpp"

using namespace std;

class Index_file : public Table_file
{


public:

struct index_entry
    {
        bool isActive;
        uint32_t position;
        uint16_t length;
    } __attribute__((__packed__));

    index_entry ie;
    Index_file();
    ~Index_file();
    void write_index_entry(const struct index_entry &entry, uint32_t offset, string tablePath);
    //index_entry get_index_entry(uint32_t position);
};

#endif