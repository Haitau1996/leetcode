class Solution {
public:
    string addStrings(string num1, string num2) {
        int carrier = 0;
        auto iter1 = num1.rbegin();
        auto iter2 = num2.rbegin();
        string result;
        while(iter1 != num1.rend() && iter2 != num2.rend()){
            int sum = ((*iter1) - '0') +((*iter2) - '0') + carrier;
            if(sum >= 10){
                carrier = 1;
                sum -= 10;
            }
            else{
                carrier = 0;
            }
            result.push_back(sum+'0'); 
            ++iter1;
            ++iter2;
        }
        auto newIter = iter1;
        auto newEnd = num1.rend();
        if(iter1 == num1.rend()){
            newIter = iter2;
            newEnd = num2.rend();
        }
        while(newIter != newEnd){
            int sum = ((*newIter) -'0') + carrier;
            if(sum >= 10){
                carrier = 1;
                sum -= 10;
            }
            else{
                carrier = 0;
            }
            result.push_back(sum+'0'); 
            ++newIter;
        }
        if(carrier) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};