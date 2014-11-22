#include <iostream>
using namespace std;

struct Edge
{
    int fid;
    int idx1;
    int idx2;
    int idx3;

    void set(int _fid, int _idx1, int _idx2, int _idx3)
    {
        fid = _fid;
        idx1 = _idx1;
        idx2 = _idx2;
        idx3 = _idx3;
    }
};

struct EdgeColor
{
    int color1;
    int color2;
    int color3;
};

class Face
{
public:
    int id;
    int color[3][3];
    Edge edges[4];

public:
    int get(int x, int y)
    {
        return color[x][y];
    }

    void set(int x, int y, int value)
    {
        color[x][y] = value;
    }

    Face()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                color[i][j] = i*3+j;
        }
    }

    EdgeColor getEdgeColor(int edgeID, Face &face)
    {
        EdgeColor ecolor;
        ecolor.color1 = face.color[edges[edgeID].idx1/3][edges[edgeID].idx1%3];
        ecolor.color2 = face.color[edges[edgeID].idx2/3][edges[edgeID].idx2%3];
        ecolor.color3 = face.color[edges[edgeID].idx3/3][edges[edgeID].idx3%3];
        return ecolor;
    }

    void setEdgeColor(EdgeColor ecolor, int edgeID, Face &face)
    {
        face.color[edges[edgeID].idx1/3][edges[edgeID].idx1%3] = ecolor.color1;
        face.color[edges[edgeID].idx2/3][edges[edgeID].idx2%3] = ecolor.color2;
        face.color[edges[edgeID].idx3/3][edges[edgeID].idx3%3] = ecolor.color3;
    }

    int setId(int id)
    {
        this->id = id;

        if(id == 0)
        {
            edges[0].set(4, 6, 7, 8);
            edges[1].set(1, 0, 3, 6);
            edges[2].set(5, 6, 7, 8);
            edges[3].set(3, 8, 5, 2);
        }
        if(id == 1)
        {
            edges[0].set(4, 8, 5, 2);
            edges[1].set(2, 0, 3, 6);
            edges[2].set(5, 0, 3, 6);
            edges[3].set(0, 8, 5, 2);
        }
        if(id == 2)
        {
            edges[0].set(4, 2, 1, 0);
            edges[1].set(3, 0, 3, 6);
            edges[2].set(5, 2, 1, 0);
            edges[3].set(1, 8, 5, 2);
        }
        if(id == 3)
        {
            edges[0].set(4, 0, 3, 6);
            edges[1].set(0, 0, 3, 6);
            edges[2].set(5, 8, 5, 2);
            edges[3].set(2, 8, 5, 2);
        }
        if(id == 4)
        {
            edges[0].set(2, 2, 1, 0);
            edges[1].set(1, 2, 1, 0);
            edges[2].set(0, 2, 1, 0);
            edges[3].set(3, 2, 1, 0);
        }
        if(id == 5)
        {
            edges[0].set(2, 6, 7, 8);
            edges[1].set(1, 6, 7, 8);
            edges[2].set(0, 6, 7, 8);
            edges[3].set(3, 6, 7, 8);
        }
    }

    void print()
    {
        cout << "Face " << id << ": " << endl;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout << color[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


class MagicCube
{
private:
    Face face[6];

public:
    //初始化时要比较细心的设定好所有成员变量的值
    MagicCube()
    {
        for(int i=0; i<6; i++)
            face[i].setId(i);
    }


    void rotate90(int faceID)
    {
        Face &curface = face[faceID];

        for(int i=0; i<3; i++)
        {
            swap(curface.color[i][0], curface.color[i][2]);
        }
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3-i; j++)
                swap(curface.color[i][j], curface.color[2-j][2-i]);
        }

        
        EdgeColor temp = curface.getEdgeColor(3, face[curface.edges[3].fid]);
        for(int i=3; i>=1; i--)
        {
             EdgeColor col = curface.getEdgeColor(i-1, face[curface.edges[i-1].fid]);
             curface.setEdgeColor(col, i, face[curface.edges[i].fid]);
        }
        curface.setEdgeColor(temp, 0, face[curface.edges[0].fid]);
        
    }

    //旋转的面和角度（角度实际上是旋转了多少个90度）
    void rotate(int faceID, int deg)
    {
        deg %= 4;
        for(int i=0; i<deg; i++)
        {
            rotate90(faceID);
        }
    }

    void print()
    {
        for(int i=0; i<6; i++)
            face[i].print();
    }

};


int main()
{
    MagicCube cube;


    cube.rotate(1, 3);
    cube.print();

    return 0;
}
