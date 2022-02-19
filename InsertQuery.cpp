#include "InsertQuery.hpp"
#include <bitset>

using namespace std;

InsertQuery::InsertQuery(){

}

InsertQuery::~InsertQuery(){

}

void InsertQuery::parse(string cmd, DbInfo dbInfo){
    cout << "insert" << endl;
    dbPath = dbInfo.getDbPath();
    cmd.erase(std::remove(cmd.begin(), cmd.end(), ';'), cmd.end());

    vector<string> element = split(cmd, " ");
    this->table = &element[2];

    string fields = element[3];
    fields = upToUppercase(fields);
    unsigned first = fields.find("(");
    unsigned last = fields.find_last_of(")");
    fields = fields.substr(first, last);
    fields.erase(fields.begin());

    *champs = split(fields, ",");

    string value = element.at(5);
    value = upToUppercase(value);
    value.erase(std::remove(value.begin(), value.end(), '\''), value.end());
    value.erase(std::remove(value.begin(), value.end(), '('), value.end());
    value.erase(std::remove(value.begin(), value.end(), ')'), value.end());

    *values = split(value, ",");

    Definition_file definition_file;
    vector<string> definitionList = definition_file.getFile(dbInfo.getDbPath() + *table + "/");
    
    length = 0;

    for (int i = 0; i < definitionList.size(); i++){
        
        vector<string> temp = split(definitionList[i], ",");

        switch (stoi(temp[1]))
        {
        case TEXT:
            ordre->push_back("TEXT");
            length += 150;
            break;
        case INT:
            ordre->push_back("INT");
            length += 8;
            break;
        case PRIMARY:
            ordre->push_back("PRIMARY");
            length += 8;
            break;
        case FLOAT:
            ordre->push_back("FLOAT");
            length += 8;
            break;
        
        default:
            break;
        }
    }

    int size = ordre->size();
    for (int i = 0; i < size; i++)
    {
        if(champs->at(i).empty()) throw "manque un bout dans le code";
        if(values->at(i).empty()) throw "manque un bout dans le code";
        //cout << "ordre : " << ordre[i] << endl;

        record->push_back(values->at(i).c_str());
        
        
        cout << ordre->at(i).c_str() << " " << champs->at(i).c_str() << " " << values->at(i).c_str() << endl;
        //cout << "toto" << record->at(i) << endl;
    }    
}


void InsertQuery::check(){

}

void InsertQuery::expand(){
    
    
}

void InsertQuery::execute(){
    //cout << "testlength " << length << endl;
    Index_file index_file;
    index_file.ie.length = length;
    index_file.ie.isActive = true;
    index_file.ie.position = 0;
    //cout << index_file.ie.length;
    
    uint32_t offset;
    index_file.write_index_entry(index_file.ie, offset, dbPath + *table + "/");
    //cout << fileLonger(dbPath + *table + "/index_file");
    

    Content_file content_file(dbPath + *table + "/");

    content_file.write_record(*record, offset, *ordre);
}

int InsertQuery::fileLonger(string path){
    cout << path << endl;
    ifstream file(path, ios::binary);
    file.seekg(0, ios::end);
    return file.tellg();
}