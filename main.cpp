#include <iostream>
#include <vector>
#include <string>

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






int main() {
    //std::cout << "Hello, World!" << std::endl;

    cout<< "test"<< endl;

    return 0;
}


