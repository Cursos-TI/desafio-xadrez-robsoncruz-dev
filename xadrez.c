#include <stdio.h>

/*
  Desafio de Xadrez - Nível Novato + Aventureiro
  - Nível Novato: Torre, Bispo, Rainha com loops simples e menu.
  - Nível Aventureiro: Cavalo em "L" tive necessidade de usar loop aninhados
*/

int main() {
    /* -------------------- Parte do Nível Novato -------------------- */
    /* SUGESTÕES do requisito */
    const int SUG_TORRE = 5;
    const int SUG_BISPO = 5;
    const int SUG_RAINHA = 8;

    /* LIMITES simples (pensando no tabuleiro 8x8) */
    const int LIM_TORRE = 8;   /* máximo em linha reta */
    const int LIM_BISPO = 7;   /* máximo em diagonal */
    const int LIM_RAINHA = 8;  /* máximo em qualquer direção reta */

    int mov_torre = 0;
    int mov_bispo = 0;
    int mov_rainha = 0;

    /* -------------------- MENU/ENTRADAS -------------------- */
    printf("===== MENU DO DESAFIO XADREZ =====\n");
    printf("Sugerido (do enunciado): Torre=%d, Bispo=%d, Rainha=%d\n", SUG_TORRE, SUG_BISPO, SUG_RAINHA);
    printf("Obs.: Limites simples -> Torre: até %d | Bispo: até %d | Rainha: até %d\n", LIM_TORRE, LIM_BISPO, LIM_RAINHA);
    printf("\n");

    /* Torre */
    do {
        printf("Quantos movimentos a TORRE vai fazer? (sugestao: %d): ", SUG_TORRE);
        if (scanf("%d", &mov_torre) != 1) {
            /* leitura invalida: limpar e pedir de novo */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Valor invalido. Tente novamente.\n");
            mov_torre = -1; /* força repetir */
            continue;
        }
        if (mov_torre < 0 || mov_torre > LIM_TORRE) {
            printf("Valor invalido para a TORRE. Digite entre 0 e %d.\n", LIM_TORRE);
        }
    } while (mov_torre < 0 || mov_torre > LIM_TORRE);

    /* Bispo */
    do {
        printf("Quantos movimentos o BISPO vai fazer? (sugestao: %d): ", SUG_BISPO);
        if (scanf("%d", &mov_bispo) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Valor invalido. Tente novamente.\n");
            mov_bispo = -1;
            continue;
        }
        if (mov_bispo < 0 || mov_bispo > LIM_BISPO) {
            printf("Valor invalido para o BISPO. Digite entre 0 e %d.\n", LIM_BISPO);
        }
    } while (mov_bispo < 0 || mov_bispo > LIM_BISPO);

    /* Rainha */
    do {
        printf("Quantos movimentos a RAINHA vai fazer? (sugestao: %d): ", SUG_RAINHA);
        if (scanf("%d", &mov_rainha) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Valor invalido. Tente novamente.\n");
            mov_rainha = -1;
            continue;
        }
        if (mov_rainha < 0 || mov_rainha > LIM_RAINHA) {
            printf("Valor invalido para a RAINHA. Digite entre 0 e %d.\n", LIM_RAINHA);
        }
    } while (mov_rainha < 0 || mov_rainha > LIM_RAINHA);

    printf("\n===== INICIO DAS MOVIMENTACOES =====\n\n");

    /* -------------------- TORRE com while -------------------- */
    /* A torre anda em linha reta para a DIREITA. */
    int passo_torre = 0;
    while (passo_torre < mov_torre) {
        printf("Torre: Direita (passo %d)\n", passo_torre + 1);
        passo_torre = passo_torre + 1;
    }
    if (mov_torre == 0) {
        printf("Torre: sem movimento.\n");
    }
    printf("\n");

    /* -------------------- BISPO com for -------------------- */
    /* O bispo anda em diagonal para CIMA DIREITA. */
    int i;
    if (mov_bispo > 0) {
        for (i = 0; i < mov_bispo; i = i + 1) {
            printf("Bispo: Cima Direita (passo %d)\n", i + 1);
        }
    } else {
        printf("Bispo: sem movimento.\n");
    }
    printf("\n");

    /* -------------------- RAINHA com do-while -------------------- */
    /* A rainha vai para a ESQUERDA. */
    int passo_rainha = 0;
    if (mov_rainha > 0) {
        do {
            printf("Rainha: Esquerda (passo %d)\n", passo_rainha + 1);
            passo_rainha = passo_rainha + 1;
        } while (passo_rainha < mov_rainha);
    } else {
        printf("Rainha: sem movimento.\n");
    }

    /* ==================== Nível Aventureiro: CAVALO ==================== */
    /*
       Requisito: mover o Cavalo em "L"
       - Duas casas para baixo
       - Uma casa para a esquerda
       - Usar loops aninhados: um for + (while ou do-while)
       - Imprimir a direção a cada casa: "Baixo", "Baixo", "Esquerda"
       - Valores definidos no código como variáveis/constantes
    */

    /* Separador visual para os movimentos do Cavalo */
    printf("\n");

    /* Quantidades definidas no código */
    const int CAVALO_BAIXO = 2;    /* duas casas para baixo */
    const int CAVALO_ESQ = 1;      /* uma casa para a esquerda */

    printf("===== Movimento do CAVALO =====\n");

    /* LOOPS ANINHADOS:
       - for: itera sobre as "fases" do L (fase 0 = baixo, fase 1 = esquerda)
       - while: repete a quantidade de passos em cada fase
    */
    int fase;              /* 0 = parte vertical (baixo), 1 = parte horizontal (esquerda) */
    for (fase = 0; fase < 2; fase = fase + 1) {
        int passos_da_fase;
        if (fase == 0) {
            passos_da_fase = CAVALO_BAIXO;  /* 2 passos para baixo */
        } else {
            passos_da_fase = CAVALO_ESQ;    /* 1 passo para esquerda */
        }

        int cont = 0;
        while (cont < passos_da_fase) {
            if (fase == 0) {
                printf("Cavalo: Baixo\n");
            } else {
                printf("Cavalo: Esquerda\n");
            }
            cont = cont + 1;
        }
    }

    printf("\n===== FIM =====\n");
    return 0;
}
