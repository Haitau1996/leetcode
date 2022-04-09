class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int ptrW = 0;
        int ptrL = 0;
        int diff = 0;
        while(ptrW < word.size() && ptrL < abbr.size()){
            if(word[ptrW] == abbr[ptrL]){
                ++ptrW;
                ++ptrL;
            }
            else if(isdigit(abbr[ptrL])&& abbr[ptrL]!='0'){
                diff = 0;
                while(ptrL+diff < abbr.size() && isdigit(abbr[ptrL+diff])) ++diff;
                string temp = abbr.substr(ptrL, diff);
                int temp_val = stoi(temp);
                ptrL+= diff;
                ptrW+=temp_val;
            }else{
                return false;
            }
        }
        if(ptrW == word.size() && ptrL == abbr.size()) return true;
        return false;
    }
};
