#include <stdio.h>

void find_combo(int score){
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // TD+2pt=8, TD+FG=7, TD=6, FG=3, Safety=2
    for (int a = 0; a * 8 <= score; a++) {
        for (int b = 0; a * 8 + b * 7 <= score; b++) {
            for (int c = 0; a * 8 + b * 7 + c * 6 <= score; c++) {
                for (int d = 0; a * 8 + b * 7 + c * 6 + d * 3 <= score; d++) {
                    int rem = score - a * 8 - b * 7 - c * 6 - d * 3;
                    if (rem % 2 == 0) {
                        int e = rem / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               a, b, c, d, e);
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 1 or 0 to STOP\n");
    while (1) {
        printf("Enter the score: ");
        scanf("%d", &score);
        if (score < 1) break;
        find_combo(score);
    }
    return 0;
}