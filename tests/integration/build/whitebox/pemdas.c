/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1647_main(void);

/* Function definitions */
int64_t _1647_main(void){
    int64_t _1648_x;
    int64_t* _1648_y;
    int64_t _1647_t3;
    uint8_t _1647_t5;
    int64_t _1647_t2;
    int64_t _1647_$retval;
    int64_t _1650_z;
    int64_t* _1647_t7;
    int64_t _1647_t10;
    int64_t _1647_t11;
    int64_t _1647_t13;
    int64_t _1647_t14;
    int64_t _1647_t17;
    _1648_x = 0;
    _1648_y = &_1648_x;
    _1647_t3 = 0;
    _1647_t5 = *_1648_y==_1647_t3;
    if (_1647_t5) {
        goto BB1948;
    } else {
        goto BB1952;
    }
BB1948:
    _1650_z = *_1648_y;
    _1647_t7 = &_1650_z;
    *_1647_t7 = $add_int64_t(_1650_z, _1650_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1650_z = $sub_int64_t(_1650_z, _1650_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1650_z = $mult_int64_t(_1650_z, _1650_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1647_t10 = 1;
    _1647_t11 = $add_int64_t(_1650_z, _1647_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1650_z = $div_int64_t(_1650_z, _1647_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1647_t13 = 1;
    _1647_t14 = $add_int64_t(_1650_z, _1647_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1650_z = $mod_int64_t(_1650_z, _1647_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1647_t17 = -1;
    _1650_z = $mult_int64_t(_1650_z, _1647_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1647_t2 = $mult_int64_t(_1650_z, _1647_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB1951;
BB1952:
    _1647_t2 = 1000;
    goto BB1951;
BB1951:
    _1647_$retval = _1647_t2;
    return _1647_$retval;
}

int main(void) {
  printf("%ld",_1647_main());
  return 0;
}
