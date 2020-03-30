// SeminarAufgaben2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
//#include <cassert>
#include "KlasseAccount.cpp"

using namespace std;


const char* strfind(const char* s1, const char* s2)
{
	while (*s1)  //*s1!=0
	{
		const char* s1_aux = s1;
		const char* s2_aux = s2;

		// Wenn die ersten Buchstaben gleich sind, uberprufe den ganzen string
		while (*s1 && *s2_aux && *s1 == *s2_aux)
		{
			s1++;
			s2_aux++;
		}

		// wenn gesfunden, returniert die Adresse, von wo der substring zuerst erschienen ist, bis zum Ende 
		if (!*s2_aux)
			return s1_aux;
		s1 = s1_aux + 1;    // sucht weiter
	}
	//Return NULL, wenn keine Erscheinung gefunden wird 
	return NULL;
}

struct Typen {
	bool b;
	char c;
	int i;
	long l;
	double d;
	long double ld;
}feld[100];

struct Typen_klein { //klein
	bool b1;
	char* c1 = new char[100]; //char s[100] -> 128
	int i1;
	long l1;
	double d1;
	long double ld1;
};

//2.

struct Typen_gross {
	bool b2;
	char c2[100];
	int i2;
	long l2;
	double d2;
	long double ld2;
};

//void pointer(Typen_gross* p) {
//	++p->i;  //p++;p.i
//	p++->i;
//	*p = &p;
//	*p->i;
//	*p->i++;
//	(*p->i)++;
//	*p++->i;
//}

int str_len(const char* s) {
	int ct = 0;
	while (*s!='\0')
	{
		s++;
		ct++;
	}
	return ct;
}

char* strcopy(char* dest, const char* sursa, int p)
{
	int i = p;
	int k = 0;
	do
	{
		dest[i] = sursa[k];
		i++;
		k++;
	} while (dest[k] != '\0');
	return dest;
}

int main()
{
	char a[100] = "Ananas\0", b[100] = "na\0";
	//Aufgabe 1
	std::cout << strfind(a, b)<<std::endl; //wo,was
	//Aufgabe2
	std::cout << sizeof(Typen_klein)<<" "<< sizeof(Typen_gross)<<"\n";
	//Schlussfolgerung: Die Struktur, die den Pointer benutzt, hat eine kleinere Grosse,
	//als die, die einen normalen Vektor benutzt
	//Aufgabe 3
	const char* s = "Anamaria";
	std::cout<<"Das Wort hat "<< str_len(s)<<" Buchstaben\n";
	//Aufgabe4
	char f[30] = "mancare";
	char v[10] = "xyz";
	//strcopy(wo, was, poz);
	std::cout << strcopy(f, v, 3);
	//Aufgabe6,7
	Konto k = Konto();
	k.Einzahlung(100);
	//cout<<k.Kontostand();
	k.Bezahlen(25);
	//cout<<k.Kontostand();
	return 0;
}
