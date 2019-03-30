#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#ifdef _MSC_VER
#include <io.h>
#define read _read
#else // _MSC_VER
#include <unistd.h>
#endif  // _MSC_VER
#include <stdio.h>

#endif /* _SYSCALLS_H_ */
