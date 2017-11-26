#include "polygon.h"


ModelPolygon::createPolygon(Point* points_array) {
    Edge edge;
    ModelPolygon MP;

    edge.begin = points_array[0];
    edge.end = points_array[2];
    MP.mpolygon.push_back(edge);

    edge.begin = points_array[2];
    edge.end = points_array[3];
    MP.mpolygon.push_back(edge);

    edge.begin = points_array[3];
    edge.end = points_array[1];
    MP.mpolygon.push_back(edge);

    edge.begin = points_array[1];
    edge.end = points_array[0];
    MP.mpolygon.push_back(edge);
}


ShipPolygon::createPolygon(Point* points_array) {
    Edge edge;
    ShipPolygon SP;

    edge.begin = points_array[0];
    edge.end = points_array[2];
    SP.spolygon.push_back(edge);

    edge.begin = points_array[2];
    edge.end = points_array[3];
    SP.spolygon.push_back(edge);

    edge.begin = points_array[3];
    edge.end = points_array[1];
    SP.spolygon.push_back(edge);

    edge.begin = points_array[1];
    edge.end = points_array[0];
    SP.spolygon.push_back(edge);
}


