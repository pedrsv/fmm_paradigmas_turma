program Hello;
uses crt;
{This language is not case sensitive}

const TAM = 30;
type
tipo_aluno = record
    mat : array[1..7] of char;
    nome: array[1..50] of char;
    sexo: char;
    p1: real;
    p2: real;
    end;

{Reservado para declarar o ponteiro da turma}

tipo_turma = record
    nome: array[1..20] of char;
    alunos: array[1..TAM] of tipo_aluno;
    total_al: integer;
    end;

{a partir daqui serão declarados os procedimentos}

{Início do programa}
var
    turma: tipo_turma;
    op: integer;

begin

    writeln ('******************************');
    writeln ('       INÍCIO DO PROGRAMA');
    writeln ('Digite o nome da turma:');
    readln(turma.nome);

    while(true) do
        begin
            clrscr;

            writeln ('**********************************************************');
            writeln ('                  = TURMA  =', turma.nome);
	        writeln ('                   ==== MENU ====');
	        writeln ('                  [1] - Cadastrar aluno');
	        writeln ('                  [2] - Listar turma');
	        writeln ('                  [3] - Pesquisar aluno');
	        writeln ('                  [4] - Cadastrar nota');
	        writeln ('                  [5] - Alterar dados de aluno');
	        writeln ('                  [0] - Sair');
	        writeln ('**********************************************************');
            writeln;writeln;
	        writeln ('                   Digite sua opção: ');
            readln(op);
        end;
end.