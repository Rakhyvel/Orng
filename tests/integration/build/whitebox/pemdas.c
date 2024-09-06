/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1941_main(void);


/* Function definitions */
int64_t _1941_main(void){
    int64_t _1942_x;
    int64_t* _1942_y;
    int64_t _1941_t5;
    uint8_t _1941_t7;
    int64_t _1941_t4;
    int64_t _1941_$retval;
    int64_t _1944_z;
    int64_t* _1941_t10;
    int64_t _1941_t13;
    int64_t _1941_t14;
    int64_t _1941_t16;
    int64_t _1941_t17;
    int64_t _1941_t20;
    _1942_x = 0;
    _1942_y = &_1942_x;
    _1941_t5 = 0;
    _1941_t7 = *_1942_y==_1941_t5;
    if (_1941_t7) {
        goto BB2174;
    } else {
        goto BB2178;
    }
BB2174:
    _1944_z = *_1942_y;
    _1941_t10 = &_1944_z;
    *_1941_t10 = $add_int64_t(_1944_z, _1944_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1944_z = $sub_int64_t(_1944_z, _1944_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1944_z = $mult_int64_t(_1944_z, _1944_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1941_t13 = 1;
    _1941_t14 = $add_int64_t(_1944_z, _1941_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1944_z = $div_int64_t(_1944_z, _1941_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1941_t16 = 1;
    _1941_t17 = $add_int64_t(_1944_z, _1941_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1944_z = $mod_int64_t(_1944_z, _1941_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1941_t20 = -1;
    _1944_z = $mult_int64_t(_1944_z, _1941_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1941_t4 = $mult_int64_t(_1944_z, _1941_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2177;
BB2178:
    _1941_t4 = 1000;
    goto BB2177;
BB2177:
    _1941_$retval = _1941_t4;
    return _1941_$retval;
}


int main(void) {
  printf("%ld",_1941_main());
  return 0;
}
