#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define lim 1000

// CONSOLA
HANDLE Ventana;
void Fullscreen();
void size (int X, int Y);

// JUEGO
int dado(int *rnd);
int dadoTruc(int *rnd);
void Escalera(int *pos);
void Serpiente(int *pos);
int validacion(char valor[]);
void compara_posiciones();

void jugador(int *x, int *vjugador, char numero[2], int bandera);
void PC(int *pos, int bandera, int *salida);

// GRAFICOS
void gotoxy (int,int);
void EscalerasYSerpientes(int contador, char blanco[5]);
void tablero();
void posicion();
void primera_linea();

//LIMPIEZA
void limpary(char (*a)[lim]);
void limp(char (*x)[105][lim]);
void graf(char (*x)[lim], char (*y)[lim], char (*z)[lim]);


int p1, p2, p3, p4, pc;
int Dado_Anterior;
char top[lim]="\0", und[lim]="\0", mid[lim]="\0", midV[105][lim], midV2[105][lim], ary[105][lim], ary2[105][lim];
char topaux[lim]="\0", undaux[lim]="\0", midaux[lim]="\0";

int main(){
	size(32,19);	
	int op, v, op2, w;
	int esc=0;
	char valor[5], segvalor[5];
	
	system("COLOR F0");
	do{
		do
		{
			size(32,19);
			SetConsoleTitle("Serpientes y Escaleras");
			printf("\n  \365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261");
			printf("\n  \261\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\365");
			printf("\n  \365\272  SERPIENTES Y ESCALERAS  \272\261");
			printf("\n  \261\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\365");
			printf("\n  \365\272         SIMBOLOS         \272\261\n  \261\272       Serpiente: \365       \272\365\n  \365\272       Escalera:  \261       \272\261");
			printf("\n  \261\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\365");
			printf("\n  \365\272     1.- Un jugador       \272\261\n  \261\272     2.- Multijugador     \272\365\n  \365\272     3.- Instrucciones    \272\261\n  \261\272     4.- Salir            \272\365");
			printf("\n  \365\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\261");
			printf("\n  \261\272     Opcion:              \272\365");
			printf("\n  \365\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\261");
			printf("\n  \365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261");
			
			gotoxy(18,14);
			gets(valor);
			v=validacion(valor);
		}while(v==0);
		op=atoi(valor);
		
		switch(op){
			case 1:
				Fullscreen();
				do{
				    jugador(&esc, &p1, "P1", esc);
					PC(&pc, esc, &esc);
				}while(esc!=1);
				esc=0;
				Fullscreen();
				break;
			case 2:
				do{
					do
					{
						system("cls");
						size(32,17);
						printf("\n  \365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261");
						printf("\n  \261\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\365");
						printf("\n  \365\272  SERPIENTES Y ESCALERAS  \272\261");
						printf("\n  \261\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\365");
						printf("\n  \365\272   Numero de jugadores    \272\261");
						printf("\n  \261\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\365");
						printf("\n  \365\272   1.- Dos jugadores      \272\261\n  \261\272   2.- tres jugadores     \272\365\n  \365\272   3.- cuatro jugadores   \272\261\n  \261\272   4.- Regresar           \272\365");
						printf("\n  \365\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271\261");
						printf("\n  \261\272     Opcion:              \272\365");
						printf("\n  \365\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\261");
						printf("\n  \365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261");
						gotoxy(18,12);
						gets(segvalor);
						w=validacion(segvalor);
					}while(w==0); 
					op2=atoi(segvalor);
					
					switch (op2)
					{
						case 1:
							Fullscreen();
							do
							{
								
								jugador(&esc, &p1, "P1", esc);
							    jugador(&esc, &p2, "P2", esc);
							    PC(&pc, esc, &esc);
							}while(esc!=1);
							Fullscreen();
						break;
						case 2:
							Fullscreen();
							do
							{
								
								jugador(&esc, &p1, "P1", esc);
				                jugador(&esc, &p2, "P2", esc);
				                jugador(&esc, &p3, "P3", esc);
							    PC(&pc, esc, &esc);
							}while(esc!=1);
							Fullscreen();
						break;
						case 3:
							Fullscreen();
							do
							{
								
								jugador(&esc, &p1, "P1", esc);
				                jugador(&esc, &p2, "P2", esc);
				                jugador(&esc, &p3, "P3", esc);
				                jugador(&esc, &p4, "P4", esc);
				                PC(&pc, esc, &esc);
							}while(esc!=1);
							Fullscreen();
						break;
						case 4:
							esc=1;
							break;
						default:
							printf("\n\n\n Valor Invalido...");
				            getch();
				            fflush(stdin);
				            system("cls");
							break;
					}
				}while(esc!=1);
				esc=0;
				break;
			case 3:
				system("cls");
				size(32,26);
				printf("----I n s t r u c c i o n e s----\n\n");
				printf("1-Los valores del dado son del\n  2-12\n\n");
				printf("2-Serpientes = [\365]\n  Escaleras = [\261]\n\n");
				printf("3-Las serpientes te llevan a la\n  casilla en el parentesis a su\n  lado\n\n");
				printf("4-Las escaleras  te llevan a la\n  casilla en el parentesis a su\n  lado\n\n");
				printf("5-Para ganar se debera conseguir\n  el numero exacto que llegue a\n  la casilla 100\n\n");
				printf("6-Si el jugador sobrepasa la\n  casilla 100, se regresa las\n  casillas sobrantes\n\n");
				printf("Presiona una tecla para regresar");
				getch();

				break;
			case 4:
				system("cls");
				printf("\n Desarrolladores:\n\n - Ladingo2000\n - Azarel\n - NCSR\n - KitsukiCross\n - Angel");
				getch();
				break;
			default:
				printf("\n\n\n Valor Invalido...");
				getch();
				fflush(stdin);
				break;
		}
		system("cls");
	}while(op!=4);
}

int dado(int *rnd){
	int x, y,exit;
	do{
	exit=0;
	srand(time(NULL));
	x=(rand()%12)+1;
	if(x==1 || Dado_Anterior==x)	
	exit=1;
	}while(exit==1);
	Dado_Anterior=x;
    //y=(rand()%6)+1;
    *rnd=x;
}

void posicion(){
	
	int i, j, pos=100, aux, fl;
	
	compara_posiciones();
	    
	graf(&top, &und, &mid);
	    
	for(i=1; i<=8; i++){
	    fflush(stdin);
		if((i%2)!=0){
			aux=pos-13;
		}
		if(i==1){
			aux=pos-9;
			fl=9;
		}else{
			fl=13;
		}
	    for(j=1; j<=fl; j++){
	    	fflush(stdin);
			if((i%2)!=0){
			    aux++;
		    }else{
		    	aux=pos;
			}
	    	strcat(ary[i], midV[aux]);
	    	strcat(ary2[i], midV2[aux]);
	    	pos--;
		}
	}
}

void compara_posiciones(){
	int i;
	
	for(i=1; i<=100; i++){
		if (p1==i&&p2==i&&p3==i&&p4==i&&pc==i)
		{
			strcat(midV[i], " \272 P1,P2,P3  \272");
			strcat(midV2[i], " \272  P4,PC    \272");
		}
		
		else if(p1==i&&p2==i&&p3==i&&p4==i){
			strcat(midV[i], " \272  P1,P2    \272");
			strcat(midV2[i], " \272  P3,P4    \272");
		}
		else if(p1==i&&p2==i&&p3==i&&pc==i){
			strcat(midV[i], " \272  P1,P2    \272");
			strcat(midV2[i], " \272  P3,PC    \272");
		}
		else if(p1==i&&p2==i&&pc==i&&p4==i){
			strcat(midV[i], " \272  P1,P2    \272");
			strcat(midV2[i], " \272  P4,PC    \272");
		}
		else if(p1==i&&pc==i&&p3==i&&p4==i){
			strcat(midV[i], " \272  P1,P3    \272");
			strcat(midV2[i], " \272  P4,PC    \272");
		}
		else if(pc==i&&p2==i&&p3==i&&p4==i){
			strcat(midV[i], " \272  P2,P3    \272");
			strcat(midV2[i], " \272  P4,PC    \272");
 		}
		
		else if(p1==i&&p2==i&&p3==i){
			strcat(midV[i], " \272 P1,P2,P3  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p2==i&&p4==i){
			strcat(midV[i], " \272 P1,P2,P4  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p4==i&&p3==i){
			strcat(midV[i], " \272 P1,P3,P4  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&p4==i&&p3==i){
			strcat(midV[i], " \272 P2,P3,P4  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p2==i&&pc==i){
			strcat(midV[i], " \272 P1,P2,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p3==i&&pc==i){
			strcat(midV[i], " \272 P1,P3,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&p3==i&&pc==i){
			strcat(midV[i], " \272 P2,P3,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p4==i&&pc==i){
			strcat(midV[i], " \272 P1,P4,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&p4==i&&pc==i){
			strcat(midV[i], " \272 P2,P4,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p3==i&&p4==i&&pc==i){
			strcat(midV[i], " \272 P3,P4,PC  \272");
			strcat(midV2[i], " \272           \272");
		}
		
		else if(p1==i&&p4==i){
			strcat(midV[i], " \272  P1,P4    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p3==i){
			strcat(midV[i], " \272  P1,P3    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&p2==i){
			strcat(midV[i], " \272  P1,P2    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i&&pc==i){
			strcat(midV[i], " \272  P1,PC    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&p4==i){
			strcat(midV[i], " \272  P2,P4    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&p3==i){
			strcat(midV[i], " \272  P2,P3    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i&&pc==i){
			strcat(midV[i], " \272  P2,PC    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p3==i&&p4==i){
			strcat(midV[i], " \272  P3,P4    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p3==i&&pc==i){
			strcat(midV[i], " \272  P3,PC    \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p4==i&&pc==i){
			strcat(midV[i], " \272  P4,PC    \272");
			strcat(midV2[i], " \272           \272");
		}

		else if(pc==i){
			strcat(midV[i], " \272    PC     \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p1==i){
			strcat(midV[i], " \272    P1     \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p2==i){
			strcat(midV[i], " \272    P2     \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p3==i){
			strcat(midV[i], " \272    P3     \272");
			strcat(midV2[i], " \272           \272");
		}
		else if(p4==i){
			strcat(midV[i], " \272    P4     \272");
			strcat(midV2[i], " \272           \272");
		}
		else
		{
			strcat(midV[i], " \272           \272");
			strcat(midV2[i], " \272           \272");
		}
	}
}

void tablero(){
	int i, j, pos=100, aux, fl, fl2;
	char wh[5];
	
	limp(&midV);
	limp(&ary);
	
	limp(&midV2);
	limp(&ary2);
	
	limpary(&top);
	limpary(&mid);
	limpary(&und);
	
	limpary(&topaux);
	limpary(&midaux);
	limpary(&undaux);
	
	printf("\n\n\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261  SERPIENTES  &  ESCALERAS  \261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\261\365\n\n");
	
	posicion();
	primera_linea();
	
	for(i=1; i<=8; i++){
		
		fflush(stdin);
		if((i%2)!=0){
			aux=pos-13;
		}
		
		if(i==1){
			aux=pos-9;
			fl=9;
			printf("%s\n", topaux);
		}else{
			fl=13;
			printf("%s\n", top);
		}
		
		for(j=1; j<=fl; j++){
			fflush(stdin);
			if((i%2)!=0){
			    aux++;
		    }else{
		    	aux=pos;
			}
			if(aux<100){
				if(aux>9){
					strcpy(wh, " ");
				}else{
					strcpy(wh, "  ");
				}
			}else{
				strcpy(wh, "\0");
			}
			EscalerasYSerpientes(aux, wh);
			pos--;
		}
		if(i==1){
			printf("\n        %s%s", midaux, ary[i]);
		    printf("\n        %s%s", midaux, ary2[i]);
			printf("\n%s\n", undaux);
		}else{
			printf("\n        %s", ary[i]);
		    printf("\n        %s", ary2[i]);
		    printf("\n%s\n", und);
		}
	}
}

void EscalerasYSerpientes(int contador, char blanco[5]){
	
	
	switch (contador){
		case 11: printf(" \272%d \261(39)%s  \272", contador, blanco); break;
		case 17: printf(" \272%d \261(67)%s  \272", contador, blanco); break;
		case 19: printf(" \272%d \261(45)%s  \272", contador, blanco); break;
		case 21: printf(" \272%d \261(56)%s  \272", contador, blanco); break;
		case 26: printf(" \272%d \261(50)%s  \272", contador, blanco); break;
		case 43: printf(" \272%d \261(84)%s  \272", contador, blanco); break;
		case 52: printf(" \272%d \261(76)%s  \272", contador, blanco); break;
		case 70: printf(" \272%d \261(92)%s  \272", contador, blanco); break;
		case 74: printf(" \272%d \261(100)  \272", contador, blanco); break;
		
		case 22: printf(" \272%d \365(2)%s   \272", contador, blanco); break;
		case 18: printf(" \272%d \365(6)%s   \272", contador, blanco); break;
		case 83: printf(" \272%d \365(8)%s   \272", contador, blanco); break;
		case 62: printf(" \272%d \365(14)%s  \272", contador, blanco); break;
		case 36: printf(" \272%d \365(20)%s  \272", contador, blanco); break;
		case 75: printf(" \272%d \365(30)%s  \272", contador, blanco); break;
		case 78: printf(" \272%d \365(49)%s  \272", contador, blanco); break;
		case 92: printf("                                     \272%d%s        \272", contador, blanco); break;
		case 93: printf(" \272%d \365(40)%s  \272", contador, blanco); break;
		case 96: printf(" \272%d \365(69)%s  \272", contador, blanco); break;
		
		default: if((contador==91 || contador==66 || contador==65) || (contador==40 || contador==39 || contador==14) || contador==13)
					{printf("         \272%d%s        \272", contador, blanco);
					}
				else{
					printf(" \272%d%s        \272", contador, blanco); 
				}	
				 break;
	}
}

void graf(char (*x)[lim], char (*y)[lim], char (*z)[lim]){
	int i;
	for(i=1; i<=13; i++){
		if(i!=1)
		{
		strcat((*x), " \311\315\315\315\315\315\315\315\315\315\315\315\273");
		strcat((*y), " \310\315\315\315\315\315\315\315\315\315\315\315\274");
		strcat((*z), " \272             \272");
		}
		if(i==1){
		strcat((*x), "         \311\315\315\315\315\315\315\315\315\315\315\315\273");
		strcat((*y), "         \310\315\315\315\315\315\315\315\315\315\315\315\274");
		strcat((*z), "         \272             \272");	
		}
	}
}

void limp(char (*x)[105][lim]){
	int i;
	for(i=1; i<=100; i++){
		strcpy((*x)[i], "\0");
	}
}

void limpary(char (*a)[lim]){
	strcpy(*a, "\0");
}

void Escalera(int *pos)
{
	
	switch (*pos)
	{
		case 11:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=39;
		break;
		case 17:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=67;
		break;
		case 19:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=45;
		break;
		case 21:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=56;
		break;
		case 26:
			system("cls");
			tablero();
			printf("\n iEscaleras!");
			getch();
			*pos=50;
		break;
		case 43:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=84;
		break;
		case 52:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=76;
		break;
		case 70:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=92;
		break;
		case 74:
			system("cls");
			tablero();
			printf("\n ¡Escaleras!");
			getch();
			*pos=100;
		break;
		default:
		break;	
	}
}

void Serpiente(int *pos)
{
	
	switch(*pos)
	{
		case 96:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=69;
		break;
		case 93:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=40;
		break;
		case 83:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=8;
		break;
		case 75:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=30;
		break;
		case 78:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=49;
		break;
		case 62:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=14;
		break;
		case 36:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=20;
		break;
		case 18:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=6;
		break;
		case 22:
			system("cls");
			tablero();
			printf("\n ¡Serpientes!");
			getch();
			*pos=2;
		break;
		default:
		break;
	}
}

void jugador(int *x, int *vjugador, char numero[2], int bandera){
	int op, suma, des, v;
	char valor[5];
	
	if(bandera==0){
		do{
		    do{
		        system("cls");
			    tablero();
			    printf("\n Turno de [%s]", numero);
			    printf("\n 1.-Lanzar dados \n 2.-Abandonar la partida \n Opcion: ");
			    gets(valor);
			    v=validacion(valor);
		    }while(v==0);
		    op=atoi(valor);
		
		    switch(op){
			    case 1:
				    dado(&suma);
				    Dado_Anterior=suma;
				    printf(" Puntos sumados: %d ", suma);
				    (*vjugador)+=suma;
				    if((*vjugador)>100){
					    des=(*vjugador)-100;
					    (*vjugador)=(*vjugador)-des*2;
				    }
				    getch();
				    Escalera(&(*vjugador));
	                Serpiente(&(*vjugador));
	                
				    if((*vjugador)==100)
				    {
				    	getch();
				    	system("cls");
						tablero();
					    printf("\n ¡[%s] Gan\242!", numero);
					    getch();
					    *x=1;
				        p1=0;
				        p2=0;
				        p3=0;
				        p4=0;
				        pc=0;
				        system("cls");
				        break;
				    }
				    
				    break;
			    case 2:
				    *x=1;
				    p1=0;
				    p2=0;
				    p3=0;
				    p4=0;
				    pc=0;
				    system("cls");
				    break;
			    default:
				    printf("\n Valor Invalido\n ");
                    system("pause");
				break;
		    }
	    }while(op!=2 && op!=1);
	}
}

void PC(int *pos, int bandera, int *salida)
{
	int suma,des;
	if(bandera==0){
		system("cls");
		tablero();
		printf("\n Turno de la [PC]:\n");
	    dado(&suma);
	    Dado_Anterior=suma;
		//dadoTruc(&suma);
	    printf(" Puntos sumados: %d ", suma);
	    pc+=suma;
	    if(pc>100){
	        des=pc-100;
	        pc=pc-des*2;
	    }
	    if(pc==100){
	    	getch();
	    	system("cls");
			tablero();
			printf("\n ¡[PC] Gan\242!");
			getch();
			(*salida)=1;
			p1=0;
			p2=0;
	        p3=0;
			p4=0;
			pc=0;
			system("cls");
		}else{
			getch();
	        Escalera(&pc);
	        Serpiente(&pc);
		}
	}
	
}

int validacion(char valor[])
{
	int i;
	for(i=0; i<strlen(valor); i++)
	{
		if(!(isdigit(valor[i])))
		{
			printf("\n\n\n Ingresa solo numeros...");
			getch();
			system("cls");
            fflush(stdin);
			return 0;
		}
	}
	return 1;
	for(i=0; i<=5;i++)
	valor[i]='0';
}

void primera_linea(){
	int i;
	for(i=1; i<=11; i++){
		if(i>2){
			
			strcat(topaux, " \311\315\315\315\315\315\315\315\315\315\315\315\273");
		    strcat(undaux, " \310\315\315\315\315\315\315\315\315\315\315\315\274");
		    //strcat(midaux, " \272         \272");
		}else{
			
			strcat(topaux, "                  ");
		    strcat(undaux, "                  ");
		    strcat(midaux, "              ");
		}
		
		//strcat((*z), " \272         \272");
	}
}

void gotoxy (int x,int y) {
	HANDLE Manipulador;
	COORD Coordenadas;
	Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;
	Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulador,Coordenadas);
}

void Fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    return;
} 

void size (int X, int Y) 
{
  Ventana = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, X, Y};
    SetConsoleWindowInfo(Ventana, 1, &windowSize);
}
