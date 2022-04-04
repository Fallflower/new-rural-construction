/*
 * @Author: Metaphor
 */
#ifndef __ADJMULTLISTNETWORK_H_
#define __ADJMULTLISTNETWORK_H_

#include "AdjVexNode.h"
#include <fstream>

//#pragma execution_character_set("utf-8")
#define DEFAULTSIZE 1000

using namespace std;

class AdjMultListNetwork
{
private:
    AdjVexNode *vexTable;
    int vexNum;
    int vexMaxNum;
    int edgeNum;

protected:
//
    void Clear();   // 删除边
    void IfValid(int v1, int v2);
    void HelpCreateInsert(int v1, int v2, const int &w);

public:
//
    AdjMultListNetwork(int MaxNum = DEFAULTSIZE );
    AdjMultListNetwork(const string& filename);
    ~AdjMultListNetwork();

    bool IsEmpty() const;
    void display() const;

    void InsertEdge(int v1, int v2, const int &w);
};


void AdjMultListNetwork::IfValid(int v1, int v2)
{
    if (v1 < 0 || v1 >=vexNum)
        cerr << "Invalid input of v1" << endl;
    if (v2 < 0 || v2 >=vexNum)
        cerr << "Invalid input of v2" << endl;
    if (v1 == v2)
        cerr << "Error: v1 equals to v2" << endl;
}

void AdjMultListNetwork::Clear()
{
    for (int i = 0; i < vexNum; i++)
    {
        AdjEdgeNode *p = vexTable[i].GetFirstEdge();
        if (p != NULL)
            delete[] p;
    }
}

void AdjMultListNetwork::HelpCreateInsert(int v1, int v2, const int &w)
{
    AdjEdgeNode *p = vexTable[v1].GetFirstEdge();
    AdjEdgeNode *q = vexTable[v2].GetFirstEdge();
    vexTable[v1].firstEdge = vexTable[v2].firstEdge = new AdjEdgeNode(v1, v2, w, p, q);
    edgeNum++;
}

AdjMultListNetwork::AdjMultListNetwork(int MaxNum)
{
    vexMaxNum = MaxNum;
    vexTable = new AdjVexNode[vexMaxNum];
    vexNum = 0;
    edgeNum = 0;
}

AdjMultListNetwork::AdjMultListNetwork(const string& filename)
{
    ifstream infile;
    infile.open(filename);
    if(!infile) //如果失败，请输入文件绝对路径
        cerr << "Open file: " << filename << " failed!" << endl;
    vexMaxNum = DEFAULTSIZE;
    vexTable = new AdjVexNode[vexMaxNum];
    infile >> vexNum;
    edgeNum = 0;
    // cout << vexNum << endl;
    for (int i = 0; i < vexNum; i++)
    {
        CountryNode p;
        infile >> p.name >> p.population;
        //cout << p << endl;
        vexTable[i] = AdjVexNode(p);
    }
    for (int i = 0; i < vexNum; i++)
        for (int j = 0; j < vexNum; j++)
        {
            int m;infile >> m;
            //cout << m << endl;
            if (i < j)
                HelpCreateInsert(i,j,m);
        }
    infile.close();
    //cout << vexNum << endl;
}

AdjMultListNetwork::~AdjMultListNetwork()
{
    Clear();
    if(vexTable!=NULL)
        delete[] vexTable;
}

bool AdjMultListNetwork::IsEmpty() const
{
    return (vexNum == 0);
}

void AdjMultListNetwork::display() const
{//以邻接表的方式输出邻接多重表
    AdjEdgeNode *p;
    cout << "无向网共有" << vexNum << "个顶点，" << edgeNum << "条边。" << endl; 
	for (int v = 0; v < vexNum; v++)	{	// 显示第v个邻接链表
		cout << v << ":\t" << vexTable[v].country;				// 显示顶点号
	    p = vexTable[v].firstEdge;
	    while (p != NULL) {

            if (v == p->adjvex1)
            {
                cout << "-->(" << p->adjvex2 << "," << p->weight << ")";
                p = p->nextEdge1;
            }
            else
            {
                cout << "-->(" << p->adjvex1 << "," << p->weight << ")";
                p = p->nextEdge2;
            }
        }
		cout << endl; 
	}
}

void AdjMultListNetwork::InsertEdge(int v1, int v2, const int &w)
{
    IfValid(v1, v2);
    AdjEdgeNode *p = vexTable[v1].GetFirstEdge();
    AdjEdgeNode *q = vexTable[v2].GetFirstEdge();
    AdjEdgeNode *t;
    if ((t = p) != NULL)
    {
        for (; t->nextEdge1 != NULL; t = t->nextEdge1)
            if((t->adjvex1 == v1 && t->adjvex2 == v2)
            || (t->adjvex1 == v2 && t->adjvex2 == v1))
            {// 若边已存在则更新其权重
                t->weight = w;
                return;
            }
    }
    vexTable[v1].firstEdge = vexTable[v2].firstEdge = new AdjEdgeNode(v1, v2, w, p, q);
    edgeNum++;
}


#endif