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

int main(int argc, char *argv[])
{
	if (argc < 2) {
		return 0;
	}
	
	Dedika app(argc, argv);
	
	// Attempt to inititalize
	if (!app.Init(argv[1])) {
		app.Error("Couldn't inititalize application");
		return 0;
	}
		
	// Attempt to run
	if (!app.Run()) {
		app.Error("Couldn't run application");
		return 0;
	}
	
	return 0;
}
