class Solution {
public:
    string reverseWords(string s) {
        istringstream steam(s);
        string temp;
        string result;
        while(!steam.eof()){
            steam >> temp;
            revSingle(temp);
            if(result.size() != 0 && temp != ""){
                result += " ";
            }
            result += temp;
            temp = "";
        }
        revSingle(result);
        return result;
    }
private:
    void revSingle(string& in){
        int low = 0;
        int high = in.size() - 1;
        while(low < high){
            swap(in[low],in[high]);
            ++low; 
            --high;
        }
    }
};