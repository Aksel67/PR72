#ifndef DEFINITION_FILE_H
#define DEFINITION_FILE_H
#pragma once
#include "Table_file.hpp"
#include "Field_type_t.h"
#include <utility>
#include <vector>
#include "DbInfo.hpp"

class Definition_file : public Table_file
{
private:
	vector<string>* type;
	vector<string>* champs;
	

public:
	Definition_file();
	Definition_file(vector<string>* type, vector<string>* champs);
	//Definition_file(string fileName);
	~Definition_file();
	//enum field_type_t{};
	struct TableDefinition;
	vector<pair<string, Field_type_t>> getDefintionTable();
	void writeTableDefinition(const vector<pair<string, Field_type_t>> &def, string tablePath);
	vector<string> getFile(string table) override ;
};
#endif