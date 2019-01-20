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
	
	Drawable* drawable  = nullptr;

public:
	NodeInterface();
	NodeInterface(NodeInterface* ni);
	virtual ~NodeInterface();
	virtual void executeRequest(tinyxml2::XMLDocument& xml) = 0;
	virtual const string getDescription() const;

	const NodeInterface* getNext() const;
	bool canInterpret(const string& str) const;
	void interact(tinyxml2::XMLDocument& xml);

	shared_ptr<const Color> retrieveColor(tinyxml2::XMLDocument& doc);
	virtual const vector<Vector2D> retrieveVertices(tinyxml2::XMLDocument& doc);
	const double retrieveDoubleProperty(tinyxml2::XMLDocument& doc, const string& prop);
};