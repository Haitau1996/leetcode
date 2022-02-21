/*
相当于是从 "1,2,3,4 ... n" 这些 char 构成的 array中挨个拿出几个数字， 为了方便我们下标从 0 开始:
1. 每一步取的数字是第 k/(arr.size()-1) 个， 如 arr = ['1','2','3'] 取第 2 个数（以下标1 开始的话就是第3个），第一步 2！= 2， 2/2 = 1, 那么就先取 arr[1] 即 2，然后去掉该元素， 变成 ['1','3']， 这时候 k = 2-2 = 0
2. 如果 k == 0, 相当于是从小到大的排列， 即第一个， 这相当于是递归的基础 case 


执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了52.65% 的用户
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> input;
        for(int i = 1; i <= n; ++i){
            input.push_back('1' + i -1);
        }
        return gen_in_range(input, k-1);
    }
private:
    string gen_in_range(vector<char>& input, int k){
        if(k == 0) return string(input.begin(), input.end());
        int temp = factorial(input.size() - 1);
        int first_elem_index = k / temp;
        string result(input.begin()+first_elem_index, input.begin()+first_elem_index+1);
        input.erase(input.begin() + first_elem_index);
        return result + gen_in_range(input, k-first_elem_index*temp);
    }
    int factorial(int n){
        int result = 1;
        for(int i = 1; i <= n; ++i){
            result*= i;
        }
        return result;
    }
};