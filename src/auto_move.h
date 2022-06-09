#include "functions.h"

/* Mouse auto move */
int auto_move()
{
    /* init */
    int x = 500, y = 500;
    int minX = 100, minY = 100;
    int maxX = 1200, maxY = 800;
    int step = 1;
    int stepFast = 20;

    /* move */
    int randX = 0;     // Направление X
    int randY = 0;     // Направление Y
    int randSleep = 0; // Скорость
    int randSteps = 0; // Шаги

    /* position */
    int cursorPositionX = 0;
    int cursorPositionY = 0;

    /* program */
    SetCursorPos(x, y);
    cursorPositionX = x;
    cursorPositionY = y;

    printf("Start -> \n");
    while (1)
    {
        randX = random(-3, 3);      // Направление X
        randY = random(-3, 3);      // Направление Y
        randSleep = random(1, 60);  // Скорость
        randSteps = random(1, 100); // Шаги

        /* code */
        for (int i = 0; i < randSteps; i++)
        {
            Sleep(randSleep);

            /* чтобы бегал в границах дозволенного */
            SetCursorPos(x += randX, y += randY);
            if (x < minX)
            {
                SetCursorPos(x = minX, y += randY);
            }
            if (y < minY)
            {
                SetCursorPos(x += randX, y = minY);
            }
            if (x > maxX)
            {
                SetCursorPos(x = maxX, y += randY);
            }
            if (y > maxY)
            {
                SetCursorPos(x += randX, y = maxY);
            }
        }
        Sleep(10000);
        printf("x: %i \n", x);
        printf("y: %i \n", y);
        printf("---\n");
    }
}
