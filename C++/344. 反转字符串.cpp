class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t low = 0;
        size_t high = s.size() - 1;
        while(low < high){
            swap(s,low, high);
            ++low;
            --high;
        }
    }
private:
    void swap(vector<char>& s, size_t low, size_t high){
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp;
    }
};