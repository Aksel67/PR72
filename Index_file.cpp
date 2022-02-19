#include "Index_file.hpp"

using namespace std;

Index_file::Index_file(){
}

Index_file::~Index_file(){

}


void Index_file::write_index_entry(const struct index_entry &entry, uint32_t offset, string tablePath){
    tablePath += "index_file";

    ofstream file;
    file.open(tablePath, fstream::app);
    file << bitset<8>(entry.isActive).to_string()
        << bitset<32>(entry.position).to_string()
        << bitset<16>(entry.length).to_string();

    file.close();

}

//index_entry Index_file::get_index_entry(uint32_t position){}

