class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

    for (const char ch : s)
      if (ch == '(')
        stack.push(')');
      else if (ch == '{')
        stack.push('}');
      else if (ch == '[')
        stack.push(']');
      else if (stack.empty() || pop(stack) != ch)
        return false;

    return stack.empty();
  }

 private:
  int pop(stack<char>& stack) {
    const int ch = stack.top();
    stack.pop();
    return ch;
    }
};