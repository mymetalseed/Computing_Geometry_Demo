#include "GeoUtils.h"
#include "Base/Vector.cpp"
#include "Base/Core.h"

double jmk::areaTriangle2d(const Point2d& a,const Point2d& b,const Point2d& c) {
	return 0.5 * ((b[X] - a[X]) * (c[Y] - a[Y]) - (c[X] - a[X]) * (b[Y] - a[Y]));
}

//a��bc���Ĳ�
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
/// ��� c�� ab���Ĳ�
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
/// ���v2v1�Ƿ���v1�������ڽӵ���ɵĽǵ��ڲ�
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
bool jmk::interiorCheck(const Vertex2d* v1, const Vertex2d* v2) {
	//�ж�v1�Ƿ���convex����relex����,vPrev��v1VNext���Ĳ�
	if (jmk::leftOrBeyond(v1->point, v1->next->point, v1->prev->point)) {
		//���,����Ƿ���convex,����: λ��v1v2���ߵ�����
		//v1 is convex vertex
		return jmk::left(v1->point, v2->point, v1->prev->point)
			&& jmk::left(v2->point, v1->point,v1->next->point);
	}
	//�ǰ���,���ж��Ƿ���relex�����������ڶ�����ڲ�
	//������(ȡ�����):  
	//    1. ���v1Next�Ƿ�λ��v1->v2 ���
	//	  2. ͬʱv1Prevλ��v1->v2���ʱ,������relex�������ڶ�����ڲ�������
	//v1 is relex vertex
	return !(jmk::leftOrBeyond(v1->point, v2->point, v1->next->point)
		&& jmk::leftOrBeyond(v2->point, v1->point, v1->prev->point));
}

bool jmk::isDiagonal(const Vertex2d* v1, const Vertex2d* v2, PolygonS2d* poly) {
	bool prospect = true;
	std::vector<Vertex2d*> vertices;

	//�Ȼ�����ж���
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
	//�������еĵ�,�ж��Ƿ����ߺ͵�ǰv1v2���ɵ����ཻ,�о��ཻ����ʧ�� 
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