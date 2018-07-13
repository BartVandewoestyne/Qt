/*
 * The important remark seems to be that a range-based for loop has undefined
 * behavior when adding and removing items from a container while iterating
 * (see [logical20160829].  It is recommended to pass const containers to avoid
 * the price of a copy.
 *
 * References:
 *
 *   [evileg20180515] Qt/C++ - Tutorial 079. foreach vs range-based for in C++11?
 *     https://evileg.com/en/post/348/
 *
 *   [stackoverflow20170515] How to iterate through a QStringList
 *     https://stackoverflow.com/questions/44558568/how-to-iterate-through-a-qstringlist
 *
 *   [mutz20160829] Goodbye, Q_FOREACH
 *     https://www.kdab.com/goodbye-q_foreach/
 *
 *   [logikal20160819] C++ 11 AND QT - PART 1
 *     http://www.logikalsolutions.com/wordpress/information-technology/c-11-and-qt-part-1/
 *
 *   [stubert20160513] Simplifying Loops with C++11 in Qt Ways
 *     https://www.embeddeduse.com/2016/05/13/simplifying-loops-with-cpp11/
 *
 *   [vratil20150524] QT CONTAINERS AND C++11 RANGE-BASED LOOPS
 *     https://www.dvratil.cz/2015/06/qt-containers-and-c11-range-based-loops/
 *
 *   [tranter20130904] Qt and C++11
 *     https://www.ics.com/blog/qt-and-c11
 */
