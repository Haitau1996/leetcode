/*
 * 使用一个双向链表实现
 * 需要注意的是， Class 的成员默认 private, 这里最好使用 struct
 */
#include <string>
using std::string;
struct URLNode {
    string url;
    URLNode* prev;
    URLNode* next;
    URLNode(string url)
        : url(url)
        , prev(nullptr)
        , next(nullptr)
    {
    }
};
class BrowserHistory {
public:
    BrowserHistory(string homepage)
    {
        home = new URLNode(homepage);
        curr = home;
    }

    void visit(string url)
    {
        URLNode* next = new URLNode(url);
        curr->next = next;
        next->prev = curr;
        curr = curr->next;
    }

    string back(int steps)
    {
        while (curr->prev != nullptr && steps != 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    string forward(int steps)
    {
        while (curr->next != nullptr && steps != 0) {
            curr = curr->next;
            --steps;
        }
        return curr->url;
    }

private:
    URLNode* home;
    URLNode* curr;
};
