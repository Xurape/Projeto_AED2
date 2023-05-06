int ficheiroVazio(FILE *ficheiro) {
    if (ficheiro == NULL) {
        // Se houver um erro ao abrir o ficheiro, consideramos que ele está vazio
        return 1;
    }

    int vazio = 1; // Assume que o ficheiro está vazio

    // Lê o primeiro caractere do ficheiro
    int caractere = fgetc(ficheiro);

    // Verifica se o ficheiro está vazio lendo até o final do ficheiro
    while (caractere != EOF) {
        if (caractere != '\n' && caractere != '\r') {
            // Se um caractere diferente de nova linha for encontrado, o ficheiro não está vazio
            vazio = 0;
            break;
        }
        caractere = fgetc(ficheiro);
    }

    fclose(ficheiro);

    return vazio;
}