# Overview

After watching Jim Hall's excellent Free DOS programming tutorial on how to write a Solitaire game [YouTube video](https://www.youtube.com/watch?v=zczmAkd8mvA) I decided to expand on the idea. 

Changes:

* Moved a number of sections into their own functions (print deck, etc..).
* Instead of using `X` to represent the `10` card I represented the card as a `10`.
* Cleaned up output to make it easier to read.
* Created a  Open Watcom `Makefile` to make compiling easier.

This was done strictly for fun and learning as I am a novice.

# Building and Running

I edited and built the code on `FreeDOS 1.4-RC3` using  Open Watcom as the compiler and fed as the editor.

**to build**

Use Open Watcom make:
```
wmake
```

**to run**

After building execute `deck`. You will see the deck of cards before and after a shuffle.

![](img/running.png?raw=true)




