# Welcome to HoNLauncher

This repository is the source code for the new launcher that will be (or may already have? depending on how old this file is by the time you're reading it?) going out with the Hands of Necromancy update v3.0 and with Hands of Necromancy II.

The code is licensed GPL, however if you use it please use your own branding for your own game. This code is provided as-is in the hopes that it will be useful.

The main reason it was coded this way is because at the time of coding, there were no decent third-party GUI libraries that were A) lightweight, B) *truly* easy-to-use, and C) cross-platform.

Some notes:
- For our own particular game, we opted to use American-continent flags for Brazil, Mexico, and USA to represent Portuguese, Spanish, and English. The reason for this is two-fold: These are the most widely understood dialects of the relevant languages, and it's also what we had translators available for.
- For Win32 the flag emoji are used, however by default the system does not support them. Blame Microsoft for this. If there's an easy way to run those through Google's emoji font, I'd prefer to do it that way, but as it is now it is what it is.
- For Win32, if you're compiling debug, the program should compile as a console application. This is the only way to get your debug "printf"'s to appear. By default a release application will compile under the win32 subsystem. This is a GUI app first and foremost.
- If there's a truly cross-platform way to do this, that is more robust and provides more options, that doesn't bring in 300 5-megabyte libraries all at once, I'm all for it. Contributions welcome.
- For Apple and Windows, the basic vendor compiler and SDK (XCode, and Visual Studio + Windows SDK), plus Git and CMake, are all that are needed to compile this. For Linux, you must have libgtk3-dev installed as well.

Have fun!
