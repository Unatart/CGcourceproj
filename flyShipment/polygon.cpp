#include "polygon.h"


ModelPolygon::createPolygon(Point* points_array) {
    Edge edge;
    ModelPolygon MP;

    edge.begin = points_array[0];
    edge.end = points_array[2];
    MP.addEdge(edge);

    edge.begin = points_array[2];
    edge.end = points_array[3];
    MP.addEdge(edge);

    edge.begin = points_array[3];
    edge.end = points_array[1];
    MP.addEdge(edge);

    edge.begin = points_array[1];
    edge.end = points_array[0];
    MP.addEdge(edge);
}

ModelPolygon::addEdge(Edge edge) {
    mpolygon.push_back(edge);
}

ShipPolygon::createPolygon(Point* points_array) {
    Edge edge;
    ShipPolygon SP;

    edge.begin = points_array[0];
    edge.end = points_array[2];
    SP.addEdge(edge);

    edge.begin = points_array[2];
    edge.end = points_array[3];
    SP.addEdge(edge);

    edge.begin = points_array[3];
    edge.end = points_array[1];
    SP.addEdge(edge);

    edge.begin = points_array[1];
    edge.end = points_array[0];
    SP.addEdge(edge);
}

ShipPolygon::addEdge(Edge edge) {
    spolygon.push_back(edge);
}

