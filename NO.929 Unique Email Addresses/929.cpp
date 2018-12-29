/**
 * 929.cpp -- #929 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/unique-email-addresses/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * Every email consists of a local name and a domain name, separated by the @ sign.
 * For example, in alice@leetcode.com, alice is the local name, 
 * and leetcode.com is the domain name.
 *
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 * If you add periods ('.') between some characters in the local name part of an email address,
 * mail sent there will be forwarded to the same address without dots in the local name.
 *
 * For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same 
 * email address.  (Note that this rule does not apply for domain names.)
 *
 * If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
 * This allows certain emails to be filtered, 
 * for example m.y+name@email.com will be forwarded to my@email.com.  
 * (Again, this rule does not apply for domain names.)
 
 * It is possible to use both of these rules at the same time.
 * Given a list of emails, we send one email to each address in the list.
 * How many different addresses actually receive mails? 
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique_emails;
        for (auto x : emails) {
            unique_emails.insert(clearEmail(x));
        }
        return unique_emails.size();
    }

    string clearEmail(string& email) {
        auto pos = email.find('@');
        auto local_name = email.substr(0, pos);
        string new_email = "";
        for (auto x : local_name) {
            if (x == '+') {
                break;
            }
            if (x != '.') {
                new_email.push_back(x);
            }
        }
        new_email += email.substr(pos + 1);
        return new_email;
    }
};

int main() {
    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };

    Solution s;
    cout << s.numUniqueEmails(emails);

    cin.get();
    return 0;
}