class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>A;
        for(int i=0;i<t.size();i++)
        {
            A.push(0);
            int sum=0;
            for(int j=0;j<t[i].size();j++)
            {
                if(isdigit(t[i][j]))
                {
                    
                    if(A.top()<0)
                    {sum=(t[i][j]-48) + abs(A.top()*10);
                    A.pop();
                     A.push(-sum);
                    }
                    else
                    {
                        sum=(t[i][j]-48) +(A.top()*10);
                    A.pop();
                     A.push(sum);
                    }
                    
                }
                else if(isdigit(t[i][j+1]) && j+1<t[i].size())
                {
                    sum= -(t[i][j+1]-48);
                    A.pop();
                    A.push(sum);
                    j++;
                }
                else
                {
                    int c,d;
                    A.pop();
                    if(t[i][j]=='+')
                    {
                        c=A.top();
                        A.pop();
                        d=A.top();
                        A.pop();
                        A.push(d+c);
                    }
                     else if(t[i][j]=='-')
                    {
                        c=A.top();
                        A.pop();
                        d=A.top();
                        A.pop();
                        A.push(d-c);
                    }
                    else if(t[i][j]=='*')
                    {
                        c=A.top();
                        A.pop();
                        d=A.top();
                        A.pop();
                        A.push(d*c);
                    }
                     else if(t[i][j]=='/')
                    {
                        c=A.top();
                        A.pop();
                        d=A.top();
                        A.pop();
                        A.push(d/c);
                    }
                }
            }
        }
        return A.top();
    }
};
