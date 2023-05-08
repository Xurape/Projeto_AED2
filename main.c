// Librarias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Funções
#include "database/dados.h"
#include "funcoes/funcoes.h"

int main (int argc, char *argv[])
{  
  // carregarDados();
  menuPrincipal();
  libertarMemoria();

  atual_medico = primeiro_medico;
  while(atual_medico->proximo != NULL) {
    system("cls");
    printf("Prox: %d | Anterior: %d | Codigo: %d | Fila: %d\n", atual_medico->proximo, atual_medico->anterior, atual_medico->codigo, atual_medico->fila);
    atual_medico = atual_medico->proximo;
  }

  return 1;
}
