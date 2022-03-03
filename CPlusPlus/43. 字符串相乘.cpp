class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())
            return core(num2,num1);
        else return core(num1, num2);
    }
private:
    string core(string num1, string num2){
        string current = oneBitMul(num1, num2.back());
        if(num2.size() == 1) return current;
        else{
            num2.pop_back();
            return plus(current, core(num1+"0",num2));
        }
    }
    string oneBitMul(string num, char c){
        int carry = 0;
        int mul = c - '0';
        if(mul == 0) return "0";
        reverse(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i){
            int temp = (num[i] - '0') * mul + carry;
            num[i] = temp % 10 + '0';
            carry = temp / 10;
        }
        if(carry) num.push_back(carry+'0');
        reverse(num.begin(), num.end());
        return num;
    }
    string plus(string num1, string num2){
        if(num2.size() > num1.size())
            swap(num1, num2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry = 0;
        int i = 0;
        while( i < num2.size()){
            int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
            num1[i] = temp%10 + '0';
            carry = temp / 10;
            ++i;
        }
        while(carry && i< num1.size()){
            int temp = (num1[i] - '0') + carry;
            num1[i] = temp%10 + '0';
            carry = temp / 10;
            ++i;
        }
        if(carry) num1+="1";
        reverse(num1.begin(), num1.end());
        return num1;
    }
};