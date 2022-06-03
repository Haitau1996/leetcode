#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        map<vector<int>, int> mp {};
        for (const auto& s : strs) {
            vector<int> curr(26, 0);
            for (const auto& c : s) {
                curr[c - 'a']++;
            }
            if (mp.find(curr) == mp.end()) {
                res.push_back(vector<string> {});
                mp[curr] = res.size() - 1;
            }
            res[mp[curr]].push_back(s);
        }
        return res;
    }
};
