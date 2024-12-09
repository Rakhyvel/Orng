/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2006_main(void);


/* Function definitions */
int64_t _2006_main(void){
    int64_t _2007_x;
    int64_t* _2007_y;
    int64_t _2006_t5;
    uint8_t _2006_t7;
    int64_t _2006_t4;
    int64_t _2006_$retval;
    int64_t _2009_z;
    int64_t* _2006_t10;
    int64_t _2006_t13;
    int64_t _2006_t14;
    int64_t _2006_t16;
    int64_t _2006_t17;
    int64_t _2006_t20;
    _2007_x = 0;
    _2007_y = &_2007_x;
    _2006_t5 = 0;
    _2006_t7 = *_2007_y==_2006_t5;
    if (_2006_t7) {
        goto BB2207;
    } else {
        goto BB2211;
    }
BB2207:
    _2009_z = *_2007_y;
    _2006_t10 = &_2009_z;
    *_2006_t10 = $add_int64_t(_2009_z, _2009_z, "tests/integration/whitebox/pemdas.orng:7:24:\n        (&mut z)^ = z + z \n                      ^");
    _2009_z = $sub_int64_t(_2009_z, _2009_z, "tests/integration/whitebox/pemdas.orng:8:16:\n        z = z - z \n              ^");
    _2009_z = $mult_int64_t(_2009_z, _2009_z, "tests/integration/whitebox/pemdas.orng:9:16:\n        z = z * z \n              ^");
    _2006_t13 = 1;
    _2006_t14 = $add_int64_t(_2009_z, _2006_t13, "tests/integration/whitebox/pemdas.orng:10:21:\n        z = z / (z + 1)\n                   ^");
    _2009_z = $div_int64_t(_2009_z, _2006_t14, "tests/integration/whitebox/pemdas.orng:10:16:\n        z = z / (z + 1)\n              ^");
    _2006_t16 = 1;
    _2006_t17 = $add_int64_t(_2009_z, _2006_t16, "tests/integration/whitebox/pemdas.orng:11:21:\n        z = z % (z + 1) \n                   ^");
    _2009_z = $mod_int64_t(_2009_z, _2006_t17, "tests/integration/whitebox/pemdas.orng:11:16:\n        z = z % (z + 1) \n              ^");
    _2006_t20 = -1;
    _2009_z = $mult_int64_t(_2009_z, _2006_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    _2006_t4 = $mult_int64_t(_2009_z, _2006_t20, "tests/integration/whitebox/pemdas.orng:12:16:\n        z = z * (-1)\n              ^");
    goto BB2210;
BB2211:
    _2006_t4 = 1000;
    goto BB2210;
BB2210:
    _2006_$retval = _2006_t4;
    return _2006_$retval;
}


int main(void) {
  printf("%ld",_2006_main());
  return 0;
}
