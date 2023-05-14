void menuUtente() {
    int utente;

    system("cls");

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos disponiveis a sair...\n");
        system("pause");
        return;
    }

    printf("Por favor, insira o código de utente: ");
    scanf("%d", &utente);

    if(!utenteExiste(utente))
        registarUtente();

    // inserirNaFilaEspera(utente);
    system("cls");

    int nr_medico;
    char nome_medico[100];

    atual_utente = primeiro_utente;
    while(atual_utente->proximo != NULL) {
        if(atual_utente->codigo == utente)
            nr_medico = atual_utente->medicoFamilia;

        atual_utente = atual_utente->proximo;
    }

    atual_medico = primeiro_medico;
    while(atual_medico->proximo != NULL) {
        if(atual_medico->codigo == nr_medico)
            strcpy(nome_medico, atual_medico->nome);

        atual_medico = atual_medico->proximo;
    }

    printf("Foi inserido na lista de espera do seu medico (Medico NR: %d | Medico: %s) com sucesso!\n", &nr_medico, &nome_medico);

    system("pause");
}

void menuMedico() {
    system("cls");

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos disponiveis a sair...\n");
        system("pause");
        return;
    }
}

void menuAdministrar() {
    system("cls");

    int opcao, gerirUtentes, gerirMedicos;

    while(opcao != 0) {
        system("cls");
        printf("\n\n");
        printf("\t   O que deseja fazer?\n");
        printf(" [1] Gerir utentes\n");
        printf(" [2] Gerir medicos\n");
        printf(" [3] Importar dados %s\n", (dadosImportados) ? "[Ja importados]" : "");
        printf(" [0] Voltar atras\n\nOpcao > ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                    while(gerirUtentes != 0) {
                        system("cls");
                        printf("\n\n");
                        printf("\t   O que deseja fazer?\n");
                        printf(" [1] Inserir utente\n");
                        printf(" [2] Editar utente\n");
                        printf(" [3] Consultar utentes\n");
                        printf(" [4] Remover utente\n");
                        printf(" [5] Listar utentes\n");
                        printf(" [0] Voltar atras\n\nOpcao > ");
                        scanf("%d", &gerirUtentes);
                        switch(gerirUtentes) {
                            case 1:
                                registarUtente();
                                break;

                            case 2:
                                editarUtente();
                                break;

                            case 3:
                                consultarUtentes();
                                break;

                            case 4:
                                removerUtente();
                                break;

                            case 5:
                                listarUtentes();
                                break;
                        }
                    }
                break;

            case 2:
                menuMedico();
                break;

            case 3:
                carregarDados();
                break;
        }
    }

}

void menuPrincipal() {
    int opcao;

    while(opcao != 0) {
        system("cls");
        printf("\n\n");
        printf("\tBem-vindo ao centro de saude!");
        printf("\n\t   E medico ou utente?\n\n");
        printf(" [1] Utente\n");
        printf(" [2] Medico\n");
        printf(" [3] Administrar\n");
        printf(" [0] Sair\n\nOpcao > ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                menuUtente();
                break;

            case 2:
                menuMedico();
                break;

            case 3:
                menuAdministrar();
                break;
        }
    }
}