#include <stdio.h>

/*
  Batalha Naval - nível novato
  - Tabuleiro 10x10 (matriz) inicializada com 0 (água)
  - Dois navios de tamanho 3: um horizontal e um vertical
  - Coordenadas iniciais definidas no código (0-based)
  - Validação de limites e sobreposição simples
  - Impressão do tabuleiro com 0 para água e 3 para navio
*/

int main() {
    /* Constantes do problema */
    const int LINHAS = 10;
    const int COLUNAS = 10;
    const int TAMANHO_NAVIO = 3;

    /* Tabuleiro: matriz 10x10 inicializada com zeros (água) */
    int tabuleiro[LINHAS][COLUNAS];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* Coordenadas dos navios (definidas no código, 0-based)
       Navio 1: horizontal, começa em (linha_h1, col_h1)
       Navio 2: vertical, começa em (linha_v2, col_v2) */
    int linha_h1 = 2;
    int col_h1   = 4; /* horizontal ocupará (2,4), (2,5), (2,6) */

    int linha_v2 = 5;
    int col_v2   = 6; /* vertical ocupará (5,6), (6,6), (7,6) */

    /* Validação - verificar se cada navio cabe dentro dos limites do tabuleiro */
    if (col_h1 < 0 || col_h1 + TAMANHO_NAVIO > COLUNAS ||
        linha_h1 < 0 || linha_h1 >= LINHAS) {
        printf("Erro: navio horizontal nao cabe no tabuleiro com as coordenadas fornecidas.\n");
        return 1;
    }

    if (linha_v2 < 0 || linha_v2 + TAMANHO_NAVIO > LINHAS ||
        col_v2 < 0 || col_v2 >= COLUNAS) {
        printf("Erro: navio vertical nao cabe no tabuleiro com as coordenadas fornecidas.\n");
        return 1;
    }

    /* Verificar sobreposição simples: checar posições antes de posicionar */
    /* Checa cada célula que o navio horizontal ocuparia */
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int r = linha_h1;
        int c = col_h1 + offset;
        if (tabuleiro[r][c] != 0) {
            printf("Erro: sobreposicao detectada ao posicionar navio horizontal em (%d,%d).\n", r, c);
            return 1;
        }
    }

    /* Checa cada célula que o navio vertical ocuparia */
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int r = linha_v2 + offset;
        int c = col_v2;
        if (tabuleiro[r][c] != 0) {
            printf("Erro: sobreposicao detectada ao posicionar navio vertical em (%d,%d).\n", r, c);
            return 1;
        }
    }

    /* Posicionar navio horizontal (valor 3) */
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int r = linha_h1;
        int c = col_h1 + offset;
        tabuleiro[r][c] = 3;
    }

    /* Posicionar navio vertical (valor 3) */
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int r = linha_v2 + offset;
        int c = col_v2;
        tabuleiro[r][c] = 3;
    }

    /* Exibir o tabuleiro no console
       - Imprime cada linha em uma linha nova
       - Separa valores por espaço para facilitar leitura */
    printf("Tabuleiro (0 = agua, 3 = navio):\n\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}