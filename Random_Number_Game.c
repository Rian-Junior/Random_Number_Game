#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
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

    // Variáveis globais
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

    // Mensagem de boas-vindas e status do jogo
    printf("Bem-vindo ao nosso jogo de adivinhação!\n");
    printf("Seu objetivo é adivinhar o número secreto. Boa sorte!\n\n");
    printf("\nConforme a cada nível aumenta +5 chances para acertar!\n\n");

    // Validação do nível de dificuldade
    char entrada[100];
    char *p;

    while (1) {
        printf("Qual o nível de dificuldade?\n\n");
        printf("[1] Fácil [2] Médio [3] Difícil\n\n");
        
        printf("Nível escolhido foi: ");
        fgets(entrada, sizeof(entrada), stdin); // Captura a entrada como string

        nivel = strtol(entrada, &p, 10); // Tenta converter a string para um número

        // Verifica se a conversão foi bem-sucedida
        if (p == entrada || *p != '\n') {
            printf("Entrada inválida! Tente novamente.\n");
        } else {
            break;
        }
    }

    // Definindo o número de tentativas com base no nível escolhido
    switch (nivel) {
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
            printf("Nível inválido! Usando nível Fácil como padrão.\n");
            numerodetentativas = 15;
            break;
    }

    // Loop principal do jogo
    for (int i = 1; i <= numerodetentativas; i++) {
        printf("Tentativa %d\n", tentativas);

        // Entrada do jogador
        while (1) {
            printf("Digite seu chute: ");
            fgets(entrada, sizeof(entrada), stdin);
            
            chute = strtol(entrada, &p, 10); 

            // Verifica se a conversão foi bem-sucedida
            if (p == entrada || *p != '\n') {
                printf("Entrada inválida! Tente novamente.\n");
            } else if (chute < 0) {
                printf("Você não pode chutar números negativos! Tente novamente.\n\n");
            } else {
                break; 
            }
        }

        printf("Seu chute foi: %d\n", chute);

        // Verifica se acertou, se o chute é maior ou menor
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou) {
            printf("\nParabéns! Você acertou o número secreto!\n");
            printf("Você venceu o jogo!\n");
            break;  // Sai do loop se acertou
        } else if (maior) {
            printf("\nSeu chute foi maior que o número secreto!\n\n");
        } else {
            printf("\nSeu chute foi menor que o número secreto!\n\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos -= pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if (acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas.\n", tentativas - 1);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente novamente!\n");
    }

    return 0;
}
