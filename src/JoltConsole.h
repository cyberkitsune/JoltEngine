/* 
 * File:   JoltConsole.h
 * Author: Sean McClenaghan
 *
 * Created on February 4, 2013, 7:41 PM
 */

#ifndef JOLTCONSOLE_H
#define	JOLTCONSOLE_H

class JoltConsole {
public:
    JoltConsole();
    static void logInfo(const char *module, const char *message, ...);
private:

};

#endif	/* JOLTCONSOLE_H */

