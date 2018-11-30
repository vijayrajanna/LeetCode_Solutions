/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.63%)
 * Total Accepted:    157.7K
 * Total Submissions: 483.3K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	bool first = true;
    
    if(obstacleGrid[0][0] == 1) return 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1) 
                obstacleGrid[i][j] = -1;
          
			
			if (i == 0)
			{
				if (obstacleGrid[i][j] < 0)
				{
					while (j < n)
					{
						obstacleGrid[i][j] = -1;
						j++;
					}
					break;
				}
				else
					obstacleGrid[i][j] = 1;
			}
			if (j == 0 && first)
			{
				if (obstacleGrid[i][j] < 0)
				{
					int k = i;
					while (k < m)
					{
						obstacleGrid[k][j] = -1;
						k++;
					}
					first = false;
				}
				else
					obstacleGrid[i][j] = 1;
			}

		}
	}


    
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] < 0) continue;
			else
            {
                int a = (obstacleGrid[i - 1][j] > 0? obstacleGrid[i - 1][j]: 0);
                
                int b = (obstacleGrid[i][j - 1] > 0? obstacleGrid[i][j - 1]: 0);
                
				obstacleGrid[i][j] = a + b;
			}
		}
	}
	return obstacleGrid[m - 1][n - 1] == -1 ? 0 : obstacleGrid[m - 1][n - 1];
}
};
