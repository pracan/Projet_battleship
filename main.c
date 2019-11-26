#include <stdio.h>
#include <stdlib.h>

#define EAU 0;
#define TIR_DANS_L_EAU 1;
#define BATEAU 2;
#define BATEAU_TOUCHE 3;

typedef int ** Grille;

void creerGrille (int L, int H, Grille grille) {
	int o,a;

	for (int i=1; i<L;i++){
		for (int j=0;j<H;j++) {
			grille[i][j]=0;
		}
	}
}

void recupGrille(int L,int H,Grille grille){
  FILE *fp;
  char buff[255];
  int a=1,b;

  creerGrille(L,H,grille);
  fp = fopen("batteau.txt", "r");
  while ( fgets(buff, 255, (FILE*)fp) != NULL){
    b=0;
    while ((buff[b]!=10)&&(buff[b]!=0)&&(b<255)){
      printf("%d: %d\n", b, buff[b]);
      b+=1;
    };
    printf("%d: %s\n", a, buff);
    if (buff[b]==0){printf("\n");}
    a+=1;
  }
  printf("\n");

  fclose(fp);
}

void afficherGrille(int L, int H, int **grille){
	int a=65;
  printf("  ");
  for (int i=0; i<L;i++) {
    printf("%d ",i+1);
  }
  printf("\n");
	for (int i=0; i<L;i++) {
		printf("%c ", a);
    a+=1;
    for (int j=0; j<H;j++){
      switch (grille[i][j]){
        case 0:
          printf(". ");
          break;
        case 1:
          printf("X");
          break;
        case 2:
          printf("%c",254);
          break;
        case 3:
          printf("%c",157);
          break;
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
  printf("\n");

	grille = malloc(L*sizeof(int*));
	for (int i=0;i<=H;i++){
		grille[i]=malloc(H*sizeof(int));
	}

	recupGrille(L,H,grille);
	afficherGrille(L,H,grille);
  
	return 0;
}