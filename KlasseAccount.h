#pragma once

class Konto
{
private:
	double Saldo;

public:
	Konto();
	void Bezahlen(const double& Betrag);
	void Einzahlung(const double& Betrag);
	double Kontostand();
	//void Datei();
};
