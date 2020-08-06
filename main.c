#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define branco "\033[1;37m"
#define verde "\033[1;32m"
#define amarelo "\033[1;33m"
#define vermelho "\033[1;31m"
struct alunos
{
    int ra;
    char nome[30];
};

struct professor
{
    char nome[30];
};

struct disciplinas
{
    int codigo_disciplina;
    char nome[30];
    char nome_professor_t1[30];
    char nome_professor_t2[30];
    int alunos_t1 [50];
    int alunos_t2 [50];
    int quantidade_alunos_t1;
    int quantidade_alunos_t2;
};

int menu()
{
    int opcao_menu;
    do
    {
        system("cls");
        printf(branco"\033[1;46m");
        system("cls");
        printf("\n 1-Cadastrar professores \n 2-Cadastrar alunos \n 3-Cadastrar Materias \n 4-Matricular alunos \n 5-Cancelar matricula \n ");
        printf("6-Vincular Professor \n 7-desvincular professor da turma \n 8-Imprimir todos professores \n 9-Imprimir todos os alunos \n 10-Imprimir todos as disciplinas");
        printf("\n 11-Imprimir todas as disciplinas de um aluno \n 12-Imprimir todos os alunos em uma disciplina de uma turma \n 13-Imprimir todos os alunos em uma disciplina");
        printf("\n 14-Imprimir todas as disciplinas de um professor \n 15-Imprimir todos os professores vinculados a uma materia \n 16-Sair \n\n Selecione uma das opcoes:");
        scanf("%d",&opcao_menu);
        fflush(stdin);
    }
    while(opcao_menu>16 || opcao_menu<0);
    return(opcao_menu);
}

void limpar(struct disciplinas *Conj_disciplinas)
{
    int i,j;
    for(i=0; i<32; i++)
    {
        for(j=0; j<50; j++)
        {
            Conj_disciplinas[i].alunos_t1[j]=0;
            Conj_disciplinas[i].alunos_t2[j]=0;
            strcpy(Conj_disciplinas[i].nome_professor_t1,"Null");
            strcpy(Conj_disciplinas[i].nome_professor_t2,"Null");
        }
    }
}

void cadastro_alunos(struct alunos *Conj_alunos,int *Num_alunos)
{
    int verificacao=1,i,flag=0;
    char nome[30];
    while(verificacao==1)
    {
        printf("\n para encerrar digite nome 0 \n \n digite nome do aluno:");
        fflush(stdin);
        gets(nome);
        for(i=0; i<*Num_alunos; i++)
        {
            if(strcmp(nome,Conj_alunos[i].nome)==0)
            {
                printf(amarelo"aluno ja cadastrado"branco);
                flag=1;
            }
        }

        if(strcmp(nome,"0")==0)
        {
            verificacao=0;
        }
        else
        {
            if(flag==0)
            {
                strcpy(Conj_alunos[*Num_alunos].nome,nome);
                Conj_alunos[*Num_alunos].ra=(*Num_alunos)+1000;
                *Num_alunos+=1;
                printf(verde" sucesso" branco);


            }
        }
        Sleep(500);
        system("cls");
        flag=0;
    }
}

void cadastro_Professores(struct professor *Conj_Professores,int *Num_Professores)
{
    int verificacao=1,flag=0,i;
    char nome[30];
    while(verificacao==1)
    {
        printf("\n para encerrar digite nome 0 \n \n digite nome do professor:");
        fflush(stdin);
        gets(nome);
        if(strcmp(nome,"0")==0)
        {
            verificacao=0;
        }
        else
        {
            for(i=0; i<*Num_Professores; i++)
            {
                if(strcmp(nome,Conj_Professores[i].nome)==0)
                {
                    flag=1;
                    printf(amarelo"professor ja cadastrado"branco);
                }
            }
            if(strcmp(Conj_Professores[*Num_Professores].nome,"0")==0)
            {
                verificacao=0;
            }
            if(flag==0)
            {
                strcpy(Conj_Professores[*Num_Professores].nome,nome);
                *Num_Professores+=1;
                printf(verde" sucesso" branco);
            }
        }
        Sleep(500);
        system("cls");
        flag=0;


    }
}

void cadastro_Disciplinas(struct disciplinas *Conj_disciplinas,int*Contador_disciplinas)
{
    int verificacao=1,flag=0,i;
    char nome[30];
    while(verificacao==1)
    {
        printf("\n para encerrar digite nome 0 \n \n digite nome da disciplina:");
        fflush(stdin);
        gets(nome);
        fflush(stdin);
        if(strcmp(nome,"0")==0)
        {
            verificacao=0;
        }
        else
        {
            for(i=0; i<*Contador_disciplinas; i++)
            {
                if(strcmp(nome,Conj_disciplinas[i].nome)==0)
                {
                    flag=1;
                    printf(amarelo"disciplina ja cadastrada"branco);

                }
            }
            if(flag==0)
            {
                strcpy(Conj_disciplinas[*Contador_disciplinas].nome,nome);
                Conj_disciplinas[*Contador_disciplinas].quantidade_alunos_t1=0;
                Conj_disciplinas[*Contador_disciplinas].quantidade_alunos_t2=0;
                Conj_disciplinas[*Contador_disciplinas].codigo_disciplina=1350+*Contador_disciplinas;
                *Contador_disciplinas+=1;
                printf(verde" sucesso" branco);
            }
        }
        Sleep(500);
        system("cls");
        flag=0;
    }
}

void verificador_alunos(struct alunos *Conj_alunos, int *Nalunos, int * Conjunto_ra,int Numero_alunosTotal,int tipo,int Ndisciplinas,int Numero_disciplinasTotal,int *Conjunto_cod,struct disciplinas *Conj_disciplinas,int turma)
{
    int continuar=1,flag=-2,flag2=1,ra,posicao=0,i,j;

    while(continuar==1)
    {   imprimir_alunos(Conj_alunos,Numero_alunosTotal,0);
        printf("\n\n\n");
        if(tipo==0)
            printf("\t\tdigite o ra dos alunos a serem matriculados, para encerrar digite 0  \n \n\t\tdigite ra:");
        else
            printf("\t\tdigite o ra dos alunos a serem desmatriculados, para encerrar digite 0  \n \n\t\tdigite ra:");
        fflush(stdin);
        scanf("%d",&ra);
        if(ra==0)
        {
            continuar=0;
        }
        else
        {
            for(i=0; i<Numero_alunosTotal; i++)
            {
                if(ra==Conj_alunos[i].ra)
                {
                    flag=1;
                }
                if(ra==Conjunto_ra[i])
                {
                    printf(amarelo"\t\taluno ja selecionado"branco);
                    flag=-1;
                }

            }
            if(tipo==1)
            {
                for(i=0; i<Ndisciplinas; i++)
                {
                    for(j=0; j<Numero_disciplinasTotal; j++)
                    {
                        if(Conjunto_cod[i]==Conj_disciplinas[j].codigo_disciplina)
                            posicao=j;
                    }

                    if(turma==1)
                    {
                        for(j=0; j<Conj_disciplinas[posicao].quantidade_alunos_t1; j++)
                        {
                            if(ra==Conj_disciplinas[posicao].alunos_t1[j])
                                flag2=0;
                        }
                    }
                    else
                    {
                        for(j=0; j<Conj_disciplinas[posicao].quantidade_alunos_t2; j++)
                        {
                            if(ra==Conj_disciplinas[posicao].alunos_t2[j])
                                flag2=0;
                        }
                    }
                }
            }
            else
            {
                flag2=0;
            }

            if(flag==-2)
            {
                printf(amarelo"\t\tra inexistente"branco);
            }
            if(flag2==1 && flag!=-2)
            {
                printf(amarelo"\t\taluno nao matriculado"branco);
            }
            if(flag==1 && flag2==0)
            {
                Conjunto_ra[(*Nalunos)]=ra;
                (*Nalunos)++;
            }
            flag=-2;
            flag2=1;
            ra=-1;
        }
        Sleep(500);
        system("cls");
    }

}

void verificador_professores(struct professor *Conj_professores, int *Nprofessores,int Numero_professoresTotal, char Conj_Ver_professores[30][30],struct disciplinas *Conj_disciplinas, int Numero_disciplinasTotal, int Ndisciplinas,int turma, int tipo, int *Conj_cod)
{
    int i,continuar=1,flag=0,posicao,j,k,flag2=0;
    char professores[30];
    while(continuar==1)
    {
        imprimir_professores(Conj_professores,Numero_professoresTotal,0);
        printf("\n\n\n");
        printf("\t\tdigite o nome dos professores a serem utilizados, para encerrar digite 0  \n \n\t\tdigite nome:");
        fflush(stdin);
        gets(professores);
        if(strcmp(professores,"0")==0)
        {
            continuar=0;
        }
        else
        {
            for(i=0; i<Numero_professoresTotal; i++)
            {
                if(strcmp(professores,Conj_professores[i].nome)==0)
                {
                    flag=1;
                }
                if(strcmp(professores,Conj_Ver_professores[i])==0)
                {
                    flag=3;
                }
            }
            if(tipo==1)
            {
                for(j=0; j<Ndisciplinas; j++)
                {
                    for(k=0; k<Numero_disciplinasTotal; k++)
                    {
                        if(Conj_cod[j]==Conj_disciplinas[k].codigo_disciplina)
                            posicao=k;
                    }
                    if(turma==1)
                    {
                        if(strcmp(professores,Conj_disciplinas[posicao].nome_professor_t1)==0)
                        {
                            flag2=1;
                        }
                    }
                    else
                    {
                        if(strcmp(professores,Conj_disciplinas[posicao].nome_professor_t2)==0)
                        {
                            flag2=1;
                        }
                    }
                }
            }
            else
            {
                flag2=1;
            }
            if(flag==1 && flag2==1)
            {
                strcpy(Conj_Ver_professores[*Nprofessores],professores);
                (*Nprofessores)++;
            }
            if(flag==3)
            {
                printf(amarelo"\t\tprofessor ja selecionado"branco);
            }
            if(flag==0)
            {
                printf(amarelo"\t\tprofessor inexistente"branco);
            }
            if(flag2==0 && flag!=0)
            {
                printf(amarelo"\t\tprofessor nao vinculado"branco);
            }
        }
        Sleep(500);
        system("cls");
        flag=0;
        flag2=0;
    }
}

void verificador_disciplinas(struct disciplinas *Conj_disciplinas, int * Ndisciplinas, int * Conjunto_cod, int Numero_disciplinasTotal)
{
    int cod,i,verificador1=1,verificador2=0,continuar=1;
    while(continuar==1)
    {
        imprimir_disciplinas(Conj_disciplinas,Numero_disciplinasTotal,0);
        printf("\n\n\n");
        printf("\t\tdigite os codigos das disciplinas, para encerrar digite 0  \n \n \t\tdigite codigo:");
        fflush(stdin);
        scanf("%d",&cod);
        if(cod==0)
        {
            continuar=0;
        }
        else
        {
            for(i=0; i<Numero_disciplinasTotal; i++)
            {
                if(cod==Conjunto_cod[i])
                {
                    printf(amarelo"\t\tmateria ja selecionada\n"branco);
                    verificador1=0;
                }
                if(cod==Conj_disciplinas[i].codigo_disciplina)
                {
                    verificador2=1;
                }
            }
            if(verificador2==0)
            {
                printf(amarelo"\t\tcodigo inexistente \n"branco);
            }
            if(verificador1==1 && verificador2==1)
            {
                Conjunto_cod[(*Ndisciplinas)]=cod;
                (*Ndisciplinas)++;
            }
            verificador1=1;
            verificador2=0;
            cod=-1;
        }
        Sleep(500);
        system("cls");
    }
}

void selecionar_turma(int *turma)
{
    do
    {
        printf("digite o numero da turma:");
        scanf("%d",turma);
        fflush(stdin);
        system("cls");
    }
    while(*turma!=1 && *turma!=2);
}

void enter_sair()
{
    char tipo;
    do
    {
        fflush(stdin);
        tipo=getch();
    }while(tipo!=13);

}

void desmatricular_alunos(struct disciplinas *Conj_disciplinas, struct alunos *Conj_alunos, int Numero_alunosTotal, int Numero_disciplinasTotal)
{
    int Conjunto_cod[32],i=0,Ndisciplinas=0,Conjunto_ra[50],posicao=0,turma,j=0,Nalunos=0,l=0,k=0,verificador=0;
    selecionar_turma(&turma);
    verificador_disciplinas(Conj_disciplinas,&Ndisciplinas,Conjunto_cod,Numero_disciplinasTotal);
    verificador_alunos(Conj_alunos,&Nalunos,Conjunto_ra,Numero_alunosTotal,1,Ndisciplinas,Numero_disciplinasTotal,Conjunto_cod,Conj_disciplinas,turma);
    if(Ndisciplinas!=0 && Nalunos!=0)
    {
        for(i=0; i<Ndisciplinas; i++)
        {
            for(j=0; j<Numero_disciplinasTotal; j++)
            {
                if(Conjunto_cod[i]==Conj_disciplinas[j].codigo_disciplina)
                    posicao=j;
            }
            for(l=0; l<Nalunos; l++)
            {
                if(turma==1)
                {
                    for(k=0; k<Conj_disciplinas[posicao].quantidade_alunos_t1; k++)
                    {
                        if(Conjunto_ra[l]==Conj_disciplinas[posicao].alunos_t1[k])
                        {
                            Conj_disciplinas[posicao].alunos_t1[k]=0;
                            verificador=1;
                        }
                    }
                    if(verificador==0)
                    {
                        printf(amarelo"Aluno %d nao estava matriculado em: %s\n"branco,Conjunto_ra[l],Conj_disciplinas[posicao].nome);
                    }


                }
                else
                {
                    for(k=0; k<Conj_disciplinas[posicao].quantidade_alunos_t2; k++)
                    {
                        if(Conjunto_ra[l]==Conj_disciplinas[posicao].alunos_t2[k])
                        {
                            Conj_disciplinas[posicao].alunos_t2[k]=0;
                        }
                    }

                }
                verificador=0;
            }
        }
        printf(verde"operacao executada"branco);
    }
    else
    {
        printf(vermelho"operacao invalida"branco);
    }
    enter_sair();
}

void matricular_alunos(struct disciplinas *Conj_disciplinas,struct alunos *Conj_alunos,int Numero_alunosTotal,int Numero_disciplinasTotal)
{
    int Conjunto_cod[32],i=0,verificador1=1,Ndisciplinas=0,Conjunto_ra[50],Nalunos=0,k=0,posicao=0,j=0,l=0,turma,verificador2=1,g;
    selecionar_turma(&turma);
    verificador_disciplinas(Conj_disciplinas,&Ndisciplinas,Conjunto_cod,Numero_disciplinasTotal);
    verificador_alunos(Conj_alunos,&Nalunos,Conjunto_ra,Numero_alunosTotal,0,Ndisciplinas,Numero_disciplinasTotal,Conjunto_cod,Conj_disciplinas,turma);
    if(Ndisciplinas!=0 && Nalunos!=0)
    {
        for(i=0; i<Ndisciplinas; i++)
        {
            for(k=0; k<Numero_disciplinasTotal; k++)
            {
                if(Conjunto_cod[i]==Conj_disciplinas[k].codigo_disciplina)
                {
                    posicao=k;
                }
            }

            for(j=0; j<Nalunos; j++)
            {
                if(turma==1)
                {
                    for(g=0; g<Conj_disciplinas[posicao].quantidade_alunos_t2; g++)
                    {
                        if(Conjunto_ra[j]==Conj_disciplinas[posicao].alunos_t2[g])
                        {
                            verificador2=0;
                            printf(amarelo"Aluno: %d ja matriculado na materia: %s em outra turma \n"branco,Conjunto_ra[j],Conj_disciplinas[posicao].nome);

                        }
                    }

                    for(l=0; l<Conj_disciplinas[posicao].quantidade_alunos_t1; l++)
                    {
                        if(Conjunto_ra[j]==Conj_disciplinas[posicao].alunos_t1[l])
                        {
                            verificador1=0;
                            if(verificador2==1)
                                printf(amarelo"Aluno: %d ja matriculado na materia: %s \n"branco,Conjunto_ra[j],Conj_disciplinas[posicao].nome);
                        }
                    }
                }
                else
                {
                    for(g=0; g<Conj_disciplinas[posicao].quantidade_alunos_t1; g++)
                    {
                        if(Conjunto_ra[j]==Conj_disciplinas[posicao].alunos_t1[g])
                        {
                            verificador2=0;
                            printf(amarelo"Aluno: %d ja matriculado na materia: %s em outra turma \n"branco,Conjunto_ra[j],Conj_disciplinas[posicao].nome);

                        }
                    }

                    for(l=0; l<Conj_disciplinas[posicao].quantidade_alunos_t2; l++)
                    {
                        if(Conjunto_ra[j]==Conj_disciplinas[posicao].alunos_t2[l])
                        {
                            verificador1=0;
                            if(verificador2==1)
                                printf(amarelo"Aluno: %d ja matriculado na materia: %s \n"branco,Conjunto_ra[j],Conj_disciplinas[posicao].nome);
                        }
                    }

                }
                if(verificador1==1 && verificador2==1 && turma==1)
                {
                    Conj_disciplinas[posicao].alunos_t1[Conj_disciplinas[posicao].quantidade_alunos_t1]=Conjunto_ra[j];
                    Conj_disciplinas[posicao].quantidade_alunos_t1++;
                }

                if(verificador1==1 && verificador2==1 && turma==2)
                {
                    Conj_disciplinas[posicao].alunos_t2[Conj_disciplinas[posicao].quantidade_alunos_t2]=Conjunto_ra[j];
                    Conj_disciplinas[posicao].quantidade_alunos_t2++;
                }

                verificador1=1;
                verificador2=1;
            }
        }
        printf(verde"execucao concluida"branco);
    }
    else
    {
        printf(vermelho"operacao invalida"branco);
    }
    enter_sair();
}

void Desvincular_professores(struct professor *Conj_professores, struct disciplinas *Conj_disciplinas, int numero_professoresTotal,int numero_disciplinasTotal)
{
    int turma,Ndisciplinas=0,Conjunto_cod[32],i,posicao,Nprofessores=0,l,j;
    char Conj_Ver_professores[30][30];
    selecionar_turma(&turma);
    verificador_disciplinas(Conj_disciplinas,&Ndisciplinas,Conjunto_cod,numero_disciplinasTotal);
    verificador_professores(Conj_professores,&Nprofessores,numero_professoresTotal,Conj_Ver_professores,Conj_disciplinas,numero_disciplinasTotal,Ndisciplinas,turma,1,Conjunto_cod);
    if(Ndisciplinas!=0 && Nprofessores!=0)
    {
        for(i=0; i<Ndisciplinas; i++)
        {
            for(l=0; l<numero_disciplinasTotal; l++)
            {
                if(Conjunto_cod[i]==Conj_disciplinas[l].codigo_disciplina)
                    posicao=l;

            }
            for(j=0; j<Nprofessores; j++)
            {
                if(turma==1)
                {
                    if(strcmp(Conj_Ver_professores[j],Conj_disciplinas[posicao].nome_professor_t1)==0)
                    {
                        strcpy(Conj_disciplinas[posicao].nome_professor_t1,"Null");
                    }
                }
                else
                {
                    if(strcmp(Conj_Ver_professores[j],Conj_disciplinas[posicao].nome_professor_t2)==0)
                    {
                        strcpy(Conj_disciplinas[posicao].nome_professor_t2,"Null");
                    }
                }
            }
        }
        printf(verde"operacao executada"branco);
    }
    else
    {
        printf(vermelho"operacao invalida"branco);
    }
    enter_sair();
}

void imprimir_professoresDaDisciplina(struct professor *conj_professores,int numero_professoresTotal,struct disciplinas *Conj_disciplinas,int numero_disciplinasTotal)
{
    int cod,flag=0,posicao,i;
    do
    {
        imprimir_disciplinas(Conj_disciplinas,numero_disciplinasTotal,0);
        printf("\n\n\n");
        fflush(stdin);
        printf("\t\t\t\tUtilize 0 para encerrar a funcao \n\n\t\t\t\tdigite o Codigo da disciplina:");
        scanf("%d",&cod);
        if(cod==0)
        {
            flag=1;
        }
        else
        {

            for(i=0; i<numero_disciplinasTotal; i++)
            {
                if(cod==Conj_disciplinas[i].codigo_disciplina)
                {
                    flag=1;
                    posicao=i;
                }
            }
            if(flag==0)
            {
                printf(amarelo"\t\t\t\tcodigo inexistente \n"branco);
            }
            Sleep(500);
            system("cls");
        }
    }
    while(flag==0);
    if(cod!=0)
    {
        printf("\n\t\t\t\t Professores da materia:%s \n\n\n\t\t\t\t|Nome dos Professores    |\n",Conj_disciplinas[posicao].nome);
        if(strcmp(Conj_disciplinas[posicao].nome_professor_t1,"Null")!=0)
        {
            printf("\t\t\t\t|%-20s  |\n",Conj_disciplinas[posicao].nome_professor_t1);
        }

        if(strcmp(Conj_disciplinas[posicao].nome_professor_t2,"Null")!=0)
        {
            printf("\t\t\t\t|%-20s  |\n",Conj_disciplinas[posicao].nome_professor_t2);
        }
        enter_sair();
    }

}

void imprimir_DisciplinasProfessor(struct professor *conj_professores,int numero_professoresTotal,struct disciplinas *conj_disciplinas,int numero_disciplinasTotal)
{
    int i,flag=0;
    char nome[30];

    do
    {
        imprimir_professores(conj_professores,numero_professoresTotal,0);
        printf("\n\n\n");
        fflush(stdin);
        printf("\t\t\t\tUtilize 0 para encerrar a funcao \n\n\t\t\t\tdigite o nome do professor:");
        gets(nome);
        if(strcmp(nome,"0")==0)
        {
            flag=2;
        }
        else
        {
            for(i=0; i<numero_professoresTotal; i++)
            {
                if(strcmp(nome,conj_professores[i].nome)==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf(amarelo"\t\t\t\tnome inexistente \n"branco);
            }

            Sleep(500);
            system("cls");
        }
    }
    while(flag==0);
    if(flag!=2)
    {
        printf("\n\t\t\t\tDisciplinas do Professor:%s\n\n\n\t\t\t\t|Turma |codigo |nome da disciplina   |\n",nome);
        for(i=0; i<numero_disciplinasTotal; i++)
        {
            if(strcmp(nome,conj_disciplinas[i].nome_professor_t1)==0)
            {
                printf("\t\t\t\t|1     |%d   | %-20s|\n",conj_disciplinas[i].codigo_disciplina,conj_disciplinas[i].nome);
            }
            if(strcmp(nome,conj_disciplinas[i].nome_professor_t2)==0)
            {
                printf("\t\t\t\t|2     |%d  | %-20s|\n",conj_disciplinas[i].codigo_disciplina,conj_disciplinas[i].nome);
            }
        }
        enter_sair();
    }

}

void imprimir_professores(struct professor *conj_professores,int numero_professoresTotal,int tipo)
{
    int i=0;
    printf("\n \t\t\t\tLista completa de professores\n\n\n \t\t\t\t|Nomes dos professores    |\n");
    for(i=0; i<numero_professoresTotal; i++)
    {
        printf(" \t\t\t\t|%-20s     | \n",conj_professores[i].nome);
    }
    if(tipo==1)
    enter_sair();
}

void imprimir_alunos(struct alunos *conj_alunos,int numero_alunosTotal,int tipo)
{
    int i=0;
    printf("\n\t\t\t\t  Lista completa de alunos\n\n\n \t\t\t\t|Ra     |  Nome dos alunos     |\n");
    for(i=0; i<numero_alunosTotal; i++)
    {
        printf("\t\t\t\t|%d   | %-20s |\n",conj_alunos[i].ra,conj_alunos[i].nome);
    }
    if(tipo==1)
    enter_sair();

}

void imprimir_alunosDisciplinaTodos(struct disciplinas *Conj_disciplinas, int numero_disciplinasTotal, struct alunos *Conj_alunos,int numero_alunosTotal)
{
    int i,cod,flag=0,posicao,j,posicao2;

    do
    {
        imprimir_disciplinas(Conj_disciplinas,numero_disciplinasTotal,0);
        printf("\n\n\n");
        fflush(stdin);
        printf("\t\t\t\tUtilize 0 para encerrar a funcao \n\n\t\t\t\tdigite o Codigo da disciplina:");
        scanf("%d",&cod);
        for(i=0; i<numero_disciplinasTotal; i++)
        {
            if(cod==Conj_disciplinas[i].codigo_disciplina)
            {
                flag=1;
                posicao=i;
            }
        }
        if(cod==0)
        {
            flag=1;
        }
        if(flag==0)
        {
            printf(amarelo"\t\t\t\tra inexistente \n"branco);
        }
        Sleep(500);
        system("cls");
    }
    while(flag==0);
    if(cod!=0)
    {
        printf("\n\t\t\t\tAlunos vinculados na materia:%s \n\n\n\t\t\t\t|Ra   | nome dos alunos       |\n",Conj_disciplinas[posicao].nome);

        for(i=0; i<Conj_disciplinas[posicao].quantidade_alunos_t1; i++)
        {
            if(Conj_disciplinas[posicao].alunos_t1[i]!=0)
            {
                for(j=0; j<numero_alunosTotal; j++)
                {
                    if(Conj_disciplinas[posicao].alunos_t1[i]==Conj_alunos[j].ra)
                    {
                        posicao2=j;
                    }
                }
                printf("\t\t\t\t|%d |%-20s   |\n",Conj_disciplinas[posicao].alunos_t1[i],Conj_alunos[posicao2].nome);
            }
        }

        for(i=0; i<Conj_disciplinas[posicao].quantidade_alunos_t2; i++)
        {
            if(Conj_disciplinas[posicao].alunos_t2[i]!=0)
            {
                for(j=0; j<numero_alunosTotal; j++)
                {
                    if(Conj_disciplinas[posicao].alunos_t2[i]==Conj_alunos[j].ra)
                    {
                        posicao2=j;
                    }
                }
                printf("\t\t\t\t|%d |%-20s   |\n",Conj_disciplinas[posicao].alunos_t2[i],Conj_alunos[posicao2].nome);
            }
        }
        enter_sair();
    }

}

void imprimir_alunosDisciplina(struct disciplinas *Conj_disciplinas,int numero_disciplinasTotal, struct alunos *Conj_alunos,int numero_alunosTotal)
{
    int turma,i,cod,flag=0,posicao,j,posicao2;
    selecionar_turma(&turma);
    do
    {
        imprimir_disciplinas(Conj_disciplinas,numero_disciplinasTotal,0);
        printf("\n\n\n");
        fflush(stdin);
        printf("\t\t\t\tUtilize 0 para encerrar a funcao \n\n\t\t\t\tdigite o Codigo da disciplina:");
        scanf("%d",&cod);
        for(i=0; i<numero_disciplinasTotal; i++)
        {
            if(cod==Conj_disciplinas[i].codigo_disciplina)
            {
                flag=1;
                posicao=i;
            }
        }
        if(cod==0)
        {
            flag=1;
        }
        if(flag==0)
        {
            printf(amarelo"\t\t\t\tra inexistente \n"branco);
        }
        Sleep(500);
        system("cls");
    }
    while(flag==0);
    if(cod!=0)
    {
        printf("\n\t\t\t\tAlunos vinculados na materia:%s \n\n\n\t\t\t\t|Ra   | nome dos alunos       |\n",Conj_disciplinas[posicao].nome);
        if(turma==1)
        {
            for(i=0; i<Conj_disciplinas[posicao].quantidade_alunos_t1; i++)
            {
                if(Conj_disciplinas[posicao].alunos_t1[i]!=0)
                {
                    for(j=0; j<numero_alunosTotal; j++)
                    {
                        if(Conj_disciplinas[posicao].alunos_t1[i]==Conj_alunos[j].ra)
                        {
                            posicao2=j;
                        }
                    }
                    printf("\t\t\t\t|%d |%-20s   |\n",Conj_disciplinas[posicao].alunos_t1[i],Conj_alunos[posicao2].nome);
                }
            }
        }
        else
        {
            for(i=0; i<Conj_disciplinas[posicao].quantidade_alunos_t2; i++)
            {
                if(Conj_disciplinas[posicao].alunos_t2[i]!=0)
                {
                    for(j=0; j<numero_alunosTotal; j++)
                    {
                        if(Conj_disciplinas[posicao].alunos_t2[i]==Conj_alunos[j].ra)
                        {
                            posicao2=j;
                        }
                    }
                    printf("\t\t\t\t|%d |%-20s   |\n",Conj_disciplinas[posicao].alunos_t2[i],Conj_alunos[posicao2].nome);
                }
            }
        }
        enter_sair();
    }
}

void imprimir_disciplinasAluno(struct alunos *conj_alunos,int numero_alunosTotal,struct disciplinas *Conj_disciplinas,int numero_disciplinasTotal)
{
    int i=0,flag=0,ra,j,quantidade=0,posicao;
    do
    {
        imprimir_alunos(conj_alunos,numero_alunosTotal,0);
        printf("\n\n\n");
        fflush(stdin);
        printf("\t\t\t\tUtilize 0 para encerrar a funcao \n\n\t\t\t\tdigite o Ra:");
        scanf("%d",&ra);
        for(i=0; i<numero_alunosTotal; i++)
        {
            if(ra==conj_alunos[i].ra)
            {
                flag=1;
                posicao=i;
            }
        }
        if(ra==0)
            flag=1;
        if(flag==0)
            printf(amarelo"\t\t\t\tra inexistente \n"branco);
        Sleep(500);
        system("cls");

    }
    while(flag==0);
    if(ra!=0)
    {
        printf("\n\t\t\t\tDisciplinas do Aluno:%s\n\n\n\t\t\t\t|Turma |codigo |nome da disciplina  |\n",conj_alunos[posicao].nome);
        for(i=0; i<numero_disciplinasTotal; i++)
        {
            if(Conj_disciplinas[i].quantidade_alunos_t1>Conj_disciplinas[i].quantidade_alunos_t2)
            {
                quantidade=Conj_disciplinas[i].quantidade_alunos_t1;
            }
            else
            {
                quantidade=Conj_disciplinas[i].quantidade_alunos_t2;
            }
            for(j=0; j<quantidade; j++)
            {
                if(ra==Conj_disciplinas[i].alunos_t1[j])
                {
                    printf("\t\t\t\t|1     |%d   |%-20s|\n",Conj_disciplinas[i].codigo_disciplina,Conj_disciplinas[i].nome);
                }

                if(ra==Conj_disciplinas[i].alunos_t2[j])
                {
                    printf("\t\t\t\t|2     |%d   |%-20s|\n",Conj_disciplinas[i].codigo_disciplina,Conj_disciplinas[i].nome);
                }
            }
        }
        enter_sair();
    }
}

void imprimir_disciplinas(struct disciplinas *Conj_disciplinas,int numero_disciplinasTotal,int tipo)
{
    int i=0;
    printf("\n \t\t\t\t Lista de todas as disciplinas \n\n\n\t\t\t\t|Codigo    | Nome das disciplinas       |\n");
    for(i=0; i<numero_disciplinasTotal; i++)
    {
        printf("\t\t\t\t|%d      |%-20s \t|\n",Conj_disciplinas[i].codigo_disciplina,Conj_disciplinas[i].nome);
    }
    if(tipo==1)
    enter_sair();
}

void Vincular_professsores(struct professor *Conj_professores, struct disciplinas *Conj_disciplinas,int numero_professoresTotal,int numero_disciplinasTotal)
{
    int turma,Ndisciplinas=0,Conjunto_cod[32],i,j,posicao,Nprofessores=0,cont_T=0,contador;
    char Conj_Ver_professores[30][30];
    selecionar_turma(&turma);
    verificador_disciplinas(Conj_disciplinas,&Ndisciplinas,Conjunto_cod,numero_disciplinasTotal);
    verificador_professores(Conj_professores,&Nprofessores,numero_professoresTotal,Conj_Ver_professores,Conj_disciplinas,numero_disciplinasTotal,Ndisciplinas,turma,0,Conjunto_cod);
    if(Nprofessores !=0 && Ndisciplinas !=0)
    {

        for(i=0; i<Ndisciplinas; i++)
        {
            for(j=0; j<numero_disciplinasTotal; j++)
            {
                if(Conjunto_cod[i]==Conj_disciplinas[j].codigo_disciplina)
                {
                    posicao=j;
                }
            }
            if(turma==1)
            {
                strcpy(Conj_disciplinas[i].nome_professor_t1,Conj_Ver_professores[Nprofessores-1]);
            }
            else
            {
                strcpy(Conj_disciplinas[i].nome_professor_t2,Conj_Ver_professores[Nprofessores-1]);
            }
        }
        printf(verde"operacao executada"branco);
    }
    else
    {
        printf(vermelho"operacao invalida"branco);
    }
    enter_sair();
}

int main()
{
    int opcao_menu,Contador_alunos=0,Contador_disciplinas=0,Contador_Professores=0;
    struct disciplinas Conj_disciplinas[32];
    struct professor Conj_Professores[30];
    struct alunos Conj_alunos[200];
    limpar(Conj_disciplinas);
    do
    {
        opcao_menu=menu();
        system("cls");
        switch(opcao_menu)
        {
        case 1:
            cadastro_Professores(Conj_Professores,&Contador_Professores);
            break;
        case 2:
            cadastro_alunos(Conj_alunos,&Contador_alunos);
            break;
        case 3:
            cadastro_Disciplinas(Conj_disciplinas,&Contador_disciplinas);
            break;
        case 4:
            matricular_alunos(Conj_disciplinas,Conj_alunos,Contador_alunos,Contador_disciplinas);
            break;
        case 5:
            desmatricular_alunos(Conj_disciplinas,Conj_alunos,Contador_alunos,Contador_disciplinas);
            break;
        case 6:
            Vincular_professsores(Conj_Professores,Conj_disciplinas,Contador_Professores,Contador_disciplinas);
            break;
        case 7:
            Desvincular_professores(Conj_Professores,Conj_disciplinas,Contador_Professores,Contador_disciplinas);
            break;
        case 8:
            imprimir_professores(Conj_Professores,Contador_Professores,1);
            break;
        case 9:
            imprimir_alunos(Conj_alunos,Contador_alunos,1);
            break;
        case 10:
            imprimir_disciplinas(Conj_disciplinas,Contador_disciplinas,1);
            break;
        case 11:
            imprimir_disciplinasAluno(Conj_alunos,Contador_alunos,Conj_disciplinas,Contador_disciplinas);
            break;
        case 12:
            imprimir_alunosDisciplina(Conj_disciplinas,Contador_disciplinas,Conj_alunos,Contador_alunos);
            break;
        case 13:
            imprimir_alunosDisciplinaTodos(Conj_disciplinas,Contador_disciplinas,Conj_alunos,Contador_alunos);
            break;
        case 14:
            imprimir_DisciplinasProfessor(Conj_Professores,Contador_Professores,Conj_disciplinas,Contador_disciplinas);
            break;
        case 15:
            imprimir_professoresDaDisciplina(Conj_Professores,Contador_Professores,Conj_disciplinas,Contador_disciplinas);
            break;
        }
    }
    while(opcao_menu!=16);
    return 0;
}
