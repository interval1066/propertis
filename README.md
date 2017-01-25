Propertis for GNU/Linux
=======================

Dead simple properties object, keep app settings in a plain flat file. Very
similar to old Windows ini files; each setting entry is a label(key)=value
pair. Examples:

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

Uses only native clib and compatible runtimes, but requires C++0x/C++11.

To use just add to your project, example main method is included. Really
intended to be super light weight for embedded projects, and it is. For the
included example be sure to edit the PRPFILE location to the actual location
of the sample properties (you need to put it somewhere, make sure to reflect
this in the use example.)

I really don't think a properties object should be more complicated than this,
unless you have a specific need of course.

WHY "PROPERTIS"?
Becuase I mispelled "properties" when I was setting up the repository and
really didn't have the stomach to sit around for 5-8 minutes correcting
the issue with github.

TODO:
Add bitmask processing to parse options rather than simple flags so I can
add a few more options, like what to do when an option's default is used
(in the case the property doesn't exist as far as the application is
concerned, should it be added or ignored- currently the option is automatically
added.) Also need to track down a bug that sometimes occures when writing the
properties file after a new property is added...

