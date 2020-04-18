// Problem link: https://leetcode.com/problems/number-of-islands

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isValidCell(vector<vector<char>>& grid, int row, int col) {
    if (row < 0 || col < 0 || row >= (int)grid.size() || col >= (int)grid[0].size()) {
        return false;
    }

    if (grid[row][col] == '0') {
        return false;
    }

    return true;
}

// DFS Solution
// Time complexity => O(m*n)
// Space complexity => O(m*n) we might end up having all elements in call stack if all elements are '1'
void traverseIslandDFS(vector<vector<char>>& grid, int row, int col) {
    if (!isValidCell(grid, row, col)) {
        return;
    }

    grid[row][col] = '0';

    traverseIslandDFS(grid, row, col + 1);
    traverseIslandDFS(grid, row + 1, col);
    traverseIslandDFS(grid, row - 1, col);
    traverseIslandDFS(grid, row, col - 1);
}

// BFS Solution
// Time complexity => O(m*n)
// Space complexity => O(m*n) we might end up having all elements in our queue
void insertNeighbourLand(queue<pair<int, int>>& q, vector<vector<char>>& grid, int p_row, int p_col) {
    // for checking neighbour lands (r, c+1), (r+1, c),(r-1,c),(r,c-1)
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (pair<int, int> dir : directions) {
        int nbrRow = p_row + dir.first;
        int nbrCol = p_col + dir.second;

        if (!isValidCell(grid, nbrRow, nbrCol)) {
            continue;
        }

        if (grid[nbrRow][nbrCol] == '1') {
            pair<int, int> nbrPair(nbrRow, nbrCol);
            q.push(nbrPair);
        }
    }
}

void traverseIslandBFS(vector<vector<char>>& grid, int row, int col) {
    queue<pair<int, int>> q;
    pair<int, int> currPair(row, col);
    q.push(currPair);

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int p_row = front.first;
        int p_col = front.second;

        if (!isValidCell(grid, p_row, p_col)) {
            continue;
        }

        grid[p_row][p_col] = '0';
        insertNeighbourLand(q, grid, p_row, p_col);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int numIsland = 0;

    for (int row = 0; row < (int)grid.size(); ++row) {
        for (int col = 0; col < (int)grid[0].size(); ++col) {
            char cell = grid[row][col];

            if (cell == '1') {
                traverseIslandDFS(grid, row, col);
                // traverseIslandBFS(grid, row, col);
                ++numIsland;
            }
        }
    }

    return numIsland;
}

int main() {
    vector<vector<char>> grid;
    // initialise the grid yourself or go to problem link at the top of this page ⬆︎⬆︎⬆︎
    cout << numIslands(grid) << endl;
}
