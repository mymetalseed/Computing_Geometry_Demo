#pragma once
#include "../Core/Primitive/Polygon.h"
#include "../Core/GeoUtils.h"

void Triangulate_earclipping(PolygonS2d* poly, std::vector<Edge2d>& edge_list);