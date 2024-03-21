/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1862_main(void);


/* Function definitions */
int64_t _1862_main(void){
    int64_t _1863_x;
    int64_t* _1863_y;
    int64_t _1862_t5;
    uint8_t _1862_t7;
    int64_t _1862_t4;
    int64_t _1862_$retval;
    int64_t _1865_z;
    int64_t* _1862_t10;
    int64_t _1862_t13;
    int64_t _1862_t14;
    int64_t _1862_t16;
    int64_t _1862_t17;
    int64_t _1862_t20;
    _1863_x = 0;
    _1863_y = &_1863_x;
    _1862_t5 = 0;
    _1862_t7 = *_1863_y==_1862_t5;
    if (_1862_t7) {
        goto BB2091;
    } else {
        goto BB2095;
    }
BB2091:
    _1865_z = *_1863_y;
    _1862_t10 = &_1865_z;
    *_1862_t10 = $add_int64_t(_1865_z, _1865_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1865_z = $sub_int64_t(_1865_z, _1865_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1865_z = $mult_int64_t(_1865_z, _1865_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1862_t13 = 1;
    _1862_t14 = $add_int64_t(_1865_z, _1862_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1865_z = $div_int64_t(_1865_z, _1862_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1862_t16 = 1;
    _1862_t17 = $add_int64_t(_1865_z, _1862_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1865_z = $mod_int64_t(_1865_z, _1862_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1862_t20 = -1;
    _1865_z = $mult_int64_t(_1865_z, _1862_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1862_t4 = $mult_int64_t(_1865_z, _1862_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2094;
BB2095:
    _1862_t4 = 1000;
    goto BB2094;
BB2094:
    _1862_$retval = _1862_t4;
    return _1862_$retval;
}


int main(void) {
  printf("%ld",_1862_main());
  return 0;
}
