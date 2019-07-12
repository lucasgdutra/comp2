#include <stdio.h>
#include <stdlib.h>
#include "externo.h"

int main(){
    FILE *AL, *Aux;
    char varre[101];
    char andar[35], lixo;
    int N,i,opc,a;
    float q,x,y,z,S;
    AL=fopen("Work.txt","w+");
    if(AL==NULL){
        printf("Problema na abertura do arquivo.");
        return 1;
    }
    N=0;
    fprintf(AL," %d\n",N);

    opc = 0;
    while(opc!=6){

        rewind(AL);
        printf("____Menu____ \n");
        printf("1)Inserir nome do aluno e suas notas (três). \n");
        printf("2)Exibir o nome e a nota do aluno que possui a maior nota. \n");
        printf("3)Exibir alunos e médias. \n");
        printf("4)Exibir e gravar em um arquivo texto os alunos aprovados juntamente com o valor da sua média. \n");
        printf("5)Exibir e gravar em um arquivo texto os alunos reprovados juntamente com o valor da sua média. \n");
        printf("6)Sair. \n");
        printf("Opção desejada -> ");
        scanf("%d", &opc);
        system("cls");
        //Sair do Programa
        if(opc==6){
            printf("Programa encerrado. \n");
            break;
        }
        if(opc<1 || opc>6){
            printf("Opção inválida. \n0");
            continue;
        }
        if(opc==1){
            fseek(AL,0,SEEK_END);
            printf("Nome do aluno: ");
            clean();
            fgets(andar,34,stdin);
            printf("Nota 1: ");
            scanf(" %f", &x);
            printf("Nota 2: ");
            scanf(" %f", &y);
            printf("Nota 3: ");
            scanf(" %f", &z);
            fprintf(AL,"%s- %f' %f' %f'\n",andar,x,y,z);
            rewind(AL);
            Aux=fopen("Rascunho.txt","w+");
            if(Aux==NULL){
                printf("Erro abertura de arquivo");
                return 1;
            }
            fscanf(AL,"%d",&N);
            N++;
            fprintf(Aux,"%d",N);
            for(i=0;i<N;i++){
                fscanf(AL,"%[^-]%c", &andar,&lixo);
                fscanf(AL,"%f' %f' %f'",&x,&y,&z);
                fprintf(Aux,"%s- %f' %f' %f'\n", andar,x,y,z);
            }
            fclose(AL);
            AL=fopen("Work.txt","w+");
            if(AL==NULL){
                printf("Erro abertura de arquivo");
                return 1;
            }
            rewind(Aux);
            fscanf(Aux,"%d", &N);
            fprintf(AL,"%d\n",N);
            for(i=0;i<N;i++){
                fscanf(Aux,"%[^-]%c", &andar,&lixo);

                fscanf(Aux,"%f' %f' %f'",&x,&y,&z);
                printf("%s- %f' %f' %f'\n", andar,x,y,z);
                fprintf(AL,"%s- %f' %f' %f'\n", andar,x,y,z);
            }
            fclose(Aux);
            system("pause");
            system("cls");
            continue;
        }
        if(opc==2){
            q=0.01;
            a=0;
            rewind(AL);
            fscanf(AL,"%d\n", &N);
            for(i=0;i<N;i++){
                fscanf(AL,"%[^-]%c", &andar,&lixo);
                fscanf(AL,"%f' %f' %f'", &x,&y,&z);
                S=x+y+z;
                if(q<S){
                    q=S;
                    a++;
                }
            }
            rewind(AL);
            fscanf(AL,"%d",&N);
            for(i=0;i<a;i++){
                fscanf(AL,"%[^-]%c", &andar, &lixo);
                fscanf(AL,"%f' %f' %f'", &x,&y,&z);
            }
            if(a>=1){
                printf("Aluno maior nota.\nNome: %s \nNota: %f \n", andar,x+y+z);
            }
            else{
                printf("Não foi encontrado nenhum aluno. \n");
            }
            system("pause");
            system("cls");
            continue;
        }
        if(opc==3){
            fscanf(AL," %d", &N);
            for(i=0;i<N;i++){
                fscanf(AL,"%[^-]%c", &andar, &lixo);
                fscanf(AL,"%f' %f' %f'", &x,&y,&z);
                printf("Nome: %s - Média das Notas: %f \n", andar,(x+y+z)/3);
            }
            system("pause");
            system("cls");
        }
        if(opc==4){
            a=0;
            Aux=fopen("Aprovados.txt","w+");
            if(AL==NULL){
                printf("Erro abertura de arquivo");
                return 1;
            }
            rewind(AL);
            fscanf(AL,"%d\n", &N);
            fprintf(Aux,"Alunos aprovados \n",0);
            for(i=0;i<N;i++){
                fscanf(AL,"%[^-]%c", &andar,&lixo);
                fscanf(AL,"%f' %f' %f'",&x,&y,&z);
                if((int)x+y+z>=6){
                    printf("Alunos Aprovados: \n Nome: %s - Média: %f",andar,(x+y+z)/3 );
                    fprintf(Aux,"Nome: %s - Média: %f'",andar,(x+y+z)/3);
                }
            }
            fclose(Aux);
            printf("\n\n");
            printf("Arquivo de texto \"Aprovados\" criado com sucesso. \n\n");
            system("pause");
            system("cls");
        }
        if(opc==5){
            a=0;
            Aux=fopen("Reprovados.txt","w+");
            if(AL==NULL){
                printf("Erro abertura de arquivo");
                return 1;
            }
            rewind(AL);
            fscanf(AL,"%d\n", &N);
            fprintf(Aux,"Alunos reprovados \n",0);
            for(i=0;i<N;i++){
                fscanf(AL,"%[^-]%c", &andar,&lixo);
                fscanf(AL,"%f' %f' %f'",&x,&y,&z);
                if((int)x+y+z<6){
                    printf("Alunos reprovados: \n Nome: %s - Média: %f",andar,(x+y+z)/3 );
                    fprintf(Aux,"Nome: %s - Média: %f'",andar,(x+y+z)/3);
                }
            }
            fclose(Aux);
            printf("\n\n");
            printf("Arquivo de texto \"Reprovados\" criado com sucesso. \n\n");
            system("pause");
            system("cls");
        }
    }//fechar o while
    fclose(AL);
    return 0;
}


