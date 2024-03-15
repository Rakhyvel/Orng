/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1757_main(void);


/* Function definitions */
int64_t _1757_main(void){
    uint8_t _1758_found;
    int64_t _1759_n;
    int64_t _1757_t5;
    uint8_t _1757_t6;
    int64_t _1757_t14;
    int64_t _1757_t10;
    uint8_t _1757_t12;
    int64_t _1757_t16;
    int64_t _1757_$retval;
    _1758_found = 0;
    _1759_n = 0;
    goto BB1954;
BB1954:
    _1757_t5 = 10;
    _1757_t6 = _1759_n<_1757_t5;
    if (_1757_t6) {
        goto BB1955;
    } else {
        goto BB1970;
    }
BB1955:
    if (_1758_found) {
        goto BB1956;
    } else {
        goto BB1958;
    }
BB1970:
    if (_1758_found) {
        goto BB1971;
    } else {
        goto BB1975;
    }
BB1956:
    _1759_n = 100;
    goto BB1958;
BB1958:
    _1757_t10 = 6;
    _1757_t12 = _1759_n==_1757_t10;
    if (_1757_t12) {
        goto BB1961;
    } else {
        goto BB1965;
    }
BB1971:
    _1757_t16 = 15;
    goto BB1974;
BB1975:
    _1757_t16 = 4;
    goto BB1974;
BB1961:
    _1758_found = 1;
    goto BB1965;
BB1965:
    _1757_t14 = 1;
    _1759_n = $add_int64_t(_1759_n, _1757_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1954;
BB1974:
    _1757_$retval = _1757_t16;
    return _1757_$retval;
}


int main(void) {
  printf("%ld",_1757_main());
  return 0;
}
