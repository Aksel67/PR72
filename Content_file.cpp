#include "Content_file.hpp"

using namespace std;

Content_file::Content_file(string dbPath){
    this->dbPath = dbPath;
}

Content_file::~Content_file(){

}

vector<uint8_t> Content_file::read_record(uint16_t length, uint32_t offset){



}

void Content_file::write_record(const vector<string> &record, uint32_t offset, vector<string> ordre){

    ofstream file;
    file.open(dbPath + "content_file", fstream::app);

    for (int i = 0; i < record.size(); i++)
    {
        if(ordre[i] == "TEXT"){
            //Ajout de 0 devant la char pour arriver à 150 de longueur
            const char* c = record[i].c_str();
            for (int j = 0; j < 150-strlen(c); j++)
            {
                file << 0; 
            }
            
            file << record[i];
        }else if (ordre[i] == "FLOAT"){
            file << bitset<8>(stof(record[i])).to_string(); 
        }else{
            file << bitset<8>(stoi(record[i])).to_string();
        }
        
    }

    file.close();
    

    /*Definition_file definition_file;
    vector<string> definitionList = definition_file.getFile(dbPath + "definition_file");
    vector<string> ordre;
    length = 0;

    for (int i = 0; i < definitionList.size(); i++){
        
        vector<string> temp = split(definitionList[i], ",");

        switch (stoi(temp[1]))
        {
        case TEXT:
            ordre.push_back("TEXT");
            length += 150;
            break;
        case INT:
            ordre.push_back("INT");
            length += 8;
            break;
        case PRIMARY:
            ordre.push_back("PRIMARY");
            length += 8;
            break;
        case FLOAT:
            ordre.push_back("FLOAT");
            length += 8;
            break;
        
        default:
            break;
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
    
        cout << record.at(i);
    }*/
    
}

