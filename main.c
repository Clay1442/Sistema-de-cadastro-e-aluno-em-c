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

//função que cadastra o aluno
 void cadastrar(){
	aluno cadastro;
	FILE *arquivo= fopen("aluno.txt", "a");//abrir um ponteiro do tipo FILE pra criar o arquivo

    if (arquivo == NULL){
    	printf("Erro ao abrir o arquivo.\n");//condição NULL
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
    
    //Salvar no arquivo.txt
	fprintf(arquivo, "%s%d\n%s%d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
	
	//resultado na tela avisando que foi salvo com sucesso
	printf("\nSalvo com sucesso\n");   
	fclose(arquivo);
	
}

//função que lista a quantidade de alunos cadastrados 
void listar(){
 FILE *arquivo = fopen("aluno.txt", "r");//abrir o arquivo.txt para leitura 
 aluno cadastro;
 int found = 0;
 if (arquivo == NULL){
 		printf("Erro ao abrir o arquivo.\n");
    	return;
 }
    //scanear e imprimir os produtos listados
	printf("Lista de Alunos Cadastrados: \n");
	 while (fgets(cadastro.nome, 100, arquivo) != NULL) {
        fscanf(arquivo, "%d\n", &cadastro.idade);  
		fgets(cadastro.curso, 200, arquivo);
	    fscanf(arquivo, "%d\n", &cadastro.matricula);

        
        printf("\n\tNome: %s", cadastro.nome);
        printf("\n\tIdade: %d\n", cadastro.idade);
        printf("\tCurso: %s", cadastro.curso);
        printf("\tMatricula: %d\n", cadastro.matricula);
        found = 1;
    }
    
	if(!found){
		printf("Nenhum aluno registrado. \n\n");
	}
 
  fclose(arquivo);
}

//função para fazer a pesquisa do aluno desejado
void pesquisar(){
 FILE *arquivo = fopen("aluno.txt", "r");   //abrindo o arquivo no modo leitura
 char pesq[100]; //    variavel usada para buscar pesquisa
 aluno cadastro ; //   struct cadastro 
 int found = 0; //   retornar o que foi encontrado
 
 if (arquivo == NULL){
 	printf("Erro ao abrir o arquivo. \n");
 	return;
 }
 
 printf("Digite o nome do aluno: \n");   // print do tipo char pra receber o aluno que se procura
  fgets(pesq, 100, stdin);
 getchar(); // limpa o buffer do teclado
      
      // while para scanear dentro do arquivo.txt 
	  while (fgets(cadastro.nome, 100, arquivo) != NULL) {
        fscanf(arquivo, "%d\n", &cadastro.idade);  
		fgets(cadastro.curso, 200, arquivo);
	    fscanf(arquivo, "%d\n", &cadastro.matricula);
      
     // usar um strstr para buscar o nome do aluno inserido na variavel pesq dentro das variaveis do aluno e imprimir o que foi encontrado  
     if (strstr(cadastro.nome, pesq) != NULL) {
            printf("\n\tNome: %s", cadastro.nome);
            printf("\tIdade: %d\n", cadastro.idade);
            printf("\tCurso: %s", cadastro.curso);
            printf("\tMatrícula: %d\n", cadastro.matricula);
            found = 1;
	 }
}     
     //se nao encontrar o nome que foi inserido imprimir na tela que não foi encontrado
     if(!found){
     	printf("Aluno não encontrado. \n");
	 }

    fclose(arquivo);//Fechar arquivo 
}

void excluir(){
 FILE *arquivo = fopen("aluno.txt", "r");
 FILE *arquivoModificado = fopen("alunoTemporario.txt", "w" );
 aluno cadastro;
 int exmatricula;
 int found = 0;
 
 
 if (arquivo == NULL || arquivoModificado == NULL) {
 	printf("Erro ao abrir o arquivo. \n");
    getchar();
 }
 
   printf("Digite o numero de matricula que deseja excluir: \n");
   scanf("%d", &exmatricula);

 
 while(fgets(cadastro.nome, 100, arquivo) != NULL) {
    fscanf(arquivo, "%d\n", &cadastro.idade);
    fgets(cadastro.curso, 200, arquivo);
	fscanf(arquivo, "%d\n", &cadastro.matricula);    
		  
		  if (cadastro.matricula != exmatricula) {
            fprintf(arquivoModificado, "%s%d\n%s%d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
        } else {
	         found = 1;	
	         printf("Matrícula excluída! \n");
		}    
      }
   
   fclose(arquivo);
   fclose(arquivoModificado);
   remove("aluno.txt");
   rename("alunoTemporario.txt", "aluno.txt");
   
   if(!found){
   	printf("Matrícula não encontrada. \n");
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
		case 3:
		   pesquisar();   
			break;
		case 4:
				
			break;
		case 5:
			excluir();	
				break;		
		case 6:
			printf("Desligando.. \n");
				break;		
		default:		
		   printf("selecao inexistente.\n");
		    break;
	}
         
         

system("pause");

}while(selecionado != 6 );

	return 0;
}
