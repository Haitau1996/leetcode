class Solution {
public:
    vector<int> lexicalOrder(int n) {
        push(1,n);
        return res;
    }
private:
    vector<int> res{};
    void push(int base, int n){
        if(base > n) return;
        res.push_back(base);

        base*=10;
        push(base,n);
        base/=10;

        if(base%10 < 9){
            ++base;
            push(base,n);
        }
    }
};
