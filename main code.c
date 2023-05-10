#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int menu();
int member_management();
int show_members();
int add_member();
int update_member();
int search_member();
int computer_management();
int show_computer();
int add_computer();
int search_computer();
int update_computer();
int login_details();
int charges();
int main()
{
    char password[6]="77338",pass[6];
    int k,l=0;
    char user[20],username[20]="devesh",decision;

    while(1)
    {
        printf("\n\n                     =======log in==========\n\n\n");
        printf("                       Enter username: ");
        gets(user);
        fflush(stdin);
        printf("                       Enter 5 digit password: ");
        for(k=0;k<=4;k++)
        {
            pass[k]=getch();
            putch('*');
            fflush(stdin);

        }
        for(k=0;k<=4;k++)
        {
            if(pass[k]==password[k])
                l++;

        }

        if(strcmp(user,username)==0  && l==5)
        {
            printf("\n\n\n                         login successful\n\n");
            fflush(stdin);
            printf("                     presss any key to continue");
            getch();
            system("cls");
            break;

        }
        else
        {
            printf("\n\n\n                      incorrect password or username\n                      presss any key to enter again ");
            fflush(stdin);
            getch();
            system("cls");
        }
    }
    fflush(stdin);
    menu();
}
int menu()
{
    printf("\n\n\n\n                     MENU\n\n");
    printf("                     1.member management\n");
    printf("                     2.computer management\n");
    printf("                     3.check login details\n");
    printf("                     4.charges\n");
    printf("                     5.exit\n\n\n");
    printf("                     select your entry: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:
        {
            member_management();
        }
        case 2:
        {
            computer_management();
        }
        case 3:
        {
            login_details();
        }
        case 4:
            charges();
        case 5:
            exit(0);
    }
}
int member_management()
{
    printf("                     MENU/MEMBER MANAGEMENT\n\n");
    printf("                     1.show members\n");
    printf("                     2.add member\n");
    printf("                     3.search member by username\n");
    printf("                     4.update member information\n");
    printf("                     5.previous page\n");
    int choice2;
    printf("\n\n\nenter your choice:  ");
    scanf("%d",&choice2);
    system("cls");

    switch(choice2)
    {
        case 1:
        {
            show_members();
        }
        case 2:
        {
            add_member();
        }
        case 3:
        {
            search_member();
        }
        case 4:
        {
            update_member();
        }
        case 5:
        {
            menu();
        }
    }
}
int show_members()
{

    FILE *fp;

    fp=fopen("member list.txt","r+");
    fflush(stdin);
    char whole[2500];
    printf("\n\nuser name  mobile no. address         email id                  date of joining\n\n");
    while(fgets(whole,2499,fp)!=NULL)
        printf("%s",whole);
    getch();
    system("cls");
    fflush(stdin);
    fflush(fp);
    member_management();
}
int add_member()
{

    FILE *fp;
    fp=fopen("member list.txt","r+");
    fseek(fp,0,SEEK_END);
    char newname[11],newmob[15],newadd[15],newema[25];
    char nd[3],nm[3],ny[3];
    printf("enter name:  ");
    fflush(stdin);
    gets(newname);
    fprintf(fp,"\n%-10s",newname);
    printf("\nenter mobile no.:  ");
    gets(newmob);
    fprintf(fp," %-10s",newmob);
    printf("\nenter address:  ");
    gets(newadd);
    fprintf(fp," %-15s",newadd);
    printf("\nenter email id:  ");
    gets(newema);
    fprintf(fp," %-25s",newema);
    printf("\nenter date of joining: press enter after adding date,month & year \n");
    scanf("%s",nd);
    scanf("%s",nm);
    scanf("%s",ny);
    fprintf(fp," %s/%s/%s",nd,nm,ny);
    fflush(stdin);
    fflush(fp);
    printf("\npress any key to continue");
    getch();


    system("cls");
    fflush(stdin);
    member_management();
}
int search_member()
{
    struct date
    {
        int d,m,y;
    };
    struct member
    {
        char name[10];char mobile[15];char address[15];char email[25];struct date join_date;
    }m[15];
    FILE *fp;

    fp=fopen("member list.txt","r+");
    int i;

    for(i=0;i<=14;i++)
    {

        fscanf(fp,"%s %s %s %s %d%*c%d%*c%d",&m[i].name,&m[i].mobile,&m[i].address,&m[i].email,&m[i].join_date.d,&m[i].join_date.m,&m[i].join_date.y);
    }
    char finuse[10];
    printf("enter user name:  ");
    fflush(stdin);
    gets(finuse);

    for(i=0;i<=14;i++)
    {
        if(strcmp(finuse,m[i].name)==0)
        {
            printf("\n\nuser name  mobile no. address         email id                  date of joining\n");
            printf("%-10s %-10s %-15s %-25s %d/%d/%d\n",m[i].name,m[i].mobile,m[i].address,m[i].email,m[i].join_date.d,m[i].join_date.m,m[i].join_date.y);
            fflush(stdin);
            fflush(fp);
            getch();
            system("cls");
            member_management();
        }
        else
            continue;
    }
    printf("\nthis name is not present ");
    fflush(stdin);
    fflush(fp);
    getch();
    system("cls");
    fflush(stdin);
    member_management();

}
int update_member()
{
    struct date
    {
        int d,m,y;
    };
    struct member
    {
        char name[10];char mobile[15];char address[15];char email[25];struct date join_date;
    }m[15];
    FILE *fp;

    fp=fopen("member list.txt","r+");
    int i;
    fflush(stdin);
    char updmob[15],updadd[15],updema[25],updnam[10];
    printf("enter username:  ");

    gets(updnam);
    printf("\nenter new mobile no.:  ");
    gets(updmob);
    printf("\nenter new address:  ");
    gets(updadd);
    printf("\nenter new email:  ");
    gets(updema);
    for(i=0;i<=14;i++)
    {
        rewind(fp);
        fseek(fp,i*74,SEEK_SET);
        fscanf(fp,"%s %s %s %s %d%*c%d%*c%d",&m[i].name,&m[i].mobile,&m[i].address,&m[i].email,&m[i].join_date.d,&m[i].join_date.m,&m[i].join_date.y);
        if(strcmp(updnam,m[i].name)==0)
        {
            fseek(fp,-72,SEEK_CUR);
            fprintf(fp,"%-10s %-10s %-15s %-25s",m[i].name,updmob,updadd,updema);
            fflush(stdin);

            printf("\npress any key to continue\n");
            getch();
            system("cls");
            fflush(fp);
            member_management();
        }
        else
            continue;
    }

    printf("\nthis name is not present");
    fflush(stdin);
    printf("\npress any key to continue\n");
    getch();
    system("cls");
    fflush(stdin);
    fflush(fp);
    member_management();

}
int computer_management()
{
    int choice3;
    fflush(stdin);
    printf("                       MNEU/COMPUTER MANAGEMENT\n\n");
    printf("                       1.show computer list\n");
    printf("                       2.add computer\n");
    printf("                       3.search computer\n");
    printf("                       4.update computer\n");
    printf("                       5.previous page\n\n\n");
    printf("                       enter your choice:  ");
    scanf("%d",&choice3);
    system("cls");
    fflush(stdin);
    switch(choice3)
    {
        case 1:
        {
            show_computer();
        }
        case 2:
        {
            add_computer();
        }
        case 3:
        {
            search_computer();
        }
        case 4:
        {
            update_computer();
        }
        case 5:
        {
            menu();
        }
    }

}
int show_computer()
{
    FILE *pf;
    pf=fopen("computer list.txt","r+");
    char full[2500];
    printf("model no.  disk_space ram  code\n");
    while(fgets(full,2499,pf)!=NULL)
    {
        printf("%s",full);
    }
    printf("\n\npress any key to continue");
    getch();
    fflush(stdin);
    fflush(pf);
    system("cls");
    computer_management();

}
int add_computer()
{

    FILE *pf;
    pf=fopen("computer list.txt","r+");

    char newmodel[10],newhard[10],newram[5];
    int newcode;
    printf("enter model no.:  ");
    gets(newmodel);
    printf("\nenter hard disk space:  ");
    gets(newhard);
    printf("\nenter ram:  ");
    gets(newram);
    fflush(stdin);
    printf("\nenter unique code: ");
    scanf("%d",&newcode);
    fflush(stdin);
    fseek(pf,0,SEEK_END);
    fprintf(pf,"\n%-10s %-10s %-4s %-2d",newmodel,newhard,newram,newcode);

    printf("\npress any key to continue: ");
    getch();
    fflush(stdin);
    fflush(pf);
    system("cls");
    computer_management();
}
int search_computer()
{
   FILE *pf;
    pf=fopen("computer list.txt","r+");
    struct computer
    {
        char name[10];char disk_space[10];char ram[5];int code;
    }c[15];
    int unicode,i=0;
    printf("write the compute unique code between 10 & 99:  ");
    scanf("%d",&unicode);
    for(i=0;i<=14;i++)
    {
        fscanf(pf,"%s %s %s %d",c[i].name,c[i].disk_space,c[i].ram,&c[i].code);
    }
    for(i=0;i<=14;i++)
    {
        if(unicode==c[i].code)
        {
            printf("\n\nmodel no.  disk_space ram  code\n");
            printf("%-10s %-10s %-4s %-2d",c[i].name,c[i].disk_space,c[i].ram,c[i].code);
            getch();
            system("cls");
            computer_management();
        }
        else
        {
            continue;
        }
    }
    printf("this computer is not in the system\n\n");
    printf("press any key to continue:   ");
    fflush(stdin);
    getch();
    fflush(stdin);
    fflush(pf);
    system("cls");
    computer_management();
}
int update_computer()
{
    FILE *pf;
    pf=fopen("computer list.txt","r+");
    struct computer
    {
        char name[10];char disk_space[10];char ram[5];int code;
    }c[15];
    int upcode,i;
    char uphard[10],upram[5];
    printf("enter the unique code of computer you want to change the details:  ");
    scanf("%d",&upcode);

    fflush(stdin);
    printf("\nenter hard disk space:  ");
    gets(uphard);
    printf("\nenter ram:  ");
    gets(upram);
    for(i=0;i<=14;i++)
    {
        rewind(pf);
        fseek(pf,i*31,SEEK_SET);
        fscanf(pf,"%s %s %s %d",&c[i].name,&c[i].disk_space,&c[i].ram,&c[i].code);
        if(upcode==c[i].code)
        {
            fseek(pf,-29,SEEK_CUR);
            fprintf(pf,"%-10s %-10s %-4s",c[i].name,uphard,upram);
            fflush(stdin);

            printf("\npress any key to continue\n");
            getch();
            system("cls");
            fflush(pf);
            computer_management();
        }
        else
            continue;
    }

    printf("\nthis name is not present");
    fflush(stdin);
    printf("\npress any key to continue\n");
    getch();
    system("cls");
    fflush(stdin);
    fflush(pf);
    computer_management();

}
int login_details()
{
    FILE *fd;
    fd=fopen("logged in.txt","r+");
    char log[2500];
    printf("username   date     time_of_usage\n");
    while(fgets(log,2499,fd)!=NULL)
    {
        printf("%s",log);
    }
    fflush(fd);
    fflush(stdin);
    fclose(fd);
    getch();
    system("cls");
    fflush(stdin);
    menu();
}
int charges()
{
    FILE *fg;
    fg=fopen("charges.txt","r+");
    char chafull[2500];
    printf("username   date     usage(in min.) charge\n");
    while(fgets(chafull,2499,fg)!=NULL)
    {
        printf("%s",chafull);
    }
    fflush(stdin);
    fflush(fg);
    fclose(fg);
    getch();
    system("cls");
    menu();
}
