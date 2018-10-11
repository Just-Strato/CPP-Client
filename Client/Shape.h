#pragma once

#include <vector>
#include "Drawable.h"

using namespace std;

class Shape : public Drawable {
private:
	vector<Vector2D> vertices;

public:
	Shape();
	Shape(vector<Vector2D, allocator<Vector2D>>&, const Color*);
	~Shape();

	const vector<Vector2D> getVertices() const;

	void setVertices(const vector<Vector2D>&);

	bool operator==(const Shape&) const;

	//Transformations géométriques
	void Translate(const Vector2D);
	void Scale(const Vector2D, const double);
	void Rotate(const Vector2D, const double);
};