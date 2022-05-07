#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int calculate(string s)
    {
        stack<char> opStk {};
        stack<int> oprand {};
        auto iter = std::remove(s.begin(), s.end(), ' ');
        s.erase(iter, s.end());
        int left = 0;
        int right = 0;
        while (left < s.size()) {
            while (right < s.size() && isdigit(s[right])) {
                ++right;
            }
            int temp = stoi(s.substr(left, right - left));
            if (!opStk.empty() && (opStk.top() == '*' || opStk.top() == '/')) {
                int first = oprand.top();
                int res = opStk.top() == '*' ? first * temp : first / temp;
                oprand.pop();
                opStk.pop();
                oprand.push(res);
            } else {
                oprand.push(temp);
            }
            if (right < s.size()) {
                opStk.push(s[right]);
            }
            left = right + 1;
            right = left;
        }
        vector<int> v;
        while (!oprand.empty()) {
            v.push_back(oprand.top());
            oprand.pop();
        }
        vector<char> c;
        while (!opStk.empty()) {
            c.push_back(opStk.top());
            opStk.pop();
        }
        reverse(v.begin(), v.end());
        reverse(c.begin(), c.end());
        int temp = v[0];
        for (int i = 0; i < c.size(); ++i) {
            temp = c[i] == '+' ? (temp + v[i + 1]) : (temp - v[i + 1]);
        }
        return temp;
    }
};
