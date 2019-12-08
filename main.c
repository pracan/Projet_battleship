#include <stdio.h>
#include <stdlib.h>

#define EAU 0;
#define TIR_DANS_L_EAU 1;
#define BATEAU 2;
#define BATEAU_TOUCHE 3;

typedef int ** Grille;
typedef int ** RangeBateau;

void vide_buffer() {
	int ch;
	do {
		ch = getchar();
	} while (ch != '\n'&& ch != EOF);
}

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
  printf("Le fichier chargé contient les lignes :\n\n");
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
  printf("\n\n");

  fclose(fp);
}

void afficherGrille(int L, int H, Grille grille){
	int a=65;
  printf(" ");
  for (int i=0;i<H;i++) {
    printf("%3d",i+1);
  }
  printf("\n");
	for (int i=0; i<L;i++) {
		printf("%c", a);
    a+=1;
    if (a==91){a+=6;};
    for (int j=0; j<H;j++){
      switch (grille[i][j]){
        case 0:
          printf("%3s","~");
          break;
        case 1:
          printf("%3s","X");
          break;
        case 2:
          printf("%3c",35);
          break;
        case 3:
          printf("%3c",37);
          break;
      }
		}
	printf("\n");
	}
}

void tir (int L, int H, Grille grille1) {
  char a;
  int b,c,k,u,i=65,j=6;
  
  vide_buffer();
  u=0;
  printf("A vous de tirer :\n");
  do{
    do {
      k=1;
      printf("Donnez l'ordonnée du tir (une lettre) :");
      scanf("%c", &a);
      vide_buffer();
      if (a>='a' && a<='z') {
        c=a-i-j;
        printf("%d",c);
      }
      else {
        if (a>='A' && a<='Z') {
          c=a-i;
          printf("%d",c);
        }
        else {
          printf("Erreur, donnez une lettre (attention à la casse). \n");
          k=0;
        }
      }
    } while(k==0);

    printf("\nDonnez l'abscisse du tir (un nombre) :");
    scanf("%d", &b);
    vide_buffer();
    b-=1;
    /*printf("\nTir en %d %d\n",c,b);*/

    if ((c>(H-1)) || (b>(L-1))) {
      u=0;
      printf("tir en dehors de la carte");
    }
    else {
      if (grille1[c][b]==0) {
        u=0;
        printf("tir dans l'eau");
      }
      else {
        u=1;
        printf("touché \n");
        printf("encore à vous \n");
      }
    }
  }while(u==1);
}

int comptecasebatteaux(int L, int H, Grille grille){
  int a=0,b=0,longu=0,haut=0;
	for (int i=0; i<L;i++) {
		for (int j=0; j<H;j++){
      if (grille[i][j]==2){
        if (j<(H-1)){if (grille[i][j+1]==2){
          longu=1;
        }}
        if (j>0){if (grille[i][j-1]==2){
          longu=1;
        }}
        if (i<(L-1)){if (grille[i+1][j]==2){
          haut=1;
        }}
        if (i>0){if (grille[i-1][j]==2){
          haut=1;
        }}
        a+=1;
        /* printf("longu: %d haut: %d a:%d b:%d\n",longu,haut,a,b);*/
        if ((longu==1)&&(haut==1)){b=-1;break;break;};
        longu=0;haut=0;  
      }
		}
	}
  if (b==-1){
    return b;
  } else {
    return a;
  }
}

int trierlesbateaux(int L, int H, Grille grille,RangeBateau rbat,int ncas){
  int a=0,i,j,b=0,l=0,ok;
  printf("\n");
  rbat=malloc((ncas+1)*sizeof(int*));
  for (i=0;i<=ncas;i++){
		rbat[i]=malloc(3*sizeof(int));
	};
  for (i=0; i<L;i++) {/* les lettres */
		for (j=0; j<H;j++){/* les chiffres */
      if (grille[i][j]==2){
        ok=1;
        for (l=0;i<ncas;i++){
		      if ((rbat[l][0]==i)&&(rbat[l][1]==j)){
            
          }
	      };
        if (ok==1){
          rbat[a][0]=i;
          rbat[a][1]=j;
          a+=1;
          l=1;
         while ((grille[i][j+l]==2)&&((l+j)<H)){
            rbat[a][0]=i;
            rbat[a][1]=j+l;
            a++;l++;
          };
          l=1;
          while ((grille[i+l][j]==2)&&((l+j)<L)){
            rbat[a][0]=i+l;
            rbat[a][1]=j;
            a++;l++;
          };
        }
      }
		}
	}
  printf("\n");
  return a;
}

int main(int argc, char **argv) {
	int L,H,ncas,i;
	Grille grille1,grille2;
  RangeBateau rbat1;

	printf("Longueur ?\n");
	scanf("%d",&L);
	printf("Hauteur ?\n");
	scanf("%d",&H);
  	printf("\n");

	grille1 = malloc((L+1)*sizeof(int*));
	for (int i=0;i<=L;i++){
		grille1[i]=malloc((H+1)*sizeof(int));
	}
	grille2 = malloc((L+1)*sizeof(int*));
	for (int i=0;i<=L;i++){
		grille2[i]=malloc((H+1)*sizeof(int));
	}
	
	creerGrille(L,H,grille2);
	recupGrille(L,H,grille1);
	afficherGrille(L,H,grille1);
  ncas=comptecasebatteaux(L,H,grille1);
  printf("\nil y a %d cases avec des bateaux\n",ncas);
  i=trierlesbateaux(L,H,grille1,rbat1,ncas);
  tir(L, H, grille1);

  for (int i=0;i<=L;i++){
		free(grille1[i]);
    free(grille2[i]);
	}
  free(grille1);
  free(grille2);
  free(rbat1);
	return 0;
};