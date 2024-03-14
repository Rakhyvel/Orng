/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1860_main(void);


/* Function definitions */
int64_t _1860_main(void){
    int64_t _1861_x;
    int64_t* _1861_y;
    int64_t _1860_t5;
    uint8_t _1860_t7;
    int64_t _1860_t4;
    int64_t _1860_$retval;
    int64_t _1863_z;
    int64_t* _1860_t10;
    int64_t _1860_t13;
    int64_t _1860_t14;
    int64_t _1860_t16;
    int64_t _1860_t17;
    int64_t _1860_t20;
    _1861_x = 0;
    _1861_y = &_1861_x;
    _1860_t5 = 0;
    _1860_t7 = *_1861_y==_1860_t5;
    if (_1860_t7) {
        goto BB2121;
    } else {
        goto BB2125;
    }
BB2121:
    _1863_z = *_1861_y;
    _1860_t10 = &_1863_z;
    *_1860_t10 = $add_int64_t(_1863_z, _1863_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1863_z = $sub_int64_t(_1863_z, _1863_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1863_z = $mult_int64_t(_1863_z, _1863_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1860_t13 = 1;
    _1860_t14 = $add_int64_t(_1863_z, _1860_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1863_z = $div_int64_t(_1863_z, _1860_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1860_t16 = 1;
    _1860_t17 = $add_int64_t(_1863_z, _1860_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1863_z = $mod_int64_t(_1863_z, _1860_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1860_t20 = -1;
    _1863_z = $mult_int64_t(_1863_z, _1860_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1860_t4 = $mult_int64_t(_1863_z, _1860_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2124;
BB2125:
    _1860_t4 = 1000;
    goto BB2124;
BB2124:
    _1860_$retval = _1860_t4;
    return _1860_$retval;
}


int main(void) {
  printf("%ld",_1860_main());
  return 0;
}
