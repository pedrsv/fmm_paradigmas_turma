/*
	AULA DE PARADIGMAS DE PROGRAMAÇÃO
	PROFESSOR: PEDRO CORREA
	ALUNO: PEDRO LUCAS SOARES DA SILVA
	DATA: 25 DE JULHO DE 2024
*/

#include <stdio.h>  // Para interação de entrada e saída com o usuário
#include <locale.h> // Para definir linguagem e acentuação gráfica
#include <string.h> // Para usar o strcmp() -- comparar string
#include <conio.h>  // Para usar o getch() -- segurar a tela
#include <stdlib.h> // Para usar o system.cls(), system("pause");

#define TAM_TURMA 30

struct tipo_aluno {
	char mat[7]; // os que forem do mesmo tipo pode ficar na mesma linha
	char nome[50];
	char sexo;
	float ap1=0;
	float ap2=0;
};

struct tipo_turma {
	char nome[8];
	tipo_aluno alunos[TAM_TURMA];
	int total_al=0;
};

// Reservado para as funções
void cadastrar(tipo_turma *turma){
	
	// TODO: ver se turma já não está cheia
	
	fflush(stdin);
	printf("\nDigite a matrícula do aluno: ");
	gets(turma->alunos[turma->total_al].mat);
	
	fflush(stdin);
	printf("\nDigite o nome do aluno: ");
	gets(turma->alunos[turma->total_al].nome);
	
	fflush(stdin);
	printf("\nDigite o sexo do aluno [M/F]: ");
	turma->alunos[turma->total_al].sexo = getchar();
	
	printf("\nAluno \"%s\" cadastrado com sucesso!", turma->alunos[turma->total_al].nome);
	turma->total_al++;
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	tipo_turma turma;
	int op;
	
	while(1){
		system("cls");
		printf("\n======== MENU ========");
		printf("\n [1] Cadastrar aluno");
		printf("\n [2] Listar turma");
		printf("\n [3] Pesquisar aluno");
		printf("\n [4] Inserir nota");
		printf("\n [5] Mostrar aprovados");
		printf("\n [0] Sair");
//		printf("\n [ ] <mock>");
		
		printf("\nDigite sua opção: ");
		scanf("%d", &op);
		
		printf("\n[DEBUG]: Início do retorno:\n");
		switch(op){
			case 0:
				return 0;
//				break; // [not needed]
			case 1:
				cadastrar(&turma);
				break;
			case 2:
//				listar(&turma);
				break;
			case 3:
//				pesquisar(&turma);
				break;
			case 4:
//				inserir(&turma);
				break;
			case 5:
//				aprovados(&turma);
				break;
			default:
				printf("\nOpção inválida!\n");
		};
		
		printf("\n[DEBUG]: Fim do retorno.\n");
		getch();
		
	};
	
	return 0;
		
}
