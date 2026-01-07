#include "QtIntelligentMap.h"
#include <QButtonGroup>
#include <iostream>
#include "BFSTRAVERSE.h"
#include "CreateGraph.h"
#include "DFSTRAVERSE.h"
#include "FindShortestPath.h"


//用来存放道路线条的数组，然后进行变化颜色的操作
#define ROAD_NUM 20
#define MAX_LINE 10 // 一条路最多 10 根线
QFrame* roadLines[ROAD_NUM][MAX_LINE];//第一个下标存的是这个道路的序号，第二个下标存的是对应道路序号的所有线条道路
int roadLineCount[ROAD_NUM];//存放每条道路对应的线条数量

Graph G;

QtIntelligentMap::QtIntelligentMap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtIntelligentMapClass())
{
    ui->setupUi(this);
	
    InitUI();
	initRoadLines();
}

QtIntelligentMap::~QtIntelligentMap()
{
    delete ui;
}

//最短路径功能所需变量
char* respath = NULL;//经过的路径
int pathCount = 0;

//当前状态变量
int currentEndSpotId = -1;
int currentStartSpotId = -1;
int currentSpotId = -1;
int currentVehicle = -1;

//表示当前为那个功能
static int mode = -1;

//初始化映射每个道路分别对应的线条 a-q
void  QtIntelligentMap::initRoadLines() 
{
	roadLines['a' - 'a'][0] = ui->line_a1;
	roadLineCount['a' - 'a'] = 1;

	roadLines['b' - 'a'][0] = ui->line_b1;
	roadLines['b' - 'a'][1] = ui->line_b2;
	roadLineCount['b' - 'a'] = 2;

	roadLines['c' - 'a'][0] = ui->line_c1;
	roadLineCount['c' - 'a'] = 1;

	roadLines['d' - 'a'][0] = ui->line_d1;
	roadLines['d' - 'a'][1] = ui->line_d2;
	roadLineCount['d' - 'a'] = 2;

	roadLines['e' - 'a'][0] = ui->line_e1;
	roadLines['e' - 'a'][1] = ui->line_e2;
	roadLineCount['e' - 'a'] = 2;

	roadLines['f' - 'a'][0] = ui->line_f1;
	roadLines['f' - 'a'][1] = ui->line_f2;
	roadLineCount['f' - 'a'] = 2;

	roadLines['g' - 'a'][0] = ui->line_g1;
	roadLineCount['g' - 'a'] = 1;

	roadLines['h' - 'a'][0] = ui->line_h1;
	roadLines['h' - 'a'][1] = ui->line_h2;
	roadLineCount['h' - 'a'] = 2;

	roadLines['i' - 'a'][0] = ui->line_i1;
	roadLines['i' - 'a'][1] = ui->line_i2;
	roadLineCount['i' - 'a'] = 2;

	roadLines['j' - 'a'][0] = ui->line_j1;
	roadLineCount['j' - 'a'] = 1;

	roadLines['k' - 'a'][0] = ui->line_k1;
	roadLineCount['k' - 'a'] = 1;

	roadLines['l' - 'a'][0] = ui->line_l1;
	roadLineCount['l' - 'a'] = 1;

	roadLines['m' - 'a'][0] = ui->line_m1;
	roadLines['m' - 'a'][1] = ui->line_m2;
	roadLineCount['m' - 'a'] = 2;

	roadLines['n' - 'a'][0] = ui->line_n1;
	roadLines['n' - 'a'][1] = ui->line_n2;
	roadLineCount['n' - 'a'] = 2;

	roadLines['o' - 'a'][0] = ui->line_o1;
	roadLineCount['o' - 'a'] = 1;

	roadLines['p' - 'a'][0] = ui->line_p1;
	roadLines['p' - 'a'][1] = ui->line_p2;
	roadLineCount['p' - 'a'] = 2;

	roadLines['q' - 'a'][0] = ui->line_q1;
	roadLineCount['q' - 'a'] = 1;
}

//设置道路颜色
void QtIntelligentMap::setRoadColor(char roadName, QString color)
{


	if (roadName < 'a' || roadName > 'q')
		return;

	int roadId = roadName - 'a';

	for (int i = 0; i < roadLineCount[roadId]; i++) {
		roadLines[roadId][i]->setStyleSheet(
			"background-color:" + color + ";"
		);
	}
}

void QtIntelligentMap::InitUI()
{
	int spotcount = 0,pathcount = 0;

	CreateGraph(G,spotcount,pathcount);
	
	ui->textEdit_print->setText("地图加载成功\n");
	ui->textEdit_print->append(QString::fromStdString("读取的地点数量：" + std::to_string(spotcount)));
	ui->textEdit_print->append(QString::fromStdString("读取的路径数量：" + std::to_string(pathcount)));
    
	//1、找到所有按钮，并放到一个按钮组中
	auto buttonGroup = new QButtonGroup(this);
	auto btnList = findChildren<QPushButton*>();
	for (auto btn : btnList)
	{
		buttonGroup->addButton(btn);
	}

	//关联按钮组的点击信号
	connect(buttonGroup, &QButtonGroup::buttonClicked, this, &QtIntelligentMap::onButtonClicked);

}

//点击按钮将会触发这个函数
void QtIntelligentMap::onButtonClicked(QAbstractButton* btn)
{
	//获取按钮的文本内容
	QString name = btn->text();

	//将所有变化过颜色的路线的颜色重置,如果这个函数触发说明已经通过运行最短路径功能变化过颜色
	if (respath)
	{

		for (int i = 0;i < pathCount;i++)
		{
			setRoadColor(respath[i], "black");
		}

		delete[] respath;
		pathCount = 0;
		respath = NULL;
	}

	//接收功能按键
	if (name == "退出系统" || name == "清空显示区" || name == "用BFS查看\n可以到哪里" || name == "用DFS查看\n可以到哪里" || name == "介绍建筑" || name == "求最短路径")
	{
		


		if (name == "退出系统")
		{
			mode = 6;
			delete[] G.spots;
			G.spots = NULL;
			mode = -1;
			exit(0);
		}
		else if (name == "清空显示区")
		{

			

			mode = 5;
			ui->textEdit_print->clear();
			mode = -1;
		}
		else if (name == "求最短路径")
			mode = 4;
		else if(name == "介绍建筑")
			mode = 3;
		else if (name == "用DFS查看\n可以到哪里")
			mode = 2;
		else if (name == "用BFS查看\n可以到哪里")
			mode = 1;

		if (mode == 1)
		{
			ui->textEdit_print->setText("请在左侧点击建筑作为起点");
		}
		else if (mode == 2)
		{
			ui->textEdit_print->setText("请在左侧点击建筑作为起点");
		}
		else if (mode == 3)
		{
			ui->textEdit_print->setText("请在左侧选择一个建筑进行介绍");
		}
		else if (mode == 4)
		{
			ui->textEdit_print->setText("请选择起点终点和交通工具");
		}

		//初始化变量,保证功能之间不冲突
		currentEndSpotId = -1;
		currentStartSpotId = -1;
		currentSpotId = -1;
		currentVehicle = -1;
		

	}
	else//接收地点或交通方式按键
	{
		if (mode == 1)//进入BFS那个功能
		{
			for (int i = 1; i <= G.spot_count; i++)
			{
				if (QString::fromStdString(G.spots[i].name) == name)
				{
					currentSpotId = i;
					ui->textEdit_print->append("已选择起点：" + name);
					break;
				}
			}
			
			int* res = new int[MSpotNUM];
			int resnum = 0;

			BFSTraverse(G, currentSpotId, res, resnum);
			if(resnum!=0)
				ui->textEdit_print->append("可以到达的地点有:\n");
			
			if (resnum == 0)
			{
				ui->textEdit_print->append("当前地点无法到达其他地方，（路可能正在施工/断路！）");
				delete[] res;
				return;
			}

			for (int i = 0; i < resnum; i++)
			{
				ui->textEdit_print->append(QString::fromStdString(G.spots[res[i]].name));
				

			}
			ui->textEdit_print->append("\n共" + QString::number(resnum) + "个地点");
			currentSpotId = -1; // 重置起点选择

			delete[] res;
			currentSpotId = -1;
			mode = -1;
		}
		else if (mode == 2)//进入DFS那个功能
		{
			if (currentSpotId == -1)
			{
				for (int i = 1; i <= G.spot_count; i++)
				{
					if (QString::fromStdString(G.spots[i].name) == name)
					{
						currentSpotId = i;
						ui->textEdit_print->append("已选择起点：" + name);
						break;
					}
				}
			}

			int* res = new int[MSpotNUM];
			int resnum = 0;

			DFSTraverse(G, currentSpotId, res, resnum);
			if(resnum != 0)
				ui->textEdit_print->append("可以到达的地点有:\n");

		
			if (resnum == 0)
			{
				ui->textEdit_print->append("当前地点无法到达其他地方，（路可能正在施工/断路！）");
				delete[] res;
				return;
			}

			for (int i = 0; i < resnum; i++)
			{
				ui->textEdit_print->append(QString::fromStdString(G.spots[res[i]].name));
			}
			ui->textEdit_print->append("\n共" + QString::number(resnum) + "个地点");
			currentSpotId = -1; // 重置起点选择

			delete[] res;
			currentSpotId = -1;
			mode = -1;
		}
		else if (mode == 3)
		{
			
			for (int i = 1; i <= G.spot_count; i++)
			{
				if (QString::fromStdString(G.spots[i].name) == name)
				{
					currentSpotId = i;
					ui->textEdit_print->append("已选择建筑：" + name);
					break;
				}
			}
			
			ui->textEdit_print->append("建筑信息如下:\n");
			ui->textEdit_print->append(QString::fromStdString("ID:" + std::to_string(G.spots[currentSpotId].id)));
			ui->textEdit_print->append(QString::fromStdString("坐标:(" + std::to_string(G.spots[currentSpotId].x) + "," + std::to_string(G.spots[currentSpotId].y) + ")"));
			ui->textEdit_print->append(QString::fromStdString("名称:") + QString::fromStdString(G.spots[currentSpotId].name));

			ui->textEdit_print->append(QString::fromStdString("介绍:") + QString::fromStdString(G.spots[currentSpotId].description));

			ui->textEdit_print->append("连接路径:");
			RoadNode* p = G.spots[currentSpotId].firstroad;

			int roadnum = 0;
			int roadsum = 0;
			int maxroad = INT_MIN;
			int minroad = INT_MAX;

			if (!p)
			{
				ui->textEdit_print->append("  无通路\n");
				currentSpotId = -1; // 重置起点选择
				return;
			}
			while (p)
			{
				if (p->distance > maxroad)
					maxroad = p->distance;
				if (p->distance < minroad)
					minroad = p->distance;
				roadsum += p->distance;
				roadnum++;
				QString distanceStr = QString::number(p->distance, 'f', 2);
				std::string distance = distanceStr.toStdString();
				ui->textEdit_print->append(QString::fromStdString("  ->" + std::string(G.spots[p->to_id].name) + " " + distance + "米 途经" + p->roadName + "路 目前" + (p->ifCanThrough ? "可通行" : "不可通行")));
				p = p->next;
			}

			ui->textEdit_print->append(QString::fromStdString("平均长度:") + QString::fromStdString(std::to_string(roadsum / roadnum)) + QString::fromStdString("米"));
			ui->textEdit_print->append(QString::fromStdString("最大长度:") + QString::fromStdString(std::to_string(minroad)) + QString::fromStdString("米"));
			ui->textEdit_print->append(QString::fromStdString("最小长度:") + QString::fromStdString(std::to_string(maxroad)) + QString::fromStdString("米"));
			currentSpotId = -1;
			mode = -1;
		}
		else if (mode == 4)
		{
			//匹配起点
			if (currentStartSpotId == -1)
			{
				for (int i = 1; i <= G.spot_count; i++)
				{
					if (QString::fromStdString(G.spots[i].name) == name)
					{
						currentStartSpotId = i;
						ui->textEdit_print->append("已选择起点：" + name);
						return;
					}
				}
				
			}

			//匹配终点
			if(currentEndSpotId == -1)
			for (int i = 1; i <= G.spot_count; i++)
			{
				if (QString::fromStdString(G.spots[i].name) == name)
				{
					currentEndSpotId = i;
					ui->textEdit_print->append("已选择终点：" + name);
					return;
				}
				
			}

			//匹配交通方式
			if (currentVehicle == -1)
			{
				if (name == "步行")
				{
					currentVehicle = 1;
					ui->textEdit_print->append("已选择交通方式：步行");
				}
				else if (name == "自行车")
				{
					currentVehicle = 2;
					ui->textEdit_print->append("已选择交通方式：自行车");
				}
				else if (name == "小轿车")
				{
					currentVehicle = 3;
					ui->textEdit_print->append("已选择交通方式：小轿车");
				}
				else
				{
					ui->textEdit_print->append("请在左下方选择交通方式");
					return;
				}
			}

			//防止二次分配地址
			if (respath)
			{
				delete[] respath;
				pathCount = 0;
				respath = NULL;
			}
			respath = new char[ROAD_NUM];
			pathCount = 0;
			
			FindShortestPath(G, currentStartSpotId, currentEndSpotId, currentVehicle,ui,respath,pathCount);

			//将所经过的路径颜色变成绿色
			for (int i = 0;i < pathCount;i++)
			{
				
				setRoadColor(respath[i], "rgb(85, 255, 0)");
			}

			mode = -1;
			currentEndSpotId = -1;
			currentStartSpotId = -1;
			currentVehicle = -1;
			
		}
		else
		{
			ui->textEdit_print->setText("请先选择功能");
		}

	}
	

	
}