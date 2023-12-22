/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1599_main(void);

/* Function definitions */
int64_t _1599_main(void){
    int64_t _1600_x;
    int64_t* _1600_y;
    int64_t _1599_t3;
    uint8_t _1599_t5;
    int64_t _1599_t2;
    int64_t _1599_$retval;
    int64_t _1602_z;
    int64_t* _1599_t7;
    int64_t _1599_t10;
    int64_t _1599_t11;
    int64_t _1599_t13;
    int64_t _1599_t14;
    int64_t _1599_t17;
    _1600_x = 0;
    _1600_y = &_1600_x;
    _1599_t3 = 0;
    _1599_t5 = *_1600_y == _1599_t3;
    if (_1599_t5) {
        goto BB1953;
    } else {
        goto BB1957;
    }
BB1953:
    _1602_z = *_1600_y;
    _1599_t7 = &_1602_z;
    *_1599_t7 = $add_int64_t(_1602_z, _1602_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1602_z = $sub_int64_t(_1602_z, _1602_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1602_z = $mult_int64_t(_1602_z, _1602_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1599_t10 = 1;
    _1599_t11 = $add_int64_t(_1602_z, _1599_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1602_z = $div_int64_t(_1602_z, _1599_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1599_t13 = 1;
    _1599_t14 = $add_int64_t(_1602_z, _1599_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1602_z = $mod_int64_t(_1602_z, _1599_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1599_t17 = -1;
    _1602_z = $mult_int64_t(_1602_z, _1599_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1599_t2 = $mult_int64_t(_1602_z, _1599_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1956;
BB1957:
    _1599_t2 = 1000;
    goto BB1956;
BB1956:
    _1599_$retval = _1599_t2;
    return _1599_$retval;
}

int main(void) {
  printf("%ld",_1599_main());
  return 0;
}
