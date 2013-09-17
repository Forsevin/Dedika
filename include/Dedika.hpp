#include <string>
#include <gtk/gtk.h>
#include <webkit/webkit.h>
#include <JavaScriptCore/JavaScript.h>

#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

/*
	This file is part of the Dedika project.

    Dedika is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Dedika.  If not, see <http://www.gnu.org/licenses/>.
*/

void Quit(GtkWidget *widget, GdkEvent *event, gpointer data);

class Dedika {
public:
	Dedika(int argc, char *argv[]);
	~Dedika();
	
	bool Init(std::string appName);
	bool Run();
	bool InitAPI();
	void Error(std::string error);
private:
	std::string name;
	std::string title;
	std::string baseurl;
	int width, height;

	GtkWidget *window;
	GtkWidget *webContainer;
	GtkWidget *webView;
};
