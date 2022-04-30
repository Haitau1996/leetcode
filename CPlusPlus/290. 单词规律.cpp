#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream ss(s);
        unordered_map<string, char> hash {};
        unordered_map<char, string> revhash {};
        string temp {};
        size_t index = 0;
        while (getline(ss, temp, ' ')) {
            if (hash.find(temp) == hash.end() && index < pattern.size() && revhash.find(pattern[index]) == revhash.end()) {
                hash.emplace(temp, pattern[index]);
                revhash.emplace(pattern[index], temp);
            } else if (hash.find(temp) != hash.end() && index < pattern.size() && revhash.find(pattern[index]) != revhash.end()) {
                if (hash[temp] != pattern[index] || revhash[pattern[index]] != temp)
                    return false;
            } else
                return false;
            ++index;
        }
        if (index == pattern.size())
            return true;
        return false;
    }
};
