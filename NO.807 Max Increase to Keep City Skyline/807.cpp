/**
 * 807.cpp -- #807 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
 * Author: Farrell Meng
 * Creation Date: 2018-04-13
 * Update Date:   2018-04-13
 * Submission Result: Accepted
 *
 * In a 2 dimensional array grid, each value grid[i][j] represents the height of a building 
 * located there. We are allowed to increase the height of any number of buildings, by any 
 * amount (the amounts can be different for different buildings). Height 0 is considered to 
 * be a building as well. 
 *
 * At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, 
 * bottom, left, and right, must be the same as the skyline of the original grid. 
 * A city's skyline is the outer contour of the rectangles formed by all the buildings when 
 * viewed from a distance. See the following example.
 *
 * What is the maximum total sum that the height of the buildings can be increased?
 *
 * Example:
 * Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
 * Output: 35
 * Explanation: 
 * The grid is:
 * [ [3, 0, 8, 4], 
 *   [2, 4, 5, 7],
 *   [9, 2, 6, 3],
 *   [0, 3, 1, 0] ]
 *
 * The skyline viewed from top or bottom is: [9, 4, 8, 7]
 * The skyline viewed from left or right is: [8, 7, 9, 3]
 *
 * The grid after increasing the height of buildings without affecting skylines is:
 * 
 * gridNew = [ [8, 4, 8, 7],
               [7, 4, 7, 7],
               [9, 4, 8, 7],
               [3, 3, 3, 3] ]

 * Notes:
 * 
 * 1 < grid.length = grid[0].length <= 50.
 * All heights grid[i][j] are in the range [0, 100].
 * All buildings in grid[i][j] occupy the entire grid cell: that is, 
 * they are a 1 x 1 x grid[i][j] rectangular prism.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		auto rows = grid.size();
		auto cols = grid[0].size();
		vector<int> skyline_from_top_to_bottom;
		vector<int> skyline_from_left_to_right;
		for (auto x : grid) {
			int max = 0;
			for (auto y : x) {
				max = y > max ? y : max;
			}
			skyline_from_left_to_right.push_back(max);
		}
		for (int i = 0; i < cols; i++) {
			int max = 0;
			for (int j = 0; j < rows; j++) {
				max = grid[j][i] > max ? grid[j][i] : max;
			}
			skyline_from_top_to_bottom.push_back(max);
		}
		int total_increased_height = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int max_increased_height_from_top_to_bottom 
					= skyline_from_top_to_bottom[j] - grid[i][j];
				int max_increased_height_from_left_to_right
					= skyline_from_left_to_right[i] - grid[i][j];
				total_increased_height
					+= max_increased_height_from_top_to_bottom < max_increased_height_from_left_to_right
					? max_increased_height_from_top_to_bottom : max_increased_height_from_left_to_right;
			}
		}
		return total_increased_height;
	}
};

int main() {
	vector<vector<int>> grid = {
		{ 3, 0, 8, 4 },
		{ 2, 4, 5, 7 },
		{ 9, 2, 6, 3 },
		{ 0, 3, 1, 0 }
	};
	Solution s;
	int result = s.maxIncreaseKeepingSkyline(grid);
	cout << result << endl;
	return 0;
}