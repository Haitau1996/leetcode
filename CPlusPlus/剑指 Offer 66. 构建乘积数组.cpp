// 暴力解法： 每个 N 计算 N-1 次乘法， O(N^2)
// 前缀和解法： 求出前缀&后缀乘积， 然后直接相乘 O(N)
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size()!=0){
            vector<int> prefix{1};
            vector<int> postfix{1};
            for(int i = 0; i < a.size()-1; ++i){
                prefix.push_back(prefix.back() * a[i]);
                postfix.push_back(postfix.back() * a[a.size()-1 - i]);
            }
            reverse(postfix.begin(), postfix.end());
            for(int i = 0; i < a.size(); ++i){
                a[i] = prefix[i]*postfix[i];
            }
        }
        return a;
    }
};
