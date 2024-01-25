/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1736_main(void);


/* Function definitions */
int64_t _1736_main(void){
    int64_t _1737_x;
    int64_t* _1737_y;
    int64_t _1736_t3;
    uint8_t _1736_t5;
    int64_t _1736_t2;
    int64_t _1736_$retval;
    int64_t _1739_z;
    int64_t* _1736_t7;
    int64_t _1736_t10;
    int64_t _1736_t11;
    int64_t _1736_t13;
    int64_t _1736_t14;
    int64_t _1736_t17;
    _1737_x = 0;
    _1737_y = &_1737_x;
    _1736_t3 = 0;
    _1736_t5 = *_1737_y==_1736_t3;
    if (_1736_t5) {
        goto BB2017;
    } else {
        goto BB2021;
    }
BB2017:
    _1739_z = *_1737_y;
    _1736_t7 = &_1739_z;
    *_1736_t7 = $add_int64_t(_1739_z, _1739_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1739_z = $sub_int64_t(_1739_z, _1739_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1739_z = $mult_int64_t(_1739_z, _1739_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1736_t10 = 1;
    _1736_t11 = $add_int64_t(_1739_z, _1736_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1739_z = $div_int64_t(_1739_z, _1736_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1736_t13 = 1;
    _1736_t14 = $add_int64_t(_1739_z, _1736_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1739_z = $mod_int64_t(_1739_z, _1736_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1736_t17 = -1;
    _1739_z = $mult_int64_t(_1739_z, _1736_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1736_t2 = $mult_int64_t(_1739_z, _1736_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2020;
BB2021:
    _1736_t2 = 1000;
    goto BB2020;
BB2020:
    _1736_$retval = _1736_t2;
    return _1736_$retval;
}


int main(void) {
  printf("%ld",_1736_main());
  return 0;
}
