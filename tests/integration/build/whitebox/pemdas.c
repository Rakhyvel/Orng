/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1976_main(void);


/* Function definitions */
int64_t _1976_main(void){
    int64_t _1977_x;
    int64_t* _1977_y;
    int64_t _1976_t5;
    uint8_t _1976_t7;
    int64_t _1976_t4;
    int64_t _1976_$retval;
    int64_t _1979_z;
    int64_t* _1976_t10;
    int64_t _1976_t13;
    int64_t _1976_t14;
    int64_t _1976_t16;
    int64_t _1976_t17;
    int64_t _1976_t20;
    _1977_x = 0;
    _1977_y = &_1977_x;
    _1976_t5 = 0;
    _1976_t7 = *_1977_y==_1976_t5;
    if (_1976_t7) {
        goto BB2178;
    } else {
        goto BB2182;
    }
BB2178:
    _1979_z = *_1977_y;
    _1976_t10 = &_1979_z;
    *_1976_t10 = $add_int64_t(_1979_z, _1979_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1979_z = $sub_int64_t(_1979_z, _1979_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1979_z = $mult_int64_t(_1979_z, _1979_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1976_t13 = 1;
    _1976_t14 = $add_int64_t(_1979_z, _1976_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1979_z = $div_int64_t(_1979_z, _1976_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1976_t16 = 1;
    _1976_t17 = $add_int64_t(_1979_z, _1976_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1979_z = $mod_int64_t(_1979_z, _1976_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1976_t20 = -1;
    _1979_z = $mult_int64_t(_1979_z, _1976_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1976_t4 = $mult_int64_t(_1979_z, _1976_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2181;
BB2182:
    _1976_t4 = 1000;
    goto BB2181;
BB2181:
    _1976_$retval = _1976_t4;
    return _1976_$retval;
}


int main(void) {
  printf("%ld",_1976_main());
  return 0;
}
