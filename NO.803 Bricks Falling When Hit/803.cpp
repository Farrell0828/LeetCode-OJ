/**
 * 803.cpp -- #803 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/bricks-falling-when-hit/description/
 * Author: Farrell Meng
 * Date:   2018-04-10
 *
 * We have a grid of 1s and 0s; the 1s in a cell represent bricks.
 * A brick will not drop if and only if it is directly connected to the top of the grid,
 * or at least one of its (4-way) adjacent bricks will not drop.
 *
 * We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j),
 * the brick (if it exists) on that location will disappear,
 * and then some other bricks may drop because of that erasure.
 *
 * Return an array representing the number of bricks that will drop after each erasure in sequence.
 *
 * Example 1:
 * Input:
 * grid = [[1,0,0,0],[1,1,1,0]]
 * hits = [[1,0]]
 * Output: [2]
 * Explanation:
 * If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
 *
 * Example 2:
 * Input:
 * grid = [[1,0,0,0],[1,1,0,0]]
 * hits = [[1,1],[1,0]]
 * Output: [0,0]
 * Explanation:
 * When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move.
 * So each erasure will cause no bricks dropping.
 * Note that the erased brick (1, 0) will not be counted as a dropped brick.
 *
 * Note:
 * The number of rows and columns in the grid will be in the range [1, 200].
 * The number of erasures will not exceed the area of the grid.
 * It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
 * An erasure may refer to a location with no brick - if it does, no bricks drop.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		auto new_grid = newGrid(grid);
		vector<int> result;
		for (auto x : hits) {
			new_grid[x[0] + 1][x[1]] = 0;
			int num1 = numOfBricks(new_grid);
			auto connected_grid = BFS(new_grid, 0, 0);
			int num2 = numOfBricks(connected_grid);
			result.push_back(num1 - num2);
			new_grid = connected_grid;
		}
		return result;
	}

	// 求图g行数的内联函数
	inline int rowWidth(const vector<vector<int>>& g) { return g.size(); }

	// 求图g列数的内联函数
	inline int colWidth(const vector<vector<int>>& g) { return g[0].size(); }

	// 判断坐标(x, y)是否越界的内联函数
	inline bool outSide(const vector<vector<int>>& g, const int& x, const int& y) {
		return (x < 0 || x >= rowWidth(g) || y < 0 || y >= colWidth(g));
	};

	// 在图grid上方增加一行，且新增的一行全为1，返回新的图new_grid
	vector<vector<int>> newGrid(const vector<vector<int>>& grid) {
		vector<vector<int>> new_grid;
		new_grid.push_back(vector<int>(colWidth(grid), 1));
		for (auto x : grid) {
			new_grid.push_back(x);
		}
		return new_grid;
	}

	// 获取图g的连通分量
	vector<vector<int>> BFS(const vector<vector<int>>& g, const int& _x, const int& _y) {
		vector<vector<int>> flag;
		for (int i = 0; i < rowWidth(g); i++) {
			vector<int> temp(colWidth(g), 0);
			flag.push_back(temp);
		}
		queue<vector<int>> q;
		q.push(vector<int>{ _x, _y });
		while (!q.empty()) {
			auto x = q.front()[0];
			auto y = q.front()[1];
			q.pop();
			flag[x][y] = 1;
			if (!outSide(g, x + 1, y) && g[x + 1][y] && !flag[x + 1][y]) 
				q.push(vector<int>{ x + 1, y });
			if (!outSide(g, x - 1, y) && g[x - 1][y] && !flag[x - 1][y]) 
				q.push(vector<int>{ x - 1, y });
			if (!outSide(g, x, y + 1) && g[x][y + 1] && !flag[x][y + 1]) 
				q.push(vector<int>{ x, y + 1 });
			if (!outSide(g, x, y - 1) && g[x][y - 1] && !flag[x][y - 1])
				q.push(vector<int>{ x, y - 1 });
		}
		return flag;
	}

	// 统计图g的砖块数目
	int numOfBricks(const vector<vector<int>>& g) {
		int count = 0;
		for (auto x : g) {
			for (auto y : x) {
				if (y == 1) count++;
			}
		}
		return count;
	}
};

void ShowVector(vector<int> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

void ShowGrid(vector<vector<int>> grid) {
	for (auto x : grid) {
		for (auto y : x) {
			if (y) cout << "■";
			else cout << "  ";
		}
		cout << endl;
	}
}

void ShowHits(vector<vector<int>> hits) {
	for (auto x : hits) {
		cout << "(" << x[0] << ", " << x[1] << "); ";
	}
	cout << endl;
}

int main() {
	vector< vector<int> > grid = { 
		{ 1, 0, 1, 0, 1 }, 
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 1, 1, 0, 1, 1 } };
	vector< vector<int> > hits = { { 1, 1 }, { 1, 0 }, { 3, 3 } };
	ShowGrid(grid);
	cout << endl;
	ShowHits(hits);
	cout << endl;
	Solution s;
	vector<int> result = s.hitBricks(grid, hits);
	ShowVector(result);
	return 0;
}