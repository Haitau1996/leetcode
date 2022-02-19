class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> buffer(s.size(),0);
        int left_count{};
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') ++left_count;
            if(s[i] == ')') {
                if(left_count > 0) --left_count;
                else{
                    buffer[i] = 1;
                }
            }
        }
        int right_count{};
        for(int i = s.size()-1; i>= 0; --i){
            if(s[i] == ')') ++right_count;
            if(s[i] == '('){
                if(right_count >0) --right_count;
                else{
                    buffer[i] = 1;
                }
            }
        }
        int zero_count = 0;
        return longersZero(buffer, 0, buffer.size()-1);
    }
private:
    int longersZero(vector<int>& input, int low, int high){
        if(low > high) return 0;
        if(low == high){
            if(input[low] == 0) return 1;
            else return 0;
        }
        int i = low;
        while(i <=high){
            if(input[i] == 0) ++i;
            else break;
        }
        if(i == (high + 1)) return high + 1 - low;
        else return max(i - low, longersZero(input,i+1,high));
    }
};