/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1703_main(void);

/* Function definitions */
int64_t _1703_main(void){
    int64_t _1704_x;
    int64_t* _1704_y;
    int64_t _1703_t3;
    uint8_t _1703_t5;
    int64_t _1703_t2;
    int64_t _1703_$retval;
    int64_t _1707_z;
    int64_t* _1703_t7;
    int64_t _1703_t10;
    int64_t _1703_t11;
    int64_t _1703_t13;
    int64_t _1703_t14;
    int64_t _1703_t17;
    _1704_x = 0;
    _1704_y = &_1704_x;
    _1703_t3 = 0;
    _1703_t5 = *_1704_y == _1703_t3;
    if (_1703_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1707_z = *_1704_y;
    _1703_t7 = &_1707_z;
    *_1703_t7 = $add_int64_t(_1707_z, _1707_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1707_z = $sub_int64_t(_1707_z, _1707_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1707_z = $mult_int64_t(_1707_z, _1707_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1703_t10 = 1;
    _1703_t11 = $add_int64_t(_1707_z, _1703_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1707_z = $div_int64_t(_1707_z, _1703_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1703_t13 = 1;
    _1703_t14 = $add_int64_t(_1707_z, _1703_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1707_z = $mod_int64_t(_1707_z, _1703_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1703_t17 = -1;
    _1707_z = $mult_int64_t(_1707_z, _1703_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1703_t2 = $mult_int64_t(_1707_z, _1703_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1703_t2 = 1000;
    goto BB6;
BB6:
    _1703_$retval = _1703_t2;
    return _1703_$retval;
}

int main(void) {
  printf("%ld",_1703_main());
  return 0;
}
