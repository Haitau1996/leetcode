/*
尝试用递归的方法， 但是会超时
*/
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
