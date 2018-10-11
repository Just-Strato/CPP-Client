#include "stdafx.h"
#include "Shape.h"

Shape::Shape() : Drawable() {
	vertices = {};
}

Shape::Shape(vector<Vector2D, allocator<Vector2D>>& v, const Color* c) : Drawable(c) {
	vertices = v;
}

Shape::~Shape() {
}

const vector<Vector2D> Shape::getVertices() const { return vertices; }

void Shape::setVertices(const vector<Vector2D>& v) { vertices = v; }

bool Shape::operator==(const Shape& s) const {
	return Drawable::operator==(s) && (vertices == s.vertices);
}

void Shape::Translate(const Vector2D V) {
	for (auto &vertice : vertices) {
		vertice.setX(std::round( vertice.getX() + V.getX() ));
		vertice.setY(std::round( vertice.getY() + V.getY() ));
	}
}

void Shape::Scale(const Vector2D point, const double ratio) {
	for (auto &vertice : vertices) {
		vertice.setX(std::round( (vertice.getX() - point.getX()) * ratio ));
		vertice.setY(std::round( (vertice.getY() - point.getY()) * ratio ));
	}
}

void Shape::Rotate(const Vector2D point, const double rad) {
	for (auto &vertice : vertices) {
		double newX = std::round((vertice.getX() - point.getX()) * cos(rad) - (vertice.getY() - point.getY()) * sin(rad));
		double newY = std::round((vertice.getX() - point.getX()) * sin(rad) + (vertice.getY() - point.getY()) * cos(rad));
		vertice.setX(newX);
		vertice.setY(newY);
	}
}
