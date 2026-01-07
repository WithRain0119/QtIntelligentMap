#include "STRUCT.h"
#include "FindShortestPath.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip> // 非STL，用于格式控制（允许保留）
#include "QtIntelligentMap.h"

using namespace std;

/**
 * @brief 查询任意两个景点之间的最短路径（Dijkstra算法实现，无STL依赖）
 * @param G 已创建好的图（const引用，避免拷贝且保证只读）
 * @return Status 成功返回OK，输入不合法返回ERROR
 */
 // G=地图，currentStartSpotId=起点ID，currentEndSpotId=终点ID，currentVehicle=交通工具，respath=存经过的道路名，pathCount=道路数量
Status FindShortestPath(const Graph& G, int currentStartSpotId, int currentEndSpotId, int currentVehicle , Ui::QtIntelligentMapClass* ui,char* respath,int& pathCount) {


    if (currentStartSpotId == currentEndSpotId) {
        cout << "提示：起点与终点相同，无需路径！" << endl;
        ui->textEdit_print->append("起点与终点相同，无需路径！");
        return OK;
    }

    // ========== 3. 初始化Dijkstra算法所需数组（无STL，用基础数组） ==========
    const double INF = 1e9; // 代表“无穷大”（不可达）
    double dist[MSpotNUM + 1];    // 各节点到起点的最短距离
    bool visited[MSpotNUM + 1];   // 标记节点是否已确定最短路径
    int preNode[MSpotNUM + 1];    // 记录路径的前驱节点ID
    char preRoad[MSpotNUM + 1][20];// 记录前驱节点对应的路名（二维字符数组，无string）

    // 初始化数组
    for (int i = 1; i <= G.spot_count; ++i) {
        dist[i] = INF;
        visited[i] = false;
        preNode[i] = 0;
        memset(preRoad[i], 0, sizeof(preRoad[i])); // 清空路名
    }
    dist[currentStartSpotId] = 0; // 起点到自身的距离为0

    // ========== 4. 执行Dijkstra算法（无STL，逻辑不变） ==========
    for (int i = 1; i <= G.spot_count; ++i) {
        // 4.1 找到“未访问且距离起点最近”的节点u
        int u = -1;
        double minDist = INF;
        for (int j = 1; j <= G.spot_count; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 无更多可达节点，提前结束
        visited[u] = true;

        // 4.2 遍历u的邻接链表，更新邻接节点的距离
        const RoadNode* p = G.spots[u].firstroad;
        while (p != nullptr) {
            int v = p->to_id;
            // 仅处理“未访问、路可通行”的节点
            if (!visited[v] && p->ifCanThrough) {
                if (dist[v] > dist[u] + p->distance) {
                    dist[v] = dist[u] + p->distance;
                    preNode[v] = u;
                    strcpy_s(preRoad[v], p->roadName); // 复制路名（cstring，非STL）
                }
            }
            p = p->next;
        }
    }

    // ========== 5. 检查是否存在可达路径 ==========
    if (dist[currentEndSpotId] == INF) {
        cout << "结果：从起点到终点无可达路径（可能存在断路/施工）！" << endl;
		ui->textEdit_print->append("从起点到终点无可达路径（可能存在断路/施工）！");
        return OK;
    }

    // ========== 6. 回溯前驱节点，生成路径（用动态数组替代vector，无STL） ==========
    int pathNodeCount = 0; // 记录路径节点总数
    // 临时数组存储逆序路径（最大长度为MSpotNUM，避免越界）
    int tempPathNodes[MSpotNUM + 1];
    char tempPathRoads[MSpotNUM + 1][20];
    double tempPathDistances[MSpotNUM + 1]; // 新增：存储每条路的距离
    memset(tempPathNodes, 0, sizeof(tempPathNodes));
    memset(tempPathDistances, 0, sizeof(tempPathDistances));
    for (int i = 0; i <= MSpotNUM; ++i) {
        memset(tempPathRoads[i], 0, sizeof(tempPathRoads[i]));
    }

    // 从终点回溯到起点，存入临时数组（逆序）
    int current = currentEndSpotId;
    while (current != currentStartSpotId) {
        tempPathNodes[pathNodeCount] = current;
        strcpy_s(tempPathRoads[pathNodeCount], preRoad[current]);

        // 关键优化：通过前驱节点直接定位路径距离
        int fromNode = preNode[current]; // 前驱节点（来源节点）
        RoadNode* p = G.spots[fromNode].firstroad;
        while (p) {
            if (p->to_id == current && strcmp(p->roadName, preRoad[current]) == 0) {
                tempPathDistances[pathNodeCount] = p->distance; // 记录距离
                break;
            }
            p = p->next;
        }

        current = preNode[current];
        pathNodeCount++;
        // 防止路径过长超出最大限制
        //按照最小生成树的样子，路个数 < 建筑物个数,最大情况为路个数 = 建筑物个数 - 1  
        if (pathNodeCount >= MSpotNUM) {
            ui->textEdit_print->append("错误：路径长度超出最大限制！");
            cout << "错误：路径长度超出最大限制！" << endl;
            return ERROR;
        }
    }//while循环

    // 存入起点
    tempPathNodes[pathNodeCount] = currentStartSpotId;
    pathNodeCount++;


    // ========== 8. 选择交通工具并计算时间 ==========
    double speed = 1.00; // 单位：m/s
   
    /*cout << "\n请选择交通工具：" << endl;
    cout << "1. 步行（速度：1m/s）" << endl;
    cout << "2. 自行车（速度：5m/s）" << endl;
    cout << "3. 小汽车（速度：10m/s）" << endl;
    cout << "输入选项（1-3）：";*/
    //cin >> choice;

    switch (currentVehicle) {
    case 1: speed = 1; break;
    case 2: speed = 5; break;
    case 3: speed = 10; break;
    default:
        cout << "选项无效，默认选择步行！" << endl;
		ui->textEdit_print->append("选项无效，默认选择步行！");
        speed = 1;
    }

    // ========== 9. 输出路径与耗时（无STL，正常输出） ==========
    //cout << "\n===== 最短路径结果 =====" << endl;
	ui->textEdit_print->append("\n===== 最短路径结果 =====");
    //cout << fixed << setprecision(2); // 输出保留2位小数
    
    // 输出起点（耗时0）
    //cout << G.spots[tempPathNodes[pathNodeCount - 1]].name << "(0.00min)";

    //最终输出的文本
	QString outputText = QString::fromStdString(G.spots[currentStartSpotId].name) + QString::fromStdString("(0.00min)");

    

    // 输出中间节点+路名 + 路长+耗时
    for (int i = pathNodeCount - 2; i >= 0; --i) {
        // 计算到当前节点的累计耗时（分钟）：距离/速度 ÷ 60
        double currentTime = (dist[tempPathNodes[i]] / speed) / 60;
		
        outputText += ("->" + QString::fromStdString(tempPathRoads[i]) + "路("+ QString::number(tempPathDistances[i],'f', 2) + "米)->" + QString::fromStdString(G.spots[tempPathNodes[i]].name) + "(" + QString::number(currentTime, 'f', 2) + "min)");
		
        respath[pathCount++] = tempPathRoads[i][0]; //记录经过的路
    }

	//输出路径过程
    ui->textEdit_print->append(outputText);

    // 输出总信息
    double totalTime = (dist[currentEndSpotId] / speed) / 60;
    
	ui->textEdit_print->append("\n总距离：" + QString::number(dist[currentEndSpotId], 'f', 2) + "米 | 总耗时：" + QString::number(totalTime, 'f', 2) + "分钟");

    return OK;
}