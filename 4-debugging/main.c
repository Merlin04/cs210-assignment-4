/*
 * Debugging log
 * first thing I notice is that stdlib, stdio isn't included, I'll add that
 * also I notice that the parameter types of argc, argv are wrong, so I'll fix that
 * Ok it compiles now, let's try running it - I get sigsegv probably because it isn't checking if it has enough args
 * I'll add a check for that
 * Ran it with args 1,2,3, it outputs "x coord: 2\ny coord: 3"
 * Huh, it seems like the z struct isn't actually being used?? I'm not sure
 * what this is supposed to do
 *
 * Update: emailed Charlie, he has given the following advice
 * > The code is attempting to compute and display the y-intercept of a
 * > linear function with the given slope and passing through the given
 * > point. Hope this helps.
 *
 * Ok, now that I know what the function is supposed to do, I'll start
 * annotating it with comments and renaming variables
 * Now I'll make some test cases. The point-slope form is y=m(x-x1)+y1,
 * and the y-intercept is y1-(x1*m).
 * - { -2,4,3 } = 11
 * - { 2,5,7 } = -3
 * - { 0,0,0 } = 0
 * - { 0,0,1 } = 1
 *
 * For testing, I'll rename main and make a new main function that calls it
 * with the test cases.
 * Hmm, seems like the function isn't actually printing the y-intercept. I
 * think it's using the wrong variable.
 * Wow those are very incorrect results - actually seems like the calculation
 * is using the uninitialized y_intercept->y instead of point->y
 * Now it gives the right result. I'll rename the function back and
 * comment out my test harness.
 */

#include <stdlib.h>
#include <stdio.h>

struct point2d {
    int x;
    int y;
};

int main(int argc, char** argv) {
    if(argc < 4) {
        printf("Program requires 3 arguments\n");
        return 1;
    }
    int slope = atoi(argv[1]);
    struct point2d *point = malloc(sizeof(struct point2d));
    point->x = atoi(argv[2]);
    point->y = atoi(argv[3]);
    struct point2d *y_intercept = malloc(sizeof(struct point2d));
    y_intercept->x = 0;
    y_intercept->y = point->y - (slope * point->x);
    printf("x coord: %d\n", y_intercept->x);
    printf("y coord: %d\n", y_intercept->y);
    return 0;
}

/*#define TESTCASE(m, x, y) { char* t[4] = { "", #m, #x, #y }; _main(4,t); }
int main(int argc, char** argv) {
    TESTCASE(-2,4,3)
    TESTCASE(2,5,7)
    TESTCASE(0,0,0)
    TESTCASE(0,0,1)
}*/