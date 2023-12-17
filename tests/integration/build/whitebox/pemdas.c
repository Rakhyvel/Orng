/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1788_main(void);

/* Function definitions */
int64_t _1788_main(void){
    int64_t _1789_x;
    int64_t* _1789_y;
    int64_t _1788_t3;
    uint8_t _1788_t5;
    int64_t _1788_t2;
    int64_t _1788_$retval;
    int64_t _1792_z;
    int64_t* _1788_t7;
    int64_t _1788_t10;
    int64_t _1788_t11;
    int64_t _1788_t13;
    int64_t _1788_t14;
    int64_t _1788_t17;
    _1789_x = 0;
    _1789_y = &_1789_x;
    _1788_t3 = 0;
    _1788_t5 = *_1789_y == _1788_t3;
    if (_1788_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1792_z = *_1789_y;
    _1788_t7 = &_1792_z;
    *_1788_t7 = $add_int64_t(_1792_z, _1792_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1792_z = $sub_int64_t(_1792_z, _1792_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1792_z = $mult_int64_t(_1792_z, _1792_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1788_t10 = 1;
    _1788_t11 = $add_int64_t(_1792_z, _1788_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1792_z = $div_int64_t(_1792_z, _1788_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1788_t13 = 1;
    _1788_t14 = $add_int64_t(_1792_z, _1788_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1792_z = $mod_int64_t(_1792_z, _1788_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1788_t17 = -1;
    _1792_z = $mult_int64_t(_1792_z, _1788_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1788_t2 = $mult_int64_t(_1792_z, _1788_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1788_t2 = 1000;
    goto BB6;
BB6:
    _1788_$retval = _1788_t2;
    return _1788_$retval;
}

int main(void) {
  printf("%ld",_1788_main());
  return 0;
}
