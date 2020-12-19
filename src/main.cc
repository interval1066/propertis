#include <iostream>
#include <cstdlib>
#include <memory>
#include <properties.h>

using namespace utils;
using namespace std;

#define PRPFILE "./props.prp"

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
      string richard = p->Get("richardiii", "default");
      cout << static_cast<string>(p->Get("richardiii", "default")) << endl;
      cout << static_cast<float>(p->Get("pi", "4.4")) << endl;
      float boo = p->Get("pi", "4.4");
      cout << boo * boo << endl;
		p->Write(PRPFILE);
	}
	catch (PropException* e) {
		cout << e->what() << endl;
	}

	return EXIT_SUCCESS;
}

