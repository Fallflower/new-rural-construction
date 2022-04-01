
#ifndef __ADJEDGENODE_H_
#define __ADJEDGENODE_H_

#include "CountryNode.h"
using namespace std;

//#pragma execution_character_set("utf-8")

struct AdjEdgeNode
{
//
    bool tag;               // 标记域，标记该边是否被处理或被搜索过
    int weight;          // 存储边权值
    int adjvex1, adjvex2;   // 存储改变相连顶点的序号
    AdjEdgeNode *nextEdge1, *nextEdge2; //分别保存两个顶点除本边之外的相连的下一条边

//
    AdjEdgeNode(bool Tag = false, int Weight = 0, int v1 = 0, int v2 = 0, AdjEdgeNode *e1 = NULL, AdjEdgeNode *e2 = NULL);
    AdjEdgeNode(int v1, int v2, int w, AdjEdgeNode *e1 = NULL, AdjEdgeNode *e2 = NULL);
    AdjEdgeNode(const AdjEdgeNode &copy);
    ~AdjEdgeNode();


    AdjEdgeNode &operator=(const AdjEdgeNode &copy);
};

AdjEdgeNode::AdjEdgeNode(bool Tag, int Weight, int v1, int v2, AdjEdgeNode *e1, AdjEdgeNode *e2)
{
    tag = Tag;
    weight = Weight;
    adjvex1 = v1;
    adjvex2 = v2;
    nextEdge1 = e1;
    nextEdge2 = e2;
}

AdjEdgeNode::AdjEdgeNode(int v1, int v2, int w,AdjEdgeNode *e1, AdjEdgeNode *e2)
{
    tag = false;
    weight = w;
    adjvex1 = v1;
    adjvex2 = v2;
    nextEdge1 = e1;
    nextEdge2 = e2;
}

AdjEdgeNode::AdjEdgeNode(const AdjEdgeNode &copy)
{
    tag = copy.tag;
    weight = copy.weight;
    adjvex1 = copy.adjvex1;
    adjvex2 = copy.adjvex2;
    nextEdge1 = copy.nextEdge1;
    nextEdge2 = copy.nextEdge2;
}

AdjEdgeNode::~AdjEdgeNode()
{
    if(nextEdge1 != NULL)
        delete[] nextEdge1;
    if(nextEdge2 != NULL)
        delete[] nextEdge2;
}
AdjEdgeNode & AdjEdgeNode::operator=(const AdjEdgeNode &copy)
{
    tag = copy.tag;
    weight = copy.weight;
    adjvex1 = copy.adjvex1;
    adjvex2 = copy.adjvex2;
    nextEdge1 = copy.nextEdge1;
    nextEdge2 = copy.nextEdge2;
    return (*this);
}

#endif