// number_converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>/*evtl unnötig*/

/* umlaute definiert für ausgabe*/
#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225


/*umrechnung dezimal in binär/dual */
void dez_bin()
{
	int zahl = 0;
	int rest = 0;
	int count = 0;
	char count_umkehr=0;
	//int laenge, size;
	char bin_verkehrt[20];
	int a;
	char bin_richtig[20];
	int stelle = 0;
	int modu;
	printf("\n\n\n Bitte Zahl eingeben zum Umwandeln\n");
	scanf("%d",&zahl);
	fflush(stdin);

	do
	{
		rest=zahl/2;
		modu= zahl%2;

		if(modu==0)
		{
			bin_verkehrt[count]='0';
		}
		else
		{
			bin_verkehrt[count]='1';
		}
		count ++;
		zahl=rest;
	}
	while(zahl != 0);
	bin_verkehrt[count]='\0';
	count=count;

	//laenge = strlen(bin_verkehrt);
	//size = laenge;
	
	
	for(count;count>=0;count--)
	{
		a=bin_verkehrt[count];
		bin_richtig[count_umkehr]= a;
		count_umkehr++;
	}
	bin_richtig[count_umkehr]= '\0';



	printf("bin zahl:  ");

	for(int i=0;i<=count_umkehr;i++)
	{
		printf("%c",bin_richtig[i]);
	}
	getchar();

}




/*rechnung dezimal in hexadezimal*/
void dez_hex()
{
	int zahl = 0;
	int rest = 0;
	int count = 0;
	char count_umkehr=0;
	char hex_verkehrt[20];
	int a;
	char hex_richtig[20];
	int stelle = 0;
	int modu;
	printf("\n\n\n Bitte Zahl eingeben zum Umwandeln\n");
	scanf("%d",&zahl);
	fflush(stdin);

	do
	{
		rest = zahl/16;
		modu = zahl%16;

		switch(modu)
		{
			case 0:
				hex_verkehrt[count] = '0';
				break;

			case 1:
				hex_verkehrt[count] = '1';
				break;

			case 2:
				hex_verkehrt[count] = '2';
				break;

			case 3:
				hex_verkehrt[count] = '3';
				break;

			case 4:
				hex_verkehrt[count] = '4';
				break;

			case 5:
				hex_verkehrt[count] = '5';
				break;

			case 6:
				hex_verkehrt[count] = '6';
				break;

			case 7:
				hex_verkehrt[count] = '7';
				break;

			case 8:
				hex_verkehrt[count] = '8';
				break;

			case 9:
				hex_verkehrt[count] = '9';
				break;

			case 10:
				hex_verkehrt[count] = 'A';
				break;

			case 11:
				hex_verkehrt[count] = 'B';
				break;

			case 12:
				hex_verkehrt[count] = 'C';
				break;

			case 13:
				hex_verkehrt[count] = 'D';
				break;

			case 14:
				hex_verkehrt[count] = 'E';
				break;

			case 15:
				hex_verkehrt[count] = 'F';
				break;

			default: ;
				/*should not get here*/
		}
		count ++;
		zahl = rest;
	}
	while(zahl != 0);
	hex_verkehrt[count] = '\0';
	count = count;

	/******************
	 *Ziffern umdrehen*
	 ******************/
	for(count;count >= 0;count--)
	{
		a = hex_verkehrt[count];
		hex_richtig[count_umkehr] = a;
		count_umkehr++;
	}
	hex_richtig[count_umkehr] = '\0';


	/********************
	 * Ausgeben der Zahl*
	 ********************/
	printf("hex zahl:  ");

	for(int i = 0;i <= count_umkehr;i++)
	{
		printf("%c",hex_richtig[i]);
	}
	getchar();
}




/*16er einmaleins bis 30*/
void einmaleins_16()
{
	int i;
	int zahl = 16;

	for(i = 0;i<31;i++)
	{
		printf("\t\t%d * %d  = %d\n",zahl,i,zahl*i);
		getchar();
	}
}




/*2^x hochzahöen bis 16*/
void hochzahl_2()
{
	int i = 0;
	int zahl = 2;

	for(i ;i<65;i++)
	{
		printf("\t\t%dx%d  = %d\n", zahl,i, _Pow_int(zahl,i));
		getchar();
	}
}



/*16^x hochzahlen bis 10*/
void hochzahl_16()
{
	int i = 0;
	int zahl = 16;
	
	for(i;i < 11;i++)
	{
		printf("\t\t%dx%d  = %d\n", zahl,i, _Pow_int(zahl,i));
		getchar();
	}
}


/*binär  nach dezimal*/
void bin_dez()
{
	char bin_wrong[25];
	char bin_right[25];
	int summe = 0;
	int zahl;
	int counter = 0;
	char a;
	int size;
	int msg = 0;

	printf("Bitte Zahl eingeben:  ");
	scanf("%24s",&bin_wrong);
	fflush(stdin);
	//printf("\n%s",bin_wrong);


	size = strlen(bin_wrong)-1;

	for(size;size >= 0;size--)
	{
		a = bin_wrong[size];
		bin_right[counter] = a;
		counter++;
	}
	bin_right[counter] = '\0';
	
	size = strlen(bin_right)-1;

	for(counter = 0;counter<=size;counter++)
	{
		zahl = bin_right[counter];
		if(zahl == 49)
		{
			zahl = 1;
		}
		else if(zahl == 48)
		{
			zahl = 0;
		}
		else
		{
			zahl = 0;

			if (msg == 0)
			{
				printf("Bitte nur Bin%crzhlen also 0 und 1 eingeben!!\n");
				msg++;
			}
		}
		summe = summe+(zahl*_Pow_int(2,counter));
	}
	if(msg>0)
	{

	}
	else
	{
		printf("\nDezimal: %d",summe);
	}
	getchar();
}



/*Umrechnung von Hexadezimal in Dezimal                     * 
 *Eingabe einer Hex-zahl welche dann Dezimal ausgegeben wird*/
void hex_dez()
{
	char hex_wrong[25];
	char hex_right[25];
	int summe = 0;
	int zahl;
	int counter = 0;
	char a;
	int size;
	int msg = 0;

	printf("Bitte Zahl eingeben:  ");
	scanf("%24s",&hex_wrong);
	fflush(stdin);
	//printf("\n%s",bin_wrong);


	size = strlen(hex_wrong)-1;

	for(size;size >= 0;size--)
	{
		a = hex_wrong[size];
		hex_right[counter] = a;
		counter++;
	}

	hex_right[counter] = '\0';
	
	size = strlen(hex_right)-1;

	for(counter = 0;counter<=size;counter++)
	{
		zahl = hex_right[counter];
		if(zahl == 49)
		{
			zahl = 1;
		}
		else if(zahl == 48)
		{
			zahl = 0;
		}
		else if(zahl == 50)
		{
			zahl = 2;
		}
		else if(zahl == 51)
		{
			zahl = 3;
		}
		else if(zahl == 52)
		{
			zahl = 4;
		}
		else if(zahl == 53)
		{
			zahl = 5;
		}
		else if(zahl == 54)
		{
			zahl = 6;
		}
		else if(zahl == 55)
		{
			zahl = 7;
		}
		else if(zahl == 56)
		{
			zahl = 8;
		}
		else if(zahl == 57)
		{
			zahl = 9;
		}
		else if(zahl == 65 || zahl == 97)
		{
			zahl = 10;
		}
		else if(zahl == 66 || zahl == 98)
		{
			zahl = 11;
		}
		else if(zahl == 67 || zahl == 99)
		{
			zahl = 12;
		}
		else if(zahl == 68 || zahl == 100)
		{
			zahl = 13;
		}
		else if(zahl == 69 || zahl == 101)
		{
			zahl = 14;
		}
		else if(zahl == 70 || zahl == 102)
		{
			zahl = 15;
		}
		else
		{
			zahl = 0;

			if (msg == 0)
			{
				printf("!!Bitte nur die Zahlen 0-9 sowie buchstaben von A-F verwenden!!\n");
				msg++;
			}
		}
		summe = summe+(zahl*_Pow_int(16,counter));
	}
	if(msg > 0)
	{

	}
	else
	{
		printf("\nDezimal: %d",summe);
	}
	getchar();
}



void hex_bin()
{
	printf("********************\n");
	printf("**Noch zu erstllen**\n");
	printf("********************\n");
	// 3 arrays  1. eingabe, 2.für die Teile 3.fürzusammengesetzt das Ergebnis ; switch case für schauen welches evtl
}




void primzahl_test()
{
	int zahl;
	int rest = 0;
	int counter = 0;
	int teiler = 1;

	printf("\n\nBitte Zahl eingeben die getestet werden soll:  ");
	scanf("%d",&zahl);
	fflush(stdin);

	while(teiler <= zahl)
	{
		rest = zahl%teiler;
		if(rest == 0)
		{
			counter = counter + 1;
		}

		teiler++;
	}
	
	if( counter == 2)
	{
		printf("\nZahl ist eine Priemzahl");
	}
	else if( counter < 2)
	{
		printf("\n0 und 1 sind keine Primzahlen, ansonsten .... FEHLER");
	}
	else if( counter > 2)
	{
		printf("\nZahl ist keine Primzahl");
	}

	printf("\nZahl: %d",zahl);
	getchar();
}


/*Zeigt alle Primzahlen bis x an*/
void primzahlen_zeigen()
{
	int zahl = 2;
	int counter = 0;
	int teiler = 1;
	int rest;
	int max;

	printf("\nBitte Zahl angeben bis zu dieser die Primzahlen\nausgegeben werden soll:   ");
	scanf("%d",&max);
	fflush(stdin);

	while(zahl <= max)
	{
		while(teiler <= zahl)
		{

			rest= zahl%teiler;
			if(rest == 0)
			{
				counter =  counter +1;
			}
			teiler ++;
		}

		if(counter == 2)
		{
			printf("\n\t%d\n",zahl);
		}
		zahl++;
		teiler = 1;
		counter = 0;
	}
	printf("\nZahl erreicht!!\n");
	getchar();
}


void zahlensysteme()
{
	int auswahl;

	do{
		system("cls");
		printf("\n\tZahlensysteme\n");
		printf("\t_______________\n\n");
		printf("\t-Dezimal zu Bin%cr (1)\n",ae);   
		printf("\t-Dezimal zu Hex   (2)\n");	
		printf("\t-Bin%cr zu Dezimal (3)\n",ae);     
		printf("\t-Hex zu Dezimal   (4)\n");	
		printf("\t-Zur%cck           (5)\n",ue);
		printf("\nBitte Umrechnungsmethode ausw%clen:\n",ae);

		scanf("%d",&auswahl);
		fflush(stdin);

		switch(auswahl)
		{
		case 1:
			dez_bin();
			break;

		case 2:
			dez_hex();
			break;

		case 3:
			bin_dez();
			break;

		case 4:
			hex_dez();
			break;

		case 5:
			break;

		}
	}
	while(auswahl != 5);
}


void hochzahlen()
{
	int auswahl;
	do{

		system("cls");
		printf("\n\tHochzahlen und co\n");
		printf("\t_________________\n\n");
		printf("\t-Hochzahlentest   (1)\n");        // (x)
		printf("\t-16er Einmaleins  (2)\n");        // (x)
		printf("\t-16er Hochzahlen  (3)\n");		// (x)
		printf("\t-Zur%cck           (4)\n",ue);

		printf("\nBitte Umrechnungsmethode ausw%clen:\n",ae);

		scanf("%d",&auswahl);
		fflush(stdin);

		switch(auswahl)
		{
			case 1:
				hochzahl_2();
				break;

			case 2:
				einmaleins_16();
				break;

			case 3:
				hochzahlen();
				break;
			case 4:
				break;
		}
	}
	while(auswahl != 4);
}



void sonstiges()
{
	int auswahl;

	do{
		system("cls");
		printf("\n\tSonstiges\n");
		printf("\t_________________\n\n");
		printf("\t-Primzahlentest   (1)\n");
		printf("\t-Primzahlen zeigen(2)\n");
		printf("\t-Zur%cck           (3)\n",ue);

		printf("\nBitte Umrechnungsmethode ausw%clen:\n",ae);

		scanf("%d",&auswahl);
		fflush(stdin);


		switch(auswahl)
		{
			case 1:
				primzahl_test();
				break;

			case 2:
				primzahlen_zeigen();
				break;

			case 3:
				break;

			default: ;
		}

	}
	while(auswahl !=3);
}


/*start
 * Auswahl was gemacht werden soll
   und Start des Programmes
 */
int main(int argc, char* argv[])
{

	int auswahl = 0 , ende = 0;

	do
	{
		printf("\n\nKleiner Zahlenumrechner zum  %cben\n\n",ue);
		printf("\t-Zahlensysteme      (1)\n");
		printf("\t-Hochzahlen         (2)\n");
		printf("\t-Sonstiges          (3)\n");
		printf("\t-Beenden            (4)\n");
		printf("Bitte Umrechnungsmethode ausw%clen:\n",ae);

		scanf("%d",&auswahl);
		fflush(stdin);

		switch(auswahl)
		{
			case 1:
				zahlensysteme();
				break;

			case 2:
				hochzahlen();
				break;

			case 3:
				sonstiges();
				break;

			case 4:
				ende = 1;
				break;

			default:  
				printf("\nBitte nur auswahl eingeben\n ");

		}
		system("cls");
	}
	while(ende != 1);
	
	return 0;
}

