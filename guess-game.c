#include <stdio.h>
#include <stdlib.h>

//default ramdom number limit & guess limit
int maxNum = 10;
int guessLimit = 5;

int randomNumber;
int counter = 0;

void setArgs(int argc, char *argv[]);
void setNumber();
void getNumber();
void guess();
void compare(int try);
void displayHelp();

int main(int argc, char *argv[])
{
    setArgs(argc, argv);
    setNumber();
    //getNumber(); //that would be cheating :)
    guess();

    return 0;
}

void setArgs(int argc, char *argv[])
{
    int i;
    for(i=1; i < argc; i++) {
        if(strcmp(argv[i], "-m") == 0){
            maxNum = atoi(argv[i+1]);
        } else if(strcmp(argv[i], "-g") == 0){
            guessLimit = atoi(argv[i+1]);
        } else if(strcmp(argv[i], "-h") == 0){
            displayHelp();
        } else {
            if(argc > 1) {
                printf("Invalid option.\n");
                printf("try 'guess-game -h' for more information.\n");
                exit(0);
            }
        }
    }
}

void setNumber()
{
    srand(time(NULL));
    randomNumber = (rand() % maxNum) +1;
    printf("Guess a number between 1 and %i \n", maxNum);
}

void getNumber()
{
    printf("random number is: %i \n", randomNumber);
}

void guess()
{
    if(counter >= guessLimit) {
        printf("Game Over. The number was %i \n", randomNumber);
        return;
    }

    //try
    int try;
    printf("try to guess the number: ");
    scanf("%i", &try); 
    counter++;

    //compare
    compare(try);
}

void compare(int try)
{
    if(try < randomNumber) {
        printf("The number is higher than %i. %i tries left.\n", try, guessLimit - counter);
        guess();
    } else if(try > randomNumber) {
        printf("The number is lower than %i. %i tries left.\n", try, guessLimit - counter);
        guess();
    } else {
        printf("you guessed the number in %i tries!\n", counter);        
    }
}

void displayHelp()
{
    printf("Usage: guess-game [OPTIONS]...\n");
    printf("If no options are given, defaults to max random number 10 and max tries of 5\n");
    printf("\n");
    printf("-m MAX RANDOM NUMBER            sets the maximum random number. Default: 10.\n");
    printf("-g MAX TRIES                    sets the maximum tries. Default: 5.\n");
    printf("\n");
    printf("guess-game on github: <https://github.com/joaopfigueira/guess-game>\n");

    exit(0);
}