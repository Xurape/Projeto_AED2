bool medicoExiste(int numero) {
    if(primeiro_medico == NULL)
        return false;

    atual_medico = primeiro_medico;

    do {
        if(atual_medico->codigo == numero)
            return true;

        atual_medico = atual_medico->proximo;
        
        if(atual_medico->codigo == numero)
            return true;
    } while(atual_medico->proximo != NULL);

    return false;
}