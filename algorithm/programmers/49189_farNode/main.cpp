#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> graph[20000];
int visit[20000];

int solution(int n, vector<vector<int>> edge)
{
  int cnt = 0;

  for (int i = 0; i < edge.size(); i++)
  {
    graph[edge[i][0] - 1].push_back(edge[i][1] - 1);
    graph[edge[i][1] - 1].push_back(edge[i][0] - 1);
  }

  queue<int> q;
  q.push(0);
  visit[0] = 1;

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    for (int i = 0; i < graph[front].size(); ++i)
    {

      int next = graph[front][i];

      if (visit[next] == 0)
      {
        visit[next] = visit[front] + 1;
        q.push(next);
      }
    }
  }

  int max = 0;
  for (int i = 0; i < n; ++i)
  {
    cout << i << " : " << visit[i] << endl;
    if (visit[i] > max)
    {
      max = visit[i];
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (visit[i] == max)
    {
      cnt++;
    }
  }

  return cnt;
}

int main()
{

  return 0;
}