// 6.51
void func_6_51(node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL || root->right != NULL)
    {
        printf("(");
    }

    func_6_51(root->left);

    printf("%c", root->data);

    printExfunc_6_51pression(root->right);

    if (root->left != NULL || root->right != NULL)
    {
        printf(")");
    }
}

// 6.543
node* buildBinaryTree(list sa)
{
    node* root = NULL;
    for (int i = 1; i <= sa.last; i++)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = sa.elem[i];
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            int level = 0;
            int index = i;
            while (index > 1)
            {
                index /= 2;
                level++;
            }

            node* parent = root;
            for (int j = level - 1; j > 0; j--)
            {
                if (i & (1 << (j - 1)))
                {
                    parent = parent->right;
                }
                else
                {
                    parent = parent->left;
                }
            }

            if (i & 1)
            {
                parent->right = newNode;
            }
            else
            {
                parent->left = newNode;
            }
        }
    }

    return root;
}

// 6.56
node* findPreorderSuccessor(node* root, node* p)
{
    if (p->right != NULL)
    {
        return p->right;
    }

    if (p->isThreaded)
    {
        return p->right;
    }

    node* ancestor = root;
    while (ancestor != NULL && ancestor->right == NULL)
    {
        ancestor = ancestor->left;
    }

    if (ancestor != NULL)
    {
        return ancestor->right;
    }

    return NULL;
}

void preorderThread(node* root, node** prev)
{
    if (root != NULL)
    {
        node* node = (node*)malloc(sizeof(node));
        node->data = root->data;
        node->left = NULL;
        node->right = NULL;
        node->isThreaded = 0;
        if (*prev != NULL)
        {
            (*prev)->right = node;
            (*prev)->isThreaded = 1;
        }
        *prev = node;
        preorderThread(root->left, prev);
        preorderThread(root->right, prev);
    }
}

node* createPreorderThreadedTree(node* root)
{
    node* threadedRoot = NULL;
    node* prev = NULL;
    preorderThread(root, &prev);
    node* current = threadedRoot;
    while (current != NULL && current->isThreaded == 0)
    {
        threadedRoot = current;
        current = current->left;
    }
    return threadedRoot;
}

int tree_depth(PTree tree)
{
    int maxDepth = 0;
    for (int i = 0; i < tree.n; ++i)
    {
        int depth = 1;
        int parent = tree.nodes[i].parent;
        while (parent != -1)
        {
            parent = tree.nodes[parent].parent;
            ++depth;
        }
        if (depth > maxDepth)
        {
            maxDepth = depth;
        }
    }
    return maxDepth;
}

// 7.24
void func_7_24(int u)
{
    stack<int> stk;
    bool vis[V] = {false};
    stk.push(u);
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        for (int v : G[u])
        {
            if (!vis[v])
            {
                stk.push(v);
            }
        }
    }
}

// 7.25
bool has_cycle()
{
    std::vector<int> indegree(V, 0);
    for (int u = 0; u < V; ++u)
    {
        for (int v : adjList[u])
        {
            indegree[v]++;
        }
    }
    stack<int> stack;
    for (int u = 0; u < V; ++u)
    {
        if (indegree[u] == 0)
        {
            stack.push(u);
        }
    }
    while (!stack.empty())
    {
        int u = stack.top();
        stack.pop();
        vis[u] = true;
        for (int v : adjList[u])
        {
            if (!vis[v])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    stack.push(v);
                }
            }
            else
            {
                return true;
            }
        }
    }
    for (int u = 0; u < V; ++u)
    {
        if (!vis[u])
        {
            return true;
        }
    }
    return false;
}

// 7.28
void findAllPathsUtil(int u, int v, std::vector<int>& path)
{
    path.push_back(u);
    vis[u] = true;

    if (u == v)
    {
        printPath(path);
    }
    else
    {
        for (int neighbor : adjList[u])
        {
            if (!vis[neighbor])
            {
                findAllPathsUtil(neighbor, v, path);
            }
        }
    }

    vis[u] = false;
    path.pop_back();
}

// 7.31

int tim, tot, out[N], dfn[N], low[N], c[N], sum[N];
bool vis[N];
stack<int> stk;
vector<int> G[N];

void tarjan(int u)
{
    stk.emplace(u);
    vis[u] = 1;
    low[u] = dfn[u] = ++tim;
    for (int v : G[u])
    {
        if (dfn[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            vis[v] = 0;
            c[v] = tot;
            sum[tot]++;
        } while (u != v);
        tot++;
    }
}
// tarjan算法求强联通分量，时间复杂度O(n + m)

// 7.35
Node* findDAGRoot(std::vector<Node*>& nodes)
{
    unordered_set<Node*> inDegreeSet;
    for (Node* node : nodes)
    {
        inDegreeSet.insert(node);
        for (Node* neighbor : node->neighbors)
        {
            inDegreeSet.erase(neighbor);
        }
    }
    if (!inDegreeSet.empty())
    {
        return *inDegreeSet.begin();
    }
    return nullptr;
}

// 7.41
int findRoot()
{
    for (int i = 0; i < V; ++i)
    {
        if (inDegree[i] == 0)
        {
            return i; 
        }
    }

    return -1; 
}

void findCriticalPath()
{
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    latest[V - 1] = earliest[V - 1];

    for (int i = V - 2; i >= 0; --i)
    {
        for (auto edge : adjList[i])
        {
            int v = edge.first;
            int weight = edge.second;
            latest[i] = std::min(latest[i] == -1 ? INT_MAX : latest[i], latest[v] - weight);
        }
    }
}
