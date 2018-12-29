/**
 * 804.cpp -- #804 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/unique-morse-code-words/
 * Author: Farrell Meng
 * Creation Date: 2018-12-29
 * Update Date:   2018-12-29
 * Submission Result: Accepted
 *
 * International Morse Code defines a standard encoding where each letter is mapped 
 * to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", 
 * "c" maps to "-.-.", and so on.
 * 
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 *
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
 *  "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * Now, given a list of words, each word can be written as a concatenation of the Morse 
 * code of each letter. For example, "cba" can be written as "-.-..--...", 
 * (which is the concatenation "-.-." + "-..." + ".-"). 
 * We'll call such a concatenation, the transformation of a word.
 * 
 * Return the number of different transformations among all words we have.
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> unique_codes;
        for (auto x : words) {
            unique_codes.insert(word2code(x));
        }
        return unique_codes.size();
    }

    vector<string> code_dic = {
        ".-", "-...", "-.-.", "-..", ".", "..-.",
        "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };

    string word2code(const string& word) {
        string code = "";
        for (auto x : word) {
            code += code_dic[x - 'a'];
        }
        return code;
    }
};

int main() {
    vector<string> words = { "gin", "zen", "gig", "msg" };
    Solution s;
    cout << s.uniqueMorseRepresentations(words);
    cin.get();
    return 0;
}