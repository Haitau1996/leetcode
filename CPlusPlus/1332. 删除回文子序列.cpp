class Solution {
public:
    int removePalindromeSub(string s)
    {
        return helper(s, 0, s.size() - 1) ? 1 : 2;
    }

private:
    bool helper(string& s, int low, int high)
    {
        while (low < high) {
            if (s[low] != s[high])
                return false;
            ++low;
            --high;
        }
        return true;
    }
};
