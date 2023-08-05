#pragma once 
#include "../Base/Vector.h"
#include "Point.h"

#include <list>
#include <vector>

template<class T,size_t dim>
struct Vertex {
	jmk::Vector<T, dim> point;
	Vertex* next;
	Vertex* prev;
	bool is_ear = false;
	bool is_processed = false;

	Vertex(jmk::Vector<T, dim>& _point, Vertex<T, dim>* _next, Vertex<T, dim>* _prev)
	:point(_point), next(_next), prev(_prev),
	{

	}
};

typedef Vertex<float, DIM2> Vertex2d;
typedef Vertex<float, DIM3> Vertex3d;

template<class T,size_t dim = DIM3>
class Polygon {
	std::vector<Vertex<T, dim>*> vertext_list;
public:
	Polygon(std::list<jmk::Vector<T, dim>>& points) {
		const int size = points.size();

		if (size < 3) {
			std::cout << "Not enough points to construct a polygon";
			return;
		}

		//1. 将顶点加入到定点列表
		for (auto _point : points) {
			vertext_list.push_back(new Vertex(_point));
		}

		//2. 每个顶点连接到下一个顶点(双向链表)
		for (size_t i = 0; i < size; ++i) {
			vertext_list[i].next = &vertext_list[(i + 1) % size];
			
			if (i != 0) {
				vertext_list[i].prev = &vertext_list[i - 1];
			}
			else {
				vertext_list[i].prev = &vertext_list[size - 1];
			}
		}
	}

	std::vector<Vertex<T, dim>*> getVertices() {
		return vertext_list;
	}
};

typedef Polygon<float, DIM3> PolygonS3d;
typedef Polygon<float, DIM2> PolygonS2d;

template<class T,size_t dim>
struct Edge {
	Vertex<T, dim> v1;
	Vertex<T, dim> v2;

	Edge(Vertex<T,dim> _v1,Vertex<T,_dim> _v2) : v1(_v1),v2(_v2){
	}
};
typedef Edge<float, DIM2> Edge2d;