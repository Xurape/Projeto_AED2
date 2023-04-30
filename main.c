// Librarias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Funções
#include "database/dados.h"
#include "funcoes/funcoes.h"

int main (int argc, char *argv[])
{  
  iniciarEstruturas();
  carregarDados();
  // menuPrincipal();
  //
  // for (int i = 0; i < medicos; i++) {
  //   printf("Codigo: %d, Fila de espera: %d, Nome: %s\n", medico[i].codigo, medico[i].filaEspera, medico[i].nome);
  // }

  return 0;
}
