#include"STRUCT.h"
#include<iostream>
#define MSpotNUM 20


static bool visited[MSpotNUM]={false};//static保证只在本函数中可以访问
static bool TheFirstOutPut = true;


//换行输出景点名称和坐标,DFS遍历，孤立时输出一行
Status DFS(Graph G,int v,int* res,int& resnum){
    // 跳过起点（因为起点是用户选的，只需要输出可达的景点）
    if (!TheFirstOutPut)//非起点
		res[resnum++] = v;
	else//是起点
        TheFirstOutPut = false;
    
    visited[v]=true;

    RoadNode* p=G.spots[v].firstroad;
   
    while(p!=NULL){
        int w=p->to_id;
        if(!visited[w]&&p->ifCanThrough==true){
            DFS(G,w,res,resnum);
        }
        p=p->next;
    }
    return OK;
}
Status DFSTraverse(Graph G,int v,int* res,int& resnum){
    
	resnum = 0;

   //判断本建筑所有的路是否存在可以走的路
    bool haveRoadToGo = false;
    auto q = G.spots[v].firstroad;
    while (q)
    {
        if (q->ifCanThrough)
        {
            haveRoadToGo = true;
            break;
        }
        q = q->next;
    }
    if(!haveRoadToGo)
    {
        
        return OK;
    }
    
    DFS(G,v,res,resnum);

    //重置visited数组，以便下次使用
    for(int i=0;i<MSpotNUM;i++){
        visited[i]=false;
    }
    //重置表示起点是否输出的变量
    TheFirstOutPut = true;
}
