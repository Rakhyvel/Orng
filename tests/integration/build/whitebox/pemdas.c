/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1709_main(void);


/* Function definitions */
int64_t _1709_main(void){
    int64_t _1710_x;
    int64_t* _1710_y;
    int64_t _1709_t3;
    uint8_t _1709_t5;
    int64_t _1709_t2;
    int64_t _1709_$retval;
    int64_t _1712_z;
    int64_t* _1709_t7;
    int64_t _1709_t10;
    int64_t _1709_t11;
    int64_t _1709_t13;
    int64_t _1709_t14;
    int64_t _1709_t17;
    _1710_x = 0;
    _1710_y = &_1710_x;
    _1709_t3 = 0;
    _1709_t5 = *_1710_y==_1709_t3;
    if (_1709_t5) {
        goto BB1995;
    } else {
        goto BB1999;
    }
BB1995:
    _1712_z = *_1710_y;
    _1709_t7 = &_1712_z;
    *_1709_t7 = $add_int64_t(_1712_z, _1712_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1712_z = $sub_int64_t(_1712_z, _1712_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1712_z = $mult_int64_t(_1712_z, _1712_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1709_t10 = 1;
    _1709_t11 = $add_int64_t(_1712_z, _1709_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1712_z = $div_int64_t(_1712_z, _1709_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1709_t13 = 1;
    _1709_t14 = $add_int64_t(_1712_z, _1709_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1712_z = $mod_int64_t(_1712_z, _1709_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1709_t17 = -1;
    _1712_z = $mult_int64_t(_1712_z, _1709_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1709_t2 = $mult_int64_t(_1712_z, _1709_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1998;
BB1999:
    _1709_t2 = 1000;
    goto BB1998;
BB1998:
    _1709_$retval = _1709_t2;
    return _1709_$retval;
}


int main(void) {
  printf("%ld",_1709_main());
  return 0;
}
