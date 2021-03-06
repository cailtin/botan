Support Information
=======================

Supported Platforms
------------------------

For Botan 2, the tier-1 supported platforms are

* Linux x86-64, GCC 4.8 or higher
* Linux x86-64, Clang 3.5 or higher
* Linux aarch64, GCC 4.8+
* Linux ppc64le, GCC 4.8+
* Windows x86-64, Visual C++ 2015 and 2017

These platforms are all tested by continuous integration, and the developers
have access to hardware in order to test patches. Problems affecting these
platforms are considered release blockers.

For Botan 2, the tier-2 supported platforms are

* Linux x86-32, GCC 4.8+
* Linux arm32, GCC 4.8+
* Windows x86-64, MinGW GCC
* Apple OS X x86-64, XCode Clang
* iOS arm32/arm64, XCode Clang
* Android arm32, NDK Clang
* FreeBSD x86-64, Clang 3.8+
* IncludeOS x86-32, Clang 3.8+

Some (but not all) of the tier-2 platforms are tested by CI. Things should
mostly work, and if problems are encountered, the Botan devs will probably be
able to help. But they are not as well tested as tier-1.

Of course many other modern OSes such as QNX, AIX, OpenBSD, NetBSD, and Solaris
are also probably fine (Botan has been tested on all of them successfully in the
past), but none of the core developers run these OSes and may not be able to
help so much in debugging problems. Patches to improve the build for these
platforms are welcome, as are any reports of successful use.

In theory any working C++11 compiler is fine but in practice, we only regularly
test with GCC, Clang, and Visual C++. Recent versions of IBM XLC will compile
the library but occasionally codegen bugs occur. Several other compilers (such
as Intel and PGI) are supported by the build system but are not tested by the
developers and may have build or codegen problems. Patches to improve support
for these compilers is welcome.

Branch Support Status
-------------------------

Following table provides the support status for Botan branches as of August 2018.
Any branch not listed here (including 1.11) is no longer supported.
Dates in the future are approximate.

============== ============== ========================== ============
Branch         First Release  End of Active Development  End of Life
============== ============== ========================== ============
1.8            2008-12-08     2010-08-31                 2016-02-13
1.10           2011-06-20     2012-07-10                 2018-12-31
2.x            2017-01-06     2020?                      2022 or later
3.x            2020?          ?                          ?
============== ============== ========================== ============

"Active development" refers to adding new features and optimizations. At the
conclusion of the active development phase, only bugfixes are applied.

Getting Help
------------------

To get help with Botan, open an issue on
`GitHub <https://github.com/randombit/botan/issues>`_
