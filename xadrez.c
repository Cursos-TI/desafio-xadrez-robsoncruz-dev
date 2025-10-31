#include <stdio.h>

/*
  Desafio de Xadrez - Nível Mestre
  Base: código do Nível Aventureiro (Torre, Bispo, Rainha e Cavalo).
  O que mudei:
    - Torre, Bispo e Rainha: usado recursividade (imprimir direção a cada casa).
    - Cavalo: usar loops aninhados (com múltiplas variáveis/condições) e usado continue/break.
      -> Movimento do Cavalo agora é em "L": duas casas para cima e uma para a direita.
    - Bispo: além da versão recursiva, também fiz com loops aninhados
             (loop externo = vertical, loop interno = horizontal).
*/

/* -------------------- Constantes (valores no código) -------------------- */
const int TORRE_DIR_PASSOS   = 5;  /* Direita */
const int BISPO_DIAG_PASSOS  = 5;  /* Cima + Direita (diagonal) */
const int RAINHA_ESQ_PASSOS  = 8;  /* Esquerda */
const int CAVALO_CIMA        = 2;  /* Cavalo: 2 p/ Cima */
const int CAVALO_DIREITA     = 1;  /* Cavalo: 1 p/ Direita */

/* -------------------- Funções recursivas -------------------- */
/* Torre: direita n vezes */
void mover_torre_direita_rec(int n) {
    if (n <= 0) {
        return; /* caso base */
    }
    printf("Direita\n");
    mover_torre_direita_rec(n - 1); /* chama de novo até zerar */
}

/* Bispo: diagonal Cima+Direita n vezes (imprime 2 linhas por passo) */
void mover_bispo_cima_direita_rec(int n) {
    if (n <= 0) {
        return;
    }
    printf("Cima\n");
    printf("Direita\n");
    mover_bispo_cima_direita_rec(n - 1);
}

/* Rainha: esquerda n vezes */
void mover_rainha_esquerda_rec(int n) {
    if (n <= 0) {
        return;
    }
    printf("Esquerda\n");
    mover_rainha_esquerda_rec(n - 1);
}

/* -------------------- Versão Bispo com loops aninhados --------------------
   Loop externo (vertical = "Cima") e loop interno (horizontal = "Direita").
   Para cada passo de diagonal, fazemos 1 passo para Cima e 1 para Direita.
*/
void mover_bispo_cima_direita_loops(int passos) {
    int v;  /* vertical */
    for (v = 0; v < passos; v = v + 1) {
        /* sobe 1 por ciclo do externo */
        printf("Cima\n");

        /* horizontal interno: 1 por ciclo (para formar a diagonal) */
        int h;
        for (h = 0; h < 1; h = h + 1) {
            printf("Direita\n");
        }
    }
}

/* -------------------- Cavalo com loops aninhados + continue/break ---------
   Movimento do Cavalo (agora): 2 p/ Cima e 1 p/ Direita.
   Requisito: loops aninhados com múltiplas variáveis e/ou condições
              e usado continue/break para controle do fluxo.
   Obs.:
     - loop externo controla a "fase" (vertical primeiro, depois horizontal)
     - loop interno realiza os passos daquela fase.
*/
void mover_cavalo_cima_direita_loops(void) {
    int fase; /* 0 = parte vertical (Cima), 1 = parte horizontal (Direita) */

    for (fase = 0; fase < 2; fase = fase + 1) {
        if (fase == 0) {
            /* Parte vertical: 2 para Cima */
            int feitos = 0;
            /* while interno para variar um pouco as estruturas */
            while (1) {
                if (feitos >= CAVALO_CIMA) {
                    break; /* já fez os 2 passos para cima */
                }
                printf("Cima\n");
                feitos = feitos + 1;

                /* Exemplo de continue (não faz nada além de ir pro próximo ciclo) */
                if (feitos < CAVALO_CIMA) {
                    continue;
                }
            }
        } else {
            /* Parte horizontal: 1 para Direita */
            int j;
            /* for interno com duas iterações só para demonstrar break/continue */
            for (j = 0; j < 2; j = j + 1) {
                if (j == 0) {
                    printf("Direita\n"); /* executa o passo de fato */
                    /* já atingimos a quantidade desejada (1) -> break */
                    break;
                } else {
                    /* não deveria imprimir nada na segunda volta, então continue */
                    continue;
                }
            }
        }
    }
}

/* ------------------------------------------------------------------------- */
int main(void) {
    /* -------------------- TORRE (recursivo) -------------------- */
    printf("===== Torre (Recursivo) =====\n");
    mover_torre_direita_rec(TORRE_DIR_PASSOS);
    printf("\n");

    /* -------------------- BISPO (recursivo) -------------------- */
    printf("===== Bispo (Recursivo) =====\n");
    mover_bispo_cima_direita_rec(BISPO_DIAG_PASSOS);
    printf("\n");

    /* -------------------- BISPO (loops aninhados) --------------- */
    printf("===== Bispo (Loops Aninhados) =====\n");
    mover_bispo_cima_direita_loops(BISPO_DIAG_PASSOS);
    printf("\n");

    /* -------------------- RAINHA (recursivo) -------------------- */
    printf("===== Rainha (Recursivo) =====\n");
    mover_rainha_esquerda_rec(RAINHA_ESQ_PASSOS);
    printf("\n");

    /* -------------------- CAVALO (loops aninhados) -------------- */
    printf("===== Cavalo (Loops Aninhados) =====\n");
    mover_cavalo_cima_direita_loops();
    printf("\n");

    printf("===== FIM =====\n");
    return 0;
}
