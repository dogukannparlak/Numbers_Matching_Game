#include <stdio.h>
#define SIZE 4
// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("   0 1 2 3\n");
    int i,j;
    for(i = 0; i < SIZE; i++) {
        printf("%d  ", i);
        for(j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Start the Matrix
    int matrix[SIZE][SIZE] = {
            {5, 7, 8, 6},
            {4, 5, 2, 4},
            {2, 8, 7, 6},
            {3, 3, 1, 1}
    };

    // Start the game board with 'X'
    char board[SIZE][SIZE];
    int i,j;
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            board[i][j] = 'X';
        }
    }

    // Start the found numbers array
    int foundNumbers[SIZE * SIZE] = {0};
    int foundCount = 0;

    // Start the total number of tries
    int totalTries = 0;

    // Print the game board at the beginning of the game
    printf("---------NUMBER MATCHING GAME---------------\n");
    printf("Game Board:\n\n");
    printBoard(board);
    // Game loop
    while (foundCount / 2 < SIZE * SIZE) {
        printf("\nEnter the coordinates (x1,y1) of the first item to open (separated by a space), or enter -1 to exit:");

        int x1, y1, x2, y2;
        scanf("%d", &x1);

        // Check if the user wants to quit the game
        if (x1 == -1) {
            break;
        }

        scanf("%d", &y1);

        // Check if the first element is already revealed
        if (board[x1][y1] != 'X') {
            printf("Error: This item has already been opened. Please try again.\n");
            continue;
        }

        // Reveal the first number in the game board
        board[x1][y1] = '0' + matrix[x1][y1];

        // Print the updated game board
        printBoard(board);

        printf("\nEnter the coordinates (x2,y2) of the second item to open (separated by a space), or enter -1 to exit:");
        scanf("%d %d", &x2, &y2);

        // Check if the second element is already revealed or the same as the first element
        if (board[x2][y2] != 'X' || (x1 == x2 && y1 == y2)) {
            printf("Error: This item has already been opened. Please try again.");
            board[x1][y1] = 'X'; // Hide the first element again
            continue;
        }

        //Open the second number on the game board
        board[x2][y2] = '0' + matrix[x2][y2];

        // Print the updated game board
        printBoard(board);

        // Increase the total number of tries
        totalTries++;

        // If the two elements are matching
        if (matrix[x1][y1] == matrix[x2][y2]) {

            // Add the number to the found numbers array
            foundNumbers[foundCount++] = matrix[x1][y1];

            // Print the found numbers
            printf("Found Numbers: ");
            int i;

            for (i = 0; i < foundCount; i++) {
                printf("-%d", foundNumbers[i]);
            }
            printf("\n");
            // Make the matching elements invisible
            board[x1][y1] = '  ';
            board[x2][y2] = '  ';
        } else {
            // If the two elements are not matching, turn them back to 'X'
            printf("\nNo match. Revealed elements will be hidden again.\n");
            board[x1][y1] = 'X';
            board[x2][y2] = 'X';
        }

        // Print the updated game board
        printBoard(board);
        if (foundCount == 8) {
            printf("Congratulations! You Found All Numbers \nTotal number of tries: %d\n", totalTries);
            break;
        }
    }
    return 0;
}
