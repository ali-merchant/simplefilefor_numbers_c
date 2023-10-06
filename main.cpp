#include <string.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>

void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);


}


int AddData();
int ListData();
int EditData();
int DelData();
int myMenu();




int AddData()
{
    char strName[20];
    char strPhone[12];
    FILE* fptr;

    printf("Enter Name :");
    scanf("%s", strName);
    strName[0]=toupper(strName[0]);


    printf("\nEnter Phone :");
    scanf("%s", strPhone);

    fptr = fopen("test.txt", "a");

    fprintf(fptr, "%s,%s\n", strName, strPhone);
    fclose(fptr);

    return 0;


}

int ListData()
{

    char strName[20], strPhone[20],waste[50];
    FILE* fptr;
    int i = 0; // total lines
    system("cls");

    // LINES

    fptr = fopen("test.txt", "r");
    while(!feof(fptr)){
        fscanf(fptr,"%s\n",waste);
        i++;
    }

    int j = 0;
    fclose(fptr);

    fptr = fopen("test.txt","r");
    char strLine[i][50];
    for(j=0;j<i;j++){
        fscanf(fptr, "%s\n", strLine[j]);
       // printf("%s\n", strLine[j]);
    }
    fclose(fptr);


    int k =0 ;j=0;
    char temp[50];
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            if(strcmp(strLine[j],strLine[k])<0){
                strcpy(temp,strLine[j]);
                strcpy(strLine[j],strLine[k]);
                strcpy(strLine[k],temp);
            }
        }
    }
    j=0;
    int b=0;
    printf("+");
    for(b=0;b<=30;b++)
    {
        printf("-");
    }
    printf("+\n");

    printf("| %s\n", strLine[j]);
    printf("| %s\n", strLine[j+1]);
    printf("| %s\n", strLine[j+2]);
    printf("| %s\n", strLine[j+3]);
    printf("| %s\n", strLine[j+4]);


    printf("+");
    for(b=0;b<=30;b++)
    {
        printf("-");
    }
    printf("+\n");

    for(b=1;b<=5;b++){GoToXY(32,b);printf("|");}
    printf("\n\npress esc  to exit");
    char ch,ch2;
    while(1){
        if (_kbhit()){
            ch2=_getch();
            if (ch2 == 224)
            {
                ch=_getch();
            }
            if(ch == 80 || ch2 ==80){
                system("cls");
                if(j<=i-6){j++;}
                printf("+");
                for(b=0;b<=30;b++)
                {
                    printf("-");
                }
                printf("+\n");

                printf("| %s\n",strLine[j]);
                printf("| %s\n",strLine[j+1]);
                printf("| %s\n",strLine[j+2]);
                printf("| %s\n",strLine[j+3]);
                printf("| %s\n",strLine[j+4]);

                printf("+");
                for(b=0;b<=30;b++)
                {
                    printf("-");
                }
                printf("+\n");

                for(b=1;b<=5;b++){GoToXY(32,b);printf("|");}

            }
            if(ch==72 || ch2 == 72){
                system("cls");
                if(j>=1){j--;}
                printf("+");
                for(b=0;b<=30;b++)
                {
                    printf("-");
                }
                printf("+\n");

                printf("| %s\n",strLine[j]);
                printf("| %s\n",strLine[j+1]);
                printf("| %s\n",strLine[j+2]);
                printf("| %s\n",strLine[j+3]);
                printf("| %s\n",strLine[j+4]);

                printf("+");
                for(b=0;b<=30;b++)
                {
                    printf("-");
                }
                printf("+\n");

                for(b=1;b<=5;b++){GoToXY(32,b);printf("|");}

            }
            printf("\n\npress esc to exit     Use Arrow keys to scroll up and down");
            if(ch==27 || ch2 == 27){
                return 0;
            }
        }
    }

    printf("Press any key to return :");
    i=_getch();
    return 0;

}

int EditData(){

    system("cls");
    FILE *orig = fopen("test.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");
    printf("enter name to change number of : ");
    //int line=0;
    char toedit[50],strName[50],strNum[50],newNum[50];
    scanf("%s",toedit);

    toedit[0]=toupper(toedit[0]);

    while(!feof(orig)){
        fscanf(orig, "%[^,],%[^\n]\n",strName,strNum);
        if(strcmp(strName,toedit) == 0){
            printf("enter new number : ");
            scanf("%s",newNum);
            fprintf(temp_file, "%s,%s\n", strName, newNum);
        }
        else{
            fprintf(temp_file, "%s,%s\n", strName, strNum);
        }

    }

    fclose(temp_file);
    fclose(orig);

    remove("test.txt");
    rename("temp.txt","test.txt");

    printf("enter key to continue");
    getch();
    return 0;



}

int DelData(){
    system("cls");
    FILE *orig = fopen("test.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");
    printf("enter name to delete: ");

    //int line=0;
    char todelete[50],strName[50],strNum[50];
    scanf("%s",todelete);
    todelete[0]=toupper(todelete[0]);


    while(!feof(orig)){
        fscanf(orig, "%[^,],%[^\n]\n",strName,strNum);
        if(strcmp(strName,todelete) != 0){
            fprintf(temp_file, "%s,%s\n", strName, strNum);
        }

    }

    fclose(temp_file);
    fclose(orig);

    remove("test.txt");
    rename("temp.txt","test.txt");

    return 0;

}

int main()
{
    int i;
    i = myMenu();

}

int myMenu()
{
    int nCh = 0;

    while (1)
    {
        system("cls");
        printf("1 - Add Data in File \n");
        printf("2 - List Data \n");
        printf("3 - Edit Data in File \n");
        printf("4 - Delete Data in File \n");
        printf("5 - Exit ");
        scanf("%d", &nCh);
        switch (nCh)
        {
        case 1:

            AddData();
            system("cls");

            break;
        case 2:
            ListData();
            break;

        case 3:
                EditData();
            break;
        case 4:
            DelData();
            break;
        case 5:
            return 0;
        default:
            printf("Please select from 1 to 5 Option ..");
            getch();
            break;


        }
    }
}
