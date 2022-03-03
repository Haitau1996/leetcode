/*
执行用时：84 ms, 在所有 C++ 提交中击败了25.80% 的用户
内存消耗：30.7 MB, 在所有 C++ 提交中击败了10.96% 的用户
先调用了 sort 对它进行排序， 不知道为什么比不排序的结果差那么多
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](string a, string b){
            return a.size() > b.size();
        });
        vector<int> flag(words.size(),0);
        for(int i = 0; i < words.size(); ++i){
            for(char c : words[i]){
                flag[i] |= (1 << (c-'a'));
            }
        }
        int result{};
        for(int i = 0; i < words.size() && words[i].size()*words[i].size() > result; ++i){
            for(int j = i+1; j < words.size(); ++j){
                if((flag[i]&flag[j]) == 0){
                    int newResult = words[i].size() * words[j].size();
                    result = result > newResult? result : newResult;
                }
            }
        }
        return result;
    }
};
