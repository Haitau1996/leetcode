/*
 * 简单的并查集的应用， 这里用了一个数字记录当前集合的个数
 */
#include <vector>

using namespace std;
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        set_cnt = n;
        idx = vector<int>(n,0);
        for(int i = 0; i < n; ++i) idx[i] = i;
        sort(logs.begin(), logs.end());
        for(const auto& l : logs){
            unite(l[1],l[2]);
            if(set_cnt == 1) return l[0];
        }
        return -1;
    }
private:
    int set_cnt;
    vector<int> idx;
    int find(int p){
        while(p != idx[p])
            p = idx[p];
        return p;
    }
    void unite(int p, int q){
        int pr = find(p);
        int qr = find(q);
        if(pr == qr) return;
        idx[pr] = qr;
        --set_cnt;
    }
};
