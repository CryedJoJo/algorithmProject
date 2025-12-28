discription：This project is created to document my journey of practicing LeetCode algorithm questions while preparing for the huawei od position.

git status;git add .;git commit -m "update";git push;

# ！递归

### [70.爬楼梯](https://leetcode.cn/problems/climbing-stairs/) 

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
            case 8: return 34; //不这样写，用例过不了
            default:
        }
        return climbStairs(n-1) + climbStairs(n - 2);
    }
};
```



```c++
class Solution {//DP 动态规划（根据思路自己实现的，但是初始条件写得不够好 需要优化
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

### [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/)

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

### 394 

### 60 

### 273

# 分治

### 169 

### [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

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



### 23



# ！单调栈

关键词（90% 单调栈）
- 下一个更大元素
- 下一个更小元素
- 最近的更大 / 更小
- 左边第一个
- 右边第一个
- 单调递增 / 递减
- 能看到多少个

### [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/)

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

![img](./单调栈/739每日温度.png)

```c++
class Solution {//单调栈
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stk;
        for(int i = 0; i < temperatures.size(); i++){
             //循环判断栈顶位置温度是否小于i位置温度
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){ 
                
                int pos = stk.top(); //栈顶，pos对应temperatures下标
                
                stk.pop(); //弹出栈顶，用于while循环判断栈顶下一个位是否满足条件
        
                answer[pos] = i - pos; //计算temperatures的pos位 与之后最近高温的距离
            }
            stk.push(i); //i压入stk，说明i位置之前其他小于i位置温度的温度都找到了第一个比自己大的温度，
            //留在栈中的位置的温度都是大于i位置温度的温度
        }
        return answer;
    }
};
```



### [503. 下一个更大元素 II](https://leetcode.cn/problems/next-greater-element-ii/)

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
**“为什么一定要第二轮？没有第二轮遍历，就无法处理“下一个更大元素在当前位置左侧”的情况**
而 503 是 **环形数组**，左侧 ≠ 不存在。为什么“第二轮”正好补上这个漏洞？
第二轮本质是：让右侧走不到的元素，能“看到”数组左侧

给一个更“极端”的失败用例
```text
nums = [5, 4, 3, 2, 1]
```

正确答案：
```text
[-1, 5, 5, 5, 5]
```
只用一轮的结果

```text
stk = [0, 1, 2, 3, 4]
answer = [-1, -1, -1, -1, -1]
```
原因：
所有元素都是单调递减
没有任何一个元素在右侧能被弹栈
但在环形数组中：
4 的下一个更大是 5
3 的下一个更大是 5
…
全部漏算

失败的“本质原因”（非常重要）
单调栈的“下一个更大元素”前提是：你能“看到”目标元素
在普通数组中：右边就是全部候选
在环形数组中：右边 + 左边 才是全部候选
但你的第一轮遍历只能看到：当前位置右侧
第二轮的本质是：补齐“左侧那一半”
为什么不能“在一轮里硬算”？
因为单调栈的一个核心前提是：每个元素入栈时，它后面所有“可能成为答案的元素”还没出现
在环形数组中：有些答案 已经出现过了。只能靠“再走一圈”补救
一句话总结（你可以直接记）503 之所以必须第二轮，是因为环形数组中“下一个更大元素”可能在左侧，而单次遍历只能看到右侧。

**ChatGpt 版本：**

```c++
class Solution {// 单调栈
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, -1);
        stack<int> stk;  // 单调递减栈，存的是下标

        // 遍历两遍数组，模拟环形数组
        for(int i = 0; i < 2 * n; ++i){
            int idx = i % n;

            // 当前元素比栈顶元素大，说明找到了“下一个更大元素”
            while(!stk.empty() && nums[stk.top()] < nums[idx]){
                int pos = stk.top();
                stk.pop();
                answer[pos] = nums[idx];
            }

            // 只在第一轮遍历时入栈
            // 第二轮只是用来“结算”还没找到更大元素的下标
            if(i < n){
                stk.push(idx);
            }
        }
        return answer;
    }
};
```



### [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)

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

![img](./单调栈/84柱状图中最大的矩形.png)

```c++
class Solution {//暴力
public:
    int largestRectangleArea(vector<int>& heights) {
        int answer = 0; //最大面积
        for(int j = 0; j < heights.size(); ++j){
            
            int width = 0;//i位置 及i位置之后 连续大于等于heights[i]（高）的 元素个数 (底边长) 
            int h = heights[j]
            for(int i = j; i < heights.size(); ++i){
                if(heights[i] >= h){
                    width++; //底边长++
                } else {
                    width = 0; //以heights[i]为（高）的连续位置结束
                }
                answer = max(answer, width*h); // 判断当前 底*高 大不大 
            }
            
        }
        return answer;
    }
};
```


heights[[**i**]] 连续升高就st.push([**i**]), 突然下降就循环判断，并修正[ **i** ]位置之前的最大矩形面积

![img](./单调栈/84柱状图中最大的矩形-单调栈.png)

```c++
class Solution {//单调栈
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0); //它的作用不是参与答案计算，是防止传入数组单调递增数组，导致无法弹栈
        stack<int> st;
        int answer = 0;
        for(int i = 0; i < heights.size(); ++i){
            // heights[i] < heights[st.top()]条件 的功能 类似执行 width = 0; 之前的边界条件
            // 类似暴力解中 width 筛选连续满足 heights[i] >= heights[j]（高）底边个数的过程
            while(!st.empty() && heights[i] < heights[st.top()]){ 
                int h = heights[st.top()]; //高
                st.pop();
                int left = st.empty() ? -1 : st.top(); //st为空时，说明上面弹出的是最后一个元素，流程图2
                int width = i - left - 1; //底
                answer = max(answer, width*h);
            }
            st.push(i);
        }
        return answer;
    }
};
```



### [85. 最大矩形](https://leetcode.cn/problems/maximal-rectangle/)

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

![img](./单调栈/85-压缩矩阵.png)

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int clo = matrix[0].size();
        // heights[j] 表示：以“当前行 i 作为底边”，第 j 列向上连续出现 '1' 的高度
        vector<int> heights(clo, 0);
        // 用来记录整个矩阵中能够形成的最大矩形面积
        int answer = 0;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < clo; ++j){
                if(matrix[i][j] == '1'){
                    // 当前列的高度可以在上一行基础上 +1表示向上连续的 '1' 又增加了一层
                    heights[j]++;
                } else {
                    // 说明在这一列上连续的 '1' 被中断 以当前行作为底边时，该列高度清零
                    heights[j] = 0;
                }
            }

            // 到这里 heights 数组已经表示 “以第 i 行为底边的柱状图高度”
            // 在这个柱状图中，计算能够形成的最大矩形面积
            answer = max(answer, largestRectangleArea(heights));
        }
        return answer;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        stack<int> st;
        int answer = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){ 
                int h = heights[st.top()]; //高
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1; //底
                answer = max(answer, width*h);
            }
            st.push(i);
        }
        return answer;
    }
};

```



### 1776

# ！并查集

在乱世中不断合纵连横，直到天下只剩下几个真正的霸主

flowchart TD
    A[开始：读题] --> B{题目是否涉及<br/>连通性 / 同一集合？}

```mermaid
B -- 否 --> Z[并查集<br/>可能不是最优解]

B -- 是 --> C{最终结果<br/>是一个“数量”吗？}

C -- 是 --> D[类型一：连通块数量型<br/>如 200 / 547]
D --> D1[初始化 count = n]
D1 --> D2[union 成功一次 → count--]
D2 --> D3[返回 count]

C -- 否 --> E{是否按顺序加边<br/>并判断是否成环？}

E -- 是 --> F[类型二：成环判断型<br/>如 684]
F --> F1[遍历每条边]
F1 --> F2{find(u) == find(v)?}
F2 -- 是 --> F3[当前边是冗余边]
F2 -- 否 --> F4[union(u, v)]

E -- 否 --> G{是否涉及删除 / 感染 / 影响范围 / 收益？}

G -- 是 --> H[类型三：连通块属性分析型<br/>如 924 / 928 / 803]
H --> H1[只建一次并查集]
H1 --> H2[统计每个连通块 size]
H2 --> H3[统计特殊节点数量<br/>(感染源等)]
H3 --> H4[分析每个候选点的贡献]
H4 --> H5[选择最优答案]

G -- 否 --> Y[需进一步分析题目<br/>并查集可能不是最佳方案]
```

### [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)

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

![img](./并查集/200岛屿数量.png)

```c++
class unionFind{//并查集
public:
    unionFind(int size):parent(size),count(0){
        for(int pos = 0; pos < size; ++pos)
            parent[pos] = pos; //东汉末年，天下大乱，诸侯各自为战
    }

    void setCount(int num){
        this->count = num;
    }

    int find(int elem){
        if(parent[elem] != elem)
            parent[elem] = find(parent[elem]); //都想当丞相，一人之下、万人之上
        return parent[elem]; //挟天子以令诸侯
    }

    void unionTow(int a, int b){
        int parentA = find(a); //统帅三军 和兵一处，决一死战
        int parentB = find(b); //统帅三军 和兵一处，决一死战
        if(parentA == parentB) return;

        parent[parentB] = parentA; //分久必合
        count--; //被吞并
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

        int arr[2][2] = { {1, 0}, 
                          {0, 1}};

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



### [684. 冗余连接](https://leetcode.cn/problems/redundant-connection/)

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
树的性质：任意两点只有一条路径 如果一条边连接的两个点已经连通，那么它一定是冗余边  
并查集：天生干这个的 

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

### [547. 省份数量](https://leetcode.cn/problems/number-of-provinces/)

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

### [924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread/)

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



下面是第一次写出来的莫名其妙的代码

非常好，这一步你是在**做“代码级复盘”**，这是进阶到高手的关键 👍
下面我**不重写代码、不换思路**，只在你这份代码的**具体错误行上加「逐行注释」**，明确说明：

> **这一行“原本错在哪里 / 为什么一定错”**

------

```cpp
class findUnion{
public:
    findUnion(int size):parent(size), count(0){
        for(int i = 0; i < size; ++i){
            parent[i] = i;
        }
    }

    int find(int a){
        if(parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void unionTow(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB) return;
        count++; 
        // ❌ 错误 1：
        // count 在这里统计的是「并查集合并次数」
        // 但在 924 题中，我们需要的是「感染节点数量 / 连通块大小」
        // 合并次数 ≠ 节点数 ≠ 拯救规模
        parent[parentB] = parentA;
    }

    int count;          // ❌ 错误 2：
                          // 这个 count 语义错误
                          // 你后面把它当作「感染规模 / 拯救数量」
                          // 实际它只是 union 次数
    vector<int> parent;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int nodeCount = graph.size();
        int answer = initial[0];
        int count = 0;   // ❌ 错误 3：
                          // 这个 count 用来记录“当前最优拯救数量”
                          // 但你后面拿它和 fu.count（合并次数）比较
                          // 两者完全不是一个概念

        for(auto node: initial){
            findUnion fu(nodeCount);

            for(int row = 0; row < nodeCount; ++row){
                if(node == row) continue; 
                // ⚠️ 这里的 continue 本意是“模拟删除 node”
                // 但并查集本身已经不适合用这种方式做「删点重建」

                for(int clos = 0; clos < nodeCount; ++clos){
                    if(row == clos || node == clos) continue;
                    // ⚠️ 同上，逻辑表面合理，但整体建模方向已经错

                    if(graph[row][clos] == 1){
                        fu.unionTow(node, clos);
                        // ❌ 错误 4（最致命）：
                        // 你此时在遍历 row 和 clos
                        // 但合并的却是 node 和 clos
                        //
                        // 这等价于：
                        //   把所有连通关系都强行连到 node 上
                        //
                        // 正确的合并对象应该是：
                        //   fu.unionTow(row, clos)
                        //
                        // 并且 node（被移除的点）根本不该参与并查集
                    }
                }
            }

            int curCount = fu.count;
            // ❌ 错误 5：
            // curCount 是“union 次数”
            // 不是感染节点数
            // 不是最终会被感染的节点数量

            if(curCount >= count){
                count == curCount;
                // ❌ 错误 6（低级但致命）：
                // 这里用了 “==” 比较
                // 实际你想写的是赋值：
                // count = curCount;

                if(node < answer){
                    answer = node;
                }
            }
        }
        return answer;
    }
};
```

------

🔥 总结：这段代码「为什么必错」

不是 bug 多，而是 **建模方向根本不成立**

你在做的是：

> **“枚举删除一个感染点，然后用并查集算感染规模”**

但 **924 题不能这么建模**，原因是：

1. 并查集不擅长“删点”
2. 感染传播取决于：
   - 连通块大小
   - **一个连通块中感染源的数量**
3. union 次数 ≠ 连通块规模

------

🧠 给你一个“错误代码反思口诀”（很值钱）

> **并查集里：**
>
> - `union 次数` 永远不能当结果
> - **先建图，再分析连通块属性**
> - 924 是“分析题”，不是“模拟题”

------

如果你愿意，下一步我可以帮你：

1️⃣ **在你这份代码基础上最小改动改对（对比版）**
2️⃣ **画图解释：为什么“删点 + 并查集”天生不适合 924**
3️⃣ **总结 924 / 928 / 803 这类“高级并查集题型套路”**

你选一个，我按你选的来。

好，我们就按你选的 **①「在你这份代码基础上，最小改动改对」** 来做。
我会遵守三个原则：

- ❌ 不推翻你原有结构
- 🔧 只改**必须改的地方**
- 🧠 每一处改动都说明**“为什么不改就一定错”**

------

 一、先说清楚：哪些“设计”必须放弃（但不算重构）

你原来的整体思路是：

> **枚举删除一个 initial 节点 → 用并查集统计感染规模**

⚠️ 这一思路 **本身不适用于 924**，但为了“最小改动”，我们不重写流程，只做**逻辑纠正**：

必须修正的点只有 4 个：

1. ❌ union 的对象错了
2. ❌ `count` 的含义错了
3. ❌ 没有统计「连通块大小」
4. ❌ 没有处理「一个连通块多个感染源」

------

二、在你原代码上「最小可行修改版」

🔧 修改 1：并查集必须能记录“连通块大小”

> **这是 924 的硬性要求，不能省**

```cpp
class findUnion{
public:
    findUnion(int size):parent(size), size(size, 1){
        for(int i = 0; i < size; ++i){
            parent[i] = i;
        }
    }

    int find(int a){
        if(parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void unionTow(int a, int b){
        int parentA = find(a);
        int parentB = find(b);
        if(parentA == parentB) return;

        parent[parentB] = parentA;
        size[parentA] += size[parentB];   // ✅ 关键：记录连通块大小
    }

    vector<int> parent;
    vector<int> size;   // ✅ 新增：连通块大小
};
```

原来的 `count` **彻底删掉**union 次数在 924 中 **毫无意义**


三、主逻辑的最小修改（重点）
❌ 原来最大的问题：你在 **删点 + 重建并查集**
 **924 正确做法：只建一次并查集**
✅ 修改后的 Solution（结构仍然很接近你原来的）

```cpp
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int nodeCount = graph.size();
        findUnion fu(nodeCount);

        // 1️⃣ 建立完整并查集（不删点）
        for(int i = 0; i < nodeCount; ++i){
            for(int j = i + 1; j < nodeCount; ++j){
                if(graph[i][j] == 1){
                    fu.unionTow(i, j);
                }
            }
        }

        // 2️⃣ 统计每个连通块中的感染源数量
        vector<int> infected(nodeCount, 0);
        for(int node : initial){
            int root = fu.find(node);//当前node 归属哪个以root为根节点的集合
            infected[root]++; //表示，当前以root为根的集合中，多了一个感染点数，就是node带来的.
            
            //如果下次node2也是归属 此root 的集合，那么就会有 infected[此root]==2，因此删除只删除node2，或者只删除node的情况下，就不能改变此集合的节点被感染的结局，所以，node，node2不是 answer节点。
        }

        // 3️⃣ 选择最优删除点
        int answer = *min_element(initial.begin(), initial.end());
        int maxSaved = 0;

        for(int node : initial){
            int root = fu.find(node);

            // 只考虑“该连通块只有 1 个感染源”的情况
            if(infected[root] == 1){
                int saved = fu.size[root];

                if(saved > maxSaved ||
                  (saved == maxSaved && node < answer)){
                    maxSaved = saved;
                    answer = node;
                }
            }
        }

        return answer;
    }
};


```

------

四、对比你原代码：**到底改了什么？**

❌ 删掉的（错误根源）

- 每次 `for(auto node : initial)` 里重建并查集
- `count`（union 次数）
- `fu.unionTow(node, clos)` 这种错误合并

------

✅ 新增的（924 必需）

- `size[]`：连通块大小
- `infected[]`：每个连通块的感染源数量
- **只建一次并查集**

------

 五、为什么这是「最小正确解」

- ✔ 仍然是并查集
- ✔ 代码结构与你原来高度相似
- ✔ 没引入 DFS / BFS
- ✔ 符合官方题解思想

------

六、你现在应该记住的一句话（非常重要）

> **924 不是“模拟删点”，而是“分析连通块”**

这也是它比 200 / 684 难的根本原因。

------

如果你愿意，下一步我可以：

2️⃣ 用 **你原代码 vs 正确代码** 做一张「逐行对照表」
3️⃣ 帮你总结 **并查集 3 个难点题型的通用判断公式**

你继续选，我陪你把并查集这块彻底吃透。

### 685

# ！滑动窗口（能屈能伸）

滑动窗口 解题关键是控制窗口边界的移动时机

1、一般，以int j 为窗口右边界，j线性++  窗口右边界移动，

2、以int i 为窗口的左边界，while循环判断窗口是否满足题目条件，在窗口满足或不满足题目的条件时 进入循环做数据处理，并进行 i++ 窗口左边界移动

j 和 i 的交替移动 组成了滑动的窗口，

### [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

中等

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长 子串** 的长度。

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
```

**示例 2:**

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

```C++
class Solution { //思路没问题，就是方法不对（用例部分通过）
public:
    int lengthOfLongestSubstring(string s) {
        string answer {};
        string subStr {};
        set<string> subStrSet{}; 
        for(int j = 0; j < s.size(); ++j){
            string cur {s[j]};
            int flag = true;
            while(subStrSet.find(cur) == subStrSet.end()){ //这儿不应该判断 == end，而是判断 != end
                subStrSet.insert(cur);
                subStr += cur;
                if(subStr.size() > answer.size()){
                    answer = subStr;
                }
                flag = false;
            }
            if(flag){
                subStrSet.clear();
                subStrSet.insert(cur);
                subStr.clear();
                subStr += cur;
            }
        }
        return answer.size();
    }
};
```

```c++
class Solution {// 滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        unordered_set<char> strSet {};
        int maxLen = 0;
        int left = 0;
        for(int j = 0; j < s.size(); ++j){

            while(strSet.find(s[j]) != strSet.end()){ //如果当前s[j] 加入产生了重复的char
                strSet.erase(s[left++]); //窗口左边界 向右滑动一格
            }
            strSet.insert(s[j]); // 12行 删除重复的char s[i]后， 在这儿插入 s[j]
            maxLen = max(maxLen, j - left + 1);
        }
        
        return maxLen;
    }
};
```



### [1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/)

中等

给定一个二进制数组 `nums` 和一个整数 `k`，假设最多可以翻转 `k` 个 `0` ，则返回执行操作后 *数组中连续 `1` 的最大个数* 。

**示例 1：**

```
输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
```

**示例 2：**

```
输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
```

示例1：算法图解
![1004.png](./滑动窗口/1004.png)

```c++
class Solution { // 滑动窗口
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        int maxLen = 0;
        int zeroCount = 0;
        int left = 0;
        for(int j = 0; j < nums.size(); ++j){
            while(zeroCount > k){
                if(nums[left] == 0)
                    zeroCount--;
                left++; //窗口左边界 向右滑动一格
            }
            if(nums[j] == 0){
                zeroCount++;
            }
            if(zeroCount <= k) //当前窗口中0的个数符合最大反转阈值k 才能计算长度
                maxLen = max(maxLen, j - left + 1);
        }
        return maxLen;
    }
};
```

```c++
class Solution { // 公式做题就是快
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        int maxLen = 0;
        int zeroCount = 0;
        int left = 0;
        for(int j = 0; j < nums.size(); ++j){
            while(zeroCount > k){
                if(nums[left] == 0)
                    zeroCount--;
                left++; //窗口左边界 向右滑动一格
            }
            if(nums[j] == 0){
                zeroCount++;
            }
            if(zeroCount <= k) //当前窗口中0的个数符合最大反转阈值k 才能计算长度
                maxLen = max(maxLen, j - left + 1);
        }
        return maxLen;
    }
};
```





### [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

中等

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其总和大于等于 `target` 的长度最小的 **子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

 

**示例 1：**

```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**

```
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**

```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```



```c++
class Solution { //滑动窗口
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size();
        int left = 0; //窗口左边界
        int sum = 0;
        int flag = false;
        for(int j = 0; j < nums.size(); ++j){ // j 窗口右边界
            sum += nums[j];
            while(sum >= target){
                flag = true;
                minLen = min(minLen, j - left + 1);
                sum -= nums[left++]; //左边窗口边界 向右边滑动1位
            }
        }

        if(!flag) //如果flag没有被修改，说明nums全体相加都小于target
            return 0;
        return minLen;
    }
};
```



### 76



# ！前缀和

### [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

中等

给你一个整数数组 `nums` 和一个整数 `k` ，请你统计并返回 *该数组中和为 `k` 的子数组的个数* 。

子数组是数组中元素的连续非空序列。

**示例 1：**

```
输入：nums = [1,1,1], k = 2
输出：2
```

**示例 2：**

```
输入：nums = [1,2,3], k = 3
输出：2
```

```c++
class Solution {//暴力（超时）
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        for(int j = 0; j < nums.size(); ++j){
            for(int i = j; i < nums.size(); ++i){
                sum +=nums[i];
                if(sum == k)
                    count++;
            }
            sum = 0;
        }
        return count;
    }
};
```

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size() + 1, 0); // 多加1个空间，是为了prefix[0] = 0,方便计算
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i+1] = prefix[i] + nums[i]; // 计算前缀和数组
        }

        int count = 0;
        unordered_map<int, int> prefixCount; // 存储前缀和 -> 出现次数
        prefixCount[0] = 1; // 关键：处理从开头开始的子数组（如 [0,1] 和为 k）

        for (int i = 1; i < prefix.size(); ++i) {
            // 查看是否存在前缀和为 (prefix[i] - k)
            // 如果存在，说明有子数组和为 k
            if (prefixCount.find(prefix[i] - k) != prefixCount.end()) {
                count += prefixCount[prefix[i] - k];
            }

            // 将当前前缀和加入哈希表（用于后续判断）
            prefixCount[prefix[i]]++;
        }

        return count;
    }
};
```

974 

523 

525 

437



# ！差分

### [1094. 拼车](https://leetcode.cn/problems/car-pooling/)

中等
车上最初有 `capacity` 个空座位。车 **只能** 向一个方向行驶（也就是说，**不允许掉头或改变方向**）
给定整数 `capacity` 和一个数组 `trips` ,  `trips[i] = [numPassengersi, fromi, toi]` 表示第 `i` 次旅行有 `numPassengersi` 乘客，接他们和放他们的位置分别是 `fromi` 和 `toi` 。这些位置是从汽车的初始位置向东的公里数。
当且仅当你可以在所有给定的行程中接送所有乘客时，返回 `true`，否则请返回 `false`。

**例 1：**

```
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
```
**示例 2：**

```
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
```

![img](./差分/1094拼车.png)

```c++
class Solution { //暴力
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curPassengerCount = 0; //乘客数量
        for(int i = 0; i < trips.size(); ++i){
            curPassengerCount = trips[i][0]; //获取当前旅行的乘客数量
            if(curPassengerCount > capacity) return false; //一开始人就超了，拼车返回失败
            for(int j = 0; j < trips.size(); ++j){
                if(i == j) continue; //如果是同一趟旅行，忽略不计算

                //[[2,1,5],[3,3,7]] 中 trips[i][2] == 5。  3 < 5 <= 7会导致旅程重叠
                // 如上图中黄色旅行[4,9,12] 蓝色旅行[6,4,12] 需要将不等式写成 4(蓝) < 12(黄) <= 12(蓝)
                if(trips[i][2] > trips[j][1] && trips[i][2] <= trips[j][2]){
                    curPassengerCount += trips[j][0];
                    if(curPassengerCount > capacity)
                        return false; //人数 > 座位，拼车失败
                }

            }
        }
        return true;
    }
};
```

![img](./差分/1094拼车差分.png)

```c++
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // diff[i] 表示：在第 i 个位置，乘客数量的“变化量”
        // 上车 +x，下车 -x
        vector<int> diff(1001, 0);

        // 1️⃣ 构建差分数组
        for (int i = 0; i < trips.size(); ++i) {
            int passengerCount = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            // 在 from 位置上车
            diff[from] += passengerCount;
            // 在 to 位置下车
            diff[to] -= passengerCount;
        }

        // 2️⃣ 还原每个时刻的车上人数，并检查是否超载
        int curPassengerCount = 0;
        for (int pos = 0; pos <= 1000; ++pos) {
            curPassengerCount += diff[pos];  // 累加变化量
            if (curPassengerCount > capacity) {
                return false; // 任意时刻超载，拼车失败
            }
        }
        return true; // 全程未超载
    }
};
```





1109 

121 

122 

1074


# 拓扑排序


代码



测试用例

测试用例



测试结果

### [210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii/)

中等

现在你总共有 `numCourses` 门课需要选，记为 `0` 到 `numCourses - 1`。给你一个数组 `prerequisites` ，其中 `prerequisites[i] = [ai, bi]` ，表示在选修课程 `ai` 前 **必须** 先选修 `bi` 。

- 例如，想要学习课程 `0` ，你需要先完成课程 `1` ，我们用一个匹配来表示：`[0,1]` 。

返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 **任意一种** 就可以了。如果不可能完成所有课程，返回 **一个空数组** 。

 

**示例 1：**

```
输入：numCourses = 2, prerequisites = [[1,0]]
输出：[0,1]
解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
```

**示例 2：**

```
输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
```

**示例 3：**

```
输入：numCourses = 1, prerequisites = []
输出：[0]
```

 

**提示：**

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- `ai != bi`
- 所有`[ai, bi]` **互不相同**

```c++
class Solution { //思路没问题，就是细节有错误
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> table;
        unordered_map<int, vector<int>> cln;


        for(vector<int> edge : prerequisites){ //构建邻接表
            if(table.find(edge[0]) == table.end()){
                unordered_set<int> cur;
                cur.insert(edge[1]);
                table[edge[0]] = cur;
            } else {
                table[edge[0]].insert(edge[1]);
            }
            if(cln.find(edge[1]) == cln.end()){
                vector<int> cur;
                cur.push_back(edge[0]);
                cln[edge[1]] = cur;
            } else {
                cln[edge[1]].push_back(edge[0]);
            }

        }

        vector<int> seq;
        int i = 0;
        while(!table.empty()){
            if(table.find(i) == table.end()){
                seq.push_back(i);
                for(auto next:cln[i]){
                    table[next].erase(i);
                    if(table[next].empty()){
                        table.erase(next);
                    }
                }
                cln.erase(i);
            } else{
                i++;
                if(i == numCourses) i = 0;
            }
        }
        return seq;
    }
};
```

GPT 修正版本
chatGPT说：“我只做三件事
❌ 不再用「while + i++ 瞎扫」
✅ 显式维护「当前入度为 0 的点」
❌ 不引入全新算法（仍然是你这套删除依赖的逻辑）”

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> table; // course -> prerequisites
        unordered_map<int, vector<int>> cln; // course -> next courses，用于清除next courses入度

        // 建图
        for (auto& edge : prerequisites) {
            table[edge[0]].insert(edge[1]);
            cln[edge[1]].push_back(edge[0]);
        }

        vector<int> seq;
        queue<int> q; //✅加入辅助队列 显式维护「当前入度为 0 的点」（这个是gpt新加的）

        // 找所有“当前没有前置依赖”的课程
        for (int i = 0; i < numCourses; ++i) {
            if (table.find(i) == table.end()) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            seq.push_back(cur);

            // cur 作为前置课程，影响后续课程
            if (cln.count(cur)) {
                for (int next : cln[cur]) {
                    table[next].erase(cur); //next课程清除入度，curCourse->nextCourse
                    if (table[next].empty()) {
                        table.erase(next); //nextCourse入度为0，意味着可以选修了
                        q.push(next);
                    }
                }
            }
        }

        // 如果还有课程没被加入，说明有环
        if (seq.size() != numCourses)
            return {};

        return seq;
    }
};

```



269 

2050



# ！字符串

### [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

简单
给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。 

**示例 1：**

**输入：**s = "()"

**输出：**true 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            switch(s[i]){
                case '(': st.push(')'); continue;
                case '[': st.push(']'); continue;
                case '{': st.push('}'); continue;
                case ')': if(st.empty() || st.top() != ')') return false; st.pop(); continue;
                case ']': if(st.empty() || st.top() != ']') return false; st.pop(); continue;
                case '}': if(st.empty() || st.top() != '}') return false; st.pop(); continue;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
```



5 

43

8 

32 



# 二分查找

### [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)

中等

整数数组 `nums` 按升序排列，数组中的值 **互不相同** 。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **向左旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,5,6,7]` 下标 `3` 上向左旋转后可能变为 `[4,5,6,7,0,1,2]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，如果 `nums` 中存在这个目标值 `target` ，则返回它的下标，否则返回 `-1` 。

你必须设计一个时间复杂度为 `O(log n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

**示例 2：**

```
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
```

**示例 3：**

```
输入：nums = [1], target = 0
输出：-1
```

**提示：**

- `1 <= nums.length <= 5000`
- `-104 <= nums[i] <= 104`
- `nums` 中的每个值都 **独一无二**
- 题目数据保证 `nums` 在预先未知的某个下标上进行了旋转
- `-104 <= target <= 104`

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int kk = 0;
        int pre = 0; //记录i-1 位置
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < nums[pre]){ //不能直接用nums[i-1]、nums[i+1] 因为可能越界
                kk = pre; //i-1
                break;
            }
            pre = i;
        }
        auto it = nums.begin();
        // bool judge = binary_search(Iterator1, Iterator2, target); //判断存在性
        auto left = lower_bound(it, it+kk, target); //lower_bound 返回第一个 >= target的迭代器
        if(left != nums.end() && *left == target){
            return left - nums.begin(); //iterator - iterator 结果是迭代器的距离
        }
        auto right = lower_bound(nums.begin()+kk+1, nums.end(), target);
        if(right != nums.end() && *right == target){
            return right - nums.begin();
        }
        return -1;
    }
};
```

tips:


34 

300 



# ！BFS

752 

210 

127 

317 

815

# ！DFS，回溯

某些纯 暴力解 都不能解决的问题，可能就需要用回溯算法了（回溯 就是递归返回时的地方，回溯就在递归中）。
回溯也是暴力算法。

适用回溯算法的问题有那些：
组合问题、排列问题、切割问题、子集问题、棋盘问题

如何理解回溯法：
1、回溯法都适用n叉树模型
2、回溯的递归函数一遍没有返回值类型
3、终止条件一般在叶子节点，也就是递归出口
4、

### [46. 全排列](https://leetcode.cn/problems/permutations/)

中等

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**示例 2：**

```
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

**示例 3：**

```
输入：nums = [1]
输出：[[1]]
```

**提示：**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数 **互不相同**

```c++
class Solution { //错误尝试
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size()+1, 0);
        backTracking(nums, nums.size()-1, used);
        return result;
    }

    void backTracking(vector<int> &nums, int level, vector<int> &used){
        if(level < 0){
            return;
        }

        // vector<int> cur(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            if(used[i] == 0){
                result[level].push_back(i);
                used[i] = 1;
                backTracking(nums, level--, used);
                used[i] = 0;
                result[level].pop_back();
            }
        }
    }

    vector<vector<int>> result {};
};
```





```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size() + 1, 0); //到达某level时，用于过滤掉已经使用过的nums
        vector<int> path; //记录排列
        backTracking(nums, nums.size(), used, path);
        return result;
    }

    void backTracking(vector<int>& nums, int level,
                      vector<int>& used, vector<int>& path) {
        if (level == 0) { //递归出口
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 0) {
                path.push_back(nums[i]);   // 用元素值
                used[i] = 1;

                backTracking(nums, level - 1, used, path);

                used[i] = 0; //回溯used
                path.pop_back(); //回溯path
            }
        }
    }

    vector<vector<int>> result;
};
```



130 

547 

17 

332 

# 动态规划

### [139. 单词拆分](https://leetcode.cn/problems/word-break/)

中等

给你一个字符串 `s` 和一个字符串列表 `wordDict` 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 `s` 则返回 `true`。

**注意：**不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

**示例 1：**

```
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
```

**示例 2：**

```
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
```

**示例 3：**

```
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
```

**提示：**

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` 和 `wordDict[i]` 仅由小写英文字母组成
- `wordDict` 中的所有字符串 **互不相同**

```c++
class Solution { //回溯 （用例超时版本）
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool judge = false;
        unordered_set<string> words;
        for(auto word: wordDict){
            words.insert(word);
        }

        backTracking(s, words, s.size(), judge);
        return judge;
    }

    void backTracking(string s, unordered_set<string>& words, int level, bool& judge){
        if(level == 0){
            judge = true;
            return;
        }
        for(int i = 0; i < s.size(); ++i){
            string preStr = s.substr(0, i+1);
            if(words.find(preStr) != words.end()){
                backTracking(s.substr(i+1), words, s.size()-i-1, judge);
            }
        }
    }
};
```
但是用例
s =
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
wordDict =
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
超时了，请指出我代码中的问题，并在原有思路的命名习惯的基础上修正代码，在关键地方加上详细注解

主要问题（简要）

1. **result 未初始化大小**：`result[level]` 直接访问会越界
2. **level-- 用错**：递归参数不应修改当前层的 `level`
3. **回溯条件错误**：`level < 0` 时应保存结果
4. **存的是索引 i，而不是 nums[i]**
5. **used 多开一位无意义**

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool judge = false;
        unordered_set<string> words;
        for (auto& word : wordDict) {
            words.insert(word);
        }

        unordered_set<string> failStr; // 记忆化：某个 s 是否已经失败
        backTracking(s, words, judge, failStr);
        return judge;
    }

    void backTracking(string s,
                      unordered_set<string>& words,
                      bool& judge,
                      unordered_set<string>& failStr) {

        // 如果已经找到答案，直接剪枝
        if (judge) return;

        // 空串，说明成功切分
        if (s.empty()) {
            judge = true;
            return;
        }

        // 如果这个 s 之前已经判断为“不可拆分”，直接返回
        if (failStr.count(s)) return;

        // 枚举前缀
        for (int i = 0; i < s.size(); ++i) {
            string preStr = s.substr(0, i + 1);

            if (words.find(preStr) != words.end()) {
                string restStr = s.substr(i + 1);
                backTracking(restStr, words, judge, failStr);

                // 一旦成功，立刻结束
                if (judge) return;
            }
        }

        // 能走到这里，说明 s 无论如何都拆不开
        failStr.insert(s);
    }
};
```

```c++
class Solution {//动态规划 gpt
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();
        // dp[i]: 前 i 个字符是否可以被拆分
        vector<bool> dp(n + 1, false);

        dp[0] = true; // 空字符串

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // 已经能拆分，不用再试
                }
            }
        }

        return dp[n];
    }
};

```
现在再看：它为什么**一定是 DP**

我们对照动态规划的三要素：

| 要素       | 在 139 中的体现                   |
| ---------- | --------------------------------- |
| 状态       | `dp[i]`                           |
| 转移       | `dp[i] ← dp[j] && 子串合法`       |
| 重叠子问题 | 多个 `i` 会反复依赖相同的 `dp[j]` |

✔ 完整
 ✔ 标准
 ✔ 教科书级 DP

一句话帮你“建立 DP 直觉”

**只要问题是：
「前 i 个能不能 / 行不行 / 合不合法」
那 90% 都是 DP**

122 

62 

64 

871 

# 贪心

45 

452 

435

621 

135

# 字典树

820 

648 

### [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)

中等

**[Trie](https://baike.baidu.com/item/字典树/9825209?fr=aladdin)**（发音类似 "try"）或者说 **前缀树** 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

请你实现 Trie 类：

- `Trie()` 初始化前缀树对象。
- `void insert(String word)` 向前缀树中插入字符串 `word` 。
- `boolean search(String word)` 如果字符串 `word` 在前缀树中，返回 `true`（即，在检索之前已经插入）；否则，返回 `false` 。
- `boolean startsWith(String prefix)` 如果之前已经插入的字符串 `word` 的前缀之一为 `prefix` ，返回 `true` ；否则，返回 `false` 。

**示例：**

```
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```



```c++
class Trie {//什么try树，不懂。我这个是hash树
public:
    Trie():box() {
        return;
    }
    
    void insert(string word) {
        box.insert(word);
    }
    
    bool search(string word) {
        if(box.find(word) != box.end())
            return true;
        return false;   
    }
    
    bool startsWith(string prefix) {
        if(search(prefix))
            return true;
        
        int size = prefix.size();
        for(auto word: box){
            if(word.size() <= size) continue;
            for(int i = 0; i < size; ++i){
                if(word[i] == prefix[i]){
                    if(i == size-1){
                        return true;
                    }
                    continue;
                } else{
                    break;
                }
            }

        }
        return false;
    }
    unordered_set<string> box;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```



```c++
class Trie {//标准解法 (gpt解法)
private:
    // Trie 中的每一个节点
    struct TrieNode {
        // children[i] 表示当前节点的第 i 个子节点
        // i = 0 -> 'a', i = 25 -> 'z'
        TrieNode* children[26];

        // 标记：是否有单词在此结束
        bool isEnd;

        TrieNode() : isEnd(false) {
            // 初始化所有孩子指针为空
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    // Trie 的根节点（不存任何字符）
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;

        // 从第一个字符开始逐个插入
        for (char c : word) {
            int index = c - 'a';

            // 如果对应子节点不存在，就新建
            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }

            // 向下走一层
            cur = cur->children[index];
        }

        // 单词完整插入完毕，在最后一个节点打标记
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int index = c - 'a';

            // 如果路径断了，说明不存在这个单词
            if (cur->children[index] == nullptr)
                return false;

            cur = cur->children[index];
        }

        // 必须是一个“完整单词”结尾
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for (char c : prefix) {
            int index = c - 'a';

            // 只要路径断了，说明没有任何单词以该前缀开头
            if (cur->children[index] == nullptr)
                return false;

            cur = cur->children[index];
        }

        // 能完整走完 prefix，就一定存在以它为前缀的单词
        return true;
    }
};
```



140 

1032

# 哈希

554 

781 

846 

460 

1224

# ！双指针

11 

15 

42 

18 

1163

# ！栈

71 

394 

1190 

84 

224

