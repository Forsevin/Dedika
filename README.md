The idea behind Dedika is to make the usage of certain web application more “dedicated” by providing a simple, clean and lightweight way to display web pages without miscellaneous GUIs, functionality etc.

An dedika application are defined through XML and consists (as of now) by title, baseurl, width and height, which get applied to the window.

The goal is to have a communal repository for application/configurations and eventually to provide a Javascript API for developing application directly towards the Dedika platform.

Building
========

The Makefile is quite primitive and there's no configuration file to handle dependencies. It only depends on Gtk+-3.0 and Webkitgtk.

To build:

$ make

$ (sudo) make install


You can put the example-application.xml in $HOME/.dedika/apps/ and run it through dedika-run example-application.

![Dedika logo](http://i.imgur.com/lEzVabB.png)
