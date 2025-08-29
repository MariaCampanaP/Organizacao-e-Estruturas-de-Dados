/*Implemente um c�digo usando pilha que simule o avan�ar e voltar de uma p�gina web. Em
sua struct utilize um campo de string para guardar o nome do site.
-> Use duas pilhas: -> p�ginas visitadas. -> p�ginas que podem ser acessadas com "avan�ar"
O usu�rio pode:
-> Visitar (url) -> empilha no hist�rico e limpa a pilha de futuro
-> Voltar() -> desempilha do hist�rico e empilha no futuro
-> Avan�ar() -> desempilha do futuro e empilha no hist�rico*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char sites[MAX][100]; //At� 100 p�ginas de 100 caracteres
    int topo; //Topo da pilha
}Pilha;

//Inicializar a pilha
void inicializar(Pilha *p){
    p->topo = -1;
}

//Verifica se a pilha est� vazia (retorna 1 se sim, 0 se n�o)
int vazia(Pilha *p){
    return p->topo == -1;
}

//Verificar se a pilha est� cheia (retorna 1 se sim, 0 se n�o)
int cheia(Pilha *p){
    return p->topo == MAX - 1;
}

//Empilhar
void push(Pilha *p, char *url){
    if(cheia(p)){ //Se est� cheia avisa que est� cheia
        printf("Pilha Cheia.\n");
        return;
    }
    strcpy(p->sites[++p->topo], url); //Incrementa o topo e copia a string "url"
}

//Desempilhar
char* pop(Pilha *p){
    if(vazia(p)){ //Se est� vazia nao tem nada para desempilhar
        return NULL;
    }
    return p->sites[p->topo--]; //Retornar o site e depois decrementa o topo
}

//Olha o elemento do topo sem remover
char* topo(Pilha *p){
    if(vazia(p)){ //Se estiver vazia nao tem topo
        return NULL;
    }
    return p->sites[p->topo]; //Retorna o site do topo
}

//visitar uma nova p�gina
void visitar(Pilha * historico, Pilha *futuro, char *url){
    push(historico, url); //Empilha o site no hist�rico
    inicializar(futuro); //Limpa a pilha de futuro
    printf("Visitando: %s\n", topo(historico)); //Mostra a p�gina
}

//Volta para a p�gina anterior
void voltar(Pilha *historico, Pilha *futuro){
    if(historico->topo <= 0){ //Se s� tem 1 p�gina (ou nenhuma)
        printf("Nao ha paginas para voltar");
        return;
    }
    char *site = pop(historico); //remove o site atual do hist�rico
    push(futuro, site); //Coloca no futuro
    printf("Voltando para: %s\n", topo(historico)); //Mostra nova p�gina atual
}

//Avan�a para a pr�xima p�gina (se tiver)
void avancar(Pilha * historico, Pilha *futuro){
    if(vazia(futuro)){ //Se n�o tiver nada no futuro
        printf("Nao ha paginas para avancar.\n");
        return;
    }
    char *site = pop(historico); //Remove do futuro
    push(historico, site); //Coloca no hist�rico
    printf("Avancando para: %s\n", topo(historico)); //Mostra p�gina atual
}

int main(){
    Pilha historico, futuro; //Cria duas pilhas
    inicializar(&historico); //Inicializa hist�rico
    inicializar(&futuro); //Inicializa futuro

    int opcao;
    char url[100];

    do{
        printf("\n---Menu---\n");
        printf("1 - Visitar o site\n");
        printf("2 - Voltar\n");
        printf("3 - Avancar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            printf("Digite a URL:");
            fgets(url, 100, stdin);
            url[strcspn(url, "\n")] = '\0';
            visitar(&historico, &futuro, url);
            break;

        case 2:
            voltar(&historico, &futuro);
            break;

        case 3:
            avancar(&historico, &futuro);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");

        }
        if(!vazia(&historico)){
            printf("Pagina atual: %s\n", topo(&historico));
        }else{
            printf("Nenhuma pagina aberta.\n");
            }

    }while(opcao != 0);

    return 0;
}
