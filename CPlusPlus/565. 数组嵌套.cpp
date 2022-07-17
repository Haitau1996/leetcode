/*
 * 将数组看成一组图， 不含重复元素说明没有两个相同元素指向同一个节点
 * 图的入度和出度都是 1， 最长的连续序列就是最大的环， 可以使用 BFS/DFS/Union-Find
 */
#include <vector>
#include <unordered_map>

using namespace std;
class Union-Find_Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        idx = vector<int>(n);
        for(int i = 0; i < n; ++i){
            idx[i] = i;
        }
        for(int i = 0; i < n; ++i){
            if(idx[i] == i){
                int curr = i;
                int next = nums[i];
                while(find(curr) != find(next)){
                    unite(curr, next);
                    curr = next;
                    next = nums[curr];
                }
            }
        }
        unordered_map<int, int> cnt;
        int res = 0;
        for(const auto& e : idx){
            cnt[e]++;
            res = max(res, cnt[e]);
        }
        return res;
    }
private:
    vector<int> idx;
    int find(int p){
        while(p != idx[p])
            p = idx[p];
        return p;
    }
    bool unite(int p, int q){
        int pr = find(p);
        int qr = find(q);
        if(pr == qr) return true;
        else{
            idx[qr] = pr;
            return false;
        }
    }
};
