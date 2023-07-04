# Computing_Geometry_Demo



计划内容(完成后勾上):  

> 图形部分

为什么要开这个?

1. recast navigation等算法的基础实际上都需要对计算几何中的部分算法有所熟悉
2. 如果想要自己实现一套基于Cluster的模型渲染方案,如virtual geometry,也需要对这部分算法很熟悉  
3. 空间一些高效的操作也有可能用到
4. 下一代的渲染架构(RayTracing)中，也大量的用到了计算几何的算法
5. 性能优化与空间结构拆分也经常用到这些算法
6. 作为自己的一套可以持续演进的学习库



- 几何基础类(`Vector√`/`Point√`/Line)
- 几何基础检测(射线检测/各种相交)
- 耳裁剪(Ear Clipping)拓扑算法
- DCEL(双向边链表)
- monotone polygons与三角剖分
- 凸包
- BSTTree/KDTree/QuadTree
- 部分图论


> C++部分

- 并发相关基础
- 异构计算