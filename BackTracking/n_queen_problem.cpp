#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> queenCol(n); // queenCol[row] = column [row, column] is the exact queen position 

// used to check whether this position is safe or not

bool isSafe(int row, int column)
{  
    for(int i = 1; i < row; i++)
    {
        // same column or same diagonal check
        if(queenCol[i] == column || abs(queenCol[i] - column) == abs(i - row))
            return false;
    }
    return true;
}

void nQueens(int row)
{
    // base case
    if(row > n)
    {
        static int solutionNo = 1; //this will be called recursively so static is necessary
        cout << "Solution :" << solutionNo++ << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << queenCol[i] << " " << endl;
        }
        cout << endl;

        return;
    }

    for(int col = 1; col <= n; col++)
    {
        if(isSafe(row, col))
        {
            queenCol[row] = col;
            nQueens(row + 1);
            // MOST IMPORTANT PART
            //if failed backtrack
            queenCol[row] = 0;
        }
    }
}

int main()
{
    cout << "Enter value of N : " << endl;
    cin >> n;

    queenCol.resize(n + 1, 0);
    nQueens(1); // 1 based indexing 

    return 0;
}