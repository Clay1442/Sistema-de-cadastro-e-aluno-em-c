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

void cadastrar(); 
void listar();
void pesquisar();
void pesquisar();
void excluir();
void editar();

int main(int argc, char *argv[]) {
    
    int selecionado; //variavel que seleciona a função  
    
do {    
   printf("\nBem vindo ao painel de cadastro de aluno\n");
   printf("Selecione o que deseja digitando o numero: \n\n 1.Cadastrar \n 2.Listar \n 3.Pesquisar \n 4.Editar \n 5.Excluir \n 6.Desligar \n");
         scanf("%d", &selecionado);   
          getchar(); // Consome o '\n' deixado pelo scanf
         
         // switch case que chama as funções 
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
			editar();	
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

}while(selecionado != 6 ); // enquanto o valor inserido na variavel "selecionado" for diferente de zero o laço se repetirar 

	return 0;
}

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
	
} // fim da função cadastrar 


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
} // fim da função listar


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
} // fim da função pesquisar


void excluir(){
 FILE *arquivo = fopen("aluno.txt", "r");  //abrindo o arquivo no modo leitura
 FILE *arquivoModificado = fopen("alunoTemporario.txt", "w" ); //abrindo arquivo aluno temporario em modo de escrita 
 aluno cadastro;
 int exmatricula; // variavel para pesquisar e auxiliar a variavel matricula 
 int found = 0; // variavel que verifica se o codigo funcionou ou não
 
 
 if (arquivo == NULL || arquivoModificado == NULL) {
 	printf("Erro ao abrir o arquivo. \n");
    getchar();
 }
 //printando a variavel que recebe exmatricula 
   printf("Digite o numero de matricula que deseja excluir: \n");
   scanf("%d", &exmatricula);

//leitura de dados usando while 
<<<<<<< Updated upstream
 while(fgets(cadastro.nome, 100, arquivo) != NULL) {
=======
 while(fgets(cadastro.nome, 100, arquivo) != NULL) {0
>>>>>>> Stashed changes
    fscanf(arquivo, "%d\n", &cadastro.idade);
    fgets(cadastro.curso, 200, arquivo);
	fscanf(arquivo, "%d\n", &cadastro.matricula);    
		  
		  //condição para o exluir a matricula inserida 
		  if (cadastro.matricula != exmatricula) {
            fprintf(arquivoModificado, "%s%d\n%s%d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula);
        } else {
	         found = 1;	// se found vor verdadeiro
	         printf("Matrícula excluída! \n");
		}    
      }
   
<<<<<<< Updated upstream
   fclose(arquivo);            //fechando arquivo 
   fclose(arquivoModificado);   //fechando o arquivoModificado
   remove("aluno.txt");     //removendo o arquivo
=======
   fclose(arquivo); //fechando arquivo 
   fclose(arquivoModificado); //fechando o arquivoModificado
   remove("aluno.txt");  //removendo o arquivo
>>>>>>> Stashed changes
   rename("alunoTemporario.txt", "aluno.txt"); //renomeando aluno temporario para aluno
   
   //caso found seja diferente de 1 printa que não foi encontrado o arquivo
   if(!found){
   	printf("Matrícula não encontrada. \n");  // se found for falso retorna o printf 
   }
} // fim da função excluir


void editar(){ 
 FILE *arquivo = fopen("aluno.txt", "r");  //abrindo o arquivo em modo de leitura
 FILE *arquivoModificado = fopen("alunoTemporario.txt", "w" );	//abrindo o arquivoModificado em modo de escrita 
<<<<<<< Updated upstream
 aluno cadastro;  
 int editar; // variavel para pesquisar e auxiliar a variavel aluno
 int found = 0;	// variavel que verifica se o codigo funcionou ou não
=======
 aluno cadastro;
 int editar;
 int found = 0;	
>>>>>>> Stashed changes
	
  if (arquivo == NULL || arquivoModificado == NULL) {
 	printf("Erro ao abrir o arquivo. \n");
    getchar();
  }
<<<<<<< Updated upstream
 //printando a variavel editar
=======
 //printando a variavel arquivo
>>>>>>> Stashed changes
  printf("Digite o numero de matricula que deseja editar: \n");
 scanf("%d", &editar);
 getchar();

// laço para scanear o arquivo 
 while(fgets(cadastro.nome, 100, arquivo) != NULL) {
    fscanf(arquivo, "%d\n", &cadastro.idade);
    fgets(cadastro.curso, 200, arquivo);
	fscanf(arquivo, "%d\n", &cadastro.matricula);    
		  
	// condição para editar caso a variavel editar seja igual a variavel da estruct cadastro.matricula
    if(cadastro.matricula == editar){
    found = 1;
			printf("Digite o novo nome do aluno: \n");
			fgets(cadastro.nome, 100, stdin);
			
			printf("Digite a nova idade:\n");
			scanf("%d", &cadastro.idade);
			getchar();
			
			printf("Digite o novo nome do curso: \n");
			fgets(cadastro.curso, 200, stdin);
			
			printf("Digite a nova matrícula:\n");
			scanf("%d", &cadastro.matricula);
			getchar(); 	
    	}
    	fprintf(arquivoModificado, "%s%d\n%s%d\n", cadastro.nome, cadastro.idade, cadastro.curso, cadastro.matricula); //armazenar os dados no arquivoModificado
	}

    fclose(arquivo);  // fechar arquivo
	fclose(arquivoModificado); // fechar arquivoModificado
	remove("aluno.txt");
	rename("alunoTemporario.txt", "aluno.txt");

	if (found) {
		printf("Aluno editado com sucesso!\n"); // variavel found igual a verdadeiro printa que foi editado
	} else {
		printf("Matrícula não encontrada.\n"); // variavel foun igual a falso printa que não encotrou matricula
	}
<<<<<<< Updated upstream
}    // fim da função editar
=======
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
			editar();	
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

>>>>>>> Stashed changes
