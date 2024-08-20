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
tipo_ponteiro = ^tipo_turma;

tipo_turma = record
    nome: array[1..20] of char;
    alunos: array[1..TAM] of tipo_aluno;
    total_al: integer;
    end;

{a partir daqui serão declarados os procedimentos}
procedure cadastrar(turma: tipo_ponteiro);
var
    sexo: char;
begin
    clrscr;
    if (turma^.total_al = TAM) then
        begin
            writeln;
            writeln('* IMPOSSÍVEL CADASTRAR! Motivo: A turma está completa!');
            writeln('* PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.          *');
            writeln;
        end
    else
        begin
        	clrscr; { limpa a tela } 
        	writeln(); writeln();
        	writeln('**********************************************************');		
        	writeln('*                       MATRICULANDO ALUNO               *');	
        	writeln('**********************************************************');

            turma^.total_al := turma^.total_al + 1;

            write('Digite a matrícula: ');
            readln(turma^.alunos[turma^.total_al].mat);
            write('Digite o nome: ');
            readln(turma^.alunos[turma^.total_al].nome);
            write('Digite o sexo: ');
            readln(sexo); {armazena em variável separada}
            turma^.alunos[turma^.total_al].sexo := upcase(sexo); {converte em maiúscula para padronizar}
            writeln;writeln;
            writeln('   ALUNO CADASTRADO COM SUCESSO !!!');
        end;
end;

procedure listar(turma: tipo_ponteiro);
var
    sexo: char;
begin
    clrscr;
    if (turma^.total_al = TAM) then
        begin
            writeln;
            writeln('* IMPOSSÍVEL LISTAR! Motivo: A turma está vazia.');
            writeln('* PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.          *');
            writeln;
        end
    else
        begin
        	clrscr; { limpa a tela } 
        	writeln(); writeln();
        	writeln('**********************************************************');		
        	writeln('*                       LISTA DE ALUNOS                  *');	
        	writeln('**********************************************************');
        end;
end;

{Início do programa}
var
    turma: tipo_turma;
    op: integer;

begin

    writeln ('******************************');
    writeln ('       INÍCIO DO PROGRAMA');
    writeln ('Digite o nome da turma:');
    readln(turma.nome);
    turma.total_al := 0;

    while(true) do
        begin
            clrscr;

            writeln ('**********************************************************');
            writeln ('                  = TURMA  = ', turma.nome);
	        writeln ('                   ==== MENU ====');
	        writeln ('                  [1] - Cadastrar aluno');
	        writeln ('                  [2] - Listar turma');
	        writeln ('                  [3] - Pesquisar aluno');
	        writeln ('                  [4] - Cadastrar nota');
	        writeln ('                  [5] - Alterar dados de aluno');
	        writeln ('                  [0] - Sair');
	        writeln ('**********************************************************');
            writeln;writeln;
	        write('                   Digite sua opção: ');
            readln(op);

            case (op) of
                1: cadastrar(@turma);
                2: listar(@turma);
                3: writeln(' pesquisar(@turma);');
                4: writeln(' Cadastrar nota');
                5: writeln(' Alterar dados');
                0: Exit;
            end;

            readln;
        end;
end.