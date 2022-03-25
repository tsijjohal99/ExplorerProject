#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <conio.h>
using namespace std;

void printGrid(int &column,int &row, vector<vector<int>> grid) {
    cout << endl;
    for(int i = 0; i <= 2*row; i++) {
        for(int j = 0; j <= 2*column; j++){
            if(i%2==0) {
                if(j%2==0)
                    cout << " ";
                else cout<<"---";
            } else {
                if(j%2==0)
                    cout<<"|";
                else {
                    if (grid[(i-1)/2][(j-1)/2] == 1) {
                        cout<<" O ";
                    } else {
                        cout<<"   ";
                    }
                }
            }
        }
        cout << endl;
    }
}

vector<int> updatePlayerPosition(int &row, int &column, char move, vector<vector<int>> &grid, vector<int> &treasure) {
    int playerPositionRow, playerPositionColumn;
    vector< vector<int> >::const_iterator rowIt;
    vector<int>::const_iterator colIt;
    for (rowIt = grid.begin(); rowIt != grid.end(); rowIt++) {
        colIt = find(rowIt->begin(), rowIt->end(), 1);
        if (colIt != rowIt->end() ) {
            playerPositionRow = rowIt - grid.begin();
            playerPositionColumn = colIt - rowIt->begin();
        }
    }
    grid[playerPositionRow][playerPositionColumn] = 0;
    switch (move) {
        case 'W':
        case 'w':{
            if (playerPositionRow == 1){
                row++;
                vector<int> add(column,0);
                grid.insert(grid.begin(),add);
                treasure[0]++;
            } else if (playerPositionRow > 1) {
                playerPositionRow--;
            }
            break;
        }
        case 'S':
        case 's':{
            playerPositionRow++;
            if (playerPositionRow == row - 1) {
                row++;
                vector<int> add(column,0);
                grid.push_back(add);
            }
            break;
        }
        case 'A':
        case 'a':{
            if (playerPositionColumn == 1) {
                column++;
                for (int i = 0; i < row; i++) {
                    grid[i].insert(grid[i].begin(),0);
                }
                treasure[1]++;
            } else if (playerPositionColumn > 1) {
                playerPositionColumn--;
            }
            break;
        }
        case 'D':
        case 'd':{
            playerPositionColumn++;
            if (playerPositionColumn == column - 1) {
                column++;
                for (int i = 0; i < row; i++) {
                    grid[i].push_back(0);
                }
            }
            break;
        }
    }
    grid[playerPositionRow][playerPositionColumn] = 1;
    return vector<int> {playerPositionRow,playerPositionColumn};
}

vector<int> generateTreasure(int mid) {
    vector<int> treasure{(rand() % 10) - 5 + mid, (rand() % 10) - 5 + mid};
    return treasure;
}

bool treasureDistance(vector<int> treasure, vector<int> playerPosition) {
    if (treasure == playerPosition) {
        cout << "Well done, you found the treasure" << endl;
        return false;
    } else {
        float distance = sqrt(pow(treasure[0] - playerPosition[0], 2) + pow(treasure[1] - playerPosition[1], 2));
        cout << "You are " << distance << " blocks away." << endl;
    }
}

int main() {
    system("cls");
    srand((unsigned) time(0));

    int size = 3;
    int mid = (size - 1)/2;
    bool gameRunning = true;

    int column = size;
    int row = size;
    vector<vector<int>> grid(row, vector<int>(column,0));
    
    grid[mid][mid] = 1;
    vector<int> treasure = generateTreasure(mid);

    while (gameRunning) {
        printGrid(column, row, grid);   
        char move;
        cout << "Enter a move: " << endl;
        move = getch();
        if (move == '0') {
            gameRunning = false;
        } else {
            vector<int> playerPosition = updatePlayerPosition(row, column, move, grid, treasure);
            gameRunning = treasureDistance(treasure, playerPosition);
        }
    }

    return 0;
}