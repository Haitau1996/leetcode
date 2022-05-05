#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState)
    {
        vector<string> res;
        for (int i = 0; i < currentState.size() - 1; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == currentState[i]) {
                invert(currentState, i);
                res.push_back(currentState);
                invert(currentState, i);
            }
        }
        return res;
    }

private:
    void invert(string& s, int i)
    {
        if (s[i] == '+') {
            s[i] = '-';
            s[i + 1] = '-';
        } else {
            s[i] = '+';
            s[i + 1] = '+';
        }
    }
};
