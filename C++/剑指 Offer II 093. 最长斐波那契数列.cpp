/*
* 最直观的做法是使用回溯， 但是会超出时间限制
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        dfs(arr,0);
        return max_size > 2 ? max_size :0;
    }
private:
    vector<int> selected;
    int max_size{};
    void dfs(vector<int> arr, int current){
        if(current == arr.size()) return;
        if(selected.size() < 2 || arr[current] == selected[selected.size()-1] + selected[selected.size()-2]){
            selected.push_back(arr[current]);
            if(selected.size() > max_size) max_size = selected.size();
            dfs(arr,current+1);
            selected.pop_back();
        }
        dfs(arr,current+1);
    }
};
/*
* 使用动态规划
1. 使用的值是它的下标
2. dp[i][j] 表示最后一个数字为 i, 倒数第二个数字为 j 的斐波那契数列的长度
    case 1: 无法找到小于 j 的 k， 使得 arr[k]+arr[j] = arr[i], dp[i][j] = 2
    case 2: 能找到， dp[i][j] = dp[k][j] + 1
3. 为了方便查找， 我们使用一个 hash_map 做 val -> index 映射的缓存
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> val_to_index{};
        for(int i = 0; i < arr.size(); ++i){
            val_to_index[arr[i]] = i;
        }
        int result = 2;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(),0));
        for(int i = 1; i < arr.size(); ++i){
            for(int j = 0; j < i; ++j){
                auto iter = val_to_index.find(arr[i]-arr[j]);
                if(iter == val_to_index.end() || iter->second >= j) dp[i][j] = 2;
                else dp[i][j] = dp[j][iter->second] + 1;
                result = max(dp[i][j],result);
            }
        }
        return (result > 2 ? result : 0);
    }
};
