#ifndef MAZE
#define MAZE

#define DEBUG false
#include "header.h"

//the top left corner is (0,0)
struct Point
{
	int r;
	int c;
	Point(int i,int j){
		r=i;
		c=j;
	}
};
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

void shuffle(int* arr)
{
	for(int i=3;i>=0;i--)
    {
		int j=rand()%(i+1);
		swap(arr[i],arr[j]);
	}
}

//x y is new position
void carve(bool** upper,bool** left,int r,int c,int d)
{
	if(d==0){ //move right
		left[r][c]=false;
	}else if(d==1){ //move left
		left[r][c+1]=false;
	}else if(d==2){ //move down
		upper[r][c]= false;
	}else if(d==3) //move up
		upper[r+1][c]=false;
}

void print(bool* upper[20],bool** left,int m,int n){
    //when we are printing the maze
    // j is row i is column
        //print first row
        for(int i=0;i<n;i++)
            cout<<"__";
        cout<<endl;
    
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                if(left[i][j])
                    cout<<"|";
                else
                    cout<<' ';
                if(i==m-1 || upper[i+1][j]){
                    cout<<"_";
                }else
                    cout<<" ";
            }
            cout<<"|"<<endl;
        }
}


void generate_bfs(bool** upper,bool** left,Point p,bool** visited,int m,int n,int depth){
    queue<Point> pq; //store the visited points in current level
    pq.push(p);
    visited[p.r][p.c]=true;
    int arr[]={0,1,2,3};

    while(!pq.empty()){
        int size=pq.size();
        cout<<"size: "<<size<<endl;
        while(size--)
        {
            Point p=pq.front();
            
            shuffle(arr);
            for(int i=0;i<4;i++)
            {
                int d=arr[i];
                //for each point, walk depth steps
                int dps=depth;
                Point np(p.r,p.c);
                while(dps)
                {
                    dps--;
                    np.r+=dr[d];
                    np.c+=dc[d];
                
                    
                    if(np.r>=0 && np.r<m && np.c>=0 && np.c<n && !visited[np.r][np.c])
                    {
                        visited[np.r][np.c]=true;
//                    if(dps==0)
                        pq.push(np);
                        carve(upper, left, np.r, np.c, d);
                    }else
                        break;
                    d=rand()%4;
                }//while
            }//for
            pq.pop();
        }
    }
    
}


void generate(bool** upper,bool** left,Point p,bool** visited,int m,int n){
	visited[p.r][p.c]=true;
	int arr[]={0, 1, 2, 3};
	shuffle(arr);
	for(int i=0;i<4;i++)
    {
		int d=arr[i];
		int r=p.r+dr[d];
		int c=p.c+dc[d];
		if(r>=0 && r<m && c>=0 && c<n && !visited[r][c]){
           // cout<<"r: "<<r<<"c: "<<c<<endl;
            if(DEBUG && c==0)
                cout<<"dir: "<<d<<endl;
			carve(upper,left,r,c,d);
            Point pp(r,c);
			generate(upper,left,pp,visited,m,n);
		}
	}
}

struct Point2
{
    int r, c;
    int array[4];
    int status;
    Point2(int i,int j){
        r=i;
        c=j;
        array[0] = 0;
        array[1] = 1;
        array[2] = 2;
        array[3] = 3;
        status = 0;
    }
};

void generate_stack(bool** upper,bool** left, Point p, bool** visited, int m, int n)
{
    stack<Point2> stack;
    Point2 p2(p.r, p.c);
    stack.push(p2);

    while(!stack.empty())
    {

        Point2 &cur = stack.top();
        if(cur.status == 0)
        {
            visited[cur.r][cur.c]=true;
            shuffle(cur.array);
        }

        if(cur.status < 4)
        {
            int d = cur.array[cur.status];
            int r = cur.r + dr[d];
            int c = cur.c + dc[d];
            if(r>=0 && r<m && c>=0 && c<n && !visited[r][c])
            {
                carve(upper, left, r, c, d);
                Point2 pp(r,c);
                stack.push(pp);
            }
            cur.status++;
        }
        else
        {
            stack.pop();
        }
    }
}

void init(bool** &arr,int m,int n,bool val){
    arr=new bool*[m];
	for(int i=0;i<m;i++)
    {
        arr[i]=new bool[n];
		for(int j=0;j<n;j++)
			arr[i][j]=val;
    }
}


void test_maze()
{
	int m=20; // row
	int n=20; // column
	Point start(0,0);
	bool** upper; //has wall
	bool** left;
	bool** visited;
    srand(time(NULL));

	init(upper,m,n,true);
	init(left,m,n,true);
	init(visited,m,n,false);
	generate_stack(upper,left,start,visited,m,n);
	print(upper,left,m,n);
    
    // init(upper,m,n,true);
    // init(left,m,n,true);
    // init(visited,m,n,false);
    // int depth=30;
    // generate_bfs(upper,left,start,visited,m,n,depth);
    // print(upper,left,m,n);
}

int main()
{
    test_maze();
    return 0;
}
#endif
