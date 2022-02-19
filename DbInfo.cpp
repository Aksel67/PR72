#include "DbInfo.hpp"

using namespace std;

DbInfo::DbInfo()
{

}

DbInfo::~DbInfo()
{
    
}

void DbInfo::setDbPath(const string& path){
    currentDB = path;
}

string DbInfo::getDbPath(){
    return currentDB;
}