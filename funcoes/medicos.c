bool medicoExiste(int numero) {
    if(primeiro_medico == NULL)
        return false;

    atual_medico = primeiro_medico;

    while(atual_medico != NULL) {
        if(atual_medico->codigo == numero)
            return true;

        atual_medico = atual_medico->proximo;
    }

    return false;
}

void registarMedico() {
    FILE *fp;
    int medico, nome;

    system("cls");

    novo_medico = (Medicos *)calloc(1, sizeof(Medicos));

    if (!(fp = fopen("database/medicos.txt", "a")))
    {
        printf("Erro ao abrir ficheiro dos medicos. A sair..\n");
        exit(1);
    }

    if (novo_medico == NULL)
    {
      printf("Alocação de memória sem sucesso...\n");
      exit(1);
    }

    printf("\nPor favor, registe os seguintes dados: \n\n");
    printf("Codigo de medico: ");
    scanf("%d", &medico);

    while(medicoExiste(medico)) {
        printf("\nEsse medico ja existe. Por favor, re-insira um codigo nao existente: ");
        scanf("%d", &medico);
    }

    novo_medico->codigo = medico;
    
    printf("Nome do medico: ");
    fflush(stdin);
    gets(novo_medico->nome);

    if (primeiro_medico == NULL) {
      primeiro_medico = novo_medico;
    } else {
      atual_medico = primeiro_medico;

      while (atual_medico->proximo != NULL) {
        atual_medico = atual_medico->proximo;
      }

      atual_medico->proximo = novo_medico;
    }
  
    fprintf(fp, "\n%d,%s", novo_medico->codigo,novo_medico->nome);
    fclose(fp);
    utentes++;

    system("cls");

    printf("Medico registado com sucesso.. A retomar..\n");

    system("pause");
}

void editarMedico() {
    system("cls");
    int medico, opcao, novo_codigo;
    char novo_nome[100];
    bool existe = true;
    
    if(primeiro_medico == NULL) {
        printf("Nao existem utentes.\n");
        system("pause");
        return;
    }

    printf("Por favor, insira o numero de medico a editar: ");
    scanf("%d", &medico);

    atual_medico = primeiro_medico;
    while (atual_medico != NULL) {
        if(atual_medico->codigo == medico) {
            printf("Codigo: %d, Nome: %s\n\n", atual_medico->codigo, atual_medico->nome);
            do {
                printf("O que deseja fazer?\n [1] Editar numero do medico\n [2] Editar nome do medico\n\n > ");
                scanf("%d", &opcao);
            } while(opcao < 1 && opcao > 2);

            switch(opcao) {
                case 1:
                    existe = false;
                    do {
                        if(existe) {
                            printf("Esse medico ja existe! Por favor, insira um medico existente.\n\n");
                        }    
                        printf("Qual o numero novo para atribuir ao medico? ");
                        scanf("%d", &novo_codigo);
                        existe = false;
                        existe = medicoExiste(novo_codigo);
                    } while(existe);
                    atual_medico->codigo = novo_codigo;
                    printf("\nCodigo do medico alterado com sucesso!\n");
                    system("pause");
                    break;

                case 2:
                    printf("\nQual o nome do medico? ");
                    fflush(stdin);
                    gets(novo_nome);
                    strcpy(atual_medico->nome, novo_nome);
                    printf("\nCodigo do medico alterado com sucesso!\n");
                    system("pause");
                    break;
            }
        }
        atual_medico = atual_medico->proximo;
    }
}

void consultarMedicos() {
    system("cls");
    int medico;

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos.\n");
        system("pause");
        return;
    }

    printf("Por favor, insira o numero de medico a consultar: ");
    scanf("%d", &medico);

    while(!medicoExiste(medico)) {
        printf("Esse medico nao existe!\nPor favor, insira o numero de medico a consultar: ");
        scanf("%d", &medico);
    }

    atual_medico = primeiro_medico;
    while (atual_medico != NULL) {
        if(atual_medico->codigo == medico) {
            printf("Codigo: %d, Nome do medico: %s\n\n", atual_medico->codigo, atual_medico->nome);
        }

        atual_medico = atual_medico->proximo;
    }

    system("pause");
}

void removerMedico() {
    system("cls");
    int medico;

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos.\n");
        system("pause");
        return;
    }

    atual_medico = primeiro_medico;
    while (atual_medico != NULL) {
        printf("Codigo: %d, Nome do medico: %s\n", atual_medico->codigo, atual_medico->nome);
        atual_medico = atual_medico->proximo;
    }

    printf("\n\nQual medico deseja remover? ");
    scanf("%d", &medico);

    while(!medicoExiste(medico)) {
        printf("\n\nEsse medico nao existe. Qual medico deseja remover? ");
        scanf("%d", &medico);
    }

    atual_medico = primeiro_medico;
    anterior_medico = NULL;
    
    while (atual_medico != NULL && atual_medico->codigo != medico) {
        anterior_medico = atual_medico;
        atual_medico = atual_medico->proximo;
    }

    if (atual_medico == NULL) {
        printf("O medico nao foi encontrado.\n");
        return;
    }

    if (anterior_medico == NULL) {
        primeiro_medico = atual_medico->proximo;
    } else {
        anterior_medico->proximo = atual_medico->proximo;
    }

    FILE *f_medicos, *tempFile;

    if (!(f_medicos = fopen("database/medicos.txt", "r")) || !(tempFile = fopen("database/medicos_temp.txt", "w")))
    {
        printf("Erro ao abrir ficheiro dos medicos. A sair..\n");
        fclose(f_medicos);
        fclose(tempFile);
        exit(1);
    }
    
    char linha[100];
    int i = 0;
    bool existe;

    while (fgets(linha, sizeof(linha), f_medicos)) {
        int medicoCodigo;
        char medicoNome[100];

        sscanf(linha, "%d,%[^\n]s", &medicoCodigo, medicoNome);

        if (medicoCodigo == medico) {
            existe = true;
            continue;
        }

        fprintf(tempFile, "%s%d,%s", (i == 0) ? "" : "\n", medicoCodigo, medicoNome);
        i++;
    }

    fclose(f_medicos);
    fclose(tempFile);

    remove("database/medicos.txt");
    rename("database/medicos_temp.txt", "database/medicos.txt");

    free(atual_medico);

    system("pause");
}

void listarUtentesPorMedico() {
    int medico;

    system("cls");
    
    if(primeiro_medico == NULL) {
        printf("Nao existem medicos.\n");
        system("pause");
        return;
    }

    atual_medico = primeiro_medico;
    while (atual_medico != NULL) {
        printf("\nMedico NR: %d | Nome: %s\n", atual_medico->codigo, atual_medico->nome);
        medico = atual_medico->codigo;

        atual_utente = primeiro_utente;
        while(atual_utente != NULL)
        {
            if(atual_utente->medicoFamilia == medico)
                printf("  Utente NR: %d\n", atual_utente->codigo);

            atual_utente = atual_utente->proximo;
        }

        atual_medico = atual_medico->proximo;
    }

    printf("\n");

    system("pause");
}

void listarMedicos() {
    system("cls");
    
    if(primeiro_medico == NULL) {
        printf("Nao existem medicos.\n");
        system("pause");
        return;
    }

    atual_medico = primeiro_medico;
    while (atual_medico != NULL) {
        printf("Codigo: %d, Nome: %s\n\n", atual_medico->codigo, atual_medico->nome);
        atual_medico = atual_medico->proximo;
    }

    system("pause");
}