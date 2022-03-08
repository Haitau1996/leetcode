/*
在滑动窗口的时候一定要注意， 可能序列的长度没有 窗口长， 而 s.size() 是一个 unsigned 数字， 它减去比自己大的数会 round 到一个很大的数字
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int WINDOW = 10;
        unordered_map<string, int> dir;
        vector<string> result;
        for(int i =0; i <= (int)s.size()-WINDOW; ++i){
            auto temp = s.substr(i,WINDOW);
            if(dir[temp]++ == 1){
                result.push_back(temp);
            }
        }
        return result;
    }
};