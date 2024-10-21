#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf(" ______     ______        _____  \n");
    printf("/ ___  \\   / ___  \\      / ___ \\ \n");
    printf("\\/   \\  \\  \\/   )  )    ( (   ) )\n");
    printf("   ___) /      /  /      \\/  / / \n");
    printf("  (___ (      /  /          ( (  \n");
    printf("      ) \\    /  /           | |  \n");
    printf("/\\___/  /   /  /            (_)  \n");
    printf("\\______/    \\_/              _   \n");
    printf("                            (_)   \n");

    printf("          By: Tryplex             \n\n");

    // Global variables
    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int acertou = 0;

    int tentativas = 1;
    double pontos = 1000;
    int nivel = 0;
    int numerodetentativas;

    // Welcome message and game status
    printf("Welcome to our guessing game!\n");
    printf("Your goal is to guess the secret number. Good luck!\n\n");
    printf("With each level, you get +5 more chances to guess!\n\n");

    // Difficulty level validation
    char entrada[100];
    char *p;

    while (1)
    {
        printf("What is the difficulty level?\n\n");
        printf("[1] Easy [2] Medium [3] Hard\n\n");

        printf("Chosen level is: ");
        fgets(entrada, sizeof(entrada), stdin); // Captures the input as a string

        nivel = strtol(entrada, &p, 10); // Tries to convert the string to a number

        // Checks if the conversion was successful
        if (p == entrada || *p != '\n')
        {
            printf("\nInvalid input! Try again.\n\n");
        }
        else
        {
            break;
        }
    }

    // Defining the number of attempts based on the chosen level
    switch (nivel)
    {
    case 1:
        numerodetentativas = 15;
        break;
    case 2:
        numerodetentativas = 10;
        break;
    case 3:
        numerodetentativas = 5;
        break;
    default:
        printf("Invalid level! Using Easy level as default.\n");
        numerodetentativas = 15;
        break;
    }

    // Main game loop
    for (int i = 1; i <= numerodetentativas; i++)
    {
        printf("Attempt %d\n", tentativas);

        // Player input
        while (1)
        {
            printf("Enter your guess: ");
            fgets(entrada, sizeof(entrada), stdin);

            chute = strtol(entrada, &p, 10);

            // Checks if the conversion was successful
            if (p == entrada || *p != '\n')
            {
                printf("Invalid input! Try again.\n");
            }
            else if (chute < 0)
            {
                printf("You cannot guess negative numbers! Try again.\n\n");
            }
            else
            {
                break;
            }
        }

        printf("Your guess was: %d\n", chute);

        // Checks if the player guessed correctly, or if the guess is higher or lower
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            printf("\nCongratulations! You guessed the secret number!\n");
            printf("You won the game!\n");
            break;
        }
        else
        {
            printf("You lost! Try again!\n");
        }
        if (maior)
        {
            printf("\nYour guess was higher than the secret number!\n\n");
        }
        else
        {
            printf("\nYour guess was lower than the secret number!\n\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos -= pontosperdidos;
    }

    printf("Game over!\n");

    return 0;
}
