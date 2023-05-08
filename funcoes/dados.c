void carregarMedicos() {
  FILE *f_medicos = NULL;

  if (!(f_medicos = fopen("database/medicos.txt", "r")))
  {
    printf("Erro ao abrir ficheiro dos medicos. A sair..\n");
    exit(1);
  }

  while (!feof(f_medicos))
  {
    novo_medico = (Medicos *)calloc(1, sizeof(Medicos));

    if (novo_medico == NULL)
    {
      printf("Alocação de memória sem sucesso...\n");
      exit(1);
    }

    printf("A importar dados..\n");

    fscanf(f_medicos, "%d,%[^\n]s", &novo_medico->codigo, novo_medico->nome);

    printf("Dados importados.\n");

    // Criar fila de espera
    novo_medico->fila = (FilaEspera *)calloc(1, sizeof(FilaEspera));
    novo_medico->fila->tam = 0;

    printf("Fila criada.\n");

    if (primeiro_medico == NULL) {
      primeiro_medico = novo_medico;
    } else {
      atual_medico = primeiro_medico;

      while (atual_medico->proximo != NULL) {
        anterior_medico = atual_medico;
        atual_medico = atual_medico->proximo;
        atual_medico->anterior = anterior_medico;
      }

      atual_medico->proximo = novo_medico;
    }

    medicos++;
  }

  fclose(f_medicos);
}

void carregarUtentes() {
  FILE *f_utentes;

  if (!(f_utentes = fopen("database/utentes.txt", "r")))
  {
    printf("Erro ao abrir ficheiro dos utentes. A sair..\n");
    exit(1);
  }

  while (!feof(f_utentes))
  {
    novo_utente = (Utentes *)calloc(1, sizeof(Utentes));

    if (novo_utente == NULL)
    {
      printf("Alocação de memória sem sucesso...\n");
      exit(1);
    }

    fscanf(f_utentes, "%d,%d", &novo_utente->codigo, &novo_utente->medicoFamilia);

    if (primeiro_utente == NULL) {
      primeiro_utente = novo_utente;
    } else {
      atual_utente = primeiro_utente;

      while (atual_utente->proximo != NULL) {
        anterior_utente = atual_utente;
        atual_utente = atual_utente->proximo;
        atual_utente->anterior = anterior_utente;
      }

      atual_utente->proximo = novo_utente;
    }
  
    utentes++;
  }

  fclose(f_utentes);
}

void carregarDados()
{
  carregarUtentes();
  carregarMedicos();

  dadosImportados = true;
}

void libertarMemoria() {
  while (atual_medico != NULL)
  {
    Medicos *temp = atual_medico;
    atual_medico = atual_medico->proximo;
    free(temp);
  }

  while (atual_utente != NULL)
  {
    Utentes *temp = atual_utente;
    atual_utente = atual_utente->proximo;
    free(temp);
  }
}