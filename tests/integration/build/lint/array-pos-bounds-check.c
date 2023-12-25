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
        int64_t _3;
} struct0;

typedef int64_t(*function1)(void);

/* Function forward definitions */
int64_t _1017_main(void);
int64_t _1019_f(void);

/* Function definitions */
int64_t _1017_main(void){
    int64_t _1017_t1;
    int64_t _1017_t2;
    int64_t _1017_t3;
    int64_t _1017_t4;
    struct0 _1018_x;
    function1 _1017_t5;
    int64_t _1017_t6;
    int64_t _1017_t7;
    int64_t _1017_$retval;
    _1017_t1 = 0;
    _1017_t2 = 0;
    _1017_t3 = 0;
    _1017_t4 = 0;
    _1018_x = (struct0) {_1017_t1, _1017_t2, _1017_t3, _1017_t4};
    _1017_t5 = _1019_f;
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _1017_t6 = _1017_t5();
    $line_idx--;
    _1017_t7 = 4;
    $bounds_check(_1017_t6, _1017_t7, "tests/integration/lint/array-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1017_$retval = *((int64_t*)&_1018_x + _1017_t6);
    return _1017_$retval;
}

int64_t _1019_f(void){
    int64_t _1019_$retval;
    _1019_$retval = 100;
    return _1019_$retval;
}

int main(void) {
  printf("%ld",_1017_main());
  return 0;
}
