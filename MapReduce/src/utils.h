#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector> 
#include <string>
using namespace std;

class KeyValue {
    public:
        string Key;
        string Value;
};

template < class T >
ostream& operator << (ostream& os, const vector<T>& v) 
{
    os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << "|" << *ii;
    }
    os << "]";
    return os;
};

void deleteDirectoryContents(const string& dir_path);

vector<KeyValue> WCMap(string value);

string WCReduce(string key, vector<string> values);

vector<string> getShards(string path);

string getFileNameFromPath(string path, string sep = "/", bool removeExtension = true);
#endif