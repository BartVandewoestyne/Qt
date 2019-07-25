/*
 * If you want to initialize a QString from a string literal in Qt5, you
 * should use:
 *
 *   - Most of the cases: QStringLiteral("foo") if it will actually be
 *     converted to QString
 *
 *   - QLatin1String("foo") if it is used with a function that has an overload
 *     for QLatin1String (such as operator==, operator+, startWith, replace,...)
 *
 * References:
 *
 *   [goffart20120521] QStringLiteral explained
 *     https://woboq.com/blog/qstringliteral.html
 */
