#include "STRUCT.h"
#include"CreateGraph.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include "QtIntelligentMap.h"

using namespace std;

/**
 * @brief 销毁图（辅助函数），释放所有动态分配的内存
 * @param G 待销毁的图的引用
 * @return Status 成功返回OK（图为空时也返回OK）
 * @note 仅用于CreateGraph创建失败时清理已分配内存，避免内存泄漏
 */
Status DestroyGraph(Graph& G) {
    // 若图已空，直接返回
    if (G.spots == nullptr) {
        return OK;
    }

    // 释放每个地点的路径链表（边节点）
    for (int i = 1; i <= G.spot_count; i++) {
        RoadNode* currentRoad = G.spots[i].firstroad;
        while (currentRoad != nullptr) {
            RoadNode* tempRoad = currentRoad;
            currentRoad = currentRoad->next;
            delete tempRoad; // 释放单个边节点
        }
    }

    // 释放地点数组（顶点节点）
    delete[] G.spots;

    // 重置图状态
    G.spots = NULL;
    G.spot_count = 0;
    G.road_count = 0;

    return OK;
}

/**
 * @brief 初始化图并从"InformationOfMap.txt"读取数据创建邻接表图
 * @param G 待创建的图的引用（传出参数，存储创建后的图数据）
 * @return Status 成功返回OK，失败返回ERROR（含具体错误提示）
 * @note 1. 文件格式：第一行（地点数 路径数）→ N行地点信息 → M行路径信息
 *       2. 地点信息格式：id 名称（可含空格） 描述（可含空格） x坐标 y坐标
 *       3. 路径信息格式：起点id 终点id 路名（不含空格） 距离（米） 是否可通行（1=是/0=否）
 *       4. 地点ID从1开始，最大不超过MSpotNUM（20），且不可重复
 */
Status CreateGraph(Graph& G,int& spotCount,int& pathCount) {
    // 1. 初始化图结构（避免野指针）
    G.spots = nullptr;
    G.spot_count = 0;
    G.road_count = 0;

    // 2. 打开地图信息文件
    ifstream infile("InformationOfMap.txt");
    if (!infile.is_open()) {
        cout << "无法打开地图信息文件：InformationOfMap.txt" << endl;
        return ERROR;
    }

    // 3. 检查文件是否为空
    if (infile.peek() == ifstream::traits_type::eof()) {
        cout << "信息文件为空" << endl;
        infile.close();
        return ERROR;
    }

    // 4. 读取地点数量和路径数量
    int spotNum, roadNum;
    if (!(infile >> spotNum >> roadNum)) {
        cout << "文件格式错误：第一行需输入「地点数量 路径数量」" << endl;
        infile.close();
        return ERROR;
    }

    // 5. 验证地点数量合法性（不超过最大限制MSpotNUM=20，且为正）
    if (spotNum <= 0) {
        cout << "地点数量不合法（需为正整数）" << endl;
        infile.close();
        return ERROR;
    }
    if (spotNum > MSpotNUM) {
        cout << "地点数量超过最大限制（" << MSpotNUM << "）" << endl;
        infile.close();
        return ERROR;
    }

    // new (nothrow)：分配失败时返回NULL
    // 6. 分配地点数组内存（下标0不用，需spotNum+1个空间）
    G.spots = new (nothrow) SpotNode[spotNum + 1];
    if (G.spots == nullptr) {
        cout << "地点内存分配失败" << endl;
        infile.close();
        return ERROR;
    }

    // 7. 初始化地点数组（避免野指针和脏数据）
    for (int i = 0; i <= spotNum; i++) {
        G.spots[i].id = 0;                  // 初始ID为0（未使用）
        G.spots[i].firstroad = nullptr;     // 初始无出边
        memset(G.spots[i].name, 0, sizeof(G.spots[i].name));         // 清空名称
        memset(G.spots[i].description, 0, sizeof(G.spots[i].description)); // 清空描述
        G.spots[i].x = 0;
        G.spots[i].y = 0;
    }

    // 8. 读取所有地点信息
    for (int i = 0; i < spotNum; i++) {
        int spotId;
        // 读取地点ID
        if (!(infile >> spotId)) {
            cout << "读取地点信息失败：第" << i + 1 << "个地点ID缺失" << endl;
            DestroyGraph(G); // 释放已分配内存
            infile.close();
            return ERROR;
        }

        // 验证地点ID合法性（范围+不重复）
        if (spotId < 1 || spotId > spotNum) {
            cout << "地点ID不合法：" << spotId << "（需在1~" << spotNum << "之间）" << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
        if (G.spots[spotId].id != 0) {
            cout << "地点ID重复：" << spotId << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }

        // 赋值地点ID
        G.spots[spotId].id = spotId;

        // 跳过分隔符（读取ID后残留的换行符/空格）
        infile.get();

        // 读取地点名称（允许含空格，最多49个字符）
        infile.getline(G.spots[spotId].name, 50);
        //判断读取是否成功
        if (infile.fail()) {
            cout << "读取地点名称失败，地点ID：" << spotId << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }

        // 读取地点描述（允许含空格，最多199个字符）
        infile.getline(G.spots[spotId].description, 200);
		//判断读取是否成功
        if (infile.fail()) {
            cout << "读取地点描述失败，地点ID：" << spotId << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }

        // 读取地点坐标（x,y为int类型）
        if (!(infile >> G.spots[spotId].x >> G.spots[spotId].y)) {
            cout << "读取地点坐标失败，地点ID：" << spotId << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
    }

    // 9. 读取所有路径信息
    int fromId, toId, canThrough;
    for (int i = 0; i < roadNum; i++) {
        // ========== 原有逻辑：创建 fromId → toId 的正向边 ==========
		//内存分配失败，指针为空
        RoadNode* newRoad = new (nothrow) RoadNode;

        if (newRoad == nullptr) {
            cout << "路径内存分配失败（第" << i + 1 << "条路径）" << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
        // 读取路径核心信息
        if (!(infile >> fromId >> toId >> newRoad->roadName >> newRoad->distance >> canThrough)) {
            cout << "读取路径信息失败，第" << i + 1 << "条路径" << endl;
            delete newRoad;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
        // 验证ID合法性
        if (fromId < 1 || fromId > spotNum || toId < 1 || toId > spotNum) {
            cout << "路径地点ID不合法：起点" << fromId << "，终点" << toId << endl;
            delete newRoad;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
        // 赋值正向边属性
        newRoad->to_id = toId;
		newRoad->ifCanThrough = (canThrough != 0);//0表示无法通行，1表示可以通行
        newRoad->next = nullptr;
        // 头插法插入正向边（fromId → toId）
        newRoad->next = G.spots[fromId].firstroad;
        G.spots[fromId].firstroad = newRoad;

        // ========== 新增逻辑：创建 toId → fromId 的反向边（无向图核心） ==========
        RoadNode* reverseRoad = new (nothrow) RoadNode;
        if (reverseRoad == nullptr) {
            cout << "反向路径内存分配失败（第" << i + 1 << "条路径）" << endl;
            DestroyGraph(G);
            infile.close();
            return ERROR;
        }
        // 反向边属性与正向边一致（路名、距离、可通行状态不变，仅起点和终点互换）
		//将正向边的信息复制到反向边
        strcpy_s(reverseRoad->roadName, sizeof(reverseRoad->roadName), newRoad->roadName);
        
        reverseRoad->distance = newRoad->distance;
        reverseRoad->to_id = fromId; // 反向边的终点是原路径的起点
        reverseRoad->ifCanThrough = newRoad->ifCanThrough; // 可通行状态一致
        reverseRoad->next = nullptr;
        // 头插法插入反向边（toId → fromId）
        reverseRoad->next = G.spots[toId].firstroad;
        G.spots[toId].firstroad = reverseRoad;
    }

    // 10. 赋值图的核心参数
    G.spot_count = spotNum;
    G.road_count = roadNum;

    // 11. 关闭文件，返回成功
    infile.close();
    
	// 向前端传回地点和路径数量参数
	spotCount = G.spot_count;
	pathCount = G.road_count;

    return OK;
}