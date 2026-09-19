class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x,y;

        if(x1>xc) x=x1;
        else if(x2<xc) x=x2;
        else x=xc;

        if(y1>yc) y=y1;
        else if(y2<yc) y=y2;
        else y=yc;

        int minD= sqrt(pow(x-xc,2)+pow(y-yc,2));
        return minD<=r;
    }
};