#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "Path.h"
#include "shortPath.h"

using namespace std;

int main() {
    int N = 7;
    int end;
    // int M=20;//生成一个有20个节点，100条边的图
    // srand(time(NULL));
    //sparseGraph
    /*SparseGraph g1(N, false);
    for(int i=0;i<M;i++){//对图中存在的节点进行随机的“连边”操作
        int a=rand()%N;
        int b=rand()%N;
        g1.addEdge(a,b);
    }
    for(int v=0;v<N;v++){//对图中的每一个节点都使用迭代器进行迭代
        cout<<v<<": ";
        SparseGraph::adjIterator adj(g1,v);//生成节点对应的迭代器
        for(int w=adj.begin();!adj.end();w=adj.next())//调用生成的节点迭代器的三种方法
            cout<<w<<" ";
        cout<<endl;
    }*/

    //DenseGraph
    DenseGraph g2(N, false);//生成一个无向的稠密图用来进行测试
    /*for(int i=0;i<M;i++){//随机的对图中的节点连接M条边
        int a=rand()%N;
        int b=rand()%N;
        g2.addEdge(a,b);
    }*/
//    for(int v=0;v<N;v++){
//        cout<<v<<": ";
//        DenseGraph::adjIterator adj2(g2,v);
//        for(int w=adj2.begin();!adj2.end();w=adj2.next()){
//            cout<<w<<" ";
//        }
//        cout<<endl;
//    }

//添加指定的边用作测试
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 5);
    g2.addEdge(0, 6);
    g2.addEdge(5, 3);
    g2.addEdge(5, 4);
    g2.addEdge(3, 4);
    g2.addEdge(4, 6);

    shortPath<DenseGraph> bfs(g2, 0);
    end = 6;
    bfs.showPath(end);
    cout << "the shortest  length  is:" << bfs.length(end) << endl;

    return 0;
}