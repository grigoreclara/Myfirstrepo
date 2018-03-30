#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int ninputs;
int verif(char,int );
int dfa[10][10];
char c[10], string[10];
char A; int X,Y;
int verif(char b,int d)
{
     int j;
     for(j=0; j<ninputs; j++)
     if(b==c[j])
     return(dfa[j][d]);
     return -1;
}


int main()
{
     int nstates, nfinals;
     int f[10];
     int i,j,s=0,final=0;
     printf("Numarul de stari pe care il contine automatul \n");
     scanf("%d",&nstates);
     printf("Numarul de litere din alfabet \n");
     scanf("%d",&ninputs);
     printf("\nalfabetul\t");

     for(i=0; i<ninputs; i++)
     {
           printf("\n\n %d litera\t", i+1);
           printf("%c",c[i]=getch());
     }

     printf("\nnumarul de stari finale\t");
     scanf("%d",&nfinals);


     for(i=0;i<nfinals;i++)
     {
          printf("\n\nStarile finale %d : q",i+1);
          scanf("%d",&f[i]);
     }

     printf("-----------------------------------------------------------------------");
     printf("\n\nTastati tabelul sub forma(de unde,cum,unde)");
/* while(!fin.eof())   {
        fin >> X >> A >> Y;
        dfa[X][A] = Y;
    }
    fin.close();*/
     for(i=0; i<ninputs; i++)
     {
          for(j=0; j<nstates; j++)
          {
               printf("\n(q%d , %c ) = q",j,c[i]);
               scanf("%d",&dfa[i][j]);
          }
     }
      for(i=0; i<nstates; i++)
        for(j=1; j<=nfinals; j++)
            if(dfa[i][j] < 0 ||dfa[i][j] >=nstates ) {
                printf("Automatul nu este bine definit\n");
                return -1;
            }

     do
     {
          i=0;
          final=0;
          s=0;
          printf("\n\nTastati cuvantul: ");
          scanf("%s",string);
        for(j=0;j<nfinals;j++)
        if(final==f[j]&&string[0]=='*')
       {

        printf("Cuvantul acceptat"); break;}
          while(string[i]!='\0')
          if((s=verif(string[i++],s))<0)
          break;
          for(i=0 ;i<nfinals ;i++)
          if(f[i] ==s )
          final=1;
          if(final==1)
          printf("\n cuvant acceptat");
          else
          printf("cuvant neacceptat");
          getch();

          printf("\nContinuati cu alte cuvinte.?  \n(d/n) ");
     }
     while(getch()=='d');

     getch();

     return 0;
}
