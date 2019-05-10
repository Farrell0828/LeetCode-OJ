#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int edge = A.size();
        for (int i = 0; i < A.size(); i++) {
            if (A[i] >= 0) {
                edge = i;
                break;
            }
        }
        vector<int> ret_left, ret_right, ret;
        for (int i = edge - 1; i >= 0; i--) {
            ret_left.push_back(A[i] * A[i]);
        }
        for (int i = edge; i < A.size(); i++) {
            ret_right.push_back(A[i] * A[i]);
        }
        auto p = ret_left.begin();
        auto q = ret_right.begin();
        while (p != ret_left.end() && q != ret_right.end()) {
            if (*p <= *q) {
                ret.push_back(*p);
                p++;
            }
            else {
                ret.push_back(*q);
                q++;
            }
        }
        while (p != ret_left.end()) {
            ret.push_back(*p);
            p++;
        }
        while (q != ret_right.end()) {
            ret.push_back(*q);
            q++;
        }
        return ret;
    }
};