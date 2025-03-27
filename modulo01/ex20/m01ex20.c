#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h> 

int main() {
    int current_amount = 25;
    int bet_amount = 0;
    char generator_dir[1024] = "/media/sf_partilha/modulo01/ex20/cheat";
    int guess;
    int exit_status;

    while(current_amount > 0) {
        printf("=====================================\n");
        printf("Welcome to the Betting Game!\n");
        printf("=====================================\n");
        printf("You have $%d available.\n", current_amount);
        printf("How much would you like to bet? $");
        guess = 0;
        scanf("%d", &bet_amount);

        printf("\nYou have chosen to bet $%d.\n", bet_amount);
        printf("Good luck!\n");

        pid_t pid = fork();
        if(pid < 0) {
            perror("fork failed.");
            exit(1);
        }

        if(pid == 0) {
            if(chdir(generator_dir) == -1){
                perror("chdir failed.");
                exit(6);
            }

           //execl("/bin/make", "make", "run", NULL);
           execl("./cheat", "cheat", NULL);
           perror("exec failed.");
           exit(7); 
        } else {

            int status = 0;
            wait(&status);
            printf("I'm thinking of a number between 1 and 5...\n");
            printf("Can you guess what it is? Enter a number between 1 and 5: ");
            while(guess < 1 || guess > 5){
                if (scanf("%d", &guess) != 1 || guess < 1 || guess > 5) {
                    printf("Oops! Please enter a valid number between 1 and 5.\n");
                } else {
                printf("You guessed: %d\n", guess);
                }
            }
            if(WIFEXITED(status)) {
                exit_status = WEXITSTATUS(status);

                if(exit_status > 0 && exit_status < 6){
                    if (exit_status == guess) {
                        printf("Congratulations! You guessed the correct number: %d! 🎉\n", exit_status);
                        printf("You are a true master of guessing!\n");
                        current_amount = current_amount + (bet_amount * 2);
                    } else {
                        printf("Oops! You guessed wrong. The correct number was: %d 😞\n", exit_status);
                        printf("Better luck next time! Keep practicing your guessing skills!\n");
                        current_amount = current_amount - bet_amount;
                    }
                }
            }
        }
    }

    printf("\n*********************************\n");
    printf("    GAME OVER! YOU LOST EVERYTHING!    \n");
    printf("*********************************\n");
    printf("\nOh no! You've lost all your money! 😱\n");
    printf("Your wallet is empty, and the game is over...\n\n");
    printf("Better luck next time, brave player.\n");
    printf("Perhaps you can try again with a new strategy... 😅\n");
    printf("\n*********************************\n");
}