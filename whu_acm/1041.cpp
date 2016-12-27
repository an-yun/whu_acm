#include <stdio.h> 

/*
 *可用单源最短路径来解
 *	kingkong 不连通
 *	matdog  权重1
 *	road 权重0
 *	
 *	Magicpig到Amaze最短距离，如果小于2，输出Yes,否则No
 * 核心点：
 *	1.构造一个有向图，用邻接矩阵 
 *		(细节点：V = n*n ,连接边的时候判断四个方向是否是kingkong或边缘，是的话不连通，否则连通加上相应的权重)
 *	2.构造一个IndexPQ，带索引的优先队列
 *		(用于找最当前还未加入的距离最小的点，快速更新这个点相连的边)
 *		
 *	zuo 2016-12-26
 */



int main()
{

	return 0;
}
