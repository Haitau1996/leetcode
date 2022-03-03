class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        set<string> resSet = findHelper(n);
        return vector<string>(resSet.begin(), resSet.end());
    }
private:
    set<string> findHelper(int n){
        set<string> res;
        if(n == 0) return res;
        if(n == 1){
            res.insert("1");
            res.insert("8");
            res.insert("0");
            return res;
        }
        if(n == 2){
            res.insert("11");
            res.insert("88");
            res.insert("69");
            res.insert("96");
            return res;
        }
        else if(!(n && 0x1)){
            auto temp = findHelper(n-1);
            for(auto i: temp){
                
            }
        }
    }
};