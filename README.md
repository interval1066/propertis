Propertis for GNU/Linux
=======================

Dead simple properties object, keep app settings in a plain flat file. Very
similar to old Windows ini files; each setting entry is a label(key)=value
pair. I wasn't interested in informing the whole Glib ecosystem of every little
property change in my app, really meant for embedded applications that are written
in STL/C++17.

Examples:

	# a comment
	; also a comment
	entry1=value
	entry2="a string"
	random=1234

	# line feeds are ignored/retained

	color=pink
	; random line feed

	p1=3.14159


You can name a properties file anything you want, and it can be placed
anywhere in the file system you have permission to write to. Lone alphabetic
words can be string values, but a phrase should be enclosed in double quotes,
or only the first word will be retained as a value. You can pass a single
word in in double quotes but the quotes will not be maintained.

Uses only native clib and compatible runtimes, but requires C++17. I took
a look at several hetrogeneous container implementations but all fell short
of my needs; either waay too complicated or simply didn't build, usually
from being too complicated. This does exactly whay I need it to do, as long
as I'm willing to work within its imitations.

To use just add to your project, example main method is included. Really
intended to be super light weight for embedded projects, and it is. For the
included example be sure to edit the PRPFILE location to the actual location
of the sample properties.

To build the example just do a cmake and a make.

Should (does) work as single threaded model code as well, remark out the
"add_compile_options(-pthread)" line in the CMakeLists.txt file.

I really don't think a properties object should be more complicated than
this, unless you have a specific need of course. Used in my never-ending
hexlab- the hexidecimal abattoir, effort.

WHY "PROPERTIS"?
Becuase I mispelled "properties" when I was setting up the repository and
really didn't have the stomach to sit around for 5-8 minutes correcting
the issue with github.

TODO:
Too many throw macros, they really aren't nessessary. Also should use
std::variant rather than my own broken variant class. Already uses c++17.

Build log:
Latest:
"Value" class now returns a string property as a full string.
Properties are retained after a write, I cleared the hashmap
after a write for some reason. Needs much more intense threaded
testing.


