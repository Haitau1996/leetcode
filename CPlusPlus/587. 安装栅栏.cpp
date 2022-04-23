// Graham 算法， 79 / 87 个通过测试用例
// 应该是排序的 lambda 表达式出了问题
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
class ImporperSolution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> res;
        auto cmpy = [](const vector<int>& p, const vector<int>&q){
            if(p[1] != q[1]){
                return p[1] < q[1];
            }else return p[0] < q[0];
        };
        auto first_iter = min_element(trees.begin(), trees.end(), cmpy);
        auto max_elem_x = max_element(trees.begin(), trees.end());
        auto max_x = (*max_elem_x)[0];
        auto base = *first_iter;
        auto cmp = [&base,&max_x](const vector<int>& p, const vector<int>& q){
            if(p == base) return true;
            else if(q == base) return false;
            if(p[1] == base[1] && q[1] == base[1]) return p[0] < q[0];
            if(abs(atan2(p[0]-base[0],p[1]-base[1]) - atan2(q[0]-base[0],q[1]-base[1])) > 1.0e-4){
                return atan2(p[0]-base[0],p[1]-base[1]) > atan2(q[0]-base[0],q[1]-base[1]);
            }else if(p[0] > base[0]){
                return p[1] < q[1];
            }else if(p[0] < base[0]){
                return p[1] > q[1];
            }else{
                if(base[0] == max_x){
                    return p[1]<q[1];
                }
                else return p[1] > q[1];
            }
        };
        sort(trees.begin(), trees.end(),cmp);
        auto cursor = trees.begin();
        while(cursor!= trees.end()){
            bool status = true;
            while(res.size() >= 2 && status){
                const auto& p1 = res[res.size()-2];
                const auto& p2 = res[res.size()-1];
                const auto& p3 = *cursor;
                vector<int> u = {p2[0]-p1[0], p2[1]-p1[1]};
                vector<int> v = {p3[0]-p2[0], p3[1]-p2[1]};
                int corss_prod_z = u[0] * v[1] - u[1]*v[0];
                if(corss_prod_z >= 0) status = false;
                else res.pop_back(); 
            }
            res.push_back(*cursor);
            ++cursor;
        }
        return res;
    }
};
// 修改的地方： 做角度排序的时候使用叉积而不是使用 atan2
// 最后在同一条线上的点需要 reverse
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() < 4) return trees;
        vector<vector<int>> res;
        auto cmpy = [](const vector<int>& p, const vector<int>&q){
            if(p[1] != q[1]){
                return p[1] < q[1];
            }else return p[0] < q[0];
        };
        auto first_index = distance(trees.begin(),min_element(trees.begin(), trees.end(), cmpy));
        swap(trees[first_index],trees[0]);
        auto base = trees[0];
        auto cmp = [&](const vector<int>& p, const vector<int>& q){
            int diff = cross(base, p, q) - cross(base, q,p);
            if(diff == 0) return dist(base, p) < dist(base, q);
            else return diff > 0;
        };
        sort(trees.begin()+1, trees.end(),cmp);
        int n = trees.size();
        int r = n - 1;
        while (r >= 0 && cross(trees[0], trees[n - 1], trees[r]) == 0) {
            r--;
        }
        for (int l = r + 1, h = n - 1; l < h; l++, h--) {
            swap(trees[l], trees[h]);
        }
        auto cursor = trees.begin();
        while(cursor!= trees.end()){
            bool status = true;
            while(res.size() >= 2 && status){
                const auto& p1 = res[res.size()-2];
                const auto& p2 = res[res.size()-1];
                const auto& p3 = *cursor;
                vector<int> u = {p2[0]-p1[0], p2[1]-p1[1]};
                vector<int> v = {p3[0]-p2[0], p3[1]-p2[1]};
                int corss_prod_z = u[0] * v[1] - u[1]*v[0];
                if(corss_prod_z >= 0) status = false;
                else res.pop_back(); 
            }
            res.push_back(*cursor);
            ++cursor;
        }
        return res;
    }
private:
    int dist(const vector<int>& p, const vector<int>& q){
        return (p[0]-q[0]) * (p[0]-q[0]) + (p[1]-q[1]) * (p[1]-q[1]);
    }
    int cross(const vector<int> & p, const vector<int> & q, const vector<int> & r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
};
