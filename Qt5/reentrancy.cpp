/*
 * Key idea:
 *
 * Reentrant *functions*:
 *
 *   - A reentrant function can be called simulatneously from multiple threads,
 *     but only if each invocation uses its own data.
 *
 *   - A thread-safe function is always reentrant, but a reentrant function
 *     is not always thread-safe.
 *
 * Reentrant *classes*:
 *
 *   - A class is said to be reentrant if its member functions can be called
 *     safely from multiple threads, as long as each thread uses a *different*
 *     instance of the class.
 *
 *   - C++ classes are often reentrant, simply because they only access their
 *     own member data.  Any thread can call a member function on an instance
 *     of a reentrant class, as long as no other thread can call a member
 *     function on the *same* instance of the class at the same time.
 *
 *   - Many Qt classes are reentrant, but they are not thread-safe, because making
 *     them thread-safe would incur the extra overhead of repeatedly locking and
 *     unlocking a QMutex.  For example, QString is reentrant but not thread-safe.
 *     You can safely access *different* instances of QString from multiple threads
 *     simultaneously, but you can't safely access the *same* instance of QString
 *     from multiple threads simultaneously (unless you protect the accesses yourself
 *     with a QMutex).
 *
 * References:
 *
 *   [qt5doc] Reentrancy and Thread-Safety
 *     https://doc.qt.io/qt-5/threads-reentrancy.html
 */

// The Counter class below is reentrant.
//
// The class isn't thread safe, because if multiple threads try to modify the
// data member n, the result is undefined.  This is because the ++ and --
// operators aren't always atomic.  Indeed, they usually expand to three
// machine instructions:
//
//   1. Load the variable's value in a register.
//   2. Increment or decrement the register's value.
//   3. Store the register's value back into main memory.
//
// If thread A and thread B load the variable's old value simultaneously,
// increment their register, and store it back, they end up overwriting each
// other, and the variable is incremented only once!

class Counter
{
public:
    Counter() { n = 0; }

    void increment() { ++n; }  // -> not atomic!  so not thread-safe!
    void decrement() { --n; }  // -> not atomic!  so not thread-safe!
    int value() const { return n; }

private:
    int n;
}
