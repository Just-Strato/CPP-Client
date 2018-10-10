#pragma once

#include "Color.h"

using namespace std;

/*Repr�sente une forme dessinable.
 *
 *
 */
class Drawable {
protected:
	const Color* color;

public:
	Drawable();
	Drawable(const Color*);
	Drawable(const Drawable&);
	~Drawable();

	const Color getColor() const;

	void setColor(const Color*);

	const Drawable& operator=(const Drawable&);
};



