#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Definition_file.hpp"
#include "QueryFactory.hpp"
#include "DbInfo.hpp"

//#include "Table_file.hpp"
using namespace std;
string dValue, lValue;

void openDatabase(string databaseName){
    while(true){
        std::string cmd;
        cout << databaseName << " > ";
        const char* character = ";";
        getline(std::cin, cmd);
        
        std::string lastChar = cmd.substr(cmd.length() - 1);
        if(lastChar != ";"){
            cout << "Erreur de syntaxe" << endl;
        }else{

        
            if(cmd == "exit;"){
                cout << "Bye." << endl;
                return;
            }else{
                try{
                    DbInfo dbInfo;
                    const string& path = lValue+dValue+"/";
                    dbInfo.setDbPath(path);
                    QueryFactory queryFactory;
                    unique_ptr<SqlQuery> query = queryFactory.generateQuery(cmd);
                    query->parse(cmd, dbInfo);
                    query->check();
                    query->expand();
                    query->execute();
                }catch(const char* e){
                    cout << e << endl;
                }
                
            }
        }

    }
};

void createDirectory(string lValue, string dValue){
    string directoryName = lValue+dValue;
    if(mkdir(directoryName.c_str(), 0777) == -1){

    }else{
        cout << "[INFO] Base de données créée" << endl;     
    }

    
    
    openDatabase(dValue);
};



int main(int argc, char *argv[]){
    std::string dArg = "-d";
    std::string lArg = "-l";

    for(int i = 0; i < argc; i++){
        
        //d argument
        if(argv[i] == dArg){
            dValue = argv[i+1];            
        }

        //l argument
        if(argv[i] == lArg){
            lValue = argv[i+1];
        }
      
    }
    
    if(!lValue.empty() && !dValue.empty()){
        createDirectory(lValue, dValue);
    }

    if(lValue.empty() && !dValue.empty()){
        cerr << "argument -l manquant" << endl;
    }


    return 0;
}


