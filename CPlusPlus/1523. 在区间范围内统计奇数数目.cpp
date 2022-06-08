class Solution {
public:
    int countOdds(int low, int high)
    {
        int diff = (high - low) >> 1;
        if (low & 0x1 || high & 0x1)
            ++diff;
        return diff;
    }
};
