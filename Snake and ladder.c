#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define NUM_SNAKES 5
#define NUM_LADDERS 5
#define MAX_PLAYERS 4

// Function prototypes
void initializeGameBoard(int board[], int snakes[][2], int ladders[][2]);
void displayGameBoard(int board[]);
void startGame(int board[], int snakes[][2], int ladders[][2]);

int main() {
    int board[BOARD_SIZE];
    int snakes[NUM_SNAKES][2], ladders[NUM_LADDERS][2];

    // Seed the random number generator
    srand(time(NULL));

    initializeGameBoard(board, snakes, ladders);
    displayGameBoard(board);
    startGame(board, snakes, ladders);

    return 0;
}

// Function to initialize the game board with snakes and ladders
void initializeGameBoard(int board[], int snakes[][2], int ladders[][2]) {
    // Initialize the game board with positions
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = i + 1;
    }

    // Initialize snakes and ladders
    for (int i = 0; i < NUM_SNAKES; i++) {
        snakes[i][0] = rand() % (BOARD_SIZE - 1) + 1; // Start position of snake
        snakes[i][1] = snakes[i][0] - (rand() % 10 + 1); // End position of snake
        board[snakes[i][0] - 1] = 'S';
    }

    for (int i = 0; i < NUM_LADDERS; i++) {
        ladders[i][0] = rand() % (BOARD_SIZE - 10) + 1; // Start position of ladder
        ladders[i][1] = ladders[i][0] + (rand() % 10 + 1); // End position of ladder
        board[ladders[i][0] - 1] = 'L';
    }
}

// Function to display the game board
void displayGameBoard(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%3d ", board[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

// Function to start the game
void startGame(int board[], int snakes[][2], int ladders[][2]) {
    int numPlayers;
    printf("\nEnter number of players (2 to 4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 2 || numPlayers > 4) {
        printf("Invalid number of players. Please enter a number between 2 and 4.\n");
        return;
    }

    int playerPositions[MAX_PLAYERS] = {0};

    printf("\n\nLet's start the game!\n");

    int currentPlayer = 0;
    while (playerPositions[currentPlayer] < BOARD_SIZE - 1) {
        // Roll the dice
        printf("\nPlayer %d's turn. Press Enter to roll the dice...", currentPlayer + 1);
        getchar(); // Clear input buffer
        getchar(); // Wait for user input
        int diceRoll = rand() % 6 + 1;
        printf("Player %d rolled a %d!\n", currentPlayer + 1, diceRoll);

        // Move the player
        int newPosition = playerPositions[currentPlayer] + diceRoll;
        if (newPosition >= BOARD_SIZE) {
            printf("Player %d needs %d to win, but rolled %d. Try again!\n", currentPlayer + 1, BOARD_SIZE - playerPositions[currentPlayer], diceRoll);
        } else {
            playerPositions[currentPlayer] = newPosition;
            printf("Player %d is now at position %d.\n", currentPlayer + 1, playerPositions[currentPlayer] + 1);

            // Check for snakes and ladders
            if (board[playerPositions[currentPlayer]] == 'S') {
                printf("Oh no! Player %d landed on a snake! Going down...\n", currentPlayer + 1);
                playerPositions[currentPlayer] = snakes[playerPositions[currentPlayer]][1] - 1;
            } else if (board[playerPositions[currentPlayer]] == 'L') {
                printf("Hooray! Player %d landed on a ladder! Going up!\n", currentPlayer + 1);
                playerPositions[currentPlayer] = ladders[playerPositions[currentPlayer]][1] - 1;
            }
        }

        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    printf("\nCongratulations! Player %d reached the end of the board!\n", currentPlayer + 1);
}
