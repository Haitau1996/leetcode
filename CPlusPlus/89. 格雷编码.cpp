class Solution {
public:
    vector<int> grayCode(int n) {    
        if(n == 1) return vector<int>{0,1};
        else{
            auto first_half = grayCode(n-1);
            int end = first_half.size()-1;
            while(end >= 0){
                first_half.push_back(first_half[end] + (1<<(n-1)));
                --end;
            }
            return first_half;
        }
    }  
};