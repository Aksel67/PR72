#include "QueryFactory.hpp" 




using namespace std;

QueryFactory::QueryFactory()
{

}

QueryFactory::~QueryFactory()
{

}

enum SQLType{
    CREATE = 1,
    SELECT = 2,
    UPDATE = 3,
    DROP = 4,
};

unique_ptr<SqlQuery> QueryFactory::generateQuery(string sql){
    
    
    sql = upToUppercase(sql);
    vector<string> element = split(sql);
    auto uniqueQuery = make_unique<SqlQuery>();
    SqlQuery* t;

    if(element[0] == "CREATE"){
        uniqueQuery = make_unique<CreateQuery>();
    }else if(element[0] == "SELECT"){

    }else if(element[0] == "DROP"){
        uniqueQuery = make_unique<DropQuery>();    
    }else if(element[0] == "INSERT"){
        uniqueQuery = make_unique<InsertQuery>();
    
    }else{
        throw "Erreur de syntaxe";
    }

    return uniqueQuery;
}

string QueryFactory::upToUppercase(string sql){
    string sqlUp;
    for(auto & c: sql){
        c = toupper(c);
        sqlUp += c;
    }

    return sqlUp;
    
}

//split method
vector<string> QueryFactory::split(const string& sql){
    const char* delimiter = " ";
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(sql);
    while(getline(tokenStream, token, *delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

/*SqlQuery* QueryFactory::getQuery(int type){
    switch(type){
        case SELECT:
            query = new SelectQuery();
            break;
        case UPDATE:
            break;
        default:
            break;
    }
    return query;
}*/




