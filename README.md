# must-kast

A kernel I'm writing or trying to write from scratch with some guidance. Must Kast in Estonian means Black Box.

## But why?

I got this random spark of interest on writing my own kernel some months ago. While I was doing my military duty, I got bored and thought to myself: "Wouldn't it be cool to try to write the core of an operating system by myself?" so in I went. I started researching about on how to write a kernel, what was required to have before getting into it, etc. Not going to lie, I skipped some necessary parts, quickly got really confused on how some things work, and because of it, I lost the motivation on writing it. So now I'm trying again and writing it on my own from zero with helpful tutorials I can rely on.

There's a kernel I wrote called [Mihkelanželo / mihkelanzhelo](https://github.com/ellartdev/mihkelanzhelo), where I got keyboard working, as well as some pseudo-RNG there too. It would randomize the color of the text when you enter a new line. It is quite buggy, as sometimes even the blinking cursor changes the color, but works okay. And also it freezes, if you type in unknown letter / symbol. That I have never solved...

My end goal is not making a full Windows 420. My end goal is to understand on how kernel functions, why it matters, and what roles does it serve for the rest of the OS's layers. If I have time, will, and want to keep developing it, I'll try to add more funky stuff onto it.

## Where am I compiling, assembling, linking the kernel?

on WSL (Windows Sub-system of Linux). That's where I compile, assemble, link the kernel.

##

Thank you for reading! :)

#
ellartdev 2021