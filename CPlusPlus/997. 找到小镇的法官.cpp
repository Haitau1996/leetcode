class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n,0);
        vector<bool> bas_neighbor(n, false); 
        for(const auto& elem : trust){
            bas_neighbor[elem[0]-1] = true;
            trust_count[elem[1]-1]++;
        }
        for(int i = 0; i < n; ++i){
            if(!bas_neighbor[i] && trust_count[i]==(n-1))
                return i+1;
        }
        return -1;
    }
};