#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<string.h>

//cadastro de livros
#define MAX_LIVROS 100
#define MAX_AUTOR_LEN 100
#define MAX_TITULO_LEN 100
#define MAX_CATEGORIA_LEN 100
#define MAX_TITULOALUGAR_LEN 100

//cadastro de usuarios
#define MAX_USUARIOS 100
#define MAX_NOMEUSUARIO_LEN 100
#define MAX_CPFUSUARIO_LEN 100
#define MAX_CPFUSUARIO_LEN 100
#define MAX_TELEFONE_LEN 100

int main()
{
    //SISTEMA PARA CADASTRO DE LIVROS
    setlocale(LC_ALL, "Portuguese"); //CORREÇÃO DO SISTEMA PARA A LINGUA PORTUGUESA
    //Variáveis para o case 1.
    int continuar, continuarPrincipal, opcao, qtdeLivrosCadastrados, i, c;
    int anoPublicado[MAX_LIVROS];
    int quantidade[MAX_LIVROS];
    char titulo[MAX_LIVROS][MAX_TITULO_LEN];
    char autor[MAX_LIVROS][MAX_AUTOR_LEN];
    char categoria[MAX_LIVROS][MAX_CATEGORIA_LEN];
    int temLivro = 0; //Variável para verificar se algum livro foi cadastrado antes de realizar uma consulta de livros

    //Vaariáveis para o case 2
    char nomeUsuario[MAX_USUARIOS][MAX_NOMEUSUARIO_LEN];
    char cpfUsuario[MAX_USUARIOS][MAX_CPFUSUARIO_LEN];
    char telefoneUsuario[MAX_USUARIOS][MAX_TELEFONE_LEN];
    int qtdeUsuariosCadastrados;
    int continuarCase2;

    //Variáveis para o case 3
    int l,j, dataDevolucao;
    char tituloAlugar[MAX_LIVROS][MAX_TITULOALUGAR_LEN];
    char nomeUsuarioEmprestarLivro;


    //Variávies para o case 4
    char infoConsulta[MAX_LIVROS];
    int opcaoCase4 = 1;


    continuarPrincipal = 1;
    while(continuarPrincipal){
        printf("\n                                            ------ESCOLHA UMA OPÇÃO------\n");
        printf("\n                                                 1: CADASTRAR LIVRO\n");
        printf("                                                2: CADASTRAR USUÁRIOS\n");
        printf("                                               3: EMPRÉSTIMO DE LIVROS\n");
        printf("                                                4: CONSULTA DE LIVROS\n");
        printf("                                                 5: ENCERRAR PROGRAMA\n");
        printf("\n                                        -------------------------------------\n");
        scanf("%d", &opcao);
        system("cls");
        Sleep(500);

    switch(opcao){
        case 1:
            do{
                printf("                           ---------------------------------------------------------");
                printf("\n                                       Quantos livros deseja cadastrar?");
                printf("\n                           ---------------------------------------------------------\n");
                scanf("%d", &qtdeLivrosCadastrados);
                system("cls");

        for(i = 0; i < qtdeLivrosCadastrados; i++){ //FOR - Loop para armazenar os dados inseridos em cada variável com "[1]" no final dela.
                cadastro_livro:
                    printf("\n                                            ------CADASTRO DE LIVROS------\n");
                        printf("                                Insira o nome do autor: ");
                        scanf(" %[^\n]", &autor[i]);
                        fflush(stdin);
                    printf("                                Insira o título do  livro %d: ", i + 1);
                        scanf(" %[^\n]", &titulo[i]);
                        fflush(stdin);
                    printf("                                Ano de publicação: ");
                        scanf("%d", &anoPublicado[i]);
                        fflush(stdin);
                    printf("                                Categoria: ");
                        scanf(" %[^\n]", &categoria[i]);
                        fflush(stdin);
                    printf("                                Quantidade disponivel: ");
                        scanf("%d", &quantidade[i]);
                        fflush(stdin);
                    printf("\n                              ---------------------------------------------------------");
                    system("cls");
                    Sleep(1000);

                    printf("\n");
                    printf("                                            ------DADOS DO LIVRO------  \n");
                    printf("\n                                   Nome............: %s\n", autor[i]);
                    printf("                                   Titulo..........: %s\n", titulo[i]);
                    printf("                                   Ano publicado...: %d\n", anoPublicado[i]);
                    printf("                                   Categoria.......: %s\n", categoria[i]);
                    printf("                                   Quantidade......: %d\n", quantidade[i]);

                    printf("\n                                   Os dados estão corretos?\n                                     1: SIM        2: NÃO\n");
                    scanf("%d", &continuar);

                    if(continuar != 1){
                        printf("\n\n                                       Preencha novamente e confira os dados!");
                        Sleep(4000);
                        system("cls");
                        goto cadastro_livro;
                        break;
                    } else {
                        system("cls");
                        printf("\n                                                ------RELATÓRIO------\n");
                        printf("                                     O livro %s foi cadastrado com sucesso!\n\n", titulo[i]);
                        temLivro = 1;
                        Sleep(4000);
                        system("cls");
                    } //fecha else
            } //fecha FOR

            } while(continuar != 1);
            break; //break case 1
         case 2:
            do {
                printf("                           ---------------------------------------------------------");
                printf("\n                                       Quantos usuários deseja cadastrar?");
                printf("\n                           ---------------------------------------------------------\n");
                scanf("%d", &qtdeUsuariosCadastrados);
                system("cls");

        for(i = 0; i < qtdeUsuariosCadastrados; i++){
                cadastro_usuarios:
                    printf("\n                                            ------CADASTRO DE USUÁRIOS------\n");
                        printf("                                Insira o nome do usuário: ");
                        scanf(" %[^\n]", &nomeUsuario[i]);
                        fflush(stdin);
                    printf("                                Insira o CPF do usuário:  ");
                        scanf("%s", &cpfUsuario[i]);
                        fflush(stdin);
                    printf("                                Insira o telefone do usuario: ");
                        scanf("%s", &telefoneUsuario[i]);
                        fflush(stdin);
                    printf("\n                              ---------------------------------------------------------");
                    system("cls");
                    Sleep(1000);

                    printf("\n");
                    printf("                                            ------DADOS DO USUÁRIO------  \n");
                    printf("\n                                   Nome.............: %s\n", nomeUsuario[i]);
                    printf("                                   Cpf...............: %s\n", cpfUsuario[i]);
                    printf("                                   Telefone..........: %s\n", telefoneUsuario[i]);

                    printf("\n                                   Os dados estão corretos?\n                                     1: SIM        2: NÃO\n");
                    scanf("%d", &continuarCase2);

                    if(continuarCase2 != 1){
                        printf("\n\n                                       Preencha novamente e confira os dados!");
                        Sleep(4000);
                        system("cls");
                        goto cadastro_usuarios;
                        break;
                    } else {
                        system("cls");
                        printf("\n                                                ------RELATÓRIO------\n");
                        printf("                                     O usuario %s foi cadastrado com sucesso!\n\n", nomeUsuario[i]);
                        temLivro = 1;
                        Sleep(4000);
                        system("cls");
                    } //fecha else
            } //fecha FOR
            } while(continuarCase2 != 1);
            break;
         case 3:
                if(temLivro == 0){
                    printf("\n             Nenhum livro cadastrado!");
                    Sleep(3000);
                    system("cls");
                }
                while(temLivro == 1){
                    pesquisa_Titulo:
                    printf("             -----------------------------------------------------------------------------------------------------");
                    printf("\n                                                  BICLIOTECA DE LIVROS");
                    printf("\n             -----------------------------------------------------------------------------------------------------\n");

                    for(l = 0; l < qtdeLivrosCadastrados; l++){

                                printf("\n\n                                                   LIVRO '%s'                           ", titulo[l]);
                                printf("\n                                            Autor.................: %s\n", autor[l]);
                                printf("                                            Título................: %s\n", titulo[l]);
                                printf("                                            Ano de publicação.....: %d\n", anoPublicado[l]);
                                printf("                                            Categoria.............: %s\n", categoria[l]);
                                printf("                                            Quantidade disponível.: %d\n", quantidade[l]);
                                printf("                   ---------------------------------------------------------------------------------");
                    }

                        printf("\n                                          INSIRA O TÍTULO DO LIVRO QUE DESEJA: ");
                        scanf(" %[^\n]", &tituloAlugar);
                        system("cls");

                        int livroEncontrado = 0;

                        for(j = 0; j < qtdeLivrosCadastrados; j++){
                            if(strcmp(titulo[j], tituloAlugar) == 0){
                                printf("\n                                            LIVRO:");
                                printf("\n                                            Autor............: %s\n", autor[j]);
                                printf("                                            Titulo..........: %s\n", titulo[j]);
                                printf("                                            Ano publicado...: %d\n", anoPublicado[j]);
                                printf("                                            Categoria.......: %s\n", categoria[j]);
                                printf("                                            Quantidade......: %d\n", quantidade[j]);

                                printf("                                            Insira o nome do usuario: ");
                                scanf(" %[^\n]", &nomeUsuarioEmprestarLivro);
                                printf("\n                                          Insira o dia de devolução do livro: ");
                                scanf("%d", &dataDevolucao);

                                printf("\n                                   Empréstimo do livro '%s' realizado com sucesso!\n", titulo[j]);
                                Sleep(4000);
                                system("cls");
                                livroEncontrado = 1;
                            }
                            } //fecha FOR

                            if (!livroEncontrado) {
                                printf("\n                                   Nenhum livro encontrado! Insira o título novamente! \n");
                                Sleep(4000);
                                system("cls");
                                goto pesquisa_Titulo;

                            } // fecha else

                    break; //break while
                    } //fecha While
                    break; //break case 3
         case 4:
                if(temLivro == 0){
                    printf("\n             Nenhum livro cadastrado!");
                    Sleep(3000);
                    system("cls");
                    break;
                }
            do {
                printf("             --------------------------------------------------------------------------------------------");
                printf("\n                      Insira o nome do autor, título ou categoria do livro que deseja consultar");
                printf("\n             --------------------------------------------------------------------------------------------\n");
                printf("             Insira aqui: ");
                scanf(" %[^\n]", &infoConsulta);

                int livroConsultado = 0;

                for(c = 0; c < qtdeLivrosCadastrados; c++){
                    if(strcmp(autor[c], infoConsulta) == 0 || strcmp(titulo[c], infoConsulta) == 0 || strcmp(categoria[c], infoConsulta) == 0){
                        system("cls");
                        Sleep(2000);
                        printf("                              ---------------------------------------------------------");
                        printf("\n                                               CONSULTA DE LIVROS");
                        printf("\n                              ---------------------------------------------------------\n\n");
                        printf("                                                 LIVRO ENCONTRADO!\n\n");
                        printf("                                        Autor.................: %s\n", autor[c]);
                        printf("                                        Título................: %s\n", titulo[c]);
                        printf("                                        Ano de publicação.....: %d\n", anoPublicado[c]);
                        printf("                                        Categoria.............: %s\n", categoria[c]);
                        printf("                                        Quantidade disponível.: %d", quantidade[c]);
                        livroConsultado = 1;

                    }
                    }//fecha FOR

                    if(!livroConsultado){
                        Sleep(2000);
                        printf("Livro indisponível!");

                    }

                        printf("\n\n                                       Deseja consultar mais um livro?\n                                             1: SIM        2: NÃO\n");
                        scanf("%d", &opcaoCase4);
                        system("cls");

                        if(opcaoCase4 != 1){
                            opcaoCase4 = 0;
                            system("cls");
                        }
                //fecha "else" do if(temLivro == 0
                } while(opcaoCase4); //Fecha while
                break; //break case 4
         default:
            continuarPrincipal = 0;
            break;
                }// fecha switch
    }// fecha whilePrincipal
        return 0;
    }