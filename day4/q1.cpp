#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Check if the given cell (i, j) is within the matrix boundaries
bool isValid(int i, int j, int r, int c) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

// Check for "XMAS" pattern starting at (i, j) in all 8 directions
int travel(int i, int j, int r, int c, vector<vector<char>>& matrix) {
    int count = 0;
    // Direction vectors for 8 directions
    int rs[] = {0, 1, 0, -1, 1, 1, -1, -1};  // Row shifts
    int cs[] = {1, 0, -1, 0, 1, -1, -1, 1};  // Column shifts

    // Iterate through all 8 directions
    for (int dir = 0; dir < 8; dir++) {
        bool xMas = true;  // Assume the pattern exists initially
        for (int next = 1; next < 4; next++) {
            int newi = i + (next * rs[dir]);  // Next row
            int newj = j + (next * cs[dir]);  // Next column
            // Check boundaries
            if (!isValid(newi, newj, r, c)) {
                xMas = false;
                break;
            }
            // Validate the sequence "M", "A", "S" at steps 1, 2, and 3
            if (next == 1 && matrix[newi][newj] != 'M') {
                xMas = false;
                break;
            } else if (next == 2 && matrix[newi][newj] != 'A') {
                xMas = false;
                break;
            } else if (next == 3 && matrix[newi][newj] != 'S') {
                xMas = false;
                break;
            }
        }
        // If "XMAS" is found in the current direction, increment the count
        if (xMas) {
            count++;
        }
    }
    return count;
}

// Count the total number of "XMAS" patterns in the matrix
int countXmas(vector<vector<char>>& matrix) {
    int r = matrix.size();    // Number of rows
    int c = matrix[0].size(); // Number of columns
    int count = 0;

    // Traverse each cell in the matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 'X') {  // Look for cells with 'X'
                count += travel(i, j, r, c, matrix);  // Check for "XMAS" from this cell
            }
        }
    }
    return count;
}

int main() {
    // Open the input file
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "error opening the file" << endl;
        return 1;
    }

    // Read the matrix from the file
    string temp;
    vector<vector<char>> matrix;
    while (getline(file, temp)) {
        vector<char> tempV;
        for (char i : temp) {
            tempV.push_back(i);
        }
        matrix.push_back(tempV);
    }

    // Print the total count of "XMAS" patterns
    cout << countXmas(matrix);
    return 0;
}