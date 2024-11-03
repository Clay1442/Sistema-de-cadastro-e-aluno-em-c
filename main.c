#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//estruct que armazena os dados que serão salvos na memoria 
typedef struct{
	char nome[100];
	char curso[200];
	int idade;
	int matricula;
}aluno;


 void cadastrar(){
	aluno cadastro;
	FILE *arquivo= fopen("aluno.txt", "a");

    if (arquivo == NULL){
    	printf("Erro ao abrir o arquivo.\n");
    	return;
	}
	
	//Leitura nome
	printf("Digite o nome do aluno: \n");
    fgets(cadastro.nome, 100, stdin);
    
    //Leitura da idade
    printf("Digite sua idade:\n");
    scanf("%d", &cadastro.idade);
    getchar(); // Consome o '\n' deixado pelo scanf
    
	//Leitura do curso   
    printf("Digite o nome do curso: \n");
	fgets(cadastro.curso, 200, stdin);   
	
	//Leitura da matricula 
     printf("Digite a matricula do aluno:");
     scanf("%d", &cadastro.matricula);
	 
	//print resultado  
    printf("\nNome: %s Idade: %d\n Curso: %s Matricula: %d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
    
    //Salvar no arquivo
	fprintf(arquivo, "%s%d\n%s%d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
	
	printf("\nSalvo com sucesso\n");   
	fclose(arquivo);
	
}

void listar(){
 FILE *arquivo = fopen("aluno.txt", "r");
 aluno cadastro;
 
 if (arquivo == NULL){
 		printf("Erro ao abrir o arquivo.\n");
    	return;
 }
	printf("Lista de Alunos Cadastrados: \n");
	 while (fgets(cadastro.nome, 100, arquivo) != NULL) {
        fscanf(arquivo, "%d\n", &cadastro.idade);  
		fgets(cadastro.curso, 200, arquivo);
	    fscanf(arquivo, "%d\n", &cadastro.matricula);

        // Imprime os dados do aluno
        printf("\n\tNome: %s", cadastro.nome);
        printf("\n\tIdade: %d\n", cadastro.idade);
        printf("\tCurso: %s", cadastro.curso);
        printf("\tMatricula: %d\n", cadastro.matricula);
    }
	
	
}



int main(int argc, char *argv[]) {
    
    int selecionado; //variavel que seleciona a função  
    
do {    
   printf("\nBem vindo ao painel de cadastro de aluno\n");
   printf("Selecione o que deseja digitando o numero: \n\n 1.Cadastrar \n 2.Listar \n 3.Pesquisar \n 4.Editar \n 5.Excluir \n 6.Desligar \n");
         scanf("%d", &selecionado);   
          getchar(); // Consome o '\n' deixado pelo scanf
         
    switch(selecionado){
       case 1:
	      cadastrar();
		  break;
		case 2:
           listar();
			break;
		default:
		   printf("selecao inexistente.\n");
		    break;
	}
         
         

system("pause");

}while(selecionado <= 6);

	return 0;
}