#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int num = 0, begin = 0;
        string S2 = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                num++;
            }
            else if (S[i] == ')') {
                num--;
            }
            if (num == 0) {
                S2 += S.substr(begin + 1, i - begin - 1);
                begin = i + 1;
            }
        }
        return S2;
    }
};