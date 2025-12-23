discription：This project is created to document my journey of practicing LeetCode algorithm questions while preparing for the huawei od position.

# ！递归

<span style=color:red>70.爬楼梯</span>(https://leetcode.cn/problems/climbing-stairs/) 

<span style=color:red></span>

简单

假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。

每次你可以爬 `1` 或 `2` 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**示例 1：**

```
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
```



```c++
class Solution {//递归
public:
    int climbStairs(int n) {
        switch (n){
            case 1: return 1;
            case 2: return 2;
            case 3: return 3;
            case 4: return 5;
            case 5: return 8;
            case 6: return 13;
            case 7: return 21;
            case 8: return 34;
            default:
        }
        return climbStairs(n-1) + climbStairs(n - 2);
    }
};
```



```c++
#include <vector>

class Solution {//DP 动态规划
public:
    int climbStairs(int n) {
        /*
        第一步：确定DP数组，以及DP数组下标的含义
        第二步：确定递推公式
        第三步：DP数组如何初始化 DP[0]、DP[1]
        第四步：确定遍历顺序
        第五步：可以打印DP数组，确认是否正确
        */
        //下标 + 1 = n楼梯阶数
        //DP[n] = DP[n-1] + DP[n-2] 
        //DP[0] = 1, DP[1] = 2, DP[2] = 3, DP[3] = 5;
        //
        if(n < 4)
            return n;
        int last1, last2;
        last2 = 2;
        last1 = 3;
        int sum;
        for(int i = 1; i < n-2; i++){
            sum = last1 + last2;
            last2 = last1;
            last1 = sum;
        }
        return sum;
    }
};
```

<span style=color:red>509. 斐波那契数</span>(https://leetcode.cn/problems/fibonacci-number/)

简单

**斐波那契数** （通常用 `F(n)` 表示）形成的序列称为 **斐波那契数列** 。该数列由 `0` 和 `1` 开始，后面的每一项数字都是前面两项数字的和。也就是：

```
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
```

给定 `n` ，请计算 `F(n)` 。

**示例 1：**

```
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
```

```c++
class Solution {//递归	
public:
    int fib(int n) {
        if(n<2)
            return n;
        return fib(n-1) + fib(n-2);
    }
};
```

```c++
class Solution {//动态规划
public:
    int fib(int n) {
        // 第一步：确定DP数组，以及DP数组下标的含义
        // 第二步：确定递推公式
        // 第三步：DP数组如何初始化 DP[0]、DP[1]
        // 第四步：确定遍历顺序
        // 第五步：可以打印DP数组，确认是否正确
        //DP[0] = 0, DP[1] = 1;  DP[i] = DP[i-1] + DP[i-2]
        int dp0 = 0;
        int dp1 = 1;
        int answer = 0;
        for(int i = 1; i < n; ++i){
            int dp2 = dp1 + dp0;
            answer = dp2;
            dp0 = dp1;
            dp1 = dp2;
        }
        return answer;
    }
};
```

394 

60 

273

# 分治

169 

<span style=color:red>240. 搜索二维矩阵 II</span>(https://leetcode.cn/problems/search-a-2d-matrix-ii/)

中等

编写一个高效的算法来搜索 `*m* x *n*` 矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

**示例 1：**

![img](https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/11/25/searchgrid2.jpg)

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
```

```c++
class Solution {//暴力
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int firstMaxRowPos = 0;
        int firstMaxCloPos = 0;
        int rowSize = matrix.size();
        int cloSize = matrix[0].size();

        if(matrix.empty() || matrix[0].empty()) 
            return false;

        bool  firstInCloFlag = false;
        bool  firstInRowFlag = false;
        for(int clo = 0; clo < cloSize; clo++){
            auto elem = matrix[0][clo]; //获取第一行每个元素
            if(elem > target){
                firstMaxCloPos = clo;
                firstInCloFlag = true;
                break;
            }
        }
        if(!firstInCloFlag){
            firstMaxCloPos = cloSize -1;
        }

        for(int row = 0; row < rowSize; row++){
            auto elem = matrix[row][0];
            if(elem > target){
                firstMaxRowPos = row;
                firstInRowFlag = true;
                break;
            }
        }
        if(!firstInRowFlag){
            firstMaxRowPos = rowSize -1;
        }

        for(int row = firstMaxRowPos; (0 <= row); row--){
            for(int clo = firstMaxCloPos; (0 <= clo); clo--){
                if(matrix[row][clo] == target){
                    return true;
                }
            }
        }
        return false;
    }
};
```

```c++
class Solution {//二分查找
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);//二分查找
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};
```



23



# ！单调栈

<span style=color:red>739. 每日温度</span>(https://leetcode.cn/problems/daily-temperatures/)

中等

给定一个整数数组 `temperatures` ，表示每天的温度，返回一个数组 `answer` ，其中 `answer[i]` 是指对于第 `i` 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

 

**示例 1:**

```
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
```



```c++
class Solution {//暴力
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i){
            bool flag = false;
            for(int j = i+1; j < temperatures.size(); ++j){
                if(temperatures[i] < temperatures[j]){
                    answer[i] = j-i;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer[i] = 0;
            }
        }
        return answer;
    }
};
```



```c++
class Solution {//单调栈
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stk;
        for(int i = 0; i < temperatures.size(); i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int pos = stk.top();
                stk.pop();
                answer[pos] = i - pos;
            }
            stk.push(i);
        }
        return answer;
    }
};
```



<span style=color:red>503. 下一个更大元素 II</span>(https://leetcode.cn/problems/next-greater-element-ii/)

中等

给定一个循环数组 `nums` （ `nums[nums.length - 1]` 的下一个元素是 `nums[0]` ），返回 *`nums` 中每个元素的 **下一个更大元素*** 。

数字 `x` 的 **下一个更大的元素** 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 `-1` 。

 

**示例 1:**

```
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
```



```c++
class Solution {//单调栈
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack<int> stk;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                int pos = stk.top();
                stk.pop();
                answer[pos] = nums[i];
            }
            stk.push(i);
        }
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                int pos = stk.top();
                stk.pop();
                answer[pos] = nums[i];
            }
        }
        return answer;
    }
};
```



<span style=color:red>84. 柱状图中最大的矩形</span>(https://leetcode.cn/problems/largest-rectangle-in-histogram/)

困难

给定 *n* 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)

```
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
```



```c++
class Solution {//暴力
public:
    int largestRectangleArea(vector<int>& heights) {
        int answer = 0;
        int flowCount;
        for(int i = 0; i < heights.size(); ++i){
            flowCount = 0;
            for(int j = 0; j < heights.size(); ++j){
                if(heights[j] >= heights[i]){
                    flowCount++;
                } else {
                    flowCount = 0;
                }
                int curAnswer = flowCount * heights[i];
                if(curAnswer > answer){
                    answer = curAnswer;
                }
            }

        }
        return answer;
    }
};
```



```c++
class Solution {//单调栈
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        stack<int> st;
        int answer = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                answer = max(answer, h*width);
            }
            st.push(i);
        }
        return answer;
    }
};

```



<span style=color:red>85. 最大矩形</span>(https://leetcode.cn/problems/maximal-rectangle/)

已解答

困难

给定一个仅包含 `0` 和 `1` 、大小为 `rows x cols` 的二维二进制矩阵，找出只包含 `1` 的最大矩形，并返回其面积。

 

**示例 1：**

![img](https://pic.leetcode.cn/1722912576-boIxpm-image.png)

```
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
```

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int clo = matrix[0].size();
        vector<int> heights(clo, 0);
        int answer = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < clo; ++j){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            answer = max(answer, curRow(heights));
        }
        return answer;
    }

    int curRow(vector<int> &heights){
        heights.emplace_back(0);
        int area = 0;
        stack<int> sk;
        for(int i = 0; i < heights.size(); ++i){
            while(!sk.empty() && heights[i] < heights[sk.top()]){
                int h = heights[sk.top()];
                sk.pop();
                int left = sk.empty() ? -1 : sk.top();
                int wieth = i - left -1;
                area = max(area, h*wieth);
            }
            sk.push(i);
        }
        return area;
    }
};
```



1776

# ！并查集

<span style=color:red>200. 岛屿数量</span>(https://leetcode.cn/problems/number-of-islands/)

中等

给你一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

**示例 1：**

```
输入：grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]
输出：1
```

```c++
class Solution {//洪泛
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >=grid.size() || j >= grid[0].size() ||grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
```



```c++
class unionFind{//并查集
public:
    unionFind(int size):parent(size),count(0){
        for(int pos = 0; pos < size; ++pos)
            parent[pos] = pos;
    }

    void setCount(int num){
        this->count = num;
    }

    int find(int elem){
        if(parent[elem] != elem)
            parent[elem] = find(parent[elem]); //亚索路径！！
        return parent[elem];
    }

    void unionTow(int a, int b){
        int parentA = find(a);
        int parentB = find(b);
        if(parentA == parentB) return;

        parent[parentB] = parentA;
        count--;
    }

    vector<int> parent;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int clos = grid[0].size();
        unionFind uf(row * clos);

        int islandCount = 0;
        for(auto line: grid){
            for(auto elem: line){
                if(elem == '1'){
                    islandCount++;
                }
            }
        }
        uf.setCount(islandCount);

        int arr[2][2] = {{1, 0}, {0, 1}};

        for(int r = 0; r < row; ++r){
            for(int c = 0; c < clos; ++c){
                if(grid[r][c] == '1'){
                    int curID = r * clos + c;
                    
                    for(auto add: arr){
                        int nr = r + add[0];
                        int nc = c + add[1];

                        if(nr < row && nc < clos && grid[nr][nc] == '1'){
                            int neighborId = nr * clos + nc;
                            uf.unionTow(curID, neighborId);
                        }
                    }
                }
            }
        }
        return uf.count;
    }
};
```



<span style=color:red>684. 冗余连接</span>(https://leetcode.cn/problems/redundant-connection/)

中等

树可以看成是一个连通且 **无环** 的 **无向** 图。

给定一个图，该图从一棵 `n` 个节点 (节点值 `1～n`) 的树中添加一条边后获得。添加的边的两个不同顶点编号在 `1` 到 `n` 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 `n` 的二维数组 `edges` ，`edges[i] = [ai, bi]` 表示图中在 `ai` 和 `bi` 之间存在一条边。请找出一条可以删去的边，删除后可使得剩余部分是一个有着 `n` 个节点的树。如果有多个答案，则返回数组 `edges` 中最后出现的那个。 

**示例 1：**

![img](https://pic.leetcode.cn/1626676174-hOEVUL-image.png)

```
输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]
```

**示例 2：**

![img](https://pic.leetcode.cn/1626676179-kGxcmu-image.png)

```
输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
```

题目核心（先一句话想清楚）给的是一棵树 + 多加的一条边

树的性质：任意两点只有一条路径 👉 如果一条边连接的两个点已经连通，那么它一定是冗余边  

并查集：天生干这个的 👍

```c++
 class findUnion{
public:
    findUnion(int size):parent(size){
        for(int i = 0; i < size; ++i){
            parent[i] = i;
        }
    }

    int find(int pos){
        if(parent[pos] != pos){
            parent[pos] = find(parent[pos]);
        }
        return parent[pos];
    }

    bool unionTow(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB) return false; //说明此边ab 有公共的父亲，而且他们现在还相连，所以必定成环
        parent[parentB] = parentA;
        return true;
    }

    vector<int> parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        findUnion fu(size + 1); //有环=》 边条数 == 点个数
        
        for(auto edge: edges){
            int pointA = edge[0];
            int pointB = edge[1];

            if(!fu.unionTow(pointA, pointB)) 
                return {edge[0], edge[1]};// return edge;
        }
        return {};
    }
};
```

[547. 省份数量](https://leetcode.cn/problems/number-of-provinces/)

中等

有 `n` 个城市，其中一些彼此相连，另一些没有相连。如果城市 `a` 与城市 `b` 直接相连，且城市 `b` 与城市 `c` 直接相连，那么城市 `a` 与城市 `c` 间接相连。

**省份** 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 `n x n` 的矩阵 `isConnected` ，其中 `isConnected[i][j] = 1` 表示第 `i` 个城市和第 `j` 个城市直接相连，而 `isConnected[i][j] = 0` 表示二者不直接相连。

返回矩阵中 **省份** 的数量。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg)

```
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg)

```
输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
```



```c++
class findUnion{//并查集
public:
    findUnion(int size):parent(size), count(size){
        for(int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int pos){
        if(parent[pos] != pos){
            parent[pos] = find(parent[pos]);
        }
        return parent[pos];
    }

    void unionTow(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB){
            return;
            //count-- //怎么能加在这儿呢？
        }
        count--; //减减，表示说当前union tow city a 和 city b，他们已经是同一省的了，所以他们两个要合成一个。可以理解为省的数量之前还分了a，b  而他们是有路的，就不能算两个省，只能减减
        parent[parentB] = parentA; 
    }

    vector<int> parent;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        findUnion fu(size);
        
        for(int city = 0; city < size; ++city){
            for(int otherCity = 0; otherCity < size; ++otherCity){
                if(otherCity == city) continue;
                if(isConnected[city][otherCity] == 1){
                    fu.unionTow(city, otherCity);
                }
            }
        }
        return fu.count;
    }
};
```

[924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread/)

困难

给出了一个由 `n` 个节点组成的网络，用 `n × n` 个邻接矩阵图 `graph` 表示。在节点网络中，当 `graph[i][j] = 1` 时，表示节点 `i` 能够直接连接到另一个节点 `j`。 

一些节点 `initial` 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 `M(initial)` 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

如果从 `initial` 中**移除某一节点**能够最小化 `M(initial)`， 返回该节点。如果有多个节点满足条件，就返回**索引最小**的节点。

请注意，如果某个节点已从受感染节点的列表 `initial` 中删除，它以后仍有可能因恶意软件传播而受到感染。 

**示例 1：**

```
输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
输出：0
```

**示例 2：**

```
输入：graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
输出：0
```

 

685

# ！滑动窗口

3 

1004 

208 

209 

76



# ！前缀和

560 974 523 525 437



# ！差分

1094 1109 121 122 1074



# 拓扑排序

210 269 2050



# ！字符串

20 5 43 8 32 



# 二分查找

33 34 300 



# ！BFS

752 210 127 317 815

# ！DFS，回溯

46 130 547 17 332 

# 动态规划

139 122 62 64 871 

# 贪心

45 452 435 621 135

# 字典树

820 648 208 140 1032

# 哈希

554 781 846 460 1224

# ！双指针

11 15 42 18 1163

# ！栈

71 394 1190 84 224

