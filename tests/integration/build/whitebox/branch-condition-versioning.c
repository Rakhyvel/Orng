/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1667_main(void);


/* Function definitions */
int64_t _1667_main(void){
    uint8_t _1668_found;
    int64_t _1669_n;
    int64_t _1667_t3;
    uint8_t _1667_t4;
    int64_t _1667_t12;
    int64_t _1667_t8;
    uint8_t _1667_t10;
    int64_t _1667_t14;
    int64_t _1667_$retval;
    _1668_found = 0;
    _1669_n = 0;
    goto BB1903;
BB1903:
    _1667_t3 = 10;
    _1667_t4 = _1669_n<_1667_t3;
    if (_1667_t4) {
        goto BB1904;
    } else {
        goto BB1919;
    }
BB1904:
    if (_1668_found) {
        goto BB1905;
    } else {
        goto BB1907;
    }
BB1919:
    if (_1668_found) {
        goto BB1920;
    } else {
        goto BB1924;
    }
BB1905:
    _1669_n = 100;
    goto BB1907;
BB1907:
    _1667_t8 = 6;
    _1667_t10 = _1669_n==_1667_t8;
    if (_1667_t10) {
        goto BB1910;
    } else {
        goto BB1914;
    }
BB1920:
    _1667_t14 = 15;
    goto BB1923;
BB1924:
    _1667_t14 = 4;
    goto BB1923;
BB1910:
    _1668_found = 1;
    goto BB1914;
BB1914:
    _1667_t12 = 1;
    _1669_n = $add_int64_t(_1669_n, _1667_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1903;
BB1923:
    _1667_$retval = _1667_t14;
    return _1667_$retval;
}


int main(void) {
  printf("%ld",_1667_main());
  return 0;
}
