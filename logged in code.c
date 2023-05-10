#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int main()
{
    FILE *fp,*pf;
    fp=fopen("logged in.txt","r+");
    pf=fopen("charges.txt","r+");
    char name[10];
    int d,m,y,time;
    printf("\n\n\n\n\n                                 enter name:  ");
    gets(name);
    printf("                                 \nenter date in dd/mm/yy format:  ");
    scanf("%d%*c%d%*c%d",&d,&m,&y);
    printf("                                 \nfor how many minutes you want to use it: ");
    fflush(stdin);
    scanf("%d",&time);
    fflush(stdin);
    fseek(fp,0,SEEK_END);
    fseek(pf,0,SEEK_END);
    fprintf(fp,"\n%-10s %-2d/%-2d/%-2d %-3d",name,d,m,y,time);
    fprintf(pf,"\n%-10s %-2d/%-2d/%-2d    %-5d       %-5d",name,d,m,y,time,time/2);
    
    fclose(fp);
    fclose(pf);
    
}