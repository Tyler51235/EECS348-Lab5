#include <stdio.h>

void printCombinations(int score) { // the function that prints the different combinations
    int td, tdf, tde, fg, safety, conv2, extra; // creates variables
    for (td = 0; td <= score / 6; td++) {//starts with 0, and as long as score isnt over the score given by user, it will add 1 to its counter,for a touchdown
        for(tde = 0; tde <= score / 7; tde++){//starts with 0, and as long as score isnt over the score given by user, it will add 1 to its counter,for a touch down with an extra point
            for (fg = 0; fg <= score / 3; fg++) {// starts with 0, and as long as score isnt over the score given by user, it will add 1 to its counter,field goal
                for (safety = 0; safety <= score / 2; safety++) { //starts with 0, and as long as score isnt over the score given by user, it will add 1 to its counter,safety
                    for (conv2 = 0; conv2 <= score / 8; conv2++) { //starts with 0, and as long as score isnt over the score given by user, it will add 1 to its counter,touch down with 2 point
                        int total_score = td * 6 + fg * 3 + safety * 2 + conv2 * 8 + tde * 7 + tdf * 9; //
                        if (total_score == score) { //prints when for each combination possible
                            printf("%d TD + 2pt,  %d TD + 1pt, %dTD, %d FG, %d Safety\n", conv2, tde, td, fg, safety);//prints
                        }        
                    }
                }
            }
        }
    }

}
int main() {// main function 
    int score;//variable created
    while (1) { //keeps the while loop on
        printf("Enter the NFL score: ");//prints asking user for a score
        scanf("%d", &score);//saves the score from the user
        if (score <= 1) { // if the is less than or equal to 1 than it stops the while loop
            break;
        }
        printf("Possible combinations of scoring plays:\n");//prints
        printCombinations(score);//calls function with 
    }
    return 0;
}
