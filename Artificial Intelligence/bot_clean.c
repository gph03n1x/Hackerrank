#include<stdio.h>
#include<math.h>
float distance(int bpx, int bpy, int dpx, int dpy) {
    return sqrt(pow(bpx - dpx, 2) + pow(bpy - dpy, 2));
}

void next_move(int posr, int posc, char board[5][5]) {
    if (board[posr][posc]  == 'd') {
        printf("CLEAN");
        return;
    }
    float md = sqrt(50);
    int clx, cly;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if (board[i][j] == 'd') {
                if (md > distance(posr, posc, i, j)){
                    clx = i;
                    cly = j;
                    md = distance(posr, posc, i, j);
                }
            }
        }
    }
    for (int i=0; i<posc-cly; i++) {
        printf("LEFT\n");
        return;
    }

    for (int i=0; i<cly-posc; i++) {
        printf("RIGHT\n");
        return;
    }

    for (int i=0; i<posr-clx; i++) {
        printf("UP\n");
        return;
    }

    for (int i=0; i<clx-posr; i++) {
        printf("DOWN\n");
        return;
    }
}
int main(void) {
    int pos[2], i;
    char board[5][5], line[6];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
