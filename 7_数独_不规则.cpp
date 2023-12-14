//Sudoku不规则版
#include<iostream>
using namespace std;

int list[10][10];//index[1,9]
int par[10][10];//index[1,9]: i-row, j-colume. value: the part_index[0,8]. 
int anti[10][10];//index: i-part_index[0,8], j-th number[1,9]. val: postion[1,81].

bool check(int i, int j, int k)
{
    for (int jj = 1; jj < 10; jj++)if (list[i][jj] == k)return false;
    for (int ii = 1; ii < 10; ii++)if (list[ii][j] == k)return false;
    
	int p = par[i][j];
    for (int ii = 1; ii < 10; ii++){
    	int row = anti[p][ii] / 10; 
    	int col = anti[p][ii] % 10; 
    	if (list[row][col] == k)
		 	return false;
	}
    return true;
}

bool dfs(int i, int j)
{
    if (j == 10)
    {
        i++;
        j = 1;
    }
    if (i == 10)return true;
    if (list[i][j])return dfs(i, j + 1);
    for (int k = 1; k < 10; k++)
    {
        if (check(i, j, k))
        {
            list[i][j] = k;
            if (dfs(i, j + 1))return true;
        }
    }
    list[i][j] = 0;
    return false;
}

int main()
{
    char c;
    for (int i = 1; i < 10; i++)for (int j = 1; j < 10; j++)
    {//input part index from 0-8 
        cin >> c;
        par[i][j] = c - '0';
    }
    
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++){
        cin >> c;//input sudoku with 0, 1-9
        list[i][j] = c - '0';
    }
    
    for (int i = 1; i < 10; i++)for (int j = 1; j < 10; j++)anti[i][j] = 0;
    
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++){
            for (int k = 1; k < 10; k++)
                if (anti[par[i][j]][k] == 0)
                {
                    anti[par[i][j]][k] = i * 10 + j;
                    break;
                }
    }
    
    dfs(1, 1);
    
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 9; j++)cout << list[i][j] << " ";
        cout << list[i][9] << endl;
    }
    
    return 0;
}
