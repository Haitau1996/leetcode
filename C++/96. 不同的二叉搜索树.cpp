class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;
        int sum = 0;
        sum += 2 * numTrees(n-1);
        for(int i = 2; i < n; ++i){
            int left = numTrees(i-1);
            int right = numTrees(n-i);
            sum += left*right;
        }
        return sum;
    }
};