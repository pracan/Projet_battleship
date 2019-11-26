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
  int a=0,b;

  creerGrille(L,H,grille);
  fp = fopen("batteau.txt", "r");
  printf("Le fichier chargé contient les lignes\n\n");
  while (( fgets(buff, 255, (FILE*)fp) != NULL)&&(a<L)){
    b=0;
    while ((buff[b]!=10)&&(buff[b]!=0)&&(b<255)&&(b<H)){
      if ((buff[b]!=46)&&(buff[b]!=32)){
          grille[a][b]=2;
      }
      b+=1;
    };
    printf("%s", buff);
    if (buff[b]==0){printf("\n");}
    a+=1;
  }
  printf("\n");

  fclose(fp);
}

void afficherGrille(int L, int H, Grille grille){
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
          printf("%c ",35);
          break;
        case 3:
          printf("%c ",36);
          break;
      }
		}
	printf("\n");
	}
}

int comptecasebatteaux(int L, int H, Grille grille){
  int a=0,b=0;
	for (int i=0; i<L;i++) {
		for (int j=0; j<H;j++){
      if (grille[i][j]==3){
        if (j<(H-1)){if (grille[i][j+1]==3){
          if (i>0){if (grille[i-1][j]==3){b=-1;}}
          if (i<L-1){if (grille[i+1][j]==3){b=-1;}}
        }}
        if (j>0){if (grille[i][j-1]==3){
          if (i>0){if (grille[i-1][j]==3){b=-1;}}
          if (i<L-1){if (grille[i+1][j]==3){b=-1;}}
        }}
        if (i<(L-1)){if (grille[i+1][j]==3){
          if (j>0){if (grille[i][j-1]==3){b=-1;}}
          if (j<L-1){if (grille[i][j+1]==3){b=-1;}}
        }}
        if (i>0){if (grille[i-1][j]==3){
          if (j>0){if (grille[i][j-1]==3){b=-1;}}
          if (i<L-1){if (grille[i][j+1]==3){b=-1;}}
        }}
        if (b==-1){
          break;
          break;
        } else {
          a+=1;
        }
      }
		}
	}
  if (b==-1){
    return b;
  } else {
    return a;
  }
}

int main(int argc, char **argv) {
	int L,H;
	Grille grille;

	printf("Longueur ?\n");
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