/*
很典型的递归， 使用一个 hash_set 缓存字典，在一个范围 low, high 中做递归：
1. 如果 s.substr(low,high-low+1) 在字典内， 可以尝试将它压入 selected, 然后递归求解 dfs(s, high+1,high+1), 求解结束后记得将 substr 弹出
2. 无论 s.substr(low, high-low+1) 在不在字典内， 我们都可以递归求解 dfs(s, low, high+1)

有两个 base case:
1. low = s.size(), 说明刚刚压入一个符合要求的新字符串 [前一个low, s.size()] 并且已经到尾了，从 selected 中构造结果
2. low != s.size() 且 high = s.size, 说明当前的结果不符合要求， 是从 [low, s.size()-1] 且他们不符合要求的情况过来的， 直接返回就好

还有一种情况可以剪枝：high - low >= 10, 因为说过了字典里没有这么长的单词。
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        dfs(s,0,0);
        return result;
    }
private:
    unordered_set<string> dict{};
    vector<string> selected{};
    vector<string> result{};
    void dfs(string& s, int beg, int end){
        // base case 1: 
        if(beg == s.size()){
            result.push_back(construct_from_selected());
            return;
        }else if(end == s.size() || end - beg >= 10){
            return;
        }else{
            auto current = s.substr(beg,end-beg+1);
            if(dict.find(current) != dict.end()){
                selected.push_back(current);
                dfs(s,end+1,end+1);
                selected.pop_back();
            }
            dfs(s,beg, end+1);
        }
    }
    string construct_from_selected(){
        string to_return{""};
        for(int i = 0; i < selected.size()-1; ++i){
            to_return += selected[i];
            to_return += " ";
        }
        to_return += selected[selected.size()-1];
        return to_return;
    }
};