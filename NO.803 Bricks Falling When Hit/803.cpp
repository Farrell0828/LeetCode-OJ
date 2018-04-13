/**
 * 803.cpp -- #803 of LeetCode OJ
 *
 * Source: https://leetcode.com/problems/bricks-falling-when-hit/description/
 * Author: Farrell Meng
 * Creation Date: 2018-04-10
 * Update Date:   2018-04-12
 * Submission Result: Time Limit Exceeded
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
#include <random>
using namespace std;

class Solution {
public:
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		auto new_grid = newGrid(grid);
		vector<int> result;
		for (auto x : hits) {
			if (new_grid[x[0] + 1][x[1]]) {
				int num1 = BFS(new_grid, 0, 0);
				new_grid[x[0] + 1][x[1]] = 0;
				showGrid(new_grid);
				cout << endl;
				int num2 = BFS(new_grid, 0, 0);
				result.push_back((num1 - num2) > 0 ? (num1 - num2 - 1) : 0);
			}
			else {
				result.push_back(0);
			}
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

	// 获取图g的连通分量包含的节点数目
	int BFS(const vector<vector<int>>& g, const int& _x, const int& _y) {
		auto flag = new vector<vector<bool>>;
		for (int i = 0; i < rowWidth(g); i++) {
			vector<bool> temp(colWidth(g), false);
			flag->push_back(temp);
		}
		auto q = new queue<vector<int>>;
		q->push(vector<int>{ _x, _y });
		(*flag)[_x][_y] = true;
		int count = 0;
		while (!q->empty()) {
			auto x = q->front()[0];
			auto y = q->front()[1];
			q->pop();
			count++;
			if (!outSide(g, x + 1, y) && g[x + 1][y] && !(*flag)[x + 1][y]) {
				q->push(vector<int>{ x + 1, y });
				(*flag)[x + 1][y] = true;
			}
			if (!outSide(g, x - 1, y) && g[x - 1][y] && !(*flag)[x - 1][y]) {
				q->push(vector<int>{ x - 1, y });
				(*flag)[x - 1][y] = true;
			}
			if (!outSide(g, x, y + 1) && g[x][y + 1] && !(*flag)[x][y + 1]) {
				q->push(vector<int>{ x, y + 1 });
				(*flag)[x][y + 1] = true;
			}
			if (!outSide(g, x, y - 1) && g[x][y - 1] && !(*flag)[x][y - 1]) {
				q->push(vector<int>{ x, y - 1 });
				(*flag)[x][y - 1] = true;
			}
		}
		delete flag;
		delete q;

		return count;
	}

	void showGrid(const vector<vector<int>>& grid) {
		for (auto x : grid) {
			for (auto y : x) {
				if (y) cout << "■";
				else cout << "  ";
			}
			cout << endl;
		}
	}
};

void ShowVector(const vector<int>& v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

void ShowGrid(const vector<vector<int>>& grid) {
	for (auto x : grid) {
		for (auto y : x) {
			if (y) cout << "■";
			else cout << "  ";
		}
		cout << endl;
	}
}

void ShowHits(const vector<vector<int>>& hits) {
	for (auto x : hits) {
		cout << "(" << x[0] << ", " << x[1] << "); ";
	}
	cout << endl;
}

inline int RowWidth(const vector<vector<int>>& g) { return g.size(); }
inline int ColWidth(const vector<vector<int>>& g) { return g[0].size(); }
inline bool OutSide(const vector<vector<int>>& g, const int& x, const int& y) {
	return (x < 0 || x >= RowWidth(g) || y < 0 || y >= ColWidth(g));
};

void GetConnected(vector<vector<int>>& g) {
	random_device rd;
	default_random_engine e(rd());
	uniform_int_distribution<> dis_0_1(0, 1);
	for (int i = 0; i < RowWidth(g); i++) {
		for (int j = 0; j < ColWidth(g); j++) {
			if (g[i][j] == 0) {
				g[i][j] = dis_0_1(e);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>>* grid = new vector<vector<int>>(n, vector<int>(n, 0));
	random_device rd;
	default_random_engine e(rd());
	uniform_int_distribution<> dis_0_1(0, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*grid)[i][j] = dis_0_1(e);
		}
	}
	
	vector<vector<int>>* hits = new vector<vector<int>>;
	uniform_int_distribution<> dis_0_n(0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			hits->push_back(vector<int>{ dis_0_n(e), dis_0_n(e) });
		}
	}
	ShowGrid(*grid);
	cout << endl;
	int too_less;
	while (cin >> too_less) {
		if (too_less == 1) {
			GetConnected(*grid);
			ShowGrid(*grid);
		}
		else {
			break;
		}
	}
	ShowHits(*hits);
	cout << endl;
	Solution s;
	vector<int> result = s.hitBricks(*grid, *hits);
	ShowVector(result);
	return 0;
}