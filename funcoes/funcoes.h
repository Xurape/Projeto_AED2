#ifndef FUNCOES
#define FUNCOES
    // Funções dados.c
    void carregarDados();
    void carregarUtentes();
    void carregarMedicos();
    void libertarMemoria();
    // Include dados.c
    #include "dados.c"

    // Funções filaEspera.c
    void adicionarUtente(Medicos *, Utentes *);
    void imprimirFilaEspera(Medicos *);
    void removerUltimoDaFilaEspera(Medicos *);
    // Include filaEspera.c
    #include "filaEspera.c"

    // Funções medicos.c
    bool medicoExiste(int);
    void registarMedico();
    void editarMedico();
    void consultarMedicos();
    void removerMedico();
    void listarUtentesPorMedico();
    void listarMedicos();
    // Include medicos.c
    #include "medicos.c"
    
    // Funções utentes.c
    bool utenteExiste(int);
    void registarUtente();
    void editarUtente();
    void consultarUtentes();
    void removerUtente();
    void listarUtentes();
    // Include utentes.c
    #include "utentes.c"

    #include "menus.c"
#endif