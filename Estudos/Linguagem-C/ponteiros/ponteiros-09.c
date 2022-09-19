#include <stdio.h>

int main() {
    int vNum[3] = {0,1,2};

    int *pNum;

    pNum = vNum;

    printf("%d\n", vNum[0]);
    printf("%d\n", *pNum);

    pNum++;
    printf("%d\n", vNum[1]);
    printf("%d\n", *pNum);

    pNum++;
    printf("%d\n", vNum[2]);
    printf("%d\n", *pNum);
    
    return 0;
}