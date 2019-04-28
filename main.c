#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char question[100];
    char file[200];
    char reponse1[20];
    char reponse2[20];
    char reponse3[20];
    int a=0;
    int i1=0;
    int i2=0;
    int i3=0;
    int x;
    int correcte=0;
    char T[5][20]={"quiz.txt","quiz1.txt","quiz2.txt"};
    srand(time(NULL));
    int rep;
    x= rand()%(3);
    printf("%d \n",x);
    printf("%s \n",T[x]);
    char fich[20];
    strcpy(fich,T[x]);
    printf("%s \n",fich);
FILE* quiz = NULL ;
quiz = fopen(fich,"r");
            fgets(file,300,quiz);
            printf("fichier %s",file);
while(file[a-1]!='?')
{
    question[a]=file[a];
    a++;
}
question[a]='\0';
printf("question :%s \n",question);
int b=a+1;
while(file[b]!=' ')
{
    if (file[b]!='*')
    {
    reponse1[i1]=file[b];
    b++;
    i1++;
    }
    if(file[b]=='*')
    {
        correcte=1;
        b++;
    }
}
reponse1[i1]='\0';
printf("reponse1: %s \n",reponse1);
int c=b+1;
while(file[c]!=' ')
{
    if(file[b]!='*')
    {
    reponse2[i2]=file[c];
    c++;
    i2++;
    }
    if(file[c]=='*')
    {
        correcte=2;
        c++;
    }
}
reponse2[i2]='\0';
printf("reponse2: %s \n",reponse2);
int d=c+1;
while(file[d]!=' ')
{
    if(file[d]!='*')
    {
    reponse3[i3]=file[d];
    d++;
    i3++;
    }
    if(file[d]=='*')
    {
        correcte=3;
        d++;
    }
}
reponse3[i3]='\0';
printf("reponse3: %s \n",reponse3);
printf("rep correcte: %d \n",correcte);
do{
printf("saisir une reponses \n");
scanf("%d",&rep);
if(rep!=correcte)
{
    printf("reponse fausse \n");
}
else
{
    printf("reponse correcte \n");
}
}while(rep!=correcte);
    return 0;
}
