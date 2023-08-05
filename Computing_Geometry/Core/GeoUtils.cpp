#include "GeoUtils.h"
#include "Base/Vector.cpp"
#include "Base/Core.h"

double jmk::areaTriangle2d(const Point2d& a,const Point2d& b,const Point2d& c) {
	return 0.5 * ((b[X] - a[X]) * (c[Y] - a[Y]) - (c[X] - a[X]) * (b[Y] - a[Y]));
}

//a在bc的哪侧
int jmk::orientation2d(const Point2d& a, const Point2d& b, const Point2d& c) {
	auto area = areaTriangle2d(a, b, c);
	if (area > 0 && area < TOLERENCE) 
		area = 0;
	if (area < 0 && area > TOLERENCE)
		area = 0;

	Vector2f ab = b - a;
	Vector2f ac = c - a;

	if (area > 0)
		return LEFT;

	if (area < 0)
		return RIGHT;

	if ((ab[X] * ac[X] < 0) || (ab[Y] * ac[Y] < 0)) {
		return BEHIND;
	}

	if (ab.magnitude() < ac.magnitude()) {
		return BEYOND;
	}

	if (a == c)
		return ORIGIN;
	if (b == c)
		return DESTINATION;


	return BETWEEN;
}

bool jmk::left(const Point2d& a, const Point2d& b, const Point2d& c)
{
	return orientation2d(a, b, c) == RELATIVE_POSITION::LEFT;
}

/// <summary>
/// 检测 c在 ab的哪侧
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns></returns>
bool jmk::leftOrBeyond(const Point2d& a, const Point2d& b, const Point2d& c)
{
	int position = orientation2d(a, b, c);
	return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}

/// <summary>
/// 检查v2v1是否在v1的三个邻接点组成的角的内部
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
bool jmk::interiorCheck(const Vertex2d* v1, const Vertex2d* v2) {
	//判定v1是否是convex或者relex顶点,vPrev在v1VNext的哪侧
	if (jmk::leftOrBeyond(v1->point, v1->next->point, v1->prev->point)) {
		//左侧,检测是否是convex,性质: 位于v1v2连线的两侧
		//v1 is convex vertex
		return jmk::left(v1->point, v2->point, v1->prev->point)
			&& jmk::left(v2->point, v1->point,v1->next->point);
	}
	//是凹角,则判断是否在relex条件下满足在多边形内部
	//不满足(取反结果):  
	//    1. 检查v1Next是否位于v1->v2 左侧
	//	  2. 同时v1Prev位于v1->v2左侧时,不满足relex条件下在多边形内部的条件
	//v1 is relex vertex
	return !(jmk::leftOrBeyond(v1->point, v2->point, v1->next->point)
		&& jmk::leftOrBeyond(v2->point, v1->point, v1->prev->point));
}

bool jmk::isDiagonal(const Vertex2d* v1, const Vertex2d* v2, PolygonS2d* poly) {
	bool prospect = true;
	std::vector<Vertex2d*> vertices;

	//先获得所有顶点
	if (poly)
		vertices = poly->getVertices();
	else {
		auto vertex_ptr = v1->next;
		vertices.push_back((Vertex2d*)v1);
		while (vertex_ptr != v1) {
			vertices.push_back(vertex_ptr);
			vertex_ptr = vertex_ptr->next;
		}
	}
	//遍历所有的点,判断是否有线和当前v1v2构成的线相交,有就相交测试失败 
	Vertex2d* current, * next;
	current = vertices[0];
	do {
		next = current->next;
		if (current != v1 && next != v1 && current != v2 && next != v2
			&& jmk::Intersection(v1->point, v2->point, current->point, next->point)) {
			prospect = false;
			break;
		}
		current = next;
	} while (current != vertices[0]);


	return prospect && interiorCheck(v1,v2) && interiorCheck(v2,v1);
}

bool jmk::Intersection(const jmk::Point2d& a, const jmk::Point2d& b, const jmk::Point2d& c,
	const jmk::Point2d& d) {
	auto ab_c = jmk::orientation2d(a, b, c);
	auto ab_d = jmk::orientation2d(a, b, d);
	auto cd_a = jmk::orientation2d(c, d, a);
	auto cd_b = jmk::orientation2d(c, d, b);
	
	if (ab_c == BETWEEN || ab_c == ORIGIN || ab_c == DESTINATION
		|| ab_d == BETWEEN || ab_d == ORIGIN || ab_d == DESTINATION
		|| cd_a == BETWEEN || cd_a == ORIGIN || cd_a == DESTINATION
		|| cd_b == BETWEEN || cd_b == ORIGIN || cd_b == DESTINATION) {
		return true;
	}

	return _xor(ab_c == LEFT, ab_d == LEFT) && _xor(cd_a == LEFT, cd_b == LEFT);
}