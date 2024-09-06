/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1934_main(void);


/* Function definitions */
int64_t _1934_main(void){
    int64_t _1935_x;
    int64_t* _1935_y;
    int64_t _1934_t5;
    uint8_t _1934_t7;
    int64_t _1934_t4;
    int64_t _1934_$retval;
    int64_t _1937_z;
    int64_t* _1934_t10;
    int64_t _1934_t13;
    int64_t _1934_t14;
    int64_t _1934_t16;
    int64_t _1934_t17;
    int64_t _1934_t20;
    _1935_x = 0;
    _1935_y = &_1935_x;
    _1934_t5 = 0;
    _1934_t7 = *_1935_y==_1934_t5;
    if (_1934_t7) {
        goto BB2166;
    } else {
        goto BB2170;
    }
BB2166:
    _1937_z = *_1935_y;
    _1934_t10 = &_1937_z;
    *_1934_t10 = $add_int64_t(_1937_z, _1937_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _1937_z = $sub_int64_t(_1937_z, _1937_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _1937_z = $mult_int64_t(_1937_z, _1937_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _1934_t13 = 1;
    _1934_t14 = $add_int64_t(_1937_z, _1934_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _1937_z = $div_int64_t(_1937_z, _1934_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _1934_t16 = 1;
    _1934_t17 = $add_int64_t(_1937_z, _1934_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _1937_z = $mod_int64_t(_1937_z, _1934_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _1934_t20 = -1;
    _1937_z = $mult_int64_t(_1937_z, _1934_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _1934_t4 = $mult_int64_t(_1937_z, _1934_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2169;
BB2170:
    _1934_t4 = 1000;
    goto BB2169;
BB2169:
    _1934_$retval = _1934_t4;
    return _1934_$retval;
}


int main(void) {
  printf("%ld",_1934_main());
  return 0;
}
