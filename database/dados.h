int utentes = 0, medicos = 0;

typedef struct utentes {
  int codigo, medicoFamilia;
  struct utentes *proximo;
} Utentes;

typedef struct filaEspera {
  int codigoUtente[100]; // assumindo que a fila de espera terá no máximo 100 utentes
  int primeiro, ultimo; // apontadores para o primeiro e últimos elementos da fila
  struct filaEspera *proximo;
} FilaEspera;

typedef struct medicos {
  int codigo;
  char nome[75];
  struct medicos *proximo;
  struct filaEspera *primeiro;
} Medicos;

Medicos *primeiro_medico = NULL, *atual_medico, *novo_medico;
Utentes *primeiro_utente = NULL, *atual_utente, *novo_utente;
FilaEspera *primeiro_filaEspera = NULL, *atual_filaEspera, *novo_filaEspera;