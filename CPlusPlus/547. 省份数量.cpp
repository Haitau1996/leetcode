class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> checked(isConnected.size(), false);
        int result{};
        for(int i = 0; i < checked.size(); ++i){
            if(!checked[i]) {
                dfs(isConnected,checked,i);
                ++result;
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& checked, int cursor){
        checked[cursor] = true;
        for(int i = 0; i < isConnected[0].size(); ++i){
            if(!checked[i] && isConnected[cursor][i])
                dfs(isConnected,checked,i);
        }
    }
};