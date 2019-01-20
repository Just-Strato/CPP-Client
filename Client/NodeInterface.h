#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

/** @brief Classe abstraite repr�sentant un maillon

	Tout maillon repr�sentant un expert de chargement ou d'�criture
	d'une forme dans un fichier devra h�riter de cette classe.
	
*/

class NodeInterface {
private:
	/** @brief Prochain maillon de la chaine. */
	NodeInterface* next = nullptr;

protected:
	
	/** @brief La forme charg� par l'expert. */
	Drawable* drawable  = nullptr;

public:
	/** @brief Constructeur par d�faut. */
	NodeInterface();

	/** @brief Constructeur par maillon. */
	NodeInterface(NodeInterface* ni);

	virtual ~NodeInterface();

	/** @brief Ajout de la forme au format XML dans le fichier. */
	virtual void executeRequest(tinyxml2::XMLDocument& xml) = 0;

	/** @brief Retourne le nom de la forme contenue. */
	virtual const string getDescription() const;

	/** @brief Retourne le maillon suivant. */
	const NodeInterface* getNext() const;

	/** @brief Tentative de reconnaissance de l'expert
		@param str doit �tre le nom du Drawable.
	*/
	bool canInterpret(const string& str) const;

	/** @brief Tentative de reconnaissance par le maillon du document XML. */
	void interact(tinyxml2::XMLDocument& xml);

	/** @brief R�cup�ration de la couleur du fichier XML. */
	shared_ptr<const Color> retrieveColor(tinyxml2::XMLDocument& doc);

	/** @brief R�cup�ration des vertices du fichier XML. */
	virtual const vector<Vector2D> retrieveVertices(tinyxml2::XMLDocument& doc);

	/** @brief R�cup�ration du radius du fichier XML. */
	const double retrieveDoubleProperty(tinyxml2::XMLDocument& doc, const string& prop);
};