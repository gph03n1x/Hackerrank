#include<stdio.h>
#include<math.h>


float distance(int bpx, int bpy, int dpx, int dpy) {
    return sqrt(pow(bpx - dpx, 2) + pow(bpy - dpy, 2));
}


void next_move(int posr, int posc, int dimh, int dimw, char board[50][50]) {
    if (board[posr][posc]  == 'd') {
        printf("CLEAN\n");
        return;
    }
    float md = distance(posr, posc, dimh, dimw);
    int clx, cly;
    for(int i=0; i<dimh; i++) {
        for(int j=0; j<dimw; j++) {
            if (board[i][j] == 'd') {
                if (md > distance(posr, posc, i, j)){
                    clx = i;
                    cly = j;
                    md = distance(posr, posc, i, j);
                }
            }
        }
    }
    if (posc != 0 && posc > cly) {
        printf("LEFT\n");
    } else if (posc+1 != dimw &&cly > posc) {
        printf("RIGHT\n");
    } else if (posr+1 != dimh && posr < clx) {
        printf("DOWN\n");
    } else {
        printf("UP\n");
    }
}


int main(void) {
    int pos[2], dim[2], i;
    char board[50][50];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    scanf("%d", &dim[0]);
    scanf("%d", &dim[1]);
    for(i=0; i<dim[0]; i++) {
        scanf("%s[^\\n]%*c", board[i]);
    }
    next_move(pos[0], pos[1],dim[0],dim[1], board);
    return 0;
}
