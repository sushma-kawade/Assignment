#include <stdio.h>
#include <math.h>

int main() {
    int n, radius;
    printf("Enter the number of towers: ");
    scanf("%d", &n);
    int towers[n][3];

    printf("Enter the factor of each tower (x y q):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &towers[i][0], &towers[i][1], &towers[i][2]);
    }

    printf("Enter the radius: ");
    scanf("%d", &radius);

    int max_quality = 0;
    int cx = 0, cy = 0;
    for (int x = 0; x <= 100; x++) {  
        for (int y = 0; y <= 100; y++) { 
            int network_quality = 0;
            for (int i = 0; i < n; i++) {
                int d = sqrt(pow(x - towers[i][0], 2) + pow(y - towers[i][1], 2));
                if (d <= radius) {
                    network_quality += towers[i][2] / (1 + d);
                }
            }
            if (network_quality > max_quality) {
                max_quality = network_quality;
                cx = x;
                cy = y;
            } else if (network_quality == max_quality && x < cx) {
                cx = x;
                cy = y;
            }
        }
    }
    printf("The coordinate with the highest network quality is: [%d, %d]\n", cx, cy);
    return 0;
}
