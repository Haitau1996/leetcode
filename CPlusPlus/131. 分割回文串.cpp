class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s,0,0);
        return result;
    }
private:
    vector<string> selseted;
    vector<vector<string>> result;
    bool check_in_range(const string& s, int low, int high){
        while(low < high){
            if(s[low] == s[high]){
                ++low;
                --high;
            }
            else return false;
        }
        return true;
    }
    void dfs(const string&s, int start, int current){
        if(start == s.size()) {
            result.push_back(selseted);
            return;
        }
        if(current == s.size()) return;
        if(check_in_range(s,start,current)){
            selseted.push_back(s.substr(start,current-start+1));
            dfs(s,current+1,current+1);
            selseted.pop_back();
        }
        dfs(s,start,++current);
    }
};