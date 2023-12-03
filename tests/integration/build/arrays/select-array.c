/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _82_main(void);

/* Function definitions */
int64_t _82_main(void) {
    int64_t _82_t2;
    int64_t _82_t3;
    int64_t _82_t4;
    struct0 _82_t1;
    int64_t _82_t6;
    int64_t _82_t7;
    int64_t _82_t8;
    struct0 _82_t5;
    struct1 _83_x;
    int64_t _82_t10;
    int64_t _82_t11;
    int64_t _82_$retval;
    _82_t2 = 1;
    _82_t3 = 2;
    _82_t4 = 3;
    _82_t1 = (struct0) {_82_t2, _82_t3, _82_t4};
    _82_t6 = 4;
    _82_t7 = 5;
    _82_t8 = 6;
    _82_t5 = (struct0) {_82_t6, _82_t7, _82_t8};
    _83_x = (struct1) {_82_t1, _82_t5};
    _82_t10 = 1;
    *((int64_t*)&_83_x._0 + _82_t10) = 72;
    _82_t11 = 1;
    _82_$retval = *((int64_t*)&_83_x._0 + _82_t11);
    return _82_$retval;
}

int main(void) {
  printf("%ld",_82_main());
  return 0;
}
