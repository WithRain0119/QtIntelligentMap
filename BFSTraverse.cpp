#include "STRUCT.h"
#include "SQUEUE.h"
#include <iostream>

//static 保证变量只在本文件内可见
static bool visited[MSpotNUM]={false};

//BFS遍历，打印景点名称和坐标
Status BFSTraverse(Graph G,int v,int* res,int& resnum){
	resnum = 0;
	bool haveRoadToGo = false;
	auto q = G.spots[v].firstroad;
	while (q)
	{
		if (q->ifCanThrough)//如果有一条路可以走
		{
			haveRoadToGo = true;
			break;

		}
		q = q->next;
	}
	if (!haveRoadToGo)//没有路可走
	{

		
		return OK;
	}

	SqQueue Q;
	
	visited[v]=true;
	IniSqueue(Q);
	EnQueue(Q,v);
	while(!isEmpty(Q)){
		int w;
		DeQueue(Q,w);
		for(RoadNode* p=G.spots[w].firstroad;p!=NULL;p=p->next){
			if(p->ifCanThrough==true&&!visited[p->to_id]){
				int m=p->to_id;
				
				res[resnum++] = m;
				visited[m]=true;
				EnQueue(Q,m);
			}
		}
	}
	//重置visited数组，以便下次使用
	for(int i=0;i<MSpotNUM;i++){
		visited[i]=false;
	}
	ReleaseQueue(Q);
	return OK;
}


