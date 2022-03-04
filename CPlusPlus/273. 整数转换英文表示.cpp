class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        else return helper(num);
    }
private:
    vector<string> below20{"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                    "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> above20{"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string helper(int num){
        if(num < 20) return below20[num];
        else if(num < 100) return above20[num/10-2]+(num%10 ? " ":"") + helper(num%10);
        else if(num < 1000) return helper(num/100) + " Hundred" + (num%100 ? " ":"")+ helper(num % 100);
        else if(num < 1000000) return helper(num/1000) + " Thousand" + (num%1000 ? " ":"") +helper(num % 1000);
        else if(num < 1000000000) return helper(num/1000000) + " Million"+ (num%1000000 ? " ":"") + helper(num%1000000);
        return helper(num/1000000000) + " Billion" +(num%1000000000 ? " ":"") + helper(num%1000000000);
    }
};