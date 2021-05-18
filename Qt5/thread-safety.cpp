/*
 * Key ideas:
 *
 * Thread-safe *functions*:
 *
 *   - A thread-safe function can be called simulatneously from multiple
 *     threads, even when the invocation uses shared data, because all
 *     references to shared data are serialized.
 *
 *   - A thread-safe function is always reentrant, but a reentrant function
 *     is not always thread-safe.
 *
 * Thread-safe *classes*:
 *
 *   - A class is thread-safe if its member functions can be called safely
 *     from multiple threads, even if all the threads use the *same* instance
 *     of the class.
 *
 * References:
 *
 *   [qt5doc] Reentrancy and Thread-Safety
 *     https://doc.qt.io/qt-5/threads-reentrancy.html
 */

// In the below class, access is serialized: Thread A performas steps
//
//   1. Load the variable's value in a register.
//   2. Increment or decrement the register's value.
//   3. Store the register's value back into main memory.
//
// without interruption (atomically) before thread B can perform the
// same steps; or vice versa.  An easy way to make the class thread-safe
// is to protect all access to the data members with a QMutex:

class Counter
{
public:
    Counter() { n = 0; }

    void increment() { QMutexLocker locker(&mutex); ++n; }
    void decrement() { QMutexLocker locker(&mutex); --n; }
    int value() const { QMutexLocker locker(&mutex); return n; }

private:
    mutable QMutex mutex;
    int n;
};
