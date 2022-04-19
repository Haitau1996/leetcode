#include<vector>
#include<limits>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int sz = s.size();
        vector<int> prefix(s.size(),numeric_limits<int>::max());
        vector<int> postfix(s.size(), numeric_limits<int>::max());
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == c) prefix[i] = 0;
            else{
                if(i == 0 || prefix[i-1] == numeric_limits<int>::max()){}
                else prefix[i] = prefix[i-1]+1;
            }
            if(s[sz-1-i] == c) postfix[sz-i-1] = 0;
            else {
                if(i == 0 || postfix[sz-i] == numeric_limits<int>::max()){}
                else {
                    postfix[sz-i-1] = postfix[sz-i]+1;
                }
            }
        }
        for(int i = 0; i < s.size(); ++i){
            if(postfix[i] < prefix[i]) prefix[i] = postfix[i];
        }
        return prefix;
    }
};
