#ifndef STRUCT_H
#define STRUCT_H



#define OK 1
#define ERROR 0
typedef int Status;
#define MQUEUESIZE 20
#define MSpotNUM 20

/* 路径节点（邻接表的边节点） */
typedef struct RoadNode {
    int to_id;                // 目标地点ID，从1开始
    char roadName[20];       //这条路的名字  
    double distance;            // 距离
    bool ifCanThrough;       //这条路能不能走，出现施工的情况，就走不了，默认可以走,当出现特殊情况就走不了。
    struct RoadNode* next;   // 下一条路径
} RoadNode;

/* 地点节点（邻接表的顶点节点） *///每个地点都包括什么内容
typedef struct SpotNode {
    int id;                  // 景点ID
    char name[50];          // 景点名称
    char description[200];   // 景点描述
    int x, y;               // 地图坐标
    RoadNode* firstroad;   // 第一条出边
} SpotNode;

/* 图结构体（邻接表） */
typedef struct {
    SpotNode* spots;     //采用顺序表结构存储各个地点，需要spot_count+1个位置，下标0不用，使用new 进行分配内存
    int spot_count, road_count;          // 景点数量  路径数量   
} Graph;



#endif//STRUCT_H