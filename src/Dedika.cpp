#include "Dedika.hpp"

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

Dedika::Dedika(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	webContainer = gtk_scrolled_window_new(NULL, NULL);
	webView = webkit_web_view_new();
}

Dedika::~Dedika()
{
	
}

bool Dedika::Init(std::string appName)
{
	std::string appLocation = std::string(getenv("HOME")) + "/.dedika/apps/"+ appName +".xml";
	
	// Load application data
	rapidxml::file<> XMLRaw(appLocation.c_str());
	rapidxml::xml_document<> XMLApp;
	XMLApp.parse<0>(XMLRaw.data());
	
	// Parse:
	rapidxml::xml_node<> * root;
	root = XMLApp.first_node("application");
	
	title 	= root->first_node("title")->value();
	baseurl = root->first_node("baseurl")->value();
	width 	= atoi(root->first_node("width")->value());
	height	= atoi(root->first_node("height")->value());
		
	// Signals
	g_signal_connect (window, "destroy", G_CALLBACK (Quit), NULL);
	
	// Window properties
	gtk_window_set_title(GTK_WINDOW(window), title.c_str());
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	
	// webView settings
	WebKitWebSettings *settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(webView));
	// Enable webgl
	g_object_set(G_OBJECT(settings), "enable-webgl", true, NULL);
	
	
	return true;
}

bool Dedika::Run()
{	
	gtk_container_add(GTK_CONTAINER(window), webContainer);
	gtk_container_add(GTK_CONTAINER(webContainer), GTK_WIDGET(webView));
	
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(webView), baseurl.c_str());
	
	gtk_widget_show_all(window);
	 gtk_widget_grab_focus(webView);
	
	gtk_main();
	
	return true;
}

bool Dedika::InitAPI() {
	
}

void Dedika::Error(std::string error)
{
	std::cout << "[E] " << error << std::endl;
	Quit(NULL, NULL, 0);
}

void Quit(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_main_quit();
}
