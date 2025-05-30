#include<iostream>
#include<vector>
using namespace std;
int maze[5][5], visited[5][5];
vector< vector<int> > path, thispath;
vector<int> v;
int Min=10000;
void dfs(int i, int j)
{
    v.clear();
    if(i == 4 && j == 4) {
        if(thispath.size() < Min) {
            Min = thispath.size();
            path = thispath;
        }
        return;
    }
    if (i<4 && maze[i+1][j] == 0 && visited[i+1][j] == 0) {
        visited[i+1][j] = 1;
        v.push_back(i+1);
        v.push_back(j);
        thispath.push_back(v);
        dfs(i+1, j);
        thispath.pop_back();
        visited[i+1][j] = 0;
        v.clear();
    }
    if (j<4 && maze[i][j+1] == 0 && visited[i][j+1] == 0) {
        visited[i][j+1] = 1;
        v.push_back(i);
        v.push_back(j+1);
        thispath.push_back(v);
        dfs(i, j+1);
        thispath.pop_back();
        visited[i][j+1] = 0;
        v.clear();
    }
    if (i>0 && maze[i-1][j] == 0 && visited[i-1][j] == 0) {
        visited[i-1][j] = 1;
        v.push_back(i-1);
        v.push_back(j);
        thispath.push_back(v);
        dfs(i-1, j);
        thispath.pop_back();
        visited[i-1][j] = 0;
        v.clear();
    }
    if (j>0 && maze[i][j-1] == 0 && visited[i][j-1] == 0) {
        visited[i][j-1] = 1;
        v.push_back(i);
        v.push_back(j-1);
        thispath.push_back(v);
        dfs(i, j-1);
        thispath.pop_back();
        visited[i][j-1] = 0;
        v.clear();
    }
    return;
}
int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> maze[i][j];
            visited[i][j] = maze[i][j];
        }
    }
    v.push_back(0);
    v.push_back(0);
    thispath.push_back(v);
    dfs(0,0);
    for(int i = 0; i < path.size(); i++)
        cout << "(" << path[i][0] << ", " << path[i][1] << ")"<<endl;
    return 0;
}