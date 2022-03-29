class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited{};
        string source("0000");
        if(dead.find(source)!=dead.end() || dead.find(target)!= dead.end()) return -1;
        queue<string> curr_que{};
        queue<string> next_que{};
        int distance = 0;
        curr_que.push(source);
        visited.insert(source);
        while(!curr_que.empty()){
            string current = curr_que.front();
            if(current == target) return distance;
            vector<string> neighbors = getNeighbors(current);
            for(const auto& neighbor : neighbors){
                if(dead.find(neighbor) == dead.end() && visited.find(neighbor) == visited.end()){
                    next_que.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            curr_que.pop();
            if(curr_que.empty()){
                ++distance;
                swap(curr_que,next_que);
            }
        }
        return -1;
    }
private:
    vector<string> getNeighbors(string current){
        vector<string> result{};
        for(int i = 0; i < current.size(); ++i){
            string up(current);
            up[i] = up[i] == '9' ? '0' : up[i] + 1;
            result.push_back(up);
            string down(current);
            down[i] = down[i] == '0' ? '9' : down[i] - 1;
            result.push_back(down);
        }
        return result;
    }
};
