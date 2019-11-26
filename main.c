#include <stdio.h>
#include <stdlib.h>

#define VIDE 0
#define PLEINE 1





void creerGrille (int L, int H, int **grille) {
	int o;
  int a;

	for (int i=1; i<=L-1;i++){
		for (int j=0;j<=H-1;j++) {
			grille[i][j]=0;
		}
	}

}

void afficherGrille(int L, int H, int **grille){
	
  for (int i=0; i<L;i++) {
    printf("%d ",i+1);
  }
  printf("\n");

	for (int i=1; i<=L-1;i++) {
		for (int j=0; j<=H-1;j++){
			if (grille[i][j]==0) {
				printf(". ");
			}
			else {
				printf("X");
			}
		}
	printf("\n");
	}
}

int main(int argc, char **argv) {
	int L,H;
	int **grille;
	
	printf(" Longueur ?\n");
	scanf("%d",&L);
	printf("Hauteur ?\n");
	scanf("%d",&H);

	grille = malloc(L*sizeof(int*));
	for (int i=0;i<=H;i++){
		grille[i]=malloc(H*sizeof(int));
	}

	creerGrille(L,H,grille);
	afficherGrille(L,H,grille);
  
	return 0;
}