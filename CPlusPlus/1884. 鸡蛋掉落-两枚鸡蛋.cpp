class Solution {
public:
    int twoEggDrop(int n) {
        int i = 0;
        int sum = 0;
        while(sum < n){
            sum += i;
            ++i;
        }
        return i-1;
    }
};
