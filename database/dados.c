void iniciarEstruturas() {
  utente = (Utentes *)calloc(1, sizeof(Utentes));
  medico = (Medicos *)calloc(1, sizeof(Medicos));

  if(utente == NULL || medico == NULL) {
    printf("Sem memoria alocavel! A sair...");
    return;
  }
}

void reallocUtente(int tamanho) {
  utente = (Utentes *)realloc(utente, (tamanho * sizeof(Utentes)));
}

void reallocMedico(int tamanho) {
  medico = (Medicos *)realloc(medico, (tamanho * sizeof(Medicos)));
}