#include <stdio.h>
#include <stdlib.h>

int height[1000000];

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);

    int max_height = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
        if (height[i] > max_height) {
            max_height = height[i];
        }
    }

    int start = 0;
    int end = max_height;
    int result = 0;

    while (start <= end) {
        long long total = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (height[i] > mid) {
                total += (height[i] - mid);
            }
        }

        if (total < m) {
            end = mid - 1;
        } else {
            result = mid;
            start = mid + 1;
        }
    }

    printf("%d\n", result);
    return 0;
}