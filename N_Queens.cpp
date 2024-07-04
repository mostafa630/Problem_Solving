 //#----------------------------------------> بسم الله <------------------------------------------------#//

//problem link : https://leetcode.com/problems/n-queens/
using namespace std;
#include <iostream>
#include<deque>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_map>


//size of board
int n;
//required to store results
vector<vector<int>>all_valid_posistions;
vector<int>current_valid_position;
//required to track visited rows and diagonals --> (if true that means there is a queen exist)
bool row_visited[10] = { false };
bool diagonal_1_visitied[20] = { false };
bool diagonal_2_visitied[20] = { false };


bool is_valid_cell(int i, int j)
{
    if (!(row_visited[i] || diagonal_1_visitied[i + j] || diagonal_2_visitied[i - j + n-1]))
        return true; 
    return false;
}
void solve(int j)  // j : column index , i : row index
{
    //base case
    if (j > n-1)
    {
        all_valid_posistions.push_back(current_valid_position);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (is_valid_cell(i, j))
        {
            row_visited[i] = diagonal_1_visitied[i + j] = diagonal_2_visitied[i - j + (n-1)] = true;
            current_valid_position.push_back(i);
            solve(j + 1); // recursion step : solve from next column
            row_visited[i] = diagonal_1_visitied[i + j] = diagonal_2_visitied[i - j + (n-1)] = false;
            current_valid_position.pop_back();
        }
    }
}
vector<string> draw_board(vector<int>valid_position)
{
    vector<string>board;
    string row = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (valid_position[j] == i)
                row.push_back('Q');
            else
                row.push_back('.');
        }
        board.push_back(row);
        row.clear();
    }
    return board;
}
void construct_all_boards(vector< vector<string>>& all_valid_boards)
{
    for (int i = 0; i < all_valid_posistions.size(); i++)
    {
        vector<string> board = draw_board(all_valid_posistions[i]);
        all_valid_boards.push_back(board);
    }
}
void print_all_boards(vector<vector<string>>all_valid_boards)
{
    for (vector<string>board : all_valid_boards)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "-----------------------------------\n";
    }
}

int main()
{
    
    vector<vector<string>>all_valid_boards;
    cin >> n; //n*n is size of board
    solve(0);
    construct_all_boards(all_valid_boards);
    cout << "total number of valid boards = " << all_valid_boards.size() << " : \n\n";
    print_all_boards(all_valid_boards);
}
