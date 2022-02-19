#include "SqlQuery.hpp" 


using namespace std;


SqlQuery::SqlQuery(){

}

SqlQuery::~SqlQuery(){

}

void SqlQuery::parse(string cmd, DbInfo dbInfo){

}

void SqlQuery::check(){

}

void SqlQuery::expand(){

}

void SqlQuery::execute(){
    
}

string SqlQuery::upToUppercase(string sql){
    string sqlUp;
    for(auto & c: sql){
        c = toupper(c);
        sqlUp += c;
    }

    return sqlUp;
    
}

//split method
vector<string> SqlQuery::split(const string& sql, const char* delimiter){
    //const char* delimiter = " ";
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(sql);
    while(getline(tokenStream, token, *delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}