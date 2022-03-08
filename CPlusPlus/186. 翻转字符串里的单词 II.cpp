class Solution {
public:
    void reverseWords(vector<char>& s) {
        int low = 0;
        int high = 0;
        while(high < s.size()-1){
            while(high < s.size()-1 && s[high+1]!=' '){
                ++high;
            }
            if(high < s.size()-1 && s[high+1]==' '){
                swap_in_range(s, low, high);
                low = high+2;
                high = high+2;
            }
        }
        swap_in_range(s,low, s.size()-1);
        swap_in_range(s,0,s.size()-1);

    }
private:
    void swap_in_range(vector<char>& s, int low, int high){
        while(low < high){
            swap(s[low],s[high]),
            ++low;
            --high;
        }
    }
};