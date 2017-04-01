#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
class hilbert{
    int move,x,y;
  public:
    hilbert(int order){
    int side = getmaxy()-(2*getmaxy()/8);
    move = side / pow(2,order);

    y = (getmaxy()-side)/2 + side;
    x = (getmaxx() - side ) / 2;
    hilbert_A(order);
}
    void hilbert_A(int n){
        if(n>0){
            hilbert_D(n-1);
            line(x,y,x,y-move);
            y=y-move;

            hilbert_A(n-1);
            line(x,y,x+move,y);
            x=x+move;

            hilbert_A(n-1);
            line(x,y,x,y+move);
            y=y+move;

            hilbert_B(n-1);
        }
    }
    void hilbert_B(int n){
        if(n>0){
            hilbert_C(n-1);
            line(x,y,x-move,y);
            x=x-move;

            hilbert_B(n-1);
            line(x,y,x,y+move);
            y=y+move;

            hilbert_B(n-1);
            line(x,y,x+move,y);
            x=x+move;

            hilbert_A(n-1);
        }
    }
    void hilbert_C(int n){
        if(n>0){
            hilbert_B(n-1);
            line(x,y,x,y+move);
            y=y+move;

            hilbert_C(n-1);
            line(x,y,x-move,y);
            x=x-move;

            hilbert_C(n-1);
            line(x,y,x,y-move);
            y=y-move;

            hilbert_D(n-1);
        }
    }
    void hilbert_D(int n){
        if(n>0){
            hilbert_A(n-1);
            line(x,y,x+move,y);
            x=x+move;

            hilbert_D(n-1);
            line(x,y,x,y-move);
            y=y-move;

            hilbert_D(n-1);
            line(x,y,x-move,y);
            x=x-move;

            hilbert_C(n-1);
        }
    }

};
int main(){
int order;
int gd = DETECT, gm;
initgraph(&gd,&gm,"");
cin>> order;
hilbert line(order);
delay(7000);

closegraph();
return 0;


}
