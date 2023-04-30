int utentes = 0, medicos = 0;

typedef struct utentes {
  int codigo, medicoFamilia;
  struct utentes * proximo;
} Utentes;

typedef struct medicos {
  int codigo, *filaEspera;
  char nome[75];
  struct medicos * proximo;
} Medicos;

typedef struct {
  int medico, *utentes;
} FilaEspera;

Utentes * utente = NULL;
Medicos * medico = NULL;

#include "dados.c"

