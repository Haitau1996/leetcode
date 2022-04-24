#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[1]!= b[1])
                return a[1] > b[1];
            else return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < mat.size(); ++i){
            int j = 0;
            while(j < mat[0].size() && mat[i][j] == 1){
                ++j;
            }
            pq.push(vector<int>{i,j});
        }
        vector<int> res{};
        while(res.size() < k){
            auto top = pq.top();
            pq.pop();
            res.push_back(top[0]);
        }
        return res;
    }
};
