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
	
	
	//Leitura nome
	printf("Digite o nome do aluno: ");
    fgets(cadastro.nome, 100, stdin);
    
    //Leitura da idade
    printf("\nDigite sua idade:");
    scanf("%d", &cadastro.idade);
    getchar(); // Consome o '\n' deixado pelo scanf
    
	//Leitura do curso   
    printf("Digite o nome do curso: ");
	fgets(cadastro.curso, 200, stdin);   
	
	//Leitura da matricula 
     printf("Digite a matricula do aluno:");
     scanf("%d", &cadastro.matricula);
	   
    printf("Nome: %s\n Idade: %d\n  Curso: %s\n Matricula: %d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
	
}




int main(int argc, char *argv[]) {
    
    int selecionado; //variavel que seleciona a função  
    
do {    
   printf("Bem vindo ao painel de cadastro de aluno\n");
   printf("Selecione o que deseja digitando o numero: \n\n 1.Cadastrar \n 2.Listar \n 3.Pesquisar \n 4.Editar \n 5.Excluir \n 6.Desligar \n");
         scanf("%d", &selecionado);   
          getchar(); // Consome o '\n' deixado pelo scanf
         
    switch(selecionado){
       case 1:
	      cadastrar();
		  break;
		default:
		   printf("selecao inexistente.\n");
		    break;
	}
         
         

system("pause");

}while(selecionado <= 6);

	return 0;
}