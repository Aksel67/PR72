#include "Definition_file.hpp" 
#include <iostream>
#include <fstream>
#include "Table_file.hpp"

using namespace std;

Definition_file::Definition_file(){ }

Definition_file::Definition_file(vector<string>* type, vector<string>* champs)
{
    this->type = type;
    this->champs = champs;
}
	
Definition_file::~Definition_file()
{
	
}


vector<pair<string, Field_type_t>> Definition_file::getDefintionTable(){
    vector<pair<string, Field_type_t>> v;
    Field_type_t t;
    vector<string> &typeRef = *type;
    for (int i = 0; i < type->size(); i++)
    {
        string ty = typeRef[i];
        if(ty == "TEXT"){
            t = TEXT;
        }else if(ty == "PRIMARY"){
            t = PRIMARY;
        }else if(ty == "INT"){
            t = INT;
        }else if(ty == "FLOAT"){
            t = FLOAT;
        }
        string a = champs->at(i);
        string b = type->at(i);
        
        //v.emplace_back(make_pair(champs[i], type->at(i)));
        v.emplace_back(a, t);
    }

    return v;
    
}

void Definition_file::writeTableDefinition(const vector<pair<string, Field_type_t>> &def, string tablePath){
    ofstream file;
    file.open(tablePath+"definition_file");
    for (int i = 0; i < def.size(); i++)
    {
        file << def[i].first << "," << def[i].second << "\n";
    }
    file.close();
    
}

vector<string> Definition_file::getFile(string table){
    vector<string> content;
    ifstream DefFile(table+"definition_file");
    string output;

    while (getline(DefFile, output))
    {
        content.push_back(output);
    }
    return content;
}


