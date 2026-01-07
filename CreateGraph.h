#ifndef CREATEGRAPH_H
#define CREATEGRAPH_H

// 包含依赖头文件，确保Status、Graph类型可识别
#include "STRUCT.h"
#include "QtIntelligentMap.h"

// 声明DestroyGraph函数
Status DestroyGraph(Graph& G);

// 声明CreateGraph函数
Status CreateGraph(Graph&,int& spotCount,int& pathCount);

#endif // CREATEGRAPH_H