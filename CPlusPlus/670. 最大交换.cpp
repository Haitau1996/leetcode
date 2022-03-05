class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        return swap_in_range(s,0,s.size());
    }
private:
    int swap_in_range(string& s, int low, int high){
        if(low == high) return stoi(s);
        char max_char = s[low];
        int max_index = low;
        for(int i = low; i < high; ++i){
            if(s[i] >= max_char){
                max_char = s[i];
                max_index = i;
            }
        }
        if(max_char == s[low]) return swap_in_range(s,low+1,high);
        else{
            iter_swap(s.begin()+max_index,s.begin()+low);
            return stoi(s);
        }       
    }
};