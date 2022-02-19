#include "DropQuery.hpp"
#include "SqlQuery.hpp"

using namespace std;

DropQuery::DropQuery()
{

}

DropQuery::~DropQuery()
{
    
}

void DropQuery::parse(string cmd, DbInfo dbInfo){
    cout << "drop" << endl;

    string end = ";";
    if(cmd.find(end) != string::npos) cmd.erase(cmd.find(end), end.length());

    dbPath = dbInfo.getDbPath();

    cmd = upToUppercase(cmd);

    *element = split(cmd, " ");

}

void DropQuery::check(){

    if (element->at(1) == "TABLE" || element->at(1) == "DATABASE"){
        
    }else{
        throw "Manque le mot clé TABLE ou DATABASE";
    }
    
    
}

void DropQuery::expand(){

}

void DropQuery::execute(){
    string rmrf = "rm -rf " + dbPath;
    const char* rm;
    char* suppr;
    if(element->at(1) == "TABLE"){
        //supprimer table
        string table = element->at(2);
        rmrf += table;
        rm = rmrf.c_str();
        cout << "[INFO] table supprimée" << endl;

    }else if (element->at(1) == "DATABASE")
    {
        //supprimer database 
        rm = rmrf.c_str();
        cout << "[INFO] base de données supprimée" << endl;
    }

    system(rm);
    
}