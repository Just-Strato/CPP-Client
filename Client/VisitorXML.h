#pragma once

#include "Visitor.h"
#include "ShapeManager.h"

/**
	@brief Fonctionnalit� du DP Visieur.

	Cr�e une string en XML d�crivant un Shape.
*/
class VisitorXML : public Visitor {
private:
	/** @brief Retourne un Vector2D au format XML. */
	string strVector(const Vector2D&) const;

	/** @brief Retourne une Color au format XML. */
	string strColor(const shared_ptr<const Color>&) const;

	/** @brief Retourne sous forme XML en ajoutant les param�tres. */
	string  strXML(const shared_ptr<Shape> vs, const string& param) const;

	template<class T>
	static string makeMarkup(const string& tagName, T value) {
		stringstream result;
		result << "<" << tagName << ">" << value << "</" << tagName << ">";
		return result.str(); 
	}

public:
	string visit(const shared_ptr<Shape> vs) const;

	string visit(const shared_ptr<Circle> vs) const;

	string visit(const shared_ptr<shape::Rectangle> vs) const;

	string visit(const shared_ptr<ShapeGroup> vs) const;

	string visit(const shared_ptr<ShapeManager> vs) const;
};