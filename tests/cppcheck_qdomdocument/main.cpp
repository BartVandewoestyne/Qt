/*
 * Test program to check behavior of cppcheck.
 *
 * On the code below, it gives "Uninitialized variable: a".
 *
 */

class A
{
public:
  A() {}

  void f() {}

};

int main()
{
    A a;
    a.f();
    return 0;
}
