/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint32_t _0;
    int64_t _1;
    double _2;
} struct0;

/* Function forward definitions */
int64_t _119_add(int64_t _119_a,int64_t _119_b);
int64_t _117_main(void);

/* Function definitions */
int64_t _119_add(int64_t _119_a,int64_t _119_b) {
    int64_t _119_$retval;
    _119_$retval = $add_int64_t(_119_a, _119_b, "tests/integration/comptime/index-heterotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _119_$retval;
}

int64_t _117_main(void) {
    uint32_t _117_t1;
    int64_t _117_t2;
    double _117_t3;
    struct0 _118_x;
    int64_t _117_$retval;
    _117_t1 = 960;
    _117_t2 = 248;
    _117_t3 = 3.14e+00;
    _118_x = (struct0) {_117_t1, _117_t2, _117_t3};
    _117_$retval = _118_x._1;
    return _117_$retval;
}

int main(void) {
  printf("%ld",_117_main());
  return 0;
}
