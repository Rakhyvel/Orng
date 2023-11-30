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
int64_t _61_add(int64_t _61_a,int64_t _61_b);
int64_t _57_main(void);

/* Function definitions */
int64_t _61_add(int64_t _61_a,int64_t _61_b) {
    int64_t _61_$retval;
    _61_$retval = $add_int64_t(_61_a, _61_b, "tests/integration/comptime/index-homotypical.orng:7:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _61_$retval;
}

int64_t _57_main(void) {
    uint32_t _57_t1;
    int64_t _57_t2;
    double _57_t3;
    struct0 _58_x;
    int64_t _57_$retval;
    _57_t1 = 960;
    _57_t2 = 248;
    _57_t3 = 3.14e+00;
    _58_x = (struct0) {_57_t1, _57_t2, _57_t3};
    _57_$retval = _58_x._1;
    return _57_$retval;
}

int main(void) {
  printf("%ld",_57_main());
  return 0;
}
