class Solution {
public:
    int countSubstrings(string s) {
        int result{};
        for(int i = 0; i < s.size(); ++i){
            result += coutWithCenter(s,i,i);
            result += coutWithCenter(s,i, i+1);
        }
        return result;
    }
// 中心开花
private:
    int coutWithCenter(const string& s, int center1, int center2){
        int result = 0;
        while(center1>= 0 && center2 < s.size()){
            if(s[center1] == s[center2]){
                ++result;
                --center1;
                ++center2;
            }
            else break;
        }
        return result;
    }
};