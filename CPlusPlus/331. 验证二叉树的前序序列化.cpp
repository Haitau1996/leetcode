class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 1;
        bool has_tree= false;
        istringstream temp(preorder);
        string buffer;
        while(getline(temp, buffer, ',')){
            if(count == 0){
                return false;
            }else if(buffer=="#"){
                --count;
            }else{
                ++count;
            }
        }
        return count == 0;
    }
};
