#include <stdio.h> // para as funções básicas de entra e saída
#include <locale.h> // para exibição da acentuação gráfica em portugês
#include <conio.h> // para o getch() - Segurar a tela
#include <string.h> // para as funções de string
#include <stdlib.h> // para o system("cls") - Limpar a tela

#define TAM_TURMA 30

struct tipo_aluno{
	char mat[7];
	char nome[50];
	char sexo;
	float p1 = 0;
	float p2 = 0;
};

struct tipo_turma{	
	char nome[8];
	tipo_aluno alunos[TAM_TURMA];
	int total_al = 0;
};

void voltar(){		
		printf("\n\n**********************************************************");			
		printf("\n*       PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.    *");
		printf("\n**********************************************************");
		getch();
}

void cadastrar(tipo_turma *turma){	
	// verifica se a turma está cheia:	
	if(turma->total_al >= TAM_TURMA ){
		printf("\n**********************************************************");		
		printf("\n* IMPOSSÍVEL CADASTRAR!  MOTIVO: A turma está completa.  *");
		printf("\n* PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.          *");
		printf("\n**********************************************************");
		return;
	}
	
	system("cls");
	printf("\n\n**********************************************************");		
	printf("\n*                       MATRICULANDO ALUNO               *");	
	printf("\n**********************************************************");
	fflush(stdin);
	printf("\n\n         Digite a matrícula do aluno: ");
	gets(turma->alunos[turma->total_al].mat);
	fflush(stdin);
	printf("\n         Digite o nome do aluno: ");
	gets(turma->alunos[turma->total_al].nome);
	fflush(stdin);
	printf("\n         Digite o sexo do aluno: ");
	turma->alunos[turma->total_al].sexo = getchar();
	
	turma->total_al++;
	
	printf("\n\n         ALUNO CADASTRADO COM SUCESSO !");
	
}

void mostrar_al(tipo_aluno al){	
	printf("\n          Mat: %s",al.mat);
	printf("\n          Nome: %s",al.nome);
	printf("\n          Sexo: %c",al.sexo);
	printf("\n          P1: %.2f",al.p1); 
	printf("\n          P2: %.2f",al.p2); 
}

void listar(tipo_turma *turma){
	system("cls");
	// verifica se está vazia
	if(turma->total_al == 0 ){
		printf("\n\nIMPOSSÍVEL LISTAR!  MOTIVO: A turma está vazia.");		
		return;
	}
	
	printf("\n\n**********************************************************");		
	printf("\n     LISTA DOS ALUNOS DA TURMA %s", turma->nome);	
	
	for(int i = 0 ; i < turma->total_al ; i++){
		printf("\n\n        ==== %dº Aluno ====", i+1);
		mostrar_al(turma->alunos[i]);
	}
		
}

void pesq_nome(tipo_turma *turma){
	char nome_pesq[50];
	int achou = 0;
	system("cls");
	printf("\n\n**********************************************************");		
	printf("\n*                       PESQUISANDO PELO NOME            *");	
	printf("\n**********************************************************");
	fflush(stdin);
	
	printf("\n          Digite o nome para pesquisa: ");
	gets(nome_pesq);
	
	for(int i = 0 ; i < turma->total_al; i++){
		
		if(!strcmpi(nome_pesq , turma->alunos[i].nome)){
			printf("\n    ALUNO ENCONTRADO NA %dª POSIÇÃO", i + 1);
			mostrar_al(turma->alunos[i]);
			achou = 1;
		}
	}	
	
	if(!achou)
		printf("\n\n ALUNO %s NÃO ENCONTRADO!", nome_pesq)	;	
		
	
}

void pesq_mat(tipo_turma *turma){
	char mat_pesq[50];
	int achou = 0;
	system("cls");
	printf("\n\n**********************************************************");		
	printf("\n*                       PESQUISANDO PELA MATRÍCULA       *");	
	printf("\n**********************************************************");
	fflush(stdin);
	
	printf("\n          Digite a matrícula para pesquisa: ");
	gets(mat_pesq);
	
	for(int i = 0 ; i < turma->total_al; i++){
		
		if(!strcmpi(mat_pesq , turma->alunos[i].mat)){
			printf("\n    ALUNO ENCONTRADO NA %dª POSIÇÃO", i + 1);
			mostrar_al(turma->alunos[i]);
			achou = 1;
		}
	}	
	
	if(!achou)
		printf("\n\n ALUNO COM MATRÍCULA %s NÃO ENCONTRADO!", mat_pesq)	;	
			
}

void pesq_sexo(tipo_turma *turma){
	char sexo;
	int achou = 0;
	system("cls");
	printf("\n\n**********************************************************");		
	printf("\n*                       PESQUISANDO PELO SEXO            *");	
	printf("\n**********************************************************");
	fflush(stdin);
	
	printf("\n          Digite o sexo para pesquisa: ");
	sexo = getchar();
	
	for(int i = 0 ; i < turma->total_al; i++){
		
		if(sexo == turma->alunos[i].sexo){
			printf("\n    ALUNO ENCONTRADO NA %dª POSIÇÃO", i + 1);
			mostrar_al(turma->alunos[i]);
			achou = 1;
		}
	}	
	
	if(!achou)
		printf("\n\n ALUNO COM SEXO %c NÃO ENCONTRADO!", sexo)	;	
	
	
}

void pesquisar(tipo_turma *turma){
	while(1){
		system("cls");
		printf("\n\n**********************************************************");
		// verifica se está vazia
		if(turma->total_al == 0 ){		
			printf("\n\n       IMPOSSÍVEL PESQUISAR!  MOTIVO: A turma está vazia.");				
			return;
		}
		int op;
		
		printf("\n\n          ==== MENU DE PESQUISA ====");
		    printf("\n         [1] - Pesquisar por nome: ");
		    printf("\n         [2] - Pesquisar por matrícula: ");
		    printf("\n         [3] - Pesquisar por sexo: ");	    
		    printf("\n         [0] - Sair da pesquisa");
		    
		    printf("\n\n          Digite sua opção: ");
		    //printf("\n\n**********************************************************");
		   // gotoxy(29,11);
		    scanf("%d", &op);
		    
		    switch(op){	    	
		    	case 0: return;	    	
				case 1: pesq_nome(turma);						
		    			break;
		    	case 2: pesq_mat(turma);
		    			break;
		    	case 3: pesq_sexo(turma);
		    			break;
		    		    			
		    	default: printf("Opção inválida");
			}
	//getch();	
	voltar();	    
	}
}




void cad_p1(tipo_turma *turma){
	char mat_pesq[7];
	int achou = 0;
	float p1;
	system("cls");
	printf("\n\n**********************************************************");		
	printf("\n*                       CADASTRANDO P1                   *");	
	printf("\n**********************************************************");
	fflush(stdin);

	printf("\n          Digite a matrícula: ");
	gets(mat_pesq);

	for(int i = 0 ; i < turma->total_al; i++){

		if(!strcmpi(mat_pesq , turma->alunos[i].mat)){
			printf("\n    DIGITE A NOTA P1: ");
			scanf("%f", &p1);
			turma->alunos[i].p1 = p1;
			achou = 1;
			printf("\n\n         NOTA P1 CADASTRADA COM SUCESSO !");
			break;
		}
	}

	if(!achou)
		printf("\n\n ALUNO COM MATRÍCULA %s NÃO ENCONTRADO!", mat_pesq)	;	
		
}


void cadastrar_nota(tipo_turma *turma){
	while(1){
		system("cls");
		printf("\n\n**********************************************************");
		// verifica se está vazia
		if(turma->total_al == 0 ){		
			printf("\n\n       IMPOSSÍVEL CADASTRAR NOTA!  MOTIVO: A turma está vazia.");				
			return;
		}
		int op;

		printf("\n\n          ==== MENU DE CADASTRO DE NOTA ====");
		    printf("\n         [1] - Cadastrar P1: ");
		    printf("\n         [2] - Cadastrar P2: ");
		    printf("\n         [3] - Cadastrar P1 e P2: ");
		    printf("\n         [0] - Sair do cadastro de nota");

		    printf("\n\n          Digite sua opção: ");
		    scanf("%d", &op);

		    switch(op){
				case 0: return;
				case 1: cad_p1(turma);
		    			break;
				case 2: //cad_p2(turma);
		    			break;
				case 3: //cad_p1_p2(turma);
		    			break;

		    	default: printf("Opção inválida");
			}
	voltar();	    
	}
}


int main() { 
    setlocale(LC_ALL, "");
    
    tipo_turma turma; // cria uma turma 
    int op;
    
    fflush(stdin);
    printf("\n**********************************************************");		
	printf("\n*                  INÍCIO DO PROGRAMA                    *");
	printf("\n*                  Digite o nome da turma: ");
	//printf("\n**********************************************************");
    //gotoxy(44,4);
	gets(turma.nome); 
    
    while(1){
    	system("cls");
    	
    	printf("\n**********************************************************");
		printf("\n                  = TURMA %s =", turma.nome);
	    printf("\n                   ==== MENU ====");
	    printf("\n                  [1] - Cadastrar aluno");
	    printf("\n                  [2] - Listar turma");
	    printf("\n                  [3] - Pesquisar aluno");
	    printf("\n                  [4] - Cadastrar nota");
	    printf("\n                  [5] - Alterar dados de aluno");
	    printf("\n                  [0] - Sair");
	    printf("\n**********************************************************");
	    printf("\n\n                   Digite sua opção: ");
	    //printf("\n\n**********************************************************");
	    //gotoxy(38,12);
	    scanf("%d", &op);

	    switch(op){
	    	
	    	case 0: return 0;
	    	
			case 1: cadastrar(&turma);
	    			break;
	    	case 2: listar(&turma);
	    			break;
	    	case 3: pesquisar(&turma);
	    			break;
	    	case 4: cadastrar_nota(&turma);
	    			break;		
	    	case 5: //cadastrar(&turma);
	    			break;			
	    	default: printf("Oção inválida");
		}
	    
	    //getch();
	    voltar();
   }
    
    
    
    
} 
