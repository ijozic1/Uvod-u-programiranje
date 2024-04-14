#include <stdio.h>
#include <math.h>

int main(){
    double t=(int)(1.6+1.6);
    printf("%g", t);
    return 0;
}

/*
1. 3 / 2 * 2
2. 3 / 2 * 2.
3. 3 / 2. * 2
4. 3 / (float)2 * 2
5. (double)3 / 2
6. (double)(3 / 2)
7. 2+0.5
8. (2 + 0.5) * 4
9. (int)(0.5 + 2) * 4
10. (float) ((int)1.5 + 2) / 4
11. (int)1.6 + (int)1.6
12. (int)(1.6 + 1.6)
*/