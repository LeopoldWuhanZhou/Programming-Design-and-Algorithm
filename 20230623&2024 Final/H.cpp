#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n,m;
struct Node {
    int x, steps;
    string path;
    Node(int a, int b, string s) : x(a), steps(b), path(s) {}
};
int main() {
    while(cin >> n >> m)
    {
        if(n==0 && m==0) break;
        int visited[1001] = {0};
        visited[n] = 1;
        queue<Node> q;
        q.push(Node(n, 0, ""));
        while(!q.empty()) 
        {
            Node s = q.front();
            q.pop();
            if(s.x == m) {
                cout << s.steps<<endl<<s.path<<endl;
                break;
            }
            if(visited[s.x*3] == 0)
            {
                visited[s.x*3] = 1;
                q.push(Node(s.x*3, s.steps+1, s.path + "H"));
            }
            if(visited[s.x/2] == 0)
            {
                visited[s.x/2] = 1;
                q.push(Node(s.x/2, s.steps+1, s.path + "O"));
            }
        }
    }
    
    return 0;
}