/*
 * 解法 1： dfs or bfs
 * 解法 2： 并查集
 */
#include <vector>

using std::vector;
class Solution1 {
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

class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        res = n;
        idx = vector<int>(n,0);
        rank = vector<int>(n,1);
        for(int i = 0; i < n; ++i){
            idx[i] = i;
        }
        for(int i = 0; i < n; ++i){
            for(int j =i+1; j < n; ++j){
                if(isConnected[i][j]) unite(i,j);
            }
        }
        return res;
    }
private:
    vector<int> idx;
    vector<int> rank;
    int res;
    int find(int p){
        while(p != idx[p]){
            p = idx[p];
        }
        return p;
    }
    void unite(int p, int q){
        int pr = find(p);
        int qr = find(q);
        if(pr == qr) return;
        else{
            if(rank[pr] > rank[qr]){
                idx[qr] = pr;
            }else if(rank[pr] < rank[qr]){
                idx[pr] = qr;
            }else{
                idx[pr] = idx[qr];
                rank[qr]++;
            }
            --res;
        }
    }
};
