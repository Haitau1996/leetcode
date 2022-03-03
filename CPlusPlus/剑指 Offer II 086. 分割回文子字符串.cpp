/*****************************
TODO: 目前使用的暴力回溯效率有点低
* 后续考虑 DP + 回溯 
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // basic case:
        if(s.size() == 1) return vector<vector<string>>(1,vector<string>{s});
        vector<vector<string>> result;
        int rbeg = s.size() - 1;
        int rend = s.size() - 1;
        while(rend >= 0){
            if(isPalin(s, rend, rbeg)){
                if(rend == 0) result.push_back(vector<string>{s});
                else{
                    auto partial_result = partition(s.substr(0, rend));
                    for(auto& elem: partial_result){
                        elem.emplace_back(s.substr(rend,rbeg-rend+1));
                    }
                    std::copy(partial_result.begin(),partial_result.end(), back_inserter(result));
                }
            }
            --rend;
        }
        return result;
    }
private:
    bool isPalin(string& s, int beg, int end){
        while(beg <= end){
            if(s[beg] != s[end]) return false;
            ++beg;
            --end;
        }
        return true;
    }
};