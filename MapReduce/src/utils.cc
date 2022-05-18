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