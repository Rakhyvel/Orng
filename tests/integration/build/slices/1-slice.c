/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
} struct2;

/* Function forward definitions */
int64_t _942_main(void);
int64_t _944_first(struct1 _944_xs);

/* Function definitions */
int64_t _942_main(void) {
    function0 _942_t0;
    int64_t _942_t3;
    int64_t _942_t5;
    struct2 _942_t4;
    int64_t* _942_t6;
    int64_t _942_t7;
    struct1 _942_t2;
    int64_t _942_t1;
    int64_t _942_$retval;
    _942_t0 = _944_first;
    _942_t3 = 0;
    _942_t5 = 233;
    _942_t4 = (struct2) {_942_t5};
    _942_t6 = ((int64_t*)&_942_t4 + _942_t3);
    _942_t7 = 1;
    _942_t2 = (struct1) {_942_t6, _942_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _942_t1 = _942_t0(_942_t2);
    $line_idx--;
    _942_$retval = _942_t1;
    return _942_$retval;
}

int64_t _944_first(struct1 _944_xs) {
    int64_t _944_t0;
    int64_t _944_$retval;
    _944_t0 = 0;
    _944_$retval = *((int64_t*)_944_xs._0 + _944_t0);
    return _944_$retval;
}

int main(void) {
  printf("%ld",_942_main());
  return 0;
}
