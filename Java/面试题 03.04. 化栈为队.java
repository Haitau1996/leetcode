/*
执行用时：12 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗：36.2 MB, 在所有 Java 提交中击败了50.16% 的用户
*/
/** 题目不难， 但是有一点需要注意
* java 类中的数据属性， 如果没有初始化的话就是 null, 因此需要在构造器中做初始化

*/
class MyQueue {

    /** Initialize your data structure here. */
    public MyQueue() {
        inStack = new Stack<Integer>();
        outStack = new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.pop());
            }
        }
        return outStack.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return inStack.empty() && outStack.empty();
    }
    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

}