/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1735_main(void);


/* Function definitions */
int64_t _1735_main(void){
    uint8_t _1736_found;
    int64_t _1737_n;
    int64_t _1735_t3;
    uint8_t _1735_t4;
    int64_t _1735_t12;
    int64_t _1735_t8;
    uint8_t _1735_t10;
    int64_t _1735_t14;
    int64_t _1735_$retval;
    _1736_found = 0;
    _1737_n = 0;
    goto BB1955;
BB1955:
    _1735_t3 = 10;
    _1735_t4 = _1737_n<_1735_t3;
    if (_1735_t4) {
        goto BB1956;
    } else {
        goto BB1971;
    }
BB1956:
    if (_1736_found) {
        goto BB1957;
    } else {
        goto BB1959;
    }
BB1971:
    if (_1736_found) {
        goto BB1972;
    } else {
        goto BB1976;
    }
BB1957:
    _1737_n = 100;
    goto BB1959;
BB1959:
    _1735_t8 = 6;
    _1735_t10 = _1737_n==_1735_t8;
    if (_1735_t10) {
        goto BB1962;
    } else {
        goto BB1966;
    }
BB1972:
    _1735_t14 = 15;
    goto BB1975;
BB1976:
    _1735_t14 = 4;
    goto BB1975;
BB1962:
    _1736_found = 1;
    goto BB1966;
BB1966:
    _1735_t12 = 1;
    _1737_n = $add_int64_t(_1737_n, _1735_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1955;
BB1975:
    _1735_$retval = _1735_t14;
    return _1735_$retval;
}


int main(void) {
  printf("%ld",_1735_main());
  return 0;
}
