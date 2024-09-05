/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1926_main(void);


/* Function definitions */
int64_t _1926_main(void){
    int64_t _1927_x;
    int64_t* _1927_y;
    int64_t _1926_t5;
    uint8_t _1926_t7;
    int64_t _1926_t4;
    int64_t _1926_$retval;
    int64_t _1929_z;
    int64_t* _1926_t10;
    int64_t _1926_t13;
    int64_t _1926_t14;
    int64_t _1926_t16;
    int64_t _1926_t17;
    int64_t _1926_t20;
    _1927_x = 0;
    _1927_y = &_1927_x;
    _1926_t5 = 0;
    _1926_t7 = *_1927_y==_1926_t5;
    if (_1926_t7) {
        goto BB2159;
    } else {
        goto BB2163;
    }
BB2159:
    _1929_z = *_1927_y;
    _1926_t10 = &_1929_z;
    *_1926_t10 = $add_int64_t(_1929_z, _1929_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1929_z = $sub_int64_t(_1929_z, _1929_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1929_z = $mult_int64_t(_1929_z, _1929_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1926_t13 = 1;
    _1926_t14 = $add_int64_t(_1929_z, _1926_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1929_z = $div_int64_t(_1929_z, _1926_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1926_t16 = 1;
    _1926_t17 = $add_int64_t(_1929_z, _1926_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1929_z = $mod_int64_t(_1929_z, _1926_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1926_t20 = -1;
    _1929_z = $mult_int64_t(_1929_z, _1926_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1926_t4 = $mult_int64_t(_1929_z, _1926_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2162;
BB2163:
    _1926_t4 = 1000;
    goto BB2162;
BB2162:
    _1926_$retval = _1926_t4;
    return _1926_$retval;
}


int main(void) {
  printf("%ld",_1926_main());
  return 0;
}
