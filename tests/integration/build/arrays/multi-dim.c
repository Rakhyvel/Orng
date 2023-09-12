/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;
typedef struct {
    struct0 _0;
    struct0 _1;
    struct0 _2;
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    struct0 _2_t5;
    struct0 _2_t9;
    struct1 _3_x;
    struct0 _2_t14;
    struct0 _2_t28;
    struct0 _2_t39;
    int64_t _2_$retval;
    _2_t1 = (struct0) {1, 2, 3};
    _2_t5 = (struct0) {4, 5, 68};
    _2_t9 = (struct0) {7, 8, 9};
    _3_x = (struct1) {_2_t1, _2_t5, _2_t9};
    _2_t14 = *(((struct0*)&_3_x)+1);
    _2_t28 = *(((struct0*)&_3_x)+1);
    *(((int64_t*)(((struct0*)&_3_x)+1))+2) = *(((int64_t*)(((struct0*)&_3_x)+1))+2) + 1;
    _2_t39 = *(((struct0*)&_3_x)+1);
    _2_$retval = (*(((int64_t*)(((struct0*)&_3_x)+1))+2));
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
