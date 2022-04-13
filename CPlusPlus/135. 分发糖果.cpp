class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> pre(n, 1);
        vector<int> post(n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                pre[i] = pre[i-1]+1;
            }
        }
        for(int i = n-2; i>=0; --i){
            if(ratings[i] > ratings[i+1]){
                post[i] = post[i+1]+1;
            }
        }
        int result{0};
        for(int i = 0; i < n; ++i){
            result += max(pre[i],post[i]);
        }
        return result;
    }
};
