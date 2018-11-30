/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (28.54%)
 * Total Accepted:    180.7K
 * Total Submissions: 633.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
 vector<int> spiralOrder(vector<vector<int>>& matrix) 
 {
	 if (matrix.empty()) return {};
	 int m = matrix.size(), n = matrix[0].size();
	 vector<int> spiral(m * n);

	 int l, r, d, u, k;
	 l = u = k = 0;
	 d = m - 1;
	 r = n - 1;

	 while (true)
	 {
		 for (int col = l; col <= r; col++)
			 spiral[k++] = matrix[u][col];
		 if (++u > d) break;

		 for (int row = u; row <= d; row++)
			 spiral[k++] = matrix[row][r];
		 if (--r < l) break;

		 for (int col = r; col >= l; col--)
			 spiral[k++] = matrix[d][col];
         
		 if (--d < u) break;

		 for (int row = d; row >= u; row--)
			 spiral[k++] = matrix[row][l];
		 if (++l > r) break;
	 }
     
     return spiral;
 }
};
