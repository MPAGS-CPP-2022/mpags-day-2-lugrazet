# mpags-cipher
A simple command line tool for encrypting/decrypting text using a Caesar Shift

## Authors
Thomas Latham, Ben Morgan, Mark Slater, Matt Williams, Luke Kreczko

## Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 8 or better, Clang 8 or better are recommended) on a UNIX operating
system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window
and change directory into /build. Then run:
```
$ cmake ../src
$ make
$ ./mpags-cipher <options>

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are then Caesar shifted by the encryption/decryption key that was provided. (No encryption is the same as encryption of key 0).
The shifted string is then output to a text file, or if none is provided, is output to stdout.

## Source code layout
```
├── CMakeLists.txt
├── LICENSE                     License file, in our case MIT
├── MPAGSCipher                 Folder of Modularised Code segments
│   ├── processCommandLine.cpp  Interprets command line arguments
│   ├── processCommandLine.hpp  Header file of ^
│   ├── runCaesarCipher.cpp     Performs a Caesar shift
│   ├── runCaesarCipher.hpp     Header file of ^
│   ├── TransformChar.cpp       Transliterates strings
│   └── TransformChar.hpp       Header file of ^
├── mpags-cipher.cpp            Main program C++ source file
└── README.md                   This file, describes the project  
```

## Copying
`mpags-cipher` is licensed under the terms of the MIT License.
Please see the file [`LICENSE`](LICENSE) for full details.