#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, pos, fault = 0;
    int found, far, next;

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
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            pos = -1;
            far = -1;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }

                next = n;
                for(k = i + 1; k < n; k++)
                    if(pages[k] == frames[j]) {
                        next = k;
                        break;
                    }

                if(next > far) {
                    far = next;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            fault++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\nPage Faults = %d\n", fault);
    return 0;
}
