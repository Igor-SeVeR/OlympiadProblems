#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#define endl "\n"

using namespace std;

vector <int> minX(51,51), maxX(51,0);

int Maximum_Y_Position = 0;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct pos{
    int x,y,code;
    pos(int _x, int _y, int _code): x(_x) , y(_y), code(_code){};
};

int newCode(int x, int y, int k)
{
    int Code = 0;
    for(int dy = 0; dy < k; ++dy){
        if(maxX[y+dy] == 0){
            Code |= (3 << (2*dy));
        } else
        {
            if(minX[y+dy] >= x && minX[y+dy] < x + k){
                Code |= (1 << (2*dy));
            }
            if(maxX[y+dy] >= x && maxX[y+dy] < x + k){
                Code |= (2 << (2*dy));
            }
        }
        
    }
    return Code;
}


signed main()
{
    fastio();
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        Maximum_Y_Position = max(y , Maximum_Y_Position);
        minX[y] = min(minX[y], x);
        maxX[y] = max(maxX[y], x);
    }
    
    /*for(int i = 1; i <= 50; ++i){
        
    }*/
    
    vector < vector < vector <int> > > position(52, vector < vector <int> >(52, vector <int>((1 << (2*k)), -1)));
    
    pos Current_Position(1,1,newCode(1,1,k));
    position[1][1][newCode(1, 1, k)] = 0;
    queue <pos> Q;
    Q.push(Current_Position);
    
    //cout << "\n\noutput:\n\n";
    
    while(!Q.empty())
    {
        //cout << "lol\n";
        Current_Position = Q.front();
        Q.pop();
        int x = Current_Position.x;
        int y = Current_Position.y;
        int code = Current_Position.code;
        
        //cout << "x = " << x << " y = " << y << "  code = " << code << endl;
        
        if(y + k > Maximum_Y_Position && code == ((1 << (2*k))-1)){
            cout << position[x][y][code] << endl;
            return 0;
        }
        
        if(x > 1){
            int nx =  x-1;
            int ny = y;
            int nc = code | newCode(nx, ny, k);
            if(position[nx][ny][nc] == -1){
                position[nx][ny][nc] = position[x][y][code] + 1;
                Q.push(pos(nx, ny, nc));
            }
        }
        if(x < 50 - k + 1){
            int nx = x + 1;
            int ny = y;
            int nc = code | newCode(nx, ny, k);
            if(position[nx]
               [ny]
               [nc] == -1){
                position[nx][ny][nc] = position[x][y][code] + 1;
                Q.push(pos(nx, ny, nc));
            }
        }
        if(y < 50 - k + 1 && ((3 | code) == code))
        {
            int nx = x;
            int ny = y+1;
            int nc = (code >> 2) | newCode(nx, ny, k);
            if(position[nx][ny][nc] == -1){
                position[nx][ny][nc] = position[x][y][code] + 1;
                Q.push(pos(nx, ny, nc));
            }
        }
    }
    return 0;
}
