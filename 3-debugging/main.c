#include <stdio.h>

/*
 * As a way of documenting my debugging process I'm going to keep a log here
 * I think the first thing I'll try is running it with some arbitrary input
 * (maybe 2 and 3)? It's not very clear what it's supposed to do, but I know
 * it takes 2 numbers as input and outputs a single number, and seems to be
 * using y as some sort of counter for the loop and x and r as values to
 * eventually be used in the return value.
 * I'll pull in libcompact for some nice helper functions/macros.*/
#include "../libcompact.h"
/* Ok now I'll try running it and printing output (using Pd macro for
 * printing numbers), and it returns 8. How about 3 and 2? Returns 9. Seems
 * like it is supposed to be exponentiation, but I need to figure out why
 * it's broken.
 * Actually I can do this automatically! I'll link the math library with
 * cmake's `target_link_libraries(3_debugging m)`, then try running the fn
 * with a bunch of values and seeing what causes the result to be
 * inaccurate.*/
#include <math.h>
/* Using this code:
for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
        int res = f(i, j);
        int expected = pow(i, j);
        if(res != expected) {
            printf("f(%d, %d) = %d, expected %d\n", i, j, res, expected);
        }
    }
}
 * I get this output:
f(0, 0) = 0, expected 1
f(2, 0) = 2, expected 1
f(3, 0) = 3, expected 1
f(4, 0) = 4, expected 1
f(5, 0) = 5, expected 1
f(6, 0) = 6, expected 1
f(7, 0) = 7, expected 1
 * So it seems like the function is failing when the exponent is 0; it is
 * outputting the first value instead of 0. It appears to be a very convoluted
 * way of doing exponentiation! I'll step through it with gdb and see what's
 * happening with a single test case. I'll add `set(CMAKE_BUILD_TYPE Debug)`
 * to my cmakelists file.
 * Opening gdb, load file with `file 3_debugging`, and I'll set a breakpoint
 * on line 49 (start of f function) with `break f`. Huh, when I run it I don't
 * hit the breakpoint.
 * After some further troubleshooting it seems gdb is broken on my system (other
 * people in the CS discord ran the exact same commands as I did with exact same
 * files and it worked), but lldb works, so I'll just use that
 * Hmm, when I step through it, it seems like the code is working properly except
 * for this one edge case, so I'll add code to explicitly handle it
 * Now, I'll run my test loop again, and it works! I think this has been fixed.
 */

int f(int x, int y) {
    if(y == 0) return 1; // handle edge case
    int r = 1;
    while (y > 1) {
        if (y % 2 == 1) {
            r = x * r;
        }
        x = x * x;
        y = y / 2;
    }
    return r * x;
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int res = f(i, j);
            int expected = pow(i, j);
            if(res != expected) {
                printf("f(%d, %d) = %d, expected %d\n", i, j, res, expected);
            }
        }
    }
    Pd(f(2,0));
    return 0;
}
