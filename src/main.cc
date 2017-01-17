#include <iostream>
#include <cstdlib>
#include <memory>
#include <properties.h>

using namespace utils;
using namespace std;

#define PRPFILE "/home/tim/props.prp"

/**
 * GNU/Linux properties class demo
 *
 * Demonstrated: an example of an attempt to search for a key from a file
 * that hasn't been opened, opening a properties file with default
 * read/write permissions, search for the key from the previous attempt,
 * the addition of a new key, and finally the file is written and closed.
 *
 * (c) 2013 Tim O'Neil
 * @author Tim O'Neil <interval1066@gmail.com>
 *
 */

int
main(int argc, char** argv)
{
	try {
		unique_ptr<Properties> p(new Properties(MODE::PRP_READWRITE));
		// the next statement, if enabled, would throw a "Key doesn't exist" exception
		// becuase we didn't specify a properties file. No file, no properties db.
		// cout << "The value of pi is approximately " << p->Get("p1", 4.0) << endl;
		p->OpenPropFile(PRPFILE);
		// now we can look for a key in the file
		/*float f = p->Get("pi", "4.0");
		cout << "The value of pi is approximately " << f << endl;
		string some = p->Get("somevalue", "Not found");
		cout << "Some Value: " << some.c_str() << endl;
		string king = p->Get("richardiii", "Richard died at Bosworth");
		cout << "Shakespeare: " << king.c_str() << endl;
		// this is a new key, as such it will be appended to the file as a new key/value pair
		p->Set("crowley", "777");
		// we've made a change (added a new key), lets write it
		p->Write(PRPFILE);
		// Now lets change the mode to read-only and try to set a new key/value pair
		//p->SetMode(MODE::PRP_READONLY); // this will throw a read-only exception on the next statement
		p->Set("anewvalue", "4049860985");
		// we can't create new key/value pairs. An exception would be thrown
		// if we tried to call the "Write" method as well and re-write the entire db.
		// You can also set the mode to write-only and not be able to read anything
		// out of it as well, but you can write/create all the values you want.
		p->Set("somekindofnewvalue", "anewone");
		p->dump();*/
		int crow = p->Get("crowley", "666");
		cout << "---> " << crow << endl;
		//p->Set("crowley", "666");
		p->dump();
		p->Write(PRPFILE);
	}
	catch (PropException* e) {
		cout << e->what() << endl;
	}

	return EXIT_SUCCESS;
}

