#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        id = vector<int>(n,0);
        for(int i = 0; i < n; ++i){
            id[i] = i;
            cnt[i] = 1;
        }
        for(const auto& e : edges){
            uni(e[0],e[1]);
        }
        long long res{0};
        for(auto [_, curr] : cnt){
            res += (long long)curr * (long long)(n-curr);
        }
        return res>>1;
    }
private:
    unordered_map<int, int> cnt;
    vector<int> id;
    int find(int p){
        while(p != id[p]) p = id[p];
        return p;
    }
    void uni(int p, int q){
        int pr = find(p);
        int qr = find(q);
        if(pr == qr) return;
        id[pr] = qr;
        cnt[qr] = cnt[qr] + cnt[pr];
        cnt.erase(pr);
    }
};
