#include "Vector.h"

jmk::Vector3f jmk::crossProduct3d(Vector3f a, Vector3f b)
{
	float x_, y_, z_;
	x_ = a[Y] * b[Z] - b[Y] * a[Z];
	y_ = -(b[Z] * a[X] - a[Z] * b[X]);
	z_ = a[X] * b[Y] - b[X] * a[Y];

	return Vector3f(x_, y_, z_);
}

float jmk::crossProduct2d(Vector2f a, Vector2f b)
{
	return 0.0f;
}

float jmk::scalerTripleProduct(Vector3f a, Vector3f b, Vector3f c)
{
	Vector3f b_cross_c = crossProduct3d(b, c);
	float value = dotProduct(a, b_cross_c);
	return value;
}

bool jmk::orthogonal(Vector3f a, Vector3f b)
{
	float value = dotProduct(a, b);
	return isEqualD(value, 0.0);
}

jmk::Vector2f jmk::prependicluar(Vector2f& vec)
{
	return Vector2f(vec[Y], -vec[X]);
}
