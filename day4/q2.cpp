#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Check if a cell is within matrix boundaries
bool isValid(int i, int j, int r, int c) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

// Verify if the cell at (i, j) forms the center of an "X-MAS" pattern
int findXmasGrid(int i, int j, int r, int c, vector<vector<int>>& numGrid) {
    // Check if all diagonal neighbors exist
    for (int rs = -1; rs <= 1; rs += 2) {
        for (int cs = -1; cs <= 1; cs += 2) {
            if (!isValid(i + rs, j + cs, r, c)) {
                return 0; // Out of bounds
            }
        }
    }
    // Validate diagonal cells and ensure they meet the "X-MAS" criteria
    if (numGrid[i - 1][j + 1] == 0 || numGrid[i + 1][j - 1] == 0 || 
        numGrid[i + 1][j + 1] == 0 || numGrid[i - 1][j - 1] == 0) {
        return 0;
    }
    if (numGrid[i - 1][j + 1] == 2 || numGrid[i + 1][j - 1] == 2 || 
        numGrid[i + 1][j + 1] == 2 || numGrid[i - 1][j - 1] == 2) {
        return 0;
    }
    if (numGrid[i - 1][j + 1] == numGrid[i + 1][j - 1]) {
        return 0;
    }
    if (numGrid[i + 1][j + 1] == numGrid[i - 1][j - 1]) {
        return 0;
    }
    return 1; // Valid X-MAS pattern
}

// Find "MAS" patterns starting from 'M' and mark them in numGrid
void travel(int i, int j, int r, int c, vector<vector<char>>& matrix, vector<vector<int>>& numGrid) {
    int rs[] = {0, 1, 0, -1, 1, 1, -1, -1}; // Direction row offsets
    int cs[] = {1, 0, -1, 0, 1, -1, -1, 1}; // Direction column offsets
    pair<int, int> p1, p2;

    for (int dir = 0; dir < 8; dir++) {
        bool mas = true; // Assume "MAS" exists
        for (int next = 1; next < 3; next++) {
            int newi = i + (next * rs[dir]);
            int newj = j + (next * cs[dir]);
            if (!isValid(newi, newj, r, c)) {
                mas = false; // Out of bounds
                break;
            }
            // Validate sequence 'A' at step 1 and 'S' at step 2
            if (next == 1) {
                if (matrix[newi][newj] != 'A') {
                    mas = false;
                    break;
                } else {
                    p1 = {newi, newj};
                }
            } else if (next == 2) {
                if (matrix[newi][newj] != 'S') {
                    mas = false;
                    break;
                } else {
                    p2 = {newi, newj};
                }
            }
        }
        if (mas) {
            // Mark cells in numGrid
            numGrid[i][j] = 1;             // 'M'
            numGrid[p1.first][p1.second] = 2; // 'A'
            numGrid[p2.first][p2.second] = 3; // 'S'
        }
    }
}

// Count the total number of "X-MAS" patterns in the matrix
int countXmas(vector<vector<char>>& matrix) {
    int r = matrix.size(); // Rows
    int c = matrix[0].size(); // Columns

    vector<vector<int>> numGrid(r, vector<int>(c, 0)); // Tracking grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 'M') { // Start from 'M'
                travel(i, j, r, c, matrix, numGrid);
            }
        }
    }

    // Count valid X-MAS patterns
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (numGrid[i][j] == 2) { // Check intersections (center 'A')
                count += findXmasGrid(i, j, r, c, numGrid);
            }
        }
    }
    return count;
}

int main() {
    // Read input from file
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "error opening the file" << endl;
        return 1;
    }

    string temp;
    vector<vector<char>> matrix;
    while (getline(file, temp)) {
        vector<char> tempV(temp.begin(), temp.end());
        matrix.push_back(tempV);
    }

    // Output total X-MAS patterns
    cout << countXmas(matrix);
    return 0;
}
