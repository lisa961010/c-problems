#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};




struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
        val(x), next(NULL) {
        }
};


int jumpFloorII(int n) {
    int result = 1;
    if(n == 1){
        return 1;
    } else if(n == 2){
        return 2;
    } else {
        for (int i = 1; i < n; ++i) {
            int j = jumpFloorII(n-i);
            result = result + j;
        }
        return result;
    }
}


int rectCover(int n) {
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else if(n <= 0){
        return 0;
    }else {
        return rectCover(n-1) + rectCover(n-2);
    }
}
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if (pNode == NULL)
    {
        return NULL;
    }

    if (pNode->right != NULL)
    {
        pNode = pNode->right;
        if (pNode->left != NULL)
        {
            while (pNode->left != NULL)
            {
                pNode = pNode->left;
            }
            return pNode;
        }else{
            return pNode;
        }
    }else{
        if(pNode->next != NULL)
        {
            if(pNode->next->right == pNode)
            {
                if(pNode->next->next == NULL)
                {
                    return NULL;
                }
                while (pNode->next->next->right == pNode->next)
                {
                    pNode = pNode->next;
                    if(pNode->next->next == NULL)
                    {
                        return NULL;
                    }
                }
                return pNode->next->next;
            }else{
                return pNode->next;
            }
        }else {
            return NULL;
        }
    }
}

 */








/*
bool judgeSymmetrical(TreeNode* p1, TreeNode* p2)
{
    if(p1 == NULL && p2 == NULL)
    {
        return true;
    }
    else if (p1 == NULL || p2 == NULL)
    {
        return false;
    }
    else if (p1->val != p2->val)
    {
        return false;
    }
    else
    {
        return judgeSymmetrical(p1->left,p2->right) && judgeSymmetrical(p1->right,p2->left);
    }
}

bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot == NULL)
    {
        return true;
    }
    return judgeSymmetrical(pRoot->left, pRoot->right);
}

*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


/*

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> result;
    queue<TreeNode*> s;

    if(pRoot)
    {
        s.push(pRoot);
    }

    while(!s.empty())
    {
        int n = s.size();
        vector<int> tmp;

        for (int i = 0; i < n; ++i) {
            TreeNode* t = s.front();
            tmp.push_back(t->val);
            if(t->left != NULL)
            {
                s.push(t->left);
            }
            if(t->right != NULL)
            {
                s.push(t->right);
            }
            s.pop();
        }
        result.push_back(tmp);
    }
    return result;
}
*/


/*vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> result;
    queue<TreeNode*> q;

    bool flag = true;

    if(pRoot == NULL)
    {
        return result;
    }

    q.push(pRoot);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> tmp(n,0);

        if(flag == true)
        {
            for (int j = 0; j < n; ++j) {
                tmp[j] = q.front()->val;
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        else
        {
            for (int j = 0; j < n; ++j) {
                tmp[n-1-j] = q.front()->val;
                if(q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        flag = !flag;
        result.push_back(tmp);
    }
    return result;
}*/





char* Serialize(TreeNode *root) {
    char* res;
    string s;

    if(root == NULL)
    {
        return (char*)'#';
    }

    string tmp = to_string(root->val) + ',';

    s = tmp + string(Serialize(root->left)) + string(Serialize(root->right));

    res = (char*)s.data();
    return  res;
}



TreeNode* Deserialize(char *str) {
    TreeNode* res;
    string s = str;

    if(str == NULL || str == (char*)'#')
    {
        return NULL;
    }

    res->left = Deserialize(str)->left;
    res->val = Deserialize(str)->val;
    res->right = Deserialize(str)->right;

    return res;
}



/*

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false

bool duplicate(int numbers[], int length, int* duplication) {
    if(numbers == NULL || length == NULL || length < 1)
    {
        duplication = NULL;
        return false;
    }

    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] < 0 || numbers[i] > (length-1) )
        {
            duplication = NULL;
            return false;
        }
    }

    for (int i = 0; i < length;) {
        if (numbers[i] != i)
        {
            if(numbers[i] != numbers[numbers[i]])
            {
                swap(numbers[i],numbers[numbers[i]]);
            }
            else{
                *duplication = numbers[i];
                return true;
            }
        }
        else
        {
            ++i;
        }
    }

    duplication = NULL;
    return false;
}
*/


/*
vector<int> multiply(const vector<int>& A) {
//    构建乘积数组
    //给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
    // 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
    // 不能使用除法。

    int n = A.size();

    vector<int> B(n);
    vector<int> v1(n);
    vector<int> v2(n);

    v1[0] = 1;
    v2[n-1] = 1;

    for (int l = 1; l < n; ++l) {
        v1[l] = v1[l-1] * A[l-1];
    }

    for (int m = n - 2; m >= 0; --m) {
        v2[m] = v2[m+1] * A[m+1];
    }

    for(int i = 0; i < n; i++)
    {
        B[i] = v1[i] * v2[i];
    }

    return B;
}*/



/*

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    //    给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//    例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
//    那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
//    针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
//    {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
//    {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

    int n = num.size();
    vector<int> res;

    if(num.empty() ||size > n || size < 1)
    {
        return res;
    }

    for (int i = 0; i <= (n - size); ++i) {

        int tmp = num[i];
        for (int j = i; j < (i + size); ++j) {
            if (num[j] > tmp)
            {
                tmp = num[j];
            }
        }
        res.push_back(tmp);
    }
    return res;
}

*/



/*

stack<int> stack1;
stack<int> stack2;

//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
void push(int node) {
    stack1.push(node);
}

int pop() {
    int res;

    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    res = stack2.top();
    stack2.pop();
    return res;
}

*/

/*

int FindGreatestSumOfSubArray(vector<int> array) {

//    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
//    在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//    但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//    例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
//    给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

    int n = array.size();
    int res;
    if (n <= 1)
    {
        return NULL;
    }

    vector<int> v;

    int max = array[0];
    res = array[0];

    for (int i = 1; i < n; ++i) {
        if ((max +array[i]) >array[i])
        {
            max = max + array[i];
        }
        else
        {
            max = array[i];
        }

        if (max > res)
        {
            res = max;
        }
    }

    return  res;
}

*/



/*

int NumberOf1Between1AndN_Solution(int n)
{
//    求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//    为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
//    ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

    int res = 0;
    if (n < 1)
    {
        return NULL;
    }

    for (int i = 1; i <= n; ++i) {
        int tmp = i;
        while (tmp/10 > 0)
        {
            if (tmp%10 == 1)
            {
                res++;
            }
            tmp = tmp/10;
        }

        if (tmp%10 == 1)
        {
            res++;
        }
    }

    return res;
}

*/


string PrintMinNumber(vector<int> numbers) {
//    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//    例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

    string res;
    int n = numbers.size();

    if (numbers.empty() || n <= 0)
    {
        return "";
    }

    for (int i = 0; i < n; ++i)
    {
        if(numbers[i] <= 0)
        {
            return "";
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string a = to_string(i) + to_string(j);
            string b = to_string(j) + to_string(i);
            if (a > b)
            {

            }


        }
    }


    return res;
}










int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<< "test"<< endl;
//    cout<< NumberOf1Between1AndN_Solution(13) << endl;



    return 0;
}


