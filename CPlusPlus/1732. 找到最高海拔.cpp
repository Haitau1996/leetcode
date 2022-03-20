class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_height{0};
        int result{0};
        for(const auto& elem : gain){
            current_height += elem;
            if(current_height > result){
                result = current_height;
            }
        }
        return result;
    }
};
