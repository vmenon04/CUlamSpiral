# UlamSpiral

This C program generates an Ulam spiral, which is a pattern formed by arranging the positive integers in a grid, starting from the center and moving outwards in a spiral pattern.

To use the program, compile it with a C compiler and run the resulting executable with the size of the spiral as the first argument. The program will output an Ulam spiral to the console.

The program works by initializing a 2D array called grid with all zeros. It then sets the starting position to the center of the grid and iterates through the positive integers while moving in a spiral pattern. Finally, the program prints the grid, only marking the prime numbers which will form an Ulam spiral.

The program will work for any positive size value, but smaller values will result in smaller spirals and larger values will result in larger spirals.

![Boids Gif](https://github.com/vmenon04/UlamSpiral/blob/main/ulam_image.png )
