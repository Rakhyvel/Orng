/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1871_main(void);


/* Function definitions */
int64_t _1871_main(void){
    int64_t _1872_x;
    int64_t* _1872_y;
    int64_t _1871_t5;
    uint8_t _1871_t7;
    int64_t _1871_t4;
    int64_t _1871_$retval;
    int64_t _1874_z;
    int64_t* _1871_t10;
    int64_t _1871_t13;
    int64_t _1871_t14;
    int64_t _1871_t16;
    int64_t _1871_t17;
    int64_t _1871_t20;
    _1872_x = 0;
    _1872_y = &_1872_x;
    _1871_t5 = 0;
    _1871_t7 = *_1872_y==_1871_t5;
    if (_1871_t7) {
        goto BB2097;
    } else {
        goto BB2101;
    }
BB2097:
    _1874_z = *_1872_y;
    _1871_t10 = &_1874_z;
    *_1871_t10 = $add_int64_t(_1874_z, _1874_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1874_z = $sub_int64_t(_1874_z, _1874_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1874_z = $mult_int64_t(_1874_z, _1874_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1871_t13 = 1;
    _1871_t14 = $add_int64_t(_1874_z, _1871_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1874_z = $div_int64_t(_1874_z, _1871_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1871_t16 = 1;
    _1871_t17 = $add_int64_t(_1874_z, _1871_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1874_z = $mod_int64_t(_1874_z, _1871_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1871_t20 = -1;
    _1874_z = $mult_int64_t(_1874_z, _1871_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1871_t4 = $mult_int64_t(_1874_z, _1871_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2100;
BB2101:
    _1871_t4 = 1000;
    goto BB2100;
BB2100:
    _1871_$retval = _1871_t4;
    return _1871_$retval;
}


int main(void) {
  printf("%ld",_1871_main());
  return 0;
}
