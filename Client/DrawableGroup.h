#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"

using namespace std;

/**
	@brief Repr�sente un ensemble de Drawable.
	
	Un Drawable est une collection de Drawable. 
*/
class DrawableGroup {
protected:
	/** @brief La liste des formes. */
	vector<shared_ptr<Drawable>> shapes;

public:
	/** @brief Destructeur de DrawableGroup. */
	virtual ~DrawableGroup();

	/** @brief Accesseur pour shapes. */
	const vector<shared_ptr<Drawable>>& getShapes() const;

	/** @brief Supprime l'�l�ment i variant de 0 � size-1. */
	virtual void Delete(int i);

	/** @brief Supprime l'�l�ment de shapes. */
	virtual void Delete(shared_ptr<Drawable>);

	/** @brief Ajout d'un Drawable. */
	void add(shared_ptr<Drawable> drawable);

	/** @brief Surcharge de l'op�rateur ==. */
	bool operator==(const shared_ptr<Drawable> shapeGroup) const;

	/** @brief Surcharge de l'op�rateur string. */
	operator string() const;
};