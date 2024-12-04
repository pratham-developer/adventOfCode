
# 🚀 Question 1
The program identifies and counts the occurrences of the word "XMAS" in a 2D grid of characters, checking in all 8 possible directions (up, down, left, right, and the 4 diagonals).

- #### `Matrix Representation and Input:`
The matrix is read from a file named input.txt, where each line represents a row in the grid.
The characters of each line are stored in a 2D vector matrix.

- #### `Validation of Boundaries:`
The function isValid(i, j, r, c) checks if a cell (i, j) lies within the boundaries of the matrix (row count r, column count c).
It ensures we don't access cells outside the grid.

- #### `Directional Search:`
The travel function looks for the word "XMAS" starting from a cell (i, j) that contains the character 'X'.
The 8 possible directions are defined using two arrays, rs and cs, representing row and column shifts, respectively.

- #### `Checking for "XMAS":`
For each of the 8 directions, the function validates whether the sequence "M", "A", "S" appears at step offsets 1, 2, and 3 from the starting cell (i, j):

Offset 1: The next character should be 'M'.

Offset 2: The next character should be 'A'.

Offset 3: The next character should be 'S'.

If any condition fails, the current direction is disqualified.

- #### `Counting Matches:`
If the word "XMAS" is found in a direction, a counter is incremented.
The function travel returns the count of valid "XMAS" sequences found starting from (i, j) in all directions.

- #### `Main Loop for the Entire Matrix:`
The countXmas function iterates over each cell in the matrix.
If a cell contains 'X', the travel function is called to explore potential matches for "XMAS" starting from that cell.

- #### `Output:`
The program outputs the total count of "XMAS" sequences found in the entire grid.


# 🚀 Question 2
This program finds and counts the number of "X-MAS" patterns in a 2D grid. An X-MAS pattern is defined as two "MAS" sequences that intersect in an 'X' shape.

- #### `MAS Sequence:`
Each sequence must consist of the letters 'M', 'A', and 'S', in that order.
The letters must appear consecutively along a straight line in one of the eight possible directions (horizontal, vertical, or diagonal).
Each sequence can be read forwards or backwards (e.g., "MAS" or "SAM").

- #### `Intersection:`
The two "MAS" sequences must intersect at their middle letter, 'A', forming an 'X' shape.
The sequences must be distinct and cannot share any nodes except for the intersecting 'A'.

- #### `Boundary Check (isValid):`
Ensures that a given cell (i, j) is within the grid boundaries to avoid invalid memory access.

- #### `Tracking Grid (numGrid):`
A grid parallel to the main matrix, where:

1 represents cells marked as 'M'.

2 represents cells marked as 'A'.

3 represents cells marked as 'S'.

This helps track potential "MAS" sequences for further verification.

- #### `The function travel:`
Starts from each 'M' in the matrix.
Checks for the sequence 'A' followed by 'S' in all 8 directions using directional offsets (rs and cs).
If valid, marks the respective cells in numGrid.

- #### `The function findXmasGrid:`
Starts from any 'A' cell (value 2 in numGrid) and verifies if:

All four diagonally adjacent cells exist (boundary check).

These diagonal cells have appropriate values (1 for 'M', 3 for 'S').

The diagonal cell pairs are distinct (to prevent duplicate patterns).

If all conditions are met, this 'A' is the center of a valid "X-MAS" pattern.

- #### `Matrix Traversal:`
The matrix is scanned cell-by-cell.

For each 'M', the travel function identifies and marks "MAS" sequences in numGrid.

For each 'A' in numGrid, the findXmasGrid function validates if it forms a center for "X-MAS".

- #### `Counting Patterns:`
The total count of valid "X-MAS" patterns is returned.


