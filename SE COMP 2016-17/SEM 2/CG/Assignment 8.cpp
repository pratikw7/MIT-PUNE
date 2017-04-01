#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
class matrix_operations
{
    double** mat;
    int r,c;
    
public:
  matrix_operations(int r,int c)
{
    mat = new double*[r];
    for(int i=0;i<r;i++)
      mat[i]=new double[c];
    this->r=r;
    this->c=c;
}
void enter_data(double data[]){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            mat[i][j]=data[i*(c)+j];
}
double** give_mat(){
    return mat;
}


int give_rows(){
    return r;
}

int give_columns(){
    return c;
}
matrix_operations add(matrix_operations matObject){
    double** matB=matObject.give_mat();
    matrix_operations matCObject(r,c);
    double** matC = matCObject.give_mat();
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            matC[i][j]=mat[i][j]+matB[i][j];
    return matCObject;

}

matrix_operations multiply(matrix_operations matObject){
    double** matB=matObject.give_mat();
    matrix_operations matCObject(r,matObject.give_columns());
    double** matC = matCObject.give_mat();
    int R=r;
    int C=matCObject.give_columns();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            matC[i][j]=0;
            for(int k=0;k<c;k++){
                matC[i][j]+=(mat[i][k]*matB[k][j]);
            }
        }
    }
    return matCObject;

}
matrix_operations multiply_scalar(int scalar){
    matrix_operations matCObject(r,c);
    double** matC = matCObject.give_mat();
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            matC[i][j]=mat[i][j]*scalar;
    return matCObject;
}

};



class skeleton 
{
    int ox,oy;
public:
skeleton(){
    ox = getmaxx()/2;
    oy = getmaxy()/2;
    line(ox,0,ox,2*oy);
    line(0,oy,2*ox,oy);

}


void drawShape(matrix_operations shape,int size){
    double** mat=shape.give_mat();
    int r=shape.give_rows();
    int c=shape.give_columns();
    int k=0;
    int arr[r*(c-1)];
    for(int i=0;i<r;i++){
        arr[k++]=(int)(mat[i][0]+ox);
        arr[k++]=(int)(oy-mat[i][1]);
    }
    arr[k++]=mat[0][0]+ox;
    arr[k]=oy-mat[0][1];
    drawpoly(size+1,arr);
}


void drawSquare(){
    double x1,y1,x2,y2,x3,y3,x4,y4,tx,ty,sx,sy,o,ox,oy;
    cout<<"\n Enter the Coordinates of Square in cyclic order: \n";
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    double vertices[12] = {x1,y1,1,x2,y2,1,x3,y3,1,x4,y4,1};
    matrix_operations mat(4,3);
    
    mat.enter_data(vertices);
    matrix_operations mat1=mat;
    drawShape(mat,4);
    int choice;
    while(true){

    cout<<"\n 1) About X axis ";
    cout<<"\n 2) About Y axis ";
    cout<<"\n 3)About X=Y axis ";
    cout<<"\n 4) Rotate about arbitrary point";
    cout<<"\n 6) Exit \n ";
    cin>>choice; 
    switch(choice){
    case 1:
    mat = reflectXaxis(mat);
    drawShape(mat,4);
    continue;

    case 2:
    mat = reflectYaxis(mat);
    drawShape(mat,4);
    continue;
    case 3:
    mat = reflectXequalsYaxis(mat);
    drawShape(mat,4);
    continue;
    case 4:
    cout<<"\n Enter rotation angle and pivot point respectively: \n";
    cin>>o>>ox>>oy;
    mat = rotate(mat,ox,oy,o);
    drawShape(mat,4);
    continue;

    case 6:break;
    }break;
    }
}



matrix_operations translate(matrix_operations mat, int tx, int ty){
    double data[9]={1,0,0,0,1,0,tx,ty,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);

}

matrix_operations scale(matrix_operations mat, double sx, double sy){
    double data[9]={sx,0,0,0,sy,0,0,0,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);
}

matrix_operations rotate_wrt_origin(matrix_operations mat,double o){
    o*=((double)3.14/(double)180);
    double data[9]={cos(o),sin(o),0,-sin(o),cos(o),0,0,0,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);
}
matrix_operations rotate(matrix_operations mat, int xo, int yo, int o){
    return translate(rotate_wrt_origin(translate(mat,-xo,-yo),o),xo,yo);
}

matrix_operations reflectXaxis(matrix_operations mat){
    double data[9]={1,0,0,0,-1,0,0,0,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);
}

matrix_operations reflectYaxis(matrix_operations mat){
    double data[9]={-1,0,0,0,1,0,0,0,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);
}

matrix_operations reflectXequalsYaxis(matrix_operations mat){
    double data[9]={0,1,0,1,0,0,0,0,1};
    matrix_operations move(3,3);
    move.enter_data(data);
    return mat.multiply(move);
}
 
};

int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"");

skeleton square;
square.drawSquare();

closegraph();	
return 0;
}
