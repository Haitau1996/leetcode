/*
经典的回溯, 使用 selected 存放已经选择的点
1. base case: 选择的数字尺寸为 k 和 为 n, 将 selected 放入 result
2. base case: 选择的尺寸大于等于 k, 和不为 n, 直接 return
3. base case: 光标大于 9 ， 直接 return
4. recursive case: 
    1. 选择当下的点， 然后光标右移， 回溯之后要将状态回退
    2. 跳过当下的点
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n >((9 + 9 - k + 1) * k /2)) return vector<vector<int>>{};
        else if(n < ((1 + 1+k-1)*k/2)) return vector<vector<int>>{};
        dfs(1,k,n);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result;
    int sum{};
    void dfs(int current, int k, int n){
        // base case:
        if(selected.size() == k && sum ==n){
            result.push_back(selected);
            return;
        }
        else if(selected.size() >= k && sum != n){
            return;
        }
        else if(current > 9) return;
        // selected current
        selected.push_back(current);
        sum+=current;
        dfs(current+1,k,n);
        selected.pop_back();
        sum-=current;
        // ignore current
        dfs(current+1,k,n);
    }
};