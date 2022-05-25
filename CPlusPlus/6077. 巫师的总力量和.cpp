// 单调队列： 超时
class Solution {
public:
    int totalStrength(vector<int>& s) {
        vector<long long> pre{0};
        const int M {1000000007};
        for(int i = 0; i < s.size(); ++i){
            pre.push_back(pre.back()+s[i]);
        }
        int res{0};
        
        for(int k = 1; k <= s.size(); ++k){  
            deque<int> q{};
            for(int i = 0; i < k; ++i){
                while(!q.empty() && s[i] <= s[q.back()]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            res = (res + ((pre[k]-pre[0])*s[q.front()]) % M)%M;
            for(int i=k; i < s.size(); ++i){
                while(!q.empty() && s[i] <= s[q.back()]){
                    q.pop_back();
                }
                q.push_back(i);
                while(q.front() <= i-k){
                    q.pop_front();
                }
                res = (res +((pre[i+1]-pre[i+1-k])*s[q.front()])%M)%M;
            }
        }
        return res;
    }
};
