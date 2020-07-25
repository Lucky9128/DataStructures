#include<iostream>
#include<vector>
#define Mat vector<vector<int>>
#define A11(mat,x,y,n)  mat[x][y]
#define A12(mat,x,y,n)  mat[x][y]
#define A13(mat,x,y,n)  mat[x][y]
#define A14(mat,x,y,n)  mat[x][y] 




using namespace std;

void display(Mat arr)
{
    for(int j=0;j<arr.size();j++)
    {
        for(int i=0;i<arr[j].size();i++)
            cout<<arr[j][i]<<"\t";
        cout<<endl;
    }
}

Mat add(Mat m1, Mat m2)
{
    Mat m3;
    for(int i=0;i<m1.size();i++)
    {
        m3.push_back({});
        for(int j=0;j<m1.size();j++)
        {
            m3[i].push_back(m1[i][j]+m2[i][j]);
        }
    }
    return m3;
}

//a11 ->  x1,y1         
//a12 ->  x1+n/2,y1     
//a21 ->  x1,y1+n/2     
//a22 ->  x1+n/2,y1+n/2 


Mat MulMatrix(Mat &m1, Mat &m2,int x1,int y1,int x2,int y2,int n)
{
    if(n<=2)
    {
        Mat res;
        int a11 = m1[x1][y1]*m2[x2][y2] + m1[x1][y1+1]*m2[x2+1][y2];
        int a12 = m1[x1][y1]*m2[x2][y2+1] + m1[x1][y1+1]*m2[x2+1][y2+1];
        int a13 = m1[x1+1][y1]*m2[x2][y2] + m1[x1+1][y1+1]*m2[x2+1][y2];
        int a14 = m1[x1+1][y1]*m2[x2][y2+1] + m1[x1+1][y1+1]*m2[x2+1][y2+1];
        res.push_back({a11,a12});
        res.push_back({a13,a14});
        return res;
    }
    else
    {   
        Mat m11 = add(MulMatrix(m1,m2,x1,y1,x2,y2,n/2),MulMatrix(m1,m2,x1,y1+n/2,x2+n/2,y2,n/2));
        Mat m12 =  add(MulMatrix(m1,m2,x1,y1,x2,y2+n/2,n/2),MulMatrix(m1,m2,x1,y1+n/2,x2+n/2,y2+n/2,n/2));
        Mat m13 =  add(MulMatrix(m1,m2,x1+n/2,y1,x2,y2,n/2),MulMatrix(m1,m2,x1+n/2,y1+n/2,x2+n/2,y2,n/2));
        Mat m14 =  add(MulMatrix(m1,m2,x1+n/2,y1,x2,y2+n/2,n/2),MulMatrix(m1,m2,x1+n/2,y1+n/2,x2+n/2,y2+n/2,n/2));
        for(int i=0;i<n/2;i++)
        {
            m11[i].insert(m11[i].end(),m12[i].begin(),m12[i].end());
        }
        for(int i=0;i<n/2;i++)
        {
            m13[i].insert(m13[i].end(),m14[i].begin(),m14[i].end());
        }
        Mat res=m11;
        res.insert(res.end(),m13.begin(),m13.end());
        return res;
    }
    
}

int main()
{
    // Mat matrix = {{1,0,1,3,1,0,1,3},{0,1,-1,1,0,1,-1,1},{1,-2,0,3,1,-2,0,3},{2,3,1,0,2,3,1,0},{1,0,1,3,1,0,1,3},{0,1,-1,1,0,1,-1,1},{1,-2,0,3,1,-2,0,3},{2,3,1,0,2,3,1,0}};
    Mat matrix = {{1,1,1,1,1,1,1,1},
                  {1,1,1,1,1,1,1,1},
                  {1,1,1,1,1,1,1,1},
                  {1,1,1,1,2,1,1,1},
                  {1,1,1,1,1,1,1,1},
                  {1,1,1,1,1,1,1,1},
                  {1,1,1,1,1,1,1,1},
                  {1,1,1,1,1,1,1,2} };
        Mat res = MulMatrix(matrix, matrix,0,0,0,0,8);
    display(res);
    return 0;
}
