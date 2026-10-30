#include "queue"
#include "iostream"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. 
A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required 
so that the state of the board is solved. 
If it is impossible for the state of the board to be solved, return -1.

*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const vector<vector<int>> neighbors = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}};
        const string target = "123450";
        string start;
        for (const auto& row : board){
            for (int tile : row) start += to_string(tile);
        }

        unordered_set<string> visisted;
        queue<pair<string, int>> pending;
        pending.push({start, 0});
        visisted.insert(start);

        while(!pending.empty()){
            auto [state, moves] = pending.front();
            pending.pop();
            if (state == target) return moves;
            int zero = state.find('0');

            for (int nextPosition : neighbors[zero]){
                string nextState = state;
                swap(nextState[zero], nextState[nextPosition]);
                if (visisted.insert(nextState).second) pending.push({nextState, moves + 1});
            }
        }
        return -1;
    }
};


int main(){
    Solution s;

    vector<vector<int>> board1 = {{1,2,3}, {4,0,5}};
    vector<vector<int>> board2 = {{1,2,3}, {5,4,0}};
    vector<vector<int>> board3 = {{4,1,2}, {5,0,3}};

    cout << "Want :  1, Was : " << s.slidingPuzzle(board1) << endl;
    cout << "Want : -1, Was : " << s.slidingPuzzle(board2) << endl;
    cout << "Want :  5, Was : " << s.slidingPuzzle(board3) << endl;

    return 0;
}