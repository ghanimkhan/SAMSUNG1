#include <iostream>
using namespace std;

int t,n,m,a,b,l;
int grid[50][50];
int ans[50][50];
int vis[50][50];

void dfs(int,int,int);

bool is_safe(int x,int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0);
}

void up(int x,int y,int l)
{
	if(is_safe(x-1,y))
	{
		if(grid[x-1][y] == 1 || grid[x-1][y] == 2 || grid[x-1][y] == 5 || grid[x-1][y] == 6)
			dfs(x-1,y,l-1);
	}
}

void down(int x,int y,int l)
{
	if(is_safe(x+1,y))
	{
		if(grid[x+1][y] == 1 || grid[x+1][y] == 2 || grid[x+1][y] == 4 || grid[x+1][y] == 7)
			dfs(x+1,y,l-1);
	}
}

void left(int x,int y,int l)
{
	if(is_safe(x,y-1))
	{
		if(grid[x][y-1] == 1 || grid[x][y-1] == 3 || grid[x][y-1] == 4 || grid[x][y-1] == 5)
			dfs(x,y-1,l-1);
	}
}

void right(int x,int y,int l)
{
	if(is_safe(x,y+1))
	{
		if(grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 6 || grid[x][y+1] == 7)
			dfs(x,y+1,l-1);
	}
}

void dfs(int x,int y,int l)
{
	if(l == 0)
		return;
	ans[x][y] = 1;
	vis[x][y] = 1;

	switch(grid[x][y])
	{
		case 1:
			up(x,y,l);
			down(x,y,l);
			left(x,y,l);
			right(x,y,l);
			break;
		case 2:
			up(x,y,l);
			down(x,y,l);
			break;
		case 3:
			left(x,y,l);
			right(x,y,l);
			break;
		case 4:
			up(x,y,l);
			right(x,y,l);
			break;
		case 5:
			down(x,y,l);
			right(x,y,l);
			break;
		case 6:
			down(x,y,l);
			left(x,y,l);
			break;
		case 7:
			up(x,y,l);
			left(x,y,l);
			break;
		default:
			break;
	}	
	vis[x][y] = 0;
}

int main()
{
	cin>>t;
	while(t--)
	{
		for(int i=0;i<50;i++)
			for(int j=0;j<50;j++)
				ans[i][j] = 0;
		for(int i=0;i<50;i++)
			for(int j=0;j<50;j++)
				vis[i][j] = 0;
		cin>>n>>m>>a>>b>>l;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>grid[i][j];
			}
		}
		if(grid[a][b])
			dfs(a,b,l);

		int result = 0;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				result += ans[i][j];
			}
		}
		cout<<endl;
		cout<<result<<endl;
	}
}