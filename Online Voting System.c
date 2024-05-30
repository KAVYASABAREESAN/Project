#include <stdio.h>
#include <stdlib.h>

// Define the structure for a candidate
struct Candidate {
    char name[50];
    int voteCount;
};

int main() {
    int numCandidates;
    
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    
    // Dynamically allocate memory for the candidates
    struct Candidate *candidateList = (struct Candidate*)malloc(numCandidates * sizeof(struct Candidate));
    
    // Input the names of the candidates
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidateList[i].name);
        candidateList[i].voteCount = 0; // Initialize the votes for each candidate to zero
    }
    
    // Display the list of candidates
    printf("\nList of candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidateList[i].name);
    }
    
    // Allow the user to cast their vote
    int userChoice;
    printf("\nEnter the number of the candidate you want to vote for: ");
    scanf("%d", &userChoice);
    
    // Validate the user's choice
    if (userChoice < 1 || userChoice > numCandidates) {
        printf("Invalid choice!\n");
        free(candidateList); // Free the allocated memory
        return 1; // Exit with error
    }
    
    // Increment the vote count for the chosen candidate
    candidateList[userChoice - 1].voteCount++;
    
    // Display a confirmation message
    printf("Thank you for voting for %s!\n", candidateList[userChoice - 1].name);
    
    // Display the updated vote count for each candidate
    printf("\nVote count:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidateList[i].name, candidateList[i].voteCount);
    }
    
    // Free the allocated memory
    free(candidateList);
    
    return 0; // Exit successfully
}
