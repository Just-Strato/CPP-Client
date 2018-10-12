#include "stdafx.h"
#include "SingletonSocket.h"

//Aucune instance n'est actuellement cr��e
bool SingletonSocket::isCreated = false;

//Il faut d�clarer instance dans le .cpp
SingletonSocket SingletonSocket::instance;

SingletonSocket::SingletonSocket() {
	//Empeche une 2eme instance du singleton.
	if (isCreated) throw logic_error("Vous ne pouvez pas cr�er une seconde instance de la classe Singleton.");
	
	//Initialisation de la librairie Winsock2
	int r;
	WSADATA wsaData;
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw - 1;

	//Initialisation du socket
	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;

		// pour les valeurs renvoy�es par WSAGetLastError() : 
		// cf. doc r�f winsock

		throw -2;
	}

	//Affectation de la variable singleton
	instance = *this;

	//La variable est cr��e
	isCreated = true;
}

SingletonSocket::~SingletonSocket() {
	isCreated = false;
}

SingletonSocket& SingletonSocket::getInstance() { 
	if (!isCreated) SingletonSocket();
	return instance; 
}

const SOCKET SingletonSocket::getSocket() const { return sock; }

bool SingletonSocket::operator==(const SOCKET& socket) const { return sock == socket; }