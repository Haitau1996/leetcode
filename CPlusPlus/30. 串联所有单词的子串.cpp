/*
尝试用递归的方法， 但是会超时
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        unordered_map<string,int> words_count;
        for(const auto &elem : words)
            words_count[elem]++;
        vector<int> result{};
        int window = (int)s.size()- len * (int)words.size();
        for(int i = 0; i <= window; ++i){
            if(check_start_from_index(s,i,len,words_count)){
                result.push_back(i);
            }
        }
        return result;
    }
private:
    bool check_start_from_index(string& s, int cursor, int len,unordered_map<string,int> dict){
        if(dict.empty()) return true;
        else if(cursor + len > s.size()) return false;
        else{
            string temp = s.substr(cursor,len);
            auto count = dict[temp];
            if(count == 0) return false;
            else if(count == 1) dict.erase(temp);
            else dict[temp]--;
            return check_start_from_index(s, cursor+len, len, dict);
        }
    }
};
/*
使用一个辅助的 dict, 每次只要看 current_dict[temp] <= word_count[temp]
不用递归调用， 在循环里判断
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        unordered_map<string,int> words_count;
        for(const auto &elem : words)
            words_count[elem]++;
        vector<int> result{};
        int window = len * words.size();
        int max_index = (int)s.size()- window;
        for(int i = 0; i <= max_index; ++i){
            int start = i;
            unordered_map<string,int> current{};
            string temp = s.substr(start,len);
            while(start-i< window && ++current[temp] <= words_count[temp]){
                start+=len;
                temp = s.substr(start,len);
            }
            if(start== i+window) result.push_back(i);
        }
        return result;
    }
};