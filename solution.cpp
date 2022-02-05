#include "solution.h"

#include <functional>
#include <queue>
using namespace sol1602;
using namespace std;

/*takeaways
  - you want to find things at the same level
    - use BFS
    - in this case we scan from left to right
      at the same level
    - so if the target is not the very last
      element at the queue, then the next
      one in the front of the queue is the
      answer - don't forget we are scanning
      from left to right

*/

Node *Solution::nextRight(Node *tree, int target)
{
    queue<Node *> q;
    q.push(tree);

    while (!q.empty())
    {
        auto size = q.size();
        while (size > 0)
        {
            auto node = q.front();
            q.pop();
            if (node->val == target)
            {
                /* last element at this level */
                if (size == 1)
                    return nullptr;
                /* this is your immediate right */
                return q.front();
            }

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            size--;
        }
    }

    return nullptr;
}