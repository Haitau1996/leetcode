/*
暴力 dfs: 超时
34 / 49 个通过测试用例
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        int sz = wordList.size();
        set<string> visited;
        queue<string> curr_que{};
        queue<string> next_que{};
        int dist = 1;
        curr_que.push(beginWord);
        visited.insert(beginWord);
        while(!curr_que.empty()){
            while(!curr_que.empty()){
                auto front = curr_que.front();
                curr_que.pop();
                if(front == endWord) return dist;
                for(const auto& elem : wordList){
                    if(visited.find(elem) == visited.end() && is_neighbor(front, elem)){
                        next_que.push(elem);
                        visited.insert(elem);
                    }
                }
            }
            swap(curr_que, next_que);
            ++dist;
        }
        return 0;
    }
private:
    bool is_neighbor(const string& first, const string& second){
        int count = 0;
        for(int i = 0; i < first.size(); ++i){
            if(first[i] != second[i]) ++count;
        }
        return count == 1;
    }
};
