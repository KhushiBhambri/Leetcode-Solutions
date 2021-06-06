
//problem 1886. Determine Whether Matrix Can Be Obtained By Rotation
// Given two n x n binary matrices mat and target,
// return true if it is possible to make mat equal to target by rotating mat in 90-degree increments,
// or false otherwise.

// Example 1:
// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
// Example 2:

// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
// Output: false
// Explanation: It is impossible to make mat equal to target by rotating mat.
// Example 3:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.

// Constraints:

// n == mat.length == target.length
// n == mat[i].length == target[i].length
// 1 <= n <= 10
// mat[i][j] and target[i][j] are either 0 or 1.

class Solution
{
public:
    void rotate(vector<vector<int>> &arr)
    {
        int n = arr[0].size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[n - 1 - j][i];
                arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j];
                arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i];
                arr[j][n - 1 - i] = temp;
            }
        }
    }
    bool check(vector<vector<int>> &mat, vector<vector<int>> target)
    {

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
                if (mat[i][j] != target[i][j])
                    return false;
        }
        return true;
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if (check(mat, target))
            return 1;
        rotate(mat);

        if (check(mat, target))
            return 1;
        rotate(mat);
        if (check(mat, target))
            return 1;
        rotate(mat);
        if (check(mat, target))
            return 1;
        return false;
    }
};
