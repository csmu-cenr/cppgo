class Test {
public:
	int f0() { return this->_f0(); }
	int f1(int x) { return this->_f1(x); }
	int f2(int x, int y) { return this->_f2(x, y); }
	int f3(int x, int y, int z) { return this->_f3(x, y, z); }
	int f4(int a, int b, int c, int d) { return  this->_f4(a, b, c, d); }
	int f5(int a, int b, int c, int d, int e) { return this->_f5(a, b, c, d, e); }
private:
	int _f0() { return 42; }
	int _f1(int x) { return x + 1; }
	int _f2(int x, int y) { return x / y; }
	int _f3(int x, int y, int z) { return x / y / z; }
	int _f4(int a, int b, int c, int d) {  return a / b / c / d; }
	int _f5(int a, int b, int c, int d, int e) { return e; }
};

typedef int (Test::*tf0)();
typedef int (Test::*tf1)(int);
typedef int (Test::*tf2)(int, int);
typedef int (Test::*tf3)(int, int, int);
typedef int (Test::*tf4)(int, int, int, int);
typedef int (Test::*tf5)(int, int, int, int, int);

extern "C"
{

void *thiscall_obj() { return new Test(); }
	
#ifdef WIN32
#pragma GCC diagnostic ignored "-Wpmf-conversions"
void *thiscall_addr_f0() { return (void *)&Test::f0; }
void *thiscall_addr_f1() { return (void *)&Test::f1; }
void *thiscall_addr_f2() { return (void *)&Test::f2; }
void *thiscall_addr_f3() { return (void *)&Test::f3; }
void *thiscall_addr_f4() { return (void *)&Test::f4; }
void *thiscall_addr_f5() { return (void *)&Test::f5; }
#else /* !WIN32 */
tf0 thiscall_addr_f0() { return &Test::f0; }
tf1 thiscall_addr_f1() { return &Test::f1; }
tf2 thiscall_addr_f2() { return &Test::f2; }
tf3 thiscall_addr_f3() { return &Test::f3; }
tf4 thiscall_addr_f4() { return &Test::f4; }
tf5 thiscall_addr_f5() { return &Test::f5; }
#endif /* WIN32 */

}
