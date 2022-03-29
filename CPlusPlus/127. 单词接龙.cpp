class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> not_visited(wordList.begin(), wordList.end());
        queue<string> curr_que{};
        queue<string> next_que{};
        if(not_visited.find(endWord) == not_visited.end()) return 0;
        int distance = 1;
        curr_que.push(beginWord);
        not_visited.erase(beginWord);
        while(!curr_que.empty()){
            auto front = curr_que.front();
            if(front == endWord) return distance;
            vector<string> neighbors = get_neighbors(front);
            for(const auto neighbor: neighbors){
                auto nei_iter = not_visited.find(neighbor);
                if(nei_iter != not_visited.end()){
                    next_que.push(neighbor);
                    not_visited.erase(nei_iter);
                }
            }
            curr_que.pop();
            if(curr_que.empty()){
                swap(curr_que, next_que);
                ++distance;
            }
        }
        return 0;
    }
private:
    vector<string> get_neighbors(const string& curr){
        vector<string> result;
        string temp(curr);
        for(int i = 0; i < curr.size(); ++i){
            char old_char = curr[i];
            for(char c = 'a'; c <= 'z'; ++c){
                if(c != old_char){
                    temp[i] = c;
                    result.push_back(temp); 
                }
            }
            temp[i] = old_char;
        }
        return result;
    }
};
