/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1643_main(void);

/* Function definitions */
int64_t _1643_main(void){
    int64_t _1644_x;
    int64_t* _1644_y;
    int64_t _1643_t3;
    uint8_t _1643_t5;
    int64_t _1643_t2;
    int64_t _1643_$retval;
    int64_t _1647_z;
    int64_t* _1643_t7;
    int64_t _1643_t10;
    int64_t _1643_t11;
    int64_t _1643_t13;
    int64_t _1643_t14;
    int64_t _1643_t17;
    _1644_x = 0;
    _1644_y = &_1644_x;
    _1643_t3 = 0;
    _1643_t5 = *_1644_y == _1643_t3;
    if (_1643_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1647_z = *_1644_y;
    _1643_t7 = &_1647_z;
    *_1643_t7 = $add_int64_t(_1647_z, _1647_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1647_z = $sub_int64_t(_1647_z, _1647_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1647_z = $mult_int64_t(_1647_z, _1647_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1643_t10 = 1;
    _1643_t11 = $add_int64_t(_1647_z, _1643_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1647_z = $div_int64_t(_1647_z, _1643_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1643_t13 = 1;
    _1643_t14 = $add_int64_t(_1647_z, _1643_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1647_z = $mod_int64_t(_1647_z, _1643_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1643_t17 = -1;
    _1647_z = $mult_int64_t(_1647_z, _1643_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1643_t2 = $mult_int64_t(_1647_z, _1643_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB6;
BB7:
    _1643_t2 = 1000;
    goto BB6;
BB6:
    _1643_$retval = _1643_t2;
    return _1643_$retval;
}

int main(void) {
  printf("%ld",_1643_main());
  return 0;
}
