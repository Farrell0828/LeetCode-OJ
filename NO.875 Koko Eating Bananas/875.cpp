/**
 * 875.cpp -- #875 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/combinations/
 * Author: Farrell Meng
 * Creation Date: 2018-08-07
 * Update Date:   2018-08-07
 * Submission Result: Accepted
 *
 * Koko loves to eat bananas. There are N piles of bananas, the i-th pile has piles[i] bananas.
 * The guards have gone and will come back in H hours.
 * Koko can decide her bananas-per-hour eating speed of K.
 * Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
 * If the pile has less than K bananas, she eats all of them instead, 
 * and won't eat any more bananas during this hour.
 * Koko likes to eat slowly, but still wants to finish eating all the bananas 
 * before the guards come back.
 * Return the minimum integer K such that she can eat all the bananas within H hours.
 * 
 * Example 1:
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 * Example 2:
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 * Example 3:
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23

 * Note:
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 0;
        int right = *max_element(piles.begin(), piles.end());
        while ((right - left) > 1) {
            int k = (left + right) / 2;
            if (canEatAll(piles, H, k)) {
                right = k;
            }
            else {
                left = k;
            }
        }
        return right;
    }

    bool canEatAll(vector<int>& piles, int H, int k) {
        int h = 0;
        for (auto x : piles) {
            if (x % k == 0) {
                h += x / k;
            }
            else {
                h += (x / k + 1);
            }
            if (h > H) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> piles1 = { 3, 6, 7, 11 };
    int H1 = 8;
    vector<int> piles2 = { 30, 11, 23, 4, 20 };
    int H2 = 5;
    int H3 = 6;

    Solution s;
    cout << s.minEatingSpeed(piles1, H1) << endl;
    cout << s.minEatingSpeed(piles2, H2) << endl;
    cout << s.minEatingSpeed(piles2, H3) << endl;

    cin.get();
    return 0;
}