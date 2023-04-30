void iniciarEstruturas() {
  utente = (Utentes *)calloc(1, sizeof(Utentes));
  medico = (Medicos *)calloc(1, sizeof(Medicos));
}

void realocarEstruturas() {  
  utente = (Utentes *) realloc(utente, ((utentes + 1) * sizeof(Utentes)));
  printf("\n\nRealocada memória de utentes, from %d to %d", utentes, utentes + 1);
  medico = (Medicos *) realloc(medico, ((medicos + 1) * sizeof(Medicos)));
  printf("\n\nRealocada memória de medicos, from %d to %d", medicos, medicos + 1);
}
