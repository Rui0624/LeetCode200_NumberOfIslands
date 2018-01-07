//
//  main.cpp
//  LeetCode200_NumberOfIslands
//
//  Created by Rui on 1/6/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != '0' && visited[i][j] == false)
                {
                    numberOfIslandsDFS(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void numberOfIslandsDFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        if(x < 0 || x >= grid.size()) return;
        if(y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] != '1' || visited[x][y] == true) return;
        visited[x][y] = true;
        numberOfIslandsDFS(grid, visited, x - 1, y);
        numberOfIslandsDFS(grid, visited, x, y - 1);
        numberOfIslandsDFS(grid, visited, x + 1, y);
        numberOfIslandsDFS(grid, visited, x, y + 1);
    }
};
