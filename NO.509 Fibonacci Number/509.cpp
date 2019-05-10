#include <map>
using namespace std;

class Solution {
public:
    int fib(int N) {
        static map<int, int> m;
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        if (m.find(N) != m.end()) {
            return m[N];
        }
        int ret = fib(N - 1) + fib(N - 2);
        m.insert(pair<int, int>(N, ret));
        return ret;
    }
};