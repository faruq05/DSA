#ifndef GRAPHTYPE_H_INCLUDED
#define GRAPHTYPE_H_INCLUDED

#include "stacktype.h"
#include "quetype.h"

template <class VertexType>
class GraphType
{
public:
    GraphType();
    GraphType(int maxV);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void AddVertex(VertexType vertex);
    void AddEdge(VertexType fromVertex, VertexType toVertex, int weight);
    int WeightIs(VertexType fromVertex, VertexType toVertex);
    void GetToVertices(VertexType vertex, QueType<VertexType> &adjVertices);
    void ClearMarks();
    void MarkVertex(VertexType vertex);
    bool IsMarked(VertexType vertex);
    void DepthFirstSearch(VertexType startVertex, VertexType endVertex);
    void BreadthFirstSearch(VertexType startVertex, VertexType endVertex);
    int OutDegree(VertexType v);
    bool FoundEdge(VertexType u, VertexType v);

private:
    int numVertices;
    int maxVertices;
    VertexType *vertices;
    int **edges;
    bool *marks;
};

#endif // GRAPHTYPE_H_INCLUDED
