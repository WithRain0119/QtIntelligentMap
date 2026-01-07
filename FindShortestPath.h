#ifndef FIND_SHORTEST_PATH_H
#define FIND_SHORTEST_PATH_H
#include "QtIntelligentMap.h"

#include "STRUCT.h"

/**
 * @brief 查询任意两个景点之间的最短路径（Dijkstra算法）
 * @param G 已创建的图（const引用，只读）
 * @return Status 成功返回OK，输入不合法返回ERROR
 */
Status FindShortestPath(const Graph& G,int  currentStartSpotId, int currentEndSpotId, int currentVehicle, Ui::QtIntelligentMapClass* ui, char* respath, int& pathCount);

#endif // FIND_SHORTEST_PATH_H
