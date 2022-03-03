class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int ig = 0;
        int is = 0;
        while(ig < g.size() && is < s.size()){
            if(g[ig] <= s[is]){
                ++count;
                ++ig;
                ++is;
            }
            else{
                ++is;
            }
        }
        return count;
    }
};