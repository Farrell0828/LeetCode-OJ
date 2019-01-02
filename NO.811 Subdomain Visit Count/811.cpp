#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        auto d_map = stringArr2Map(cpdomains);
        return map2StringArr(d_map);
    }

    vector<string> splitDomain(const string& domain) {
        vector<string> ret;
        for (int i = domain.size() - 1; i >= 0; i--) {
            if (domain[i] == '.') {
                ret.push_back(domain.substr(i + 1));
            }
        }
        ret.push_back(domain);
        return ret;
    }

    unordered_map<string, int> stringArr2Map(const vector<string>& cpdomains) {
        unordered_map<string, int> d_map;
        for (auto x : cpdomains) {
            int times = 0;
            string domain = "";
            for (size_t i = 0; i < x.size(); i++) {
                if (x[i] == ' ') {
                    times = stoi(x.substr(0, i));
                    domain = x.substr(i + 1);
                    break;
                }
            }
            auto splited_domains = splitDomain(domain);
            for (auto y : splited_domains) {
                if (d_map.find(y) != d_map.end()) {
                    d_map[y] += times;
                }
                else {
                    d_map.insert(pair<string, int>(y, times));
                }
            }
        }
        return d_map;
    }

    vector<string> map2StringArr(const unordered_map<string, int>& d_map) {
        vector<string> ret;
        for (auto x : d_map) {
            string str = "";
            str += to_string(x.second);
            str.push_back(' ');
            str += x.first;
            ret.push_back(str);
        }
        return ret;
    }
};

void ShowVector(const vector<string>& v) {
    for (auto x : v) {
        cout << x << endl;
    }
}

int main() {
    vector<string> cpdomains = {
        "9001 discuss.leetcode.com"
    };
    Solution s;
    ShowVector(s.subdomainVisits(cpdomains));
    cin.get();
    return 0;
}