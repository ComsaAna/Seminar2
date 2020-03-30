#include "KlasseAccount.h"
#include <iostream>
#include <fstream>
using namespace std;
std::ofstream g("output.txt");

Konto::Konto() {
	this->Saldo = 0;
}

void Konto::Bezahlen(const double& Betrag) {
	if (Saldo >= Betrag) {
		Saldo -= Betrag;
		g << "OUT " << Betrag << " " << Saldo<<"\n";
	}
}

void Konto::Einzahlung(const double& Betrag) {
	Saldo += Betrag;
	g << "IN " << Betrag << " " << Saldo << "\n";
}

double Konto::Kontostand() {
	return Saldo;
}

