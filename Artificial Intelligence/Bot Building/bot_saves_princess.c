#include <stdio.h>
#include <string.h>
#include <math.h>
void displayPathtoPrincess(int n, char grid[101][101]){
    int mx = 0, my = 0, px = 0, py = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (grid[i][j] == 'p') {
                px = i;
                py = j;
            }
            if (grid[i][j] == 'm') {
                mx = i;
                my = j;
            }
        }
    }

    for (int i=0; i<my-py; i++) {
        printf("LEFT\n");
    }

    for (int i=0; i<py-my; i++) {
        printf("RIGHT\n");
    }

    for (int i=0; i<mx-px; i++) {
        printf("UP\n");
    }

    for (int i=0; i<px-mx; i++) {
        printf("DOWN\n");
    }

}
int main(void) {

    int m;
    scanf("%d", &m);
    char grid[101][101]={};
    char line[101];

    for(int i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}
