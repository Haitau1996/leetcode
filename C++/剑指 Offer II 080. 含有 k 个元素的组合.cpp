class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result;
    void dfs(int current, int n, int k){
        if((selected.size() + (n - current + 1)) < k) return;
        if(selected.size() == k){
            result.push_back(selected);
        }
        else{
            selected.push_back(current);
            dfs(current+1, n, k);
            selected.pop_back();
            dfs(current+1,n,k);
        }
    }
};