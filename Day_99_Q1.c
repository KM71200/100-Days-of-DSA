#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int position;
    int speed;
} Car;


int compare(const void *a, const void *b)
{
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int main()
{
    int target, n;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    Car cars[n];

    printf("Enter position and speed of each car:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cars[i].position, &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = -1.0;

    for (int i = 0; i < n; i++)
    {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime)
        {
            fleets++;
            lastTime = time;
        }
    }

    printf("Number of car fleets = %d\n", fleets);

    return 0;
}
