/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1804_main(void);


/* Function definitions */
int64_t _1804_main(void){
    int64_t _1805_x;
    int64_t* _1805_y;
    int64_t _1804_t3;
    uint8_t _1804_t5;
    int64_t _1804_t2;
    int64_t _1804_$retval;
    int64_t _1807_z;
    int64_t* _1804_t7;
    int64_t _1804_t10;
    int64_t _1804_t11;
    int64_t _1804_t13;
    int64_t _1804_t14;
    int64_t _1804_t17;
    _1805_x = 0;
    _1805_y = &_1805_x;
    _1804_t3 = 0;
    _1804_t5 = *_1805_y==_1804_t3;
    if (_1804_t5) {
        goto BB2069;
    } else {
        goto BB2073;
    }
BB2069:
    _1807_z = *_1805_y;
    _1804_t7 = &_1807_z;
    *_1804_t7 = $add_int64_t(_1807_z, _1807_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1807_z = $sub_int64_t(_1807_z, _1807_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1807_z = $mult_int64_t(_1807_z, _1807_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1804_t10 = 1;
    _1804_t11 = $add_int64_t(_1807_z, _1804_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1807_z = $div_int64_t(_1807_z, _1804_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1804_t13 = 1;
    _1804_t14 = $add_int64_t(_1807_z, _1804_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1807_z = $mod_int64_t(_1807_z, _1804_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1804_t17 = -1;
    _1807_z = $mult_int64_t(_1807_z, _1804_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1804_t2 = $mult_int64_t(_1807_z, _1804_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2072;
BB2073:
    _1804_t2 = 1000;
    goto BB2072;
BB2072:
    _1804_$retval = _1804_t2;
    return _1804_$retval;
}


int main(void) {
  printf("%ld",_1804_main());
  return 0;
}
