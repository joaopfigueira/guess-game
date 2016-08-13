#include <stdio.h>

#define MAXNUM 10
#define GUESSLIMIT 5

int randomNumber;
int counter = 0;

void setNumber();
void getNumber();
void guess();
void compare(int try);

void main()
{
    setNumber();
    //getNumber(); //that would be cheating :)
    guess();
}

void setNumber()
{
    srand(time(NULL));
    randomNumber = (rand() % MAXNUM) +1;
    printf("Guess a number between 1 and %i \n", MAXNUM);
}

void getNumber()
{
    printf("random number is: %i \n", randomNumber);
}

void guess()
{
    if(counter >= GUESSLIMIT) {
        printf("Game Over. The number was %i", randomNumber);
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
        printf("The number is higher than %i. %i tries left.\n", try, GUESSLIMIT - counter);
        guess();
    } else if(try > randomNumber) {
        printf("The number is lower than %i. %i tries left.\n", try, GUESSLIMIT - counter);
        guess();
    } else {
        printf("you guessed the number in %i tries!\n", counter);        
    }
}