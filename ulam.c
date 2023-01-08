#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME '#'
#define NOT_PRIME ' '

char isPrime(int n)
{
    if (n == 1)
    {
        return NOT_PRIME;
    }
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return NOT_PRIME;
        }
        i += 1;
    }
    return PRIME;
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s SIZE\n", argv[0]);
        return 1;
    }

    // Size of spiral
    int size = atoi(argv[1]);
    if (size < 1)
    {
        fprintf(stderr, "Error: SIZE must be a positive integer.\n");
        return 1;
    }

    // 2D array to store the spiral
    int **spiral = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        spiral[i] = malloc(size * sizeof(int));
    }

    // Initialize the array to zeros
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            spiral[i][j] = 0;
        }
    }

    // Starting position
    int x = size / 2;
    int y = size / 2;
    spiral[x][y] = 1;

    // Direction vectors for moving up, left, down, right
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    // Current direction index
    int dir = 0;

    // Counter for assigning values to the spiral
    int counter = 2;

    // Rotation Factor
    int rotFac = 1;

    // Generate the spiral
    while (counter <= size * size)
    {
        if (dir < 2)
        {
            for (int i = 0; i < rotFac; i++)
            {
                x += dx[dir];
                y += dy[dir];
                spiral[x][y] = counter;
                counter++;
            }
            dir = (dir + 1) % 4;
        }
        if (dir >= 2)
        {
            for (int i = 0; i < rotFac + 1; i++)
            {
                x += dx[dir];
                y += dy[dir];
                spiral[x][y] = counter;
                counter++;
            }
            dir = (dir + 1) % 4;
        }

        if (dir == 0)
        {
            rotFac += 2;
        }
    }

    // Print the spiral
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", isPrime(spiral[i][j]));
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++)
    {
        free(spiral[i]);
    }
    free(spiral);

    return 0;
}
