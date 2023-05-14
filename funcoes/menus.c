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

    system("cls");

    int nr_medico;

    Utentes *utenteData;
    Medicos *medicoData;

    atual_utente = primeiro_utente;
    while(atual_utente->proximo != NULL) {
        if(atual_utente->codigo == utente) {
            utenteData = atual_utente;
            nr_medico = atual_utente->medicoFamilia;
            break;
        }

        atual_utente = atual_utente->proximo;
    }

    atual_medico = primeiro_medico;
    while(atual_medico->proximo != NULL) {
        if(atual_medico->codigo == nr_medico) {
            medicoData = atual_medico;
            break;
        }

        atual_medico = atual_medico->proximo;
    }

    adicionarUtente(medicoData, utenteData);

    printf("Foi inserido na lista de espera do seu medico (Medico NR: %d | Medico: %s) com sucesso!\n", medicoData->codigo, medicoData->nome);

    system("pause");
}

void menuMedico() {
    int medico;
    Medicos *medicoData;
    system("cls");

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos disponiveis a sair...\n");
        system("pause");
        return;
    }

    printf("Qual o seu numero de medico? ");
    scanf("%d", &medico);

    atual_medico = primeiro_medico;
    while(atual_medico != NULL) {
        if(atual_medico->codigo == medico) {
            medicoData = atual_medico;
            break;
        }

        atual_medico = atual_medico->proximo;
    }

    imprimirFilaEspera(medicoData);
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
                while(gerirMedicos != 0) {
                    system("cls");
                    printf("\n\n");
                    printf("\t   O que deseja fazer?\n");
                    printf(" [1] Inserir medico\n");
                    printf(" [2] Editar medico\n");
                    printf(" [3] Consultar medicos\n");
                    printf(" [4] Remover medico\n");
                    printf(" [5] Listar medicos\n");
                    printf(" [6] Listar utentes por medico\n");
                    printf(" [0] Voltar atras\n\nOpcao > ");
                    scanf("%d", &gerirMedicos);
                    switch(gerirMedicos) {
                        case 1:
                            registarMedico();
                            break;

                        case 2:
                            editarMedico();
                            break;

                        case 3:
                            consultarMedicos();
                            break;

                        case 4:
                            removerMedico();
                            break;

                        case 5:
                            listarMedicos();
                            break;

                        case 6:
                            listarUtentesPorMedico();
                            break;
                    }
                }
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