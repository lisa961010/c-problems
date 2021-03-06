#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

#include "sort.h"

using namespace std;

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

/*
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


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/


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

/*

static bool cmp(int x, int y) {
    string a = to_string(x) + to_string(y);
    string b = to_string(y) + to_string(x);
    return a < b;
}


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

    sort(numbers.begin(),numbers.end(),cmp);


    for (int j = 0; j < n; ++j) {
        res = res + to_string(numbers[j]);
    }

    return res;
}

*/






/*

//static bool cmp(int x, int y)
//{
//    return x < y;
//}


int GetUglyNumber_Solution(int index) {
//    把只包含质因子2、3和5的数称作丑数（Ugly Number）。
//    例如6、8都是丑数，但14不是，因为它包含质因子7。
//    习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

    int res;

    if (index < 1)
    {
        return NULL;
    }

    vector<int> tmp(index);
    int a = 0;
    int b = 0;
    int c = 0;
    tmp[0] = 1;

    for (int i = 1; i < index; ++i)
    {
        tmp[i] = min(2*tmp[a],min(3*tmp[b],5*tmp[c]));
        if (tmp[i] == 2*tmp[a])
        {
            a++;
        }
        if (tmp[i] == 3*tmp[b])
        {
            b++;
        }
        if (tmp[i] == 5*tmp[c])
        {
            c++;
        }
    }

    res = tmp[index-1];
    return res;
}

*/


/*

int FirstNotRepeatingChar(string str) {

//    在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
//    返回它的位置, 如果没有则返回 -1 (需要区分大小写)

    int res = -1;
    if (str.size() < 0 || str.size() > 10000)
    {
        return -1;
    }

    vector<int> tmp(256);

    int n = str.size();
    for (int i = 0; i < n; ++i) {
        tmp[str[i]]++;
    }

    for (int j = 0; j < n; ++j) {
        if (tmp[str[j]] == 1)
        {
            return j;
        }
    }

    return -1;

}

*/



/*

int minNumberInRotateArray(vector<int> rotateArray) {
//    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//    输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
//    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。?

    int n = rotateArray.size();
    if (n == 0)
    {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (rotateArray[0] <= 0)
        {
            return 0;
        }
    }

    for (int j = n-1; j >= 0; --j) {
        if (rotateArray[j] < rotateArray[j-1])
        {
            return rotateArray[j];
        }
    }

    return rotateArray[0];
}

*/



/*

int MoreThanHalfNum_Solution(vector<int> numbers) {
//    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//    例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//    由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

    int n = numbers.size();
    int cmp = n/2;
    int tmp = 1;
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return numbers[0];
    }

    sort(numbers.begin(),numbers.end());

    for (int i = 1; i < n; ++i) {
        if (numbers[i] == numbers[i-1])
        {
            tmp++;
            if (tmp > cmp)
            {
                return numbers[i];
            }
        }
        else
        {
            tmp = 1;
        }
    }

    return 0;
}

*/





/*vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//    输入n个整数，找出其中最小的K个数。
//    例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

    vector<int> res;

    int n = input.size();
    if (n == 0 || k > n)
    {
        return res;
    }

    sort(input.begin(),input.end());


    for (int i = 0; i < k; ++i) {
        res.push_back(input[i]);
    }

    return res;

}*/




int InversePairs(vector<int> data) {
//    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//    输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

//    题目保证输入的数组中没有的相同的数字,数据范围：
//    对于%50的数据,size<=10^4; 对于%75的数据,size<=10^5; 对于%100的数据,size<=2*10^5


    int n = data.size();
    if (n == 0)
    {
        return 0;
    }

    int res = 0;

    for (int j = 0; j < n-1; ++j) {
        for (int k = j; k < n; ++k) {
            if (data[j] > data[k])
            {
                res++;
            }
        }
    }

    res = res%1000000007;

    return res;
}




/*

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
//    输入两个链表，找出它们的第一个公共结点。

    ListNode* res;

    if (pHead1 == NULL || pHead2 == NULL)
    {
        return NULL;
    }

    ListNode* s1 = pHead1;
    ListNode* s2 = pHead2;


    while (pHead1 != NULL)
    {
        while (pHead2 != NULL)
        {
            if (pHead1 != pHead2)
            {
                pHead2 = pHead2->next;
            }else{
                return pHead1;
            }
        }
        pHead2 = s2;
        pHead1 = pHead1->next;
    }
    return NULL;
}

*/



/*
bool IsContinuous( vector<int> numbers ) {

//    LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)
//    他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
//    “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
//    LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
//    上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
//    现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何，
//    如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

    int n = numbers.size();
    int tmp = 0;
    int count = 0;
    int i = 4;

    if (n != 5)
    {
        return false;
    }

    sort(numbers.begin(), numbers.end());

    while (numbers[tmp] == 0)
    {
        tmp++;
    }

    while (i != tmp)
    {
        if (numbers[i] == numbers[i-1])
        {
            return false;
        }

        count = count + (numbers[i] - numbers[i-1] - 1);
        i--;
    }

    if (tmp >= count)
    {
        return true;
    }

    return false;
}
*/


/*

int LastRemaining_Solution(int n, int m)
{
//    每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
//    HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
//    首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
//    每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
//    从他的下一个小朋友开始,继续0...m-1报数....这样下去....
//    直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
//    请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

    vector<int> tmp(n);
    vector<int> u(n);
    int p = 0;

    if (n <= 0 || m <= 0)
    {
        return -1;
    }

    for (int j = 0; j < n-1; ++j) {
        for (int k = 0; k < m; ++k) {
            while (tmp[p] != 0)
            {
                if (p == n-1)
                {
                    p = 0;
                }
                else
                {
                    p++;
                }
            }
            if (p == n-1)
            {
                p = 0;
            }
            else
            {
                p++;
            }
        }
        if (p == 0)
        {
            p = n-1;
        }
        else
        {
            p--;
        }
        tmp[p] = 1;
        if (p == n-1)
        {
            p = 0;
        }
        else
        {
            p++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (tmp[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

*/




/*
int Sum_Solution(int n) {
//    求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

    int res = 0;
    n && (res = Sum_Solution(n-1) + n);
    return res;
}
*/



int Add(int num1, int num2)
{
//    写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

    while (num2 != 0)
    {
        int tmp = num1^num2;
        num2 = (num1&num2)<<1;
        num1 = tmp;
    }

    return num1;
}








int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<< "test"<< endl;
//    cout<< NumberOf1Between1AndN_Solution(13) << endl;


    /*vector<int> data{1,2,3,4,5,6,7,0};
    cout<<InversePairs(data) <<endl;

    vector<int> output = sort1(data);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << "  ";
    }*/


//    cout << IsContinuous({1,3,0,0,5});

//    cout << LastRemaining_Solution(5,3);

//    cout << Sum_Solution(4);




    return 0;
}


