class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> checked(isConnected.size(), false);
        int result = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            if(!checked[i]) {
                bfs(isConnected, checked, i);
                ++result;
            }
        }
        return result;
    }
private:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& checked, int cursor){
        queue<int> to_check{};
        to_check.push(cursor);
        checked[cursor]= true;
        while(!to_check.empty()){
            int current = to_check.front();
            for(int i = 0; i < isConnected.size(); ++i){
                if(!checked[i] && isConnected[current][i]){
                    to_check.push(i);
                    checked[i] = true;
                }
            }
            to_check.pop();
        }
    }
};