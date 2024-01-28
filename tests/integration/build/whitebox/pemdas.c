/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1780_main(void);


/* Function definitions */
int64_t _1780_main(void){
    int64_t _1781_x;
    int64_t* _1781_y;
    int64_t _1780_t3;
    uint8_t _1780_t5;
    int64_t _1780_t2;
    int64_t _1780_$retval;
    int64_t _1783_z;
    int64_t* _1780_t7;
    int64_t _1780_t10;
    int64_t _1780_t11;
    int64_t _1780_t13;
    int64_t _1780_t14;
    int64_t _1780_t17;
    _1781_x = 0;
    _1781_y = &_1781_x;
    _1780_t3 = 0;
    _1780_t5 = *_1781_y==_1780_t3;
    if (_1780_t5) {
        goto BB2057;
    } else {
        goto BB2061;
    }
BB2057:
    _1783_z = *_1781_y;
    _1780_t7 = &_1783_z;
    *_1780_t7 = $add_int64_t(_1783_z, _1783_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1783_z = $sub_int64_t(_1783_z, _1783_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1783_z = $mult_int64_t(_1783_z, _1783_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1780_t10 = 1;
    _1780_t11 = $add_int64_t(_1783_z, _1780_t10, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1783_z = $div_int64_t(_1783_z, _1780_t11, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1780_t13 = 1;
    _1780_t14 = $add_int64_t(_1783_z, _1780_t13, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1783_z = $mod_int64_t(_1783_z, _1780_t14, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1780_t17 = -1;
    _1783_z = $mult_int64_t(_1783_z, _1780_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1780_t2 = $mult_int64_t(_1783_z, _1780_t17, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2060;
BB2061:
    _1780_t2 = 1000;
    goto BB2060;
BB2060:
    _1780_$retval = _1780_t2;
    return _1780_$retval;
}


int main(void) {
  printf("%ld",_1780_main());
  return 0;
}
