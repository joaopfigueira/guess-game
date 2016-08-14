#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//default ramdom number limit & guess limit
int maxNum = 10;
int guessLimit = 5;

int randomNumber;
int counter = 0;

int setArgs(int argc, char *argv[]);
void setNumber();
void getNumber();
void guess();
void compare(int try);
void displayHelp();

int main(int argc, char *argv[])
{
    setArgs(argc, argv);

    return 0;
}

int setArgs(int argc, char *argv[])
{
    int opt;
    while((opt = getopt(argc, argv, "hm:g:")) != 1) {
        switch (opt) {
            case 'm':
                maxNum = atoi(optarg);
                break;
            case 'g':
                guessLimit = atoi(optarg);
                break;
            case 'h':
                displayHelp();
                break;
            default:
                setNumber();
                //getNumber(); //that would be cheating :)
                guess();
                exit(EXIT_FAILURE);
        }
    }

    return 0;
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