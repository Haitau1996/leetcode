class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_multiset<int> buffer;
        long res{};
        for(auto i:answers)
            buffer.insert(i+1);
        for(auto iter = buffer.begin(); iter!=buffer.end(); ){
            auto cnt = buffer.count(*iter);
            int temp = (cnt%(*iter) == 0)? cnt/(*iter) : cnt/(*iter)+1;
            res = res + temp*(*iter);
            std::advance(iter,cnt);
        }
        return res;
    }
};