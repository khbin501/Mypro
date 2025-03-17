#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 2500
#define LINE_LENGTH 2500

typedef struct {
    char region[200];
    int age;
    char candidate[200];
} Vote;

int main() {
    FILE *file = fopen("/root/Desktop/Mypro/VSC/C/FileIo/vote.txt", "r");
    
    Vote votes[MAX_CANDIDATES];
    char line[LINE_LENGTH];
    int totalVotes = 0, thirdRowVotes = 0, tenthRowVotes = 0;
    int washingtonVotes = 0, lincolnVotes = 0, RooseveltVotes = 0;

    while (fgets(line, LINE_LENGTH, file)) {
        sscanf(line, "%s %d %s", votes[totalVotes].region, &votes[totalVotes].age, votes[totalVotes].candidate);
        
        if (strcmp(votes[totalVotes].candidate, "Washington") == 0) washingtonVotes++;
        if (strcmp(votes[totalVotes].candidate, "Lincoln") == 0) lincolnVotes++;
        if (strcmp(votes[totalVotes].candidate, "Roosevelt") == 0) RooseveltVotes++;
        
        totalVotes++;
    }
    
            fclose(file);

    printf("Vote Percentages:\n");
    printf("Washington: %.2f%%\n", (washingtonVotes * 100.0) / totalVotes);
    printf("Lincoln: %.2f%%\n", (lincolnVotes * 100.0) / totalVotes);
    printf("Roosevelt: %.2f%%\n", (RooseveltVotes * 100.0) / totalVotes);

    printf("\nEvery Third Row:\n");
    washingtonVotes = lincolnVotes = RooseveltVotes = 0;
    for (int i = 0; i < totalVotes; i+=3) {
        if (strcmp(votes[i].candidate, "Washington") == 0) washingtonVotes++;
        if (strcmp(votes[i].candidate, "Lincoln") == 0) lincolnVotes++;
        if (strcmp(votes[i].candidate, "Roosevelt") == 0) RooseveltVotes++;
    }
    printf("Washington: %d votes\n", washingtonVotes);
    printf("Lincoln: %d votes\n", lincolnVotes);
    printf("Roosevelt: %d votes\n", RooseveltVotes);

    printf("\nEvery Tenth Row:\n");
    washingtonVotes = lincolnVotes = RooseveltVotes = 0;
    for (int i = 0; i < totalVotes; i+=10) {
        if (strcmp(votes[i].candidate, "Washington") == 0) washingtonVotes++;
        if (strcmp(votes[i].candidate, "Lincoln") == 0) lincolnVotes++;
        if (strcmp(votes[i].candidate, "Roosevelt") == 0) RooseveltVotes++;
    }
    printf("Washington: %d votes\n", washingtonVotes);
    printf("Lincoln: %d votes\n", lincolnVotes);
    printf("Roosevelt: %d votes\n", RooseveltVotes);
        
        
    return 0;

}