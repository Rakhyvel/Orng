/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2001_main(void);


/* Function definitions */
int64_t _2001_main(void){
    int64_t _2002_x;
    int64_t* _2002_y;
    int64_t _2001_t5;
    uint8_t _2001_t7;
    int64_t _2001_t4;
    int64_t _2001_$retval;
    int64_t _2004_z;
    int64_t* _2001_t10;
    int64_t _2001_t13;
    int64_t _2001_t14;
    int64_t _2001_t16;
    int64_t _2001_t17;
    int64_t _2001_t20;
    _2002_x = 0;
    _2002_y = &_2002_x;
    _2001_t5 = 0;
    _2001_t7 = *_2002_y==_2001_t5;
    if (_2001_t7) {
        goto BB2204;
    } else {
        goto BB2208;
    }
BB2204:
    _2004_z = *_2002_y;
    _2001_t10 = &_2004_z;
    *_2001_t10 = $add_int64_t(_2004_z, _2004_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _2004_z = $sub_int64_t(_2004_z, _2004_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _2004_z = $mult_int64_t(_2004_z, _2004_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _2001_t13 = 1;
    _2001_t14 = $add_int64_t(_2004_z, _2001_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _2004_z = $div_int64_t(_2004_z, _2001_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _2001_t16 = 1;
    _2001_t17 = $add_int64_t(_2004_z, _2001_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _2004_z = $mod_int64_t(_2004_z, _2001_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _2001_t20 = -1;
    _2004_z = $mult_int64_t(_2004_z, _2001_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _2001_t4 = $mult_int64_t(_2004_z, _2001_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2207;
BB2208:
    _2001_t4 = 1000;
    goto BB2207;
BB2207:
    _2001_$retval = _2001_t4;
    return _2001_$retval;
}


int main(void) {
  printf("%ld",_2001_main());
  return 0;
}
