#include <stdio.h>
#include <stdlib.h>

#define EAU 0;
#define TIR_DANS_L_EAU 1;
#define BATEAU 2;
#define BATEAU_TOUCHE 3;

typedef int ** Grille;

int Longueurmodifie () {
  int L;
  
  printf("Longueur de la grille?\n");
  scanf("%d",&L);
  return (L);
}

int Hauteurmodifie () {
  int H,k;

  do{
    printf("Hauteur de la grille?\n");
    scanf("%d",&H);
    if (H>=52) {
      k=1;
      printf("trop grand\n");
    }
  }while(k==1);
  return (H);
}

void creerGrille (int L, int H, Grille grille) {

  for (int i=0; i<H;i++){
    for (int j=0;j<L;j++) {
      grille[i][j]=0;
    }
  }
}

void afficherGrille(int L, int H, Grille grille){
  int a=65;
  
  printf(" ");
  for (int j=0;j<L;j++) {
    printf("%3d",j+1);
  }
  printf("\n");
  
  for (int i=0; i<H;i++) {
    a=65+i;
    if (a>=65 && a<=90){
      printf("%c", a);
    }
    else {
      if (a>=91 && a<=116){
        printf("%c", a+6);
      }
    }

    
    a+=1;
    for (int j=0; j<L;j++){
      switch (grille[i][j]){
        case 0:
          printf("%3s","~");//représente l'eau
          break;
        case 1:
          printf("%3s","X");//représente un tir manqué
          break;
        case 2:
          printf("%3c",35);//représente un bateau
          break;
        case 3:
          printf("%3c",111);//représente bateau touché
          break;
      }
    }
  printf("\n");
  }
}

int bateaumodifie() {//pour changer le nombre de bateau
  int a;
  
  printf("Avoir les paramètres par défaut :\n- 1 porte-avion de 6 cases\n- 2 croiseurs de 4 cases\n- 3 sous-marins de 3 cases\n- 4 torpilleurs de 2 cases\nOui (taper 1) ou non (taper 2)");
  scanf("%d",&a);
  return (a);
}

int porteavionmodifie () {
  int a;
  
  printf("nombre de porte-avion : ");
  scanf("%d",&a);
  return (a);
}

int croiseurmodifie () {
  int a;
  
  printf("nombre de croiseur : ");
  scanf("%d",&a);
  return (a);
}

int sousmarinsmodifie () {
  int a;
  
  printf("nombre de sous-marins : ");
  scanf("%d",&a);
  return (a);
}

int torpilleurmodifie () {
  int a;
  
  printf("nombre de torpilleur : ");
  scanf("%d",&a);
  return (a);
}

int coordonneeordonnee () {//demande l'ordonnée (une lettre)
  char a;
  int c,k,i=65,j=6;

  k=1;
  do {
    printf("Donner l'ordonnée :");
    scanf("%c", &a);
    scanf("%c", &a);
    if (a>='a' && a<='z') {
      c=a-i-j;
      k=1;
      return(c);
    }
    else {
      if (a>='A' && a<='Z') {
        c=a-i;
        k=1;
        return(c);
      }
      else {
        printf("Erreur, donner une lettre (majuscule ou minuscule). \n");
        k=0;
      }
    }
  }while(k==0);
}

int coordonneeabscisse () {//demande l'abscisse (un chiffre)
  int b;

  printf("\nDonner l'abscisse :");
  scanf("%d", &b);
  b=b-1;
  return(b);
}

int voisinNord (int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au nord
  
  if (c==1) {//le cas où le bateau est horizontal
    for (int i=0;i<s;i++) {
	  if (a==0) {
		return(0);
	  }
	  else {
		if (grille[a-1][b+i]!=0) {
		  return(1);
		}
		else {
		  return (0);
		}
	  }
	}
  }
  else {//le cas où le bateau est vertical
    if (a==0) {
	  return(0);
	}
	else {
	  if (grille[a-1][b]!=0) {
	    return(1);
	  }
	}
  }
return(0);
}

int voisinSud (int H, int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au sud
	
  if (c==1) {//le cas où le bateau est horizontal
	for (int i=0;i<s;i++) {
	  if (a==H-1) {
	    return(0);
	  }
	  else {
		if (grille[a+1][b+i]!=0) {
		  return(1);
		}
	  }
	}
    return(0);
  }
  else {//le cas où le bateau est vertical
    if (a==H-1) {
	  return(0);
	}
	else {
	  if (grille[a+s][b]!=0) {
		return(1);
	  }
	  else {
	    return(0);
	  }
	}
  }
}

int voisinNordEst (int L,int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Nord Est
	
  if (c==1) {//le cas où le bateau est horizontal
	if (a==0 || b==L-1) {
	  return(0);
	}
	else {
	  if (grille[a-1][b+s]!=0) {
	    return(1);
	  }
	  else {
	    return(0);
	  }
    }
  }
  else {//le cas où le bateau est vertical
    if (a==0 || b==L-1) {
      return(0);
	}
	else {
	  if (grille[a-1][b+1]!=0) {
		return(1);
	  }
	  else {
		return(0);
	  }
	}
  }
}

int voisinNordOuest (int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Nord Ouest
	
  if (c==1) {//le cas où le bateau est horizontal
	if (a==0 || b==0) {
	  return(0);
	}
	else {
	  if (grille[a-1][b-1]!=0) {
	    return(1);
	  }
	  else {
		return(0);
	  }
	}
  }
  else {//le cas où le bateau est vertical
    if (a==0 || b==0) {
	 return(0);
	}
	else {
	  if (grille[a-1][b-1]!=0) {
		return(1);
	  }
	  else {
		return(0);
	  }
	}
  }
}

int voisinSudEst (int L, int H,int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Sud Est
	
  if (c==1) {//le cas où le bateau est horizontal
    if (a==H-1 || b==L-1) {
	  return(0);
	}
	else {
	  if (grille[a+1][b+s]!=0) {
	    return(1);
	  }
	  else {
	    return(0);
	  }
	}
  }
  else {//le cas où le bateau est vertical
    if (a==H-1 || b==L-1) {
	  return(0);
	}
    else {
	  if (grille[a+s][b+1]!=0) {
		return(1);
	  }
	  else {
		return(0);
	  }
	}
  }
}

int voisinSudOuest (int H,int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Sud Ouest
	
  if (c==1) {//le cas où le bateau est horizontal
	if (a==H-1 || b==0) {
	  return(0);
	}
	else {
	  if (grille[a+1][b-1]!=0) {
		return(1);
	  }
	  else {
	    return(0);
	  }
	}
  }
  else {//le cas où le bateau est vertical
    if (a==H-1 || b==0) {
	  return(0);
	}
	else {
	  if (grille[a+s][b-1]!=0) {
		return(1);
	  }
	  else {
		return(0);
	  }
    }
  }
}

int voisinEst (int L,int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Est
	
  if (c==1) {//le cas où le bateau est horizontal
	if (b==L-1) {
	  return(0);
	}
	else {
	  if (grille[a][b+s]!=0) {
	    return(1);
	  }
	}
	return (0);
  }
  else {//le cas où le bateau est vertical
    for (int i=0;i<s;i++) {
	  if (b==L-1) {
		return(0);
	  }
	  else {
		if (grille[a+i][b+1]!=0) {
		  return(1);
		}
	  }
	}
    return(0);
  }
}

int voisinOuest (int a, int b, int s, int c, Grille grille) {//pour savoir s'il y a un bateau dans la case au Ouest
	
  if (c==1) {//le cas où le bateau est horizontal
	if (b==0) {
	  return(0);
	}
	else {
	  if (grille[a][b-1]!=0) {
		return(1);
	  }
	}
	return (0);
  }
  else {//le cas où le bateau est vertical
    for (int i=0;i<s;i++) {
	  if (b==0) {
	    return(0);
	  }
	  else {
		if (grille[a+i][b-1]!=0) {
		  return(1);
		}
	  }
	}
    return(0);
  }
}

int compteCelluleVoisinage(int L, int H, int a, int b, int s, int c, Grille grille){//permet de savoir si un bateau est collé
  int cmd;
	
  cmd=voisinNord (a, b, s, c, grille)+voisinSud(H,a, b, s, c, grille)+voisinNordEst(L,a, b, s, c, grille)+voisinNordOuest(a, b, s, c, grille)+voisinSudEst(L,H,a, b, s, c, grille)+voisinSudOuest(H,a, b, s, c, grille)+voisinEst(L,a, b, s, c, grille)+voisinOuest(a, b, s, c, grille);
  return(cmd);
}

int bateaudehors(int L, int H, int a, int b, int s, int c, Grille grille){//savoir si la pose du bateau est possible
  if (c==1) {
	if (a>=H || b+s>L) {
	  printf("bateau en dehors de la carte\n");
	  return(1);
	}
	else {
	  return(0);
	}
  }
  else {
	if (a+s>H || b>=L) {
	  printf("bateau en dehors de la carte\n");
	  return(1);
	}
	else {
	  return(0);
	}
  }
}

void porteavion (int L, int H, int p, Grille grille) {//permet de poser le porte-avion
  int a,b,c,e,s,q,v;
	
  s=6;
  if (p==1) {//le cas où les paramètres ne sont pas modifiés
	do{
      printf("Où mettre le porte-avion (6 cases)\n");
	  a=coordonneeordonnee ();
	  b=coordonneeabscisse ();
	  printf("Mettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
	  scanf("%d", &c);
	  v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	}while(v==1);
	
	switch (c) {
	  case 1://pose du porte-avion en horizontal
		for (int i=0; i<6;i++){
		  grille[a][i+b]=2;
		 }
		break;
	  case 2://pose du porte-avion en vertical
        for (int i=0; i<6;i++){
		  grille[i+a][b]=2;
		}
		break;
	 }
    afficherGrille(L,H,grille);
  }
  
  else {//paramètre modifié
    e=porteavionmodifie();//le nombre de porte-avion que l'utilisateur veut poser
    for (int i=0; i<e;i++){
	  do{
		do{
          printf("Où mettre le porte-avion (6 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
          v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);//bateau collé ou pas
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
	  
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<6;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<6;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
}

void croiseur(int L, int H,int p, Grille grille) {//permet de poser le croiseur
  int a,b,c,e,s,q,v;

  s=4;
  if (p==1) {//le cas où les paramètres ne sont pas modifiés
    for (int i=0;i<2;i++){
	  do{
	    do{
          printf("Où mettre le croiseur (4 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
		  v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<4;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<4;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
  
  else {//paramètre modifié
    e=croiseurmodifie();//le nombre de croiseurs que l'utilisateur veut poser
    for (int i=0; i<e;i++){
	  do{
		do{
          printf("Où mettre le croiseur (4 cases)\n");
          a=coordonneeordonnee ();
   	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
	      v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<4;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<4;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
}

void sousmarin (int L, int H,int p, Grille grille) {//permet de poser le sous-marin
  int a,b,c,e,s,q,v;
  
  s=3;
  if (p==1) {//le cas où les paramètres ne sont pas modifiés
    for (int i=0;i<3;i++){
	  do{
		do{
          printf("Où mettre le sous-marin (3 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
          v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<3;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<3;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
  
  else {//paramètre modifié
    e=sousmarinsmodifie();//le nombre de sous-marin que l'utilisateur veut poser
    for (int i=0; i<e;i++){
	  do{
		do{
          printf("Où mettre le sous-marin (3 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
          v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<3;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<3;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
}

void torpilleur (int L, int H,int p, Grille grille) {//permet de poser le torpilleur
  int a,b,c,e,s,q,v;
  
  s=2;
  if (p==1) {//le cas où les paramètres ne sont pas modifiés
    for (int i=0;i<4;i++){
	  do{
		do{
          printf("Où mettre le torpilleur (2 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
          v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<2;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<2;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
  
  else {//paramètre modifié
    e=torpilleurmodifie();//le nombre de torpilleur que l'utilisateur veut poser
    for (int i=0; i<e;i++){
	  do{
		do{
          printf("Où mettre le torpilleur (2 cases)\n");
          a=coordonneeordonnee ();
	      b=coordonneeabscisse ();
          printf("\nMettre le bateau horizontalement (taper 1) ou verticalement (taper(2)");
          scanf("%d", &c);
	      v=bateaudehors(L,H,a, b, s, c, grille);//bateau en dehors de la carte ou pas
	    }while(v==1);
	    
        q=compteCelluleVoisinage (L,H, a, b, s, c, grille);
        if (q!=0) {
		  printf("Bateau collé\n");
	    }
      }while(q!=0);
      
      switch (c) {
        case 1://pose du porte-avion en horizontal
          for (int i=0; i<2;i++){
            grille[a][i+b]=2;
          }
          break;
        case 2://pose du porte-avion en vertical
          for (int i=0; i<2;i++){
            grille[i+a][b]=2;
          }
          break;
      }
      afficherGrille(L,H,grille);
    }
  }
}

int tir (int L, int H, int c, int b, Grille grille) {//savoir où le tir a atterri

  if ((c>(H-1)) || (b>(L-1)) || c<0 || b<0) {
    printf("tir en dehors de la carte\n");
    return(0);
  }
  else {
    if (grille[c][b]==0) {
      printf("tir dans l'eau\n");
      return(1);
    }
    else {
      if (grille[c][b]==3){
        printf("Bateau déjà touché !\n");
        return(4);
      }
      else {
		if (grille[c][b]==1){
		  printf("Déjà tiré à cette endroit\n");
		  return(1);
		}
		else {
		  printf("bateau touché \n");
		  return(3);
		}
      }
    }
  }
}

void nouvellegrille(int L,int H,int c, int b,int t, Grille grille) {//grille après le tir

  switch (t){//les différents cas selon où le tir a atterri
    case 0://tir en dehors de la carte
      break;
    case 1://tir dans l'eau 
      grille[c][b]=1;
      break;
    case 4://tir sur un bateau déjà touché
      break;
    case 3://tir sur un bateau
      grille[c][b]=3;
      break;
  }
}

int fin(int L,int H,Grille grille){//permet de savoir s'il reste un bateau à toucher
  int k;
  
  k=0;
  for (int i=1; i<H;i++){
    for (int j=0;j<L;j++) {
      if (grille[i][j]==2) {//sile case est égal à 2 alors présence d'un bateau
        k=k+1;
      }
    }
  }
  return(k);
}

void jeu(int L,int H,Grille grille1, Grille grille2) {//procédure qui fait jouer les joueurs
  int c,b,t,k,u;

  do {
    printf("\fLe joueur 1 joue \n");
    afficherGrille(L,H,grille1);
    do{
      k=fin(L,H,grille2);//savoirs'il reste des bateaux
      if (k!=0) {
		printf("A vous de tirer \n");
        c=coordonneeordonnee();
        b=coordonneeabscisse();
        t=tir(L, H, c, b, grille2);
        nouvellegrille(L,H,c, b, t, grille2);
      }
      else {
        printf("Le joueur 1 a gagné !");
        u=1;
        break;
      }
    }while(t==3);//si t égale à 3 alors tir sur un bateau donc le joueur 1 rejoue

    if (u!=1) {//si u égale à 1, le joueur 1 a gagné
      printf("\fLe joueur 2 joue \n");
      afficherGrille(L,H,grille2);
      do {
        k=fin(L,H,grille1);//savoirs'il reste des bateaux
        if (k!=0) {
          c=coordonneeordonnee();
          b=coordonneeabscisse();
          t=tir(L, H, c, b, grille1);
          nouvellegrille(L,H,c, b, t, grille1);
        }
        else {
          printf("Le joueur 2 a gagné !");
          break;
        }
      }while(t==3);//si t égale à 3 alors tir sur un bateau donc le joueur 2 rejoue
    }
  }while(k!=0);
}

int main(int argc, char **argv) {
  int L,H,p;
  Grille grille1,grille2;

  printf("Avoir la grille par défaut (10x10) ?\nOui (taper 1) ou non (taper 2) : ");
  scanf("%d",&p);
  switch (p) {
    case 2:
      L=Longueurmodifie();
      H=Hauteurmodifie();
      break;
    case 1:
      L=10;
      H=10;
      break;
  }

  grille1 = malloc((L+H)*sizeof(int*));
  for (int i=0;i<=L+H;i++){
    grille1[i]=malloc((H+1)*sizeof(int));
  }
  grille2 = malloc((L+H)*sizeof(int*));
  for (int i=0;i<=L+H;i++){
    grille2[i]=malloc((H+1)*sizeof(int));
  }
  
  creerGrille(L,H,grille1);
  creerGrille(L,H,grille2);
  p=bateaumodifie();//savoir si le nombre de bateau est modifié
  
  printf("Configuration de la grille du joueur 1 \n");
  afficherGrille(L,H,grille1);
  porteavion(L, H, p, grille1);
  croiseur(L, H, p, grille1);
  sousmarin(L, H, p, grille1);
  torpilleur(L, H, p, grille1);
  
  printf("Configuration de la grille du joueur 2 \n");
  afficherGrille(L,H,grille2);
  porteavion (L, H, p, grille2);
  croiseur (L, H, p, grille2);
  sousmarin (L, H, p, grille2);
  torpilleur (L, H, p, grille2);
  
  jeu(L, H, grille1, grille2);
  return 0;
}