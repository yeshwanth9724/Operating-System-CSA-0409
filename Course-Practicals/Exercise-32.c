#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, k, pos, fault = 0, found, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i]) {
                found = 1;
                time[j] = i;
            }

        if(!found) {
            pos = 0;
            min = time[0];

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = i;
            fault++;
        }

        printf("\n");
        for(k = 0; k < f; k++)
            printf("%d ", frames[k]);
    }

    printf("\nPage Faults = %d\n", fault);
    return 0;
}
