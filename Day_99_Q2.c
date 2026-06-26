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

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize)
{
    if (positionSize == 0)
        return 0;

    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++)
    {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < positionSize; i++)
    {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime)
        {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}
