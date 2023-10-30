#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Cria uma estrutura para armazenar os dados do usuário
struct Usuario{
    char nome_usuario[30];
    char sobrenome_usuario[30];
    char idade_usuario[4];
    char email_usuario[100];
    char senha_usuario[20];
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Cria um Array para armazenar até 10 usuários.
    struct Usuario usuarios[10];

    //Declaração das variáveis.
    int numUsuarios = 0;
    char resp_usuario, resp_novocad, resp_vercad, resp_login, resp_errologin;
    char logemail_usuario[100];
    char logsenha_usuario[20];

    //Verifica se o usuário já é cadastrado no sistema.
    inicio_sys: printf("Seja bem vindo! \nJá é cadastrado na nossa plataforma(S/N)?: ");
    scanf(" %s", &resp_usuario);

    //Se a resposta for Não, entra na área de cadastramento.
    if((resp_usuario == 'n')||(resp_usuario=='N')){

        //Recebe o primeiro nome e coloca dentro do Array
        inicio: printf("\nVamos dar início ao seu cadastro!\n\nInforme o seu nome: ");
        scanf(" %s", usuarios[numUsuarios].nome_usuario);

        //Recebe o segundo nome e coloca dentro do Array
        printf("Informe o seu sobrenome: ");
        scanf(" %s", usuarios[numUsuarios].sobrenome_usuario);

        //Recebe a idade e coloca dentro do Array
        printf("Informe a sua idade: ");
        scanf("%s", usuarios[numUsuarios].idade_usuario);

        //Recebe o email e coloca dentro do Array
        printf("Informe o seu email: ");
        scanf("%s", usuarios[numUsuarios].email_usuario);

        //Recebe a senha e coloca dentro do Array
        printf("Informe a sua senha: ");
        scanf("%s", usuarios[numUsuarios].senha_usuario);
        numUsuarios++;

        //Verifica se necessita realizar mais algum cadastro.
        printf("\nDeseja cadastrar outro usuário? (S/N): ");
        scanf(" %s", &resp_novocad);
        switch (resp_novocad){
            case 'S': case 's':case 'Sim': case 'sim':
            goto inicio;
            break;
            case 'N': case 'n':case 'Nao': case 'nao':
            printf("\nCadastro concluído.\nObrigado por se cadastrar no nosso sistema.");
            printf("\n\nFoi realizado: %d cadastramentos.", numUsuarios);

            //Verifica se deseja visualizar os cadastros feitos
            printf("\nDeseja ver os cadastros realizados? (S/N): ");
            scanf(" %s", &resp_vercad);

            switch (resp_vercad){
                //Se sim
                case 'S': case 's':case 'Sim': case 'sim':
                cadastros: printf("\nDados Cadastrados:\n");

                //Inicia um loop 'for', percorrendo todos os usuários cadastrados
                //O loop começa com cont=0 e continua até que cont seja menor do que o número de usuários
                //cadastrados("numUsuarios")
                for (int cont = 0; cont<numUsuarios; cont++){
                    printf("\nUsuário %d:\n", cont + 1);
                    printf("Nome: %s %s\n", usuarios[cont].nome_usuario, usuarios[cont].sobrenome_usuario);//Imprimi o nome armazenado na estrutura(usuarios)
                    printf("Idade: %s\n", usuarios[cont].idade_usuario);//Imprimi a idade armazenada na estrutura(usuarios)
                    printf("Email: %s\n", usuarios[cont].email_usuario);//Imprimi o email armazenado na estrutura(usuarios)
                }
                //Verifica se deseja realizar Login no Sistema.
                area_login: printf("\nDeseja efetuar Login no sistema? (S/N): ");
                scanf(" %s", &resp_login);

                //Se sim, recebe o email e senha cadastrados
                if((resp_login=='S')||(resp_login=='s')){
                    inicio_login: printf("\nInforme o email cadastrado: ");
                    scanf(" %s", logemail_usuario);

                    printf("Informe a senha cadastrada: ");
                    scanf("%s", logsenha_usuario);

                    int login_sucesso = 0;// Variável para verificar se o login foi bem-sucedido

                    //Loop 'for' que percorre o array de usuários, representado pela estrutura 'usuarios',
                    //e verifica se as informações fornecidas durante a tentativa de login (email e senha)
                    //correspondem às informações de algum usuário já cadastrado.
                    for (int cont = 0; cont < numUsuarios; cont++) {
                        if (strcmp(logemail_usuario, usuarios[cont].email_usuario) == 0 &&
                            strcmp(logsenha_usuario, usuarios[cont].senha_usuario) == 0) {
                            printf("\nLogin realizado com sucesso!\nBem vindo a WeBook!\n");
                            login_sucesso = 1; // Define login_sucesso para 1 para indicar que o login foi bem-sucedido
                            break; // Saia do loop assim que o login for bem-sucedido
                        }
                    }
                    //Se o login não for bem sucedido, retorna ao início da área de Login
                    if (login_sucesso == 0) {
                        printf("\nErro no login. Usuário desconhecido, Email e/ou senha incorretos.\n");
                        printf("Deseja se cadastrar no sistema(S/N)?: ");
                        scanf(" %s", &resp_errologin);
                        switch(resp_errologin){
                            case 'S': case 's':case 'Sim': case 'sim':
                                goto inicio;
                            break;
                            case 'N': case 'n':case 'Nao': case 'nao':
                                printf("\nFinalizando sistema...\n");
                            break;

                        }
                    }

                }
                //Se não
                else{
                    printf("\nFinalizando sistema...\n");
                }
                break;
                //Se não deseja visualizar os cadastros feitos, entra na área de Login
                case 'N': case 'n':case 'Nao': case 'nao':
                    goto area_login;
                    break;
            }
        }
    }
    //Se o usuário não deseja realizar o cadastro, encerra o sistema.
    else if((resp_usuario == 's')||(resp_usuario=='S')){
        goto inicio_login;
    }
    //Se digitar diferente de S ou N, imprime mensagem de erro.
    else{
        printf("\nHouve um erro.\nRetornando ao início...\n\n");
        goto inicio_sys;
    }
    return 0;
}
