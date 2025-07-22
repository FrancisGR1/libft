grep -R -n -A2 "@TODO\|TODO" Strings/

git add de classic strings
norminettar tudo

Documentar código
Cleanup commentend mains
testar todas as funcs adicionadas

Ideias:

ESTRUTURAS DE DADOS
Árvores
    Retrievals
Gráficos
Pilha/s

ARENAS:
Fazer um macro:
    #define my_malloc malloc
    -> internamente vai usar uma arena global

testar arena com estruturas complexas;
modificar tamanho se arena_reset() esvaziar o ptr mais à frente;

criar um pointer de alocação que usa por definição malloc() mas que pode apontar para outro alocador
    - criar um interface (t_arena) para este ptr; tem de estar alinhado com o cabeçalho do malloc() - retorno, parâmetros


Strings Clássicos:
- testar todos
vfprint?
Fazer e incluir snprintf

