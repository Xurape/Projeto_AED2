int utentes = 0, medicos = 0;

bool dadosImportados = false;

typedef struct utentes {
  int codigo, medicoFamilia;
  struct utentes *anterior;
  struct utentes *proximo;
} Utentes;

typedef struct filaEspera {
  int *utentes, tam;
} FilaEspera;

typedef struct medicos {
  int codigo;
  char nome[75];
  struct medicos *anterior;
  struct medicos *proximo;
  FilaEspera *fila;
} Medicos;

Medicos *primeiro_medico = NULL, *anterior_medico, *atual_medico, *novo_medico;
Utentes *primeiro_utente = NULL, *anterior_utente, *atual_utente, *novo_utente;