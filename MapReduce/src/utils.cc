#include <iostream>
#include <experimental/filesystem>
#include "utils.h"

void deleteDirectoryContents(const string& dir_path)
{
    for (const auto& entry : experimental::filesystem::directory_iterator(dir_path)) 
        experimental::filesystem::remove_all(entry.path());
};

vector<KeyValue> WCMap(string value) {
    cout << value <<endl;
    vector <KeyValue> ret;

    return ret;
};

string WCReduce(string key, vector<string> values){
    string ret;

    return ret;
};

vector<string> getShards(string path) {
    vector<string> ret;
    for (auto & entry : experimental::filesystem::directory_iterator(path)) {
        //cout << entry.path() << endl;
        ret.push_back(entry.path());
    }
    return ret;
}

string getFileNameFromPath(string path, string sep , bool removeExtension ) {
    string name = path.substr(path.find_last_of(sep)+1);
    if (removeExtension) {
        name = name.substr(0,name.find_first_of("."));
    }
    return name;
}