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
} struct0;

/* Function forward definitions */
int64_t _196_add(int64_t _196_a,int64_t _196_b);
int64_t _186_main(void);

/* Function definitions */
int64_t _196_add(int64_t _196_a,int64_t _196_b) {
    int64_t _196_$retval;
    _196_$retval = $add_int64_t(_196_a, _196_b, "tests/integration/comptime/default-init.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _196_$retval;
}

int64_t _186_main(void) {
    int64_t _186_t1;
    int64_t _186_t2;
    struct0 _187_x;
    int64_t _186_$retval;
    _186_t1 = 240;
    _186_t2 = 5;
    _187_x = (struct0) {_186_t1, _186_t2};
    _186_$retval = $add_int64_t(_187_x._0, _187_x._1, "tests/integration/comptime/default-init.orng:4:10:\n    x.a + x.b\n        ^");
    return _186_$retval;
}

int main(void) {
  printf("%ld",_186_main());
  return 0;
}
