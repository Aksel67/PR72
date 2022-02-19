#include "CreateQuery.hpp"
#include "SqlQuery.hpp"
#include "DbInfo.hpp"

#include <sys/stat.h>
using namespace std;

CreateQuery::CreateQuery()
{

}

CreateQuery::~CreateQuery()
{
    
}

void CreateQuery::parse(string cmd, DbInfo dbInfo){
    dbPath = dbInfo.getDbPath();

    cmd = upToUppercase(cmd);
    vector<string> element = split(cmd, " ");

    if(element[1] == "TABLE"){
        this->table = &element[2];

        //erase tout sauf entre parentheses
        unsigned first = cmd.find("(");
        unsigned last = cmd.find_last_of(")");
        cmd = cmd.substr(first, last);
        cmd.erase(cmd.begin());
    
        //suppression de la parenthèse et du point virgule
        string end;
        string::size_type i;
        end = ")";
        i = cmd.find(end);
        if(i != string::npos) cmd.erase(i, end.length());

        end = ";";
        i = cmd.find(end);
        if(i != string::npos) cmd.erase(i, end.length());

        //split champ
        vector<string> champsList = split(cmd, ",");
        
        string currentElement;
        for (int i = 0; i < champsList.size(); i++)
        {
            //cout << champsList[i] <<endl;
            vector<string> list = split(champsList[i], " ");
            if(list[0] == "INT" || list[0] == "PRIMARY" 
                    || list[0] == "FLOAT" || list[0] == "TEXT")
            {
                type->push_back(list[0]);
            }else{
                throw "Type de colonne incorrect";
            }
            champs->push_back(list[1].c_str());
        }
    }else{
        throw "Mot clé TABLE manquant";
    }
}


void CreateQuery::check(){
    string tablePath = dbPath+*table+"/";

    
    ifstream ifile;
    ifile.open(tablePath);
    if(!ifile){
        if(mkdir(tablePath.c_str(), 0777) == -1){
            throw "Erreur dans la création de la table";
        }else{
            cout << "[INFO] Table créée" << endl;
        }
    }else{
        throw "La table existe déjà";
    }
}

void CreateQuery::expand(){

}

void CreateQuery::execute(){
    string tablePath = dbPath+*table+"/";
    Definition_file definition_file(type, champs);
    Index_file index_file;
    const vector<pair<string, Field_type_t>> &champsType = definition_file.getDefintionTable();
    for (int i = 0; i < definition_file.getDefintionTable().size(); i++)
    {
        //cout << type->at(i).c_str() << champsType[i].second << endl;
    }
    
    if(!definition_file.exists(tablePath+"definition_file")){
        definition_file.create("definition_file", tablePath);
    }else{
        definition_file.open();  
    }

    if(!index_file.exists(tablePath+"index_file")){
        index_file.create("index_file", tablePath);
    }else{
        index_file.open();  
    }

    definition_file.writeTableDefinition(champsType, tablePath);
    

}




