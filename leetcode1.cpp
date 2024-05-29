#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2(int x) : val(x), left(NULL), right(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
// Baseball game 
// Time O(n)  Space O(n)
 int calPoints(vector<string>& operations) {
        vector<int> scores;
        int size = 0;

        for (auto i : operations) {
            if (i == "+") {
                scores.push_back(scores[size - 1] + scores[size - 2]);
                size++;
            } else if (i == "D") {
                scores.push_back(2 * scores[size - 1]);
                size++;
            } else if (i == "C") {
                size--;
                scores.pop_back();
            } else {
                size++;
                scores.push_back(stoi(i));
            }
        }

        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += scores[i];
        }
        return sum;
    }

    // First unique character in a string 
    // Time O(n) Space O(1)
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

       
        for (char c : s) {
            freq[c]++;
        }

      
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1; 
    }
// 3. Last Stone Weight
// Time: O(nlogn) Space: O(n)
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(abs(x - y));
            }
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
//4.Final Prices With a Special Discount in a Shop
//Time:O(n)  Space:O(n)
vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        for(int i = 0; i < prices.size(); i++) {
            int flag = 0;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {
                    flag = 1;
                    result.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if(flag == 0) {
                result.push_back(prices[i]);
            }
        }
        return result;
    }
// Palindrome list
// Time:O(n) Space: O(n)
bool isPalindromee(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = head;
        stack<int> st;
        while (curr != NULL) {
            st.push(curr->val);
            curr = curr->next;
        }
        while (temp != NULL) {
            int x = st.top();
            st.pop();
            if (x != temp->val) {
                return false;
            }
            else {
                temp = temp->next;
            }
        }
        return true;
    }

// 6. Reverse linked list
// Time:O(n) Space:O(1)
ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while (cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
    
//7. Middle of the linked list
// Time:O(n) Space: O(1)
 ListNode* middleNode(ListNode* head) {
        ListNode *a, *b;
        a = b = head;

        while(a && a->next)
        {
            a = a->next->next;
            b = b->next;
        }
        return b;
    }
//8. Merge Two Sorted List
// Time:O(m+n) Space:O(1)
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy.next;
    }
//9. Palindrome list
// Time:O(n)  Space:O(1)
bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = head;
        stack<int> st;
        while (curr != NULL) {
            st.push(curr->val);
            curr = curr->next;
        }
        while (temp != NULL) {
            int x = st.top();
            st.pop();
            if (x != temp->val) {
                return false;
            }
            else {
                temp = temp->next;
            }
        }
        return true;
    }
// 10. Remove linked lists elements
// Time:O(n)  Space:O(1)
 ListNode* removeElements(ListNode* head, int val) {
    if (!head) {
        return head;
    }
    else {
        ListNode* h = removeElements(head->next, val);
        if (head->val == val)
        {
            return h;
        }
        else {
            head->next = h;
        }
        return head;
    }
}
//11. Binary tree Preorder Traversal
//Time:O(n)  Space: O(h) h-hight of the tree
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        
        if(root == nullptr)
            return result;
        
        nodeStack.push(root);
        
        while(!nodeStack.empty()) {
            TreeNode* current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val);
            
            if(current->right != nullptr)
                nodeStack.push(current->right);
            
            if(current->left != nullptr)
                nodeStack.push(current->left);
        }
        
        return result;
    }
// 12. Binary Tree Postorder Traversal
// Time:O(n) Space: O(h)
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* lastVisited = nullptr;

        while (root != nullptr || !nodeStack.empty()) {
            if (root != nullptr) {
                nodeStack.push(root);
                root = root->left;
            } else {
                TreeNode* peekNode = nodeStack.top();
                if (peekNode->right != nullptr && peekNode->right != lastVisited) {
                    root = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    nodeStack.pop();
                }
            }
        }

        return result;
    }
// 13 Binary Tree Inorder Traversal
// Time: O(n)  Space: O(h)
  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;

        while (currentNode != nullptr || !nodeStack.empty()) {
            while (currentNode != nullptr) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(currentNode->val);
            currentNode = currentNode->right;
        }

        return result;
    }

// 14. Sum of left leaves
// Time:O(n) Space: O(h)

int sum=0;
void sumOfLeftLeaves(TreeNode* root, bool ifLeft){
    if(ifLeft && !root->left && !root->right){
        sum += root->val;
        return;
    }
    if(root->left) sumOfLeftLeaves(root->left, true);
    if(root->right) sumOfLeftLeaves(root->right, false);
}
public:
    int sumOfLeftLeaves(TreeNode* root) {
     if(!root) return 0;
     sumOfLeftLeaves(root, false);
     return sum;
    }

//15.Root equals sum of children
//Time: O(1) Space: O(1)
 bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }

//16. Two Sum 
// Time:O(n^2)  Space:O(1)
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int size = nums.size();
        for(int i = 0; i < size -1 ; i++){
            for(int j = i+1 ; j < size; j++){
                if (nums[i]+ nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
// 17.Contains duplicate
// Time:O(n)  Space:O(n)
 bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int x = nums.size();
        int y = s.size();
        if (x == y) {
            return false;
        } else {
            return true;
        }
    }
//18. Find the differences
// Time:O(n)   Space:O(1)
 char findTheDifference(string s, string t) {
        char c = 0;
        for (char cs : s) 
            c ^= cs;
        for (char ct : t) 
            c ^= ct;
        return c;
    }
//19. Missing numbers
// Time:O(n) Space: O(n)
 int missingNumber(vector<int>& nums) {
    unordered_map<int, bool> hash_table;

    for (int i = 0; i < nums.size(); i++) {
        hash_table[nums.at(i)] = true;
    }

    for (int i = 0; i <= nums.size(); ++i) {
        if (hash_table.find(i) == hash_table.end()) {
            return i;
        }
    }

    return -1;
}
//20. Jewels and stones
// Time:O(n*m)  Space:O(1)
   int numJewelsInStones(string J, string S) {
       int count = 0;
       for (char c : S) {
           if (J.find(c) !=-1)
               count++;
       }
       return count;
   }




};


int main() {
    Solution sol;
    int solutions;
    cout<<"Ereza Greicevci leetcode problems"<<endl;
    cout<<endl;
    cout<<"Stack & Queue"<<endl;
    cout<<"Press 1 for: Baseball Game" <<endl;
    cout<<"Press 2 for: First unique character in a string" <<endl;
    cout<<"Press 3 for: Last Stone Weight" <<endl;
    cout<<"Press 4 for: Final Prices With a Special Discount in a Shop"<<endl;
    cout<<"Press 5 for: Palindrome list" <<endl;
    cout<<endl;
    cout<<"Linked List"<<endl;
    cout<<"Press 6 for: Reverse Linked List " <<endl;
    cout<<"Press 7 for: Middle of the linked list " <<endl;
    cout<<"Press 8 for: Merge Two Sorted Lists" <<endl;
    cout<<"Press 9 for: Palindrome List" <<endl;
    cout<<"Press 10 for: Remove linked list elements" <<endl<<endl;
    cout<<"Binary tree"<< endl;
    cout<<"Press 11 for: Binary Tree Preorder Traversal " <<endl;
    cout<<"Press 12 for: Binary Tree Postorder Traversal" <<endl;
    cout<<"Press 13 for: Binary Tree Inorder Traversal" <<endl;
    cout<<"Press 14 for: Sum of left leaves" <<endl;
    cout<<"Press 15 for: Root equals sum of children" <<endl<<endl;
    cout<<"Hash tables"<<endl;
    cout<<"Press 16 for: Two Sum" <<endl;
    cout<<"Press 17 for: Contains Duplicate" <<endl;
    cout<<"Press 18 for: Find the Differences" <<endl;
    cout<<"Press 19 for: Missing numbers " <<endl;
    cout<<"Press 20 for: Jewels and Stones" <<endl<<endl;
   
    
    cin>> solutions;
 
    switch(solutions){
     case 1:
     {
         vector<string> operations = {"5", "2", "C", "D", "+"};
         cout << "Total points: " << sol.calPoints(operations) << endl;
         break;
     }
     case 2:
     {
         cout << "First unique character in 'leetcode': " << 
         sol.firstUniqChar("leetcode") << endl;
         cout << "First unique character in 'loveleetcode': " << 
         sol.firstUniqChar("loveleetcode") << endl;
         break;
    }
    case 3:
    {
        vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << "Last stone weight for stones 1: " << sol.lastStoneWeight(stones1) << endl;

    vector<int> stones2 = {5, 5, 5, 5};
    cout << "Last stone weight for stones 2: " << sol.lastStoneWeight(stones2) << endl;
    break;
    }
    case 4:
    {
      vector<int> prices = {8, 4, 6, 2, 3};
    
    vector<int> finalPrices = sol.finalPrices(prices);
    
    cout << "Original Prices: ";
    for(int price : prices) {
        cout << price << " ";
    }
    cout << endl;
    
    cout << "Final Prices after discount: ";
    for(int finalPrice : finalPrices) {
        cout << finalPrice << " ";
    }
    cout << endl;
   break;
    }
    case 5:
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        ListNode* current = head;
        cout << "Linked list elements: ";
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }cout << endl;
        bool result = sol.isPalindromee(head);

        cout << "Is the linked list a palindrome? " << (result ? "Yes" : "No") << endl;    
        break;

    }
    case 6:
    {
  ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = sol.reverseList(head);

    ListNode* temp = reversedHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    break;
    }
    case 7:
    {
       ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = sol.middleNode(head);

    cout << "The middle node value is: " << middle->val << endl;
    break;
    }
    
    case 8:
    {
       ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* mergedList = sol.mergeTwoLists(l1, l2);

    cout << "Merged sorted list: ";
    ListNode* temp = mergedList;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    break;
    }
    case 9:
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        ListNode* current = head;
        cout << "Linked list elements: ";
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }cout << endl;
        bool result = sol.isPalindrome(head);

        cout << "Is the linked list a palindrome? " << (result ? "Yes" : "No") << endl;    
        break;
    }
    case 10:
    {
     ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);
        ListNode* current = head;
        cout << "Linked list elements: ";
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
        ListNode* result = sol.removeElements(head, 6);

        cout << "New linked list after removing elements: ";
        while (result != nullptr) {
            cout << result->val << " ";
            ListNode* temp = result;
            result = result->next;
            delete temp;
        }
        cout << endl;
        break;
    }
    case 11:
    {
          TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    break;
    }
    case 12:
    {
      TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    break;
    }
    case 13:
    {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    break;
    }
    case 14:
    {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int sum = sol.sumOfLeftLeaves(root);

    cout << "Sum of left leaves: " << sum << endl;
    break;
    }
    case 15:
    {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);

    cout << "Is the tree valid? " << (sol.checkTree(root) ? "Yes" : "No") << endl;
    break;
    }
    case 16:
    {
       vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    break;
    }
    case 17:
    {
      vector<int> nums = {1, 2, 3, 1}; // Example input

    if (sol.containsDuplicate(nums)) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }
    break;
    }
    case 18:
    {
    string s = "abcd";
    string t = "abcde";

    char result = sol.findTheDifference(s, t);
    cout << "The difference character is: " << result << endl;
    break;
    }
    case 19:
    {
    vector<int> nums = { 3, 0, 1 };
 cout << "Numbers: ";
 for (int i = 0; i < nums.size(); i++) {
     cout << nums.at(i) << " ";
 }cout << endl;
 cout << "The missing number is: " << sol.missingNumber(nums) << endl;
    break;
    }
    case 20:
    {
    string jewels = "aA";
string stones = "aAAbbbb";
cout << "Jewels: " << jewels << endl;
cout << "Stones: " << stones << endl;

cout << "Number of jewels in stones: " << sol.numJewelsInStones(jewels, stones) << endl;
    break;
    }
 }
    return 0;
}
