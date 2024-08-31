/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1876_main(void);


/* Function definitions */
int64_t _1876_main(void){
    int64_t _1877_x;
    int64_t* _1877_y;
    int64_t _1876_t5;
    uint8_t _1876_t7;
    int64_t _1876_t4;
    int64_t _1876_$retval;
    int64_t _1879_z;
    int64_t* _1876_t10;
    int64_t _1876_t13;
    int64_t _1876_t14;
    int64_t _1876_t16;
    int64_t _1876_t17;
    int64_t _1876_t20;
    _1877_x = 0;
    _1877_y = &_1877_x;
    _1876_t5 = 0;
    _1876_t7 = *_1877_y==_1876_t5;
    if (_1876_t7) {
        goto BB2101;
    } else {
        goto BB2105;
    }
BB2101:
    _1879_z = *_1877_y;
    _1876_t10 = &_1879_z;
    *_1876_t10 = $add_int64_t(_1879_z, _1879_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1879_z = $sub_int64_t(_1879_z, _1879_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1879_z = $mult_int64_t(_1879_z, _1879_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1876_t13 = 1;
    _1876_t14 = $add_int64_t(_1879_z, _1876_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1879_z = $div_int64_t(_1879_z, _1876_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1876_t16 = 1;
    _1876_t17 = $add_int64_t(_1879_z, _1876_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1879_z = $mod_int64_t(_1879_z, _1876_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1876_t20 = -1;
    _1879_z = $mult_int64_t(_1879_z, _1876_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1876_t4 = $mult_int64_t(_1879_z, _1876_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2104;
BB2105:
    _1876_t4 = 1000;
    goto BB2104;
BB2104:
    _1876_$retval = _1876_t4;
    return _1876_$retval;
}


int main(void) {
  printf("%ld",_1876_main());
  return 0;
}
