/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
	int64_t _4;
} struct1;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _415_main();

/* Function definitions */
int64_t _415_main() {
	int64_t _415_t1;
	int64_t _415_t2;
	int64_t _415_t3;
	int64_t _415_t4;
	int64_t _415_t5;
	struct1 _416_x;
	struct1* _415_t7;
	int64_t _415_t8;
	struct3 _416_y;
	int64_t _415_t9;
	int64_t _415_t10;
	int64_t _415_t11;
	int64_t _415_t12;
	int64_t _415_$retval;
BB0:
	_415_t1 = 1;
	_415_t2 = 2;
	_415_t3 = 3;
	_415_t4 = 4;
	_415_t5 = 5;
	_416_x = (struct1) {_415_t1, _415_t2, _415_t3, _415_t4, _415_t5};
	_415_t7 = &_416_x;
	_415_t8 = 5;
	_416_y = (struct3) {(int64_t*)_415_t7, _415_t8};
	_415_t9 = 2;
	_415_t10 = 81;
	*(((int64_t*)((&_416_y)->_0))+_415_t9) = _415_t10;
	_415_t11 = 2;
	_415_t12 = *(((int64_t*)((&_416_y)->_0))+_415_t11);
	_415_$retval = _415_t12;
	return _415_$retval;
}


int main()
{
  printf("%ld",_415_main());
  return 0;
}

#endif
