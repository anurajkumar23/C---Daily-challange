// Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

// Example 1:

// Input:
// row = 3, col = 4 
// M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
// Output: $1 1 0 1 $1 0 0 1 $
// Explanation: Above the matrix of size 3x4
// looks like
// 1 1 0 1
// 1 0 0 1
// 1 1 0 1
// The two unique rows are R1: {1 1 0 1} and R2: {1 0 0 1}. 
// As R1 first appeared at row-0 and R2 appeared at row-1, in the resulting list, R1 is kept before R2.
// Example 2:

// Input:
// row = 2, col = 4 
// M[][] = {{0 0 0 1}, {0 0 0 1}}
// Output: $0 0 0 1 $
// Explanation: Above the matrix of size 2x4
// looks like
// 0 0 0 1
// 0 0 0 1
// Only unique row is $0 0 0 1 $

class solution{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>> ans; 
        set<vector<int>> s;  //creating a set;
        
        for(int i=0; i<row; i++){    //traversing from row
            vector<int> temp;         //making temp variable to store the value
            for(int j=0; j<col; j++){
                temp.push_back(M[i][j]);     // moving temp temp
            }
            if(!s.count(temp)){     // not in set of temp
                ans.push_back(temp);    //then push into temp
                s.insert(temp);        //insert into temp
            }
        }
        return ans;
        
    }
};