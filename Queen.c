#include <conio.h>
#include <stdio.h>
#include <omp.h>
#define N 16
int col[N];
int diagP[N];
int diagN[N];   
int solution=0;

void afficher_conf( int *col )
{   
    int i, j, k;
    for (i=0;  i<N; i++)
		printf("\t   %c", i+'a');
   	printf("\n");
	for (i=0;  i<N; i++)
		printf("\t-------");
   	printf("\n");
       for(i=1; i<=N; i++)  {
		printf("    %d", i);
		for (j=0; j<N; j++) {
			if ( j==col[i-1] ) printf("\t  R");
             else printf("\t   ");
		}
        printf("\n");
		for (k=0;  k<N; k++)
			printf("\t-------");
   		printf("\n");
}
printf("\n\n");
}

void placer(int nDames) 
{
    if(nDames==N)
    {     // afficher_conf(col); // pour afficher les solutions 
                 ++solution;
                 }
    for(int i=0; i<N; ++i)
    {
    for(int j=0; j<nDames; ++j)
        if(col[j]==i || diagP[j]==nDames+1+i || diagN[j]==nDames+1-i) 
            goto next;
    col[nDames]=i;
    diagP[nDames]=nDames+1+i;
    diagN[nDames]=nDames+1-i;
    placer(nDames+1); 
    next: continue;
    }
    return;
}
         
    
int main(int argc, char *argv[])
{        
        double t=0;
        double tInitial=0, tFinal=0;
        tInitial=omp_get_wtime();   
        placer(0);
        printf("\nNombre de solutions: %d\n",solution);
        tFinal=omp_get_wtime();
        t=(tFinal-tInitial);
            printf("temps = %f s\n", t);
        return 0;
}