/*
* 766. 托普利茨矩阵
*
如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
给定一个 M x N 的矩阵，当且仅当它是托普利茨矩阵时返回 True。

示例 1：
输入: 
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
输出: True
解释:
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是True。

示例 2：
输入:
matrix = [
  [1,2],
  [2,2]
]
输出: False
解释: 
对角线"[1, 2]"上的元素不同。


注意：
     matrix 是一个包含整数的二维数组。
    matrix 的行数和列数均在 [1, 20]范围内。
    matrix[i][j] 包含的整数在 [0, 99]范围内。

* 
* 解题思路： 
*   
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //检查第一列的所有值
        for(int i=0;i < matrix.size()-1;++i){
            if(!check(matrix, i, 0, matrix[i][0]))
                return false;
        }

        //检查第一行的所有值，除了第一个[0,0]
        for(int j=1;j < matrix[0].size()-1;++j){
            if(!check(matrix, 0, j, matrix[0][j]))
                return false;
        }
        return true;
    }

    bool check(vector<vector<int>>& matrix, int x, int y, int base){
        while(++x  < matrix.size() && ++y < matrix[0].size()){
            if(matrix[x][y] != base)
                return false;
        }
        return true;
    }
};