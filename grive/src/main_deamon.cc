/*
	grive: an GPL program to sync a local directory with Google Drive
	Created on: Dec 28, 2015
	Author: meir toledano

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation version 2
	of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <string>

#include "filewatcher/FileWatcher.hh"

using namespace std;
using namespace gr;

// where UpdateListener is defined as such
class UpdateListener : public fw::FileWatchListener
{
public:
	UpdateListener() {}
	void handleFileAction(fw::WatchID watchid, const string& dir, const string& filename,
			fw::Action action)
	{
		switch(action)
		{
		case fw::Actions::Add:
			std::cout << "File (" << dir + "\\" + filename << ") Added! " <<  std::endl;
			break;
		case fw::Actions::Delete:
			std::cout << "File (" << dir + "\\" + filename << ") Deleted! " << std::endl;
			break;
		case fw::Actions::Modified:
			std::cout << "File (" << dir + "\\" + filename << ") Modified! " << std::endl;
			break;
		default:
			std::cout << "Should never happen!" << std::endl;
		}
	};
};

int main( int argc, char **argv ) {
	// Create the object
	fw::FileWatcher* fileWatcher = new fw::FileWatcher();

	// add a directory watch
	fw::WatchID watchid = fileWatcher->addWatch(
			"/home/meir/Documents/testgrive2/",
			new UpdateListener());


	// somewhere in your update loop call update
	while(true) {
		fileWatcher->update();
	}

}
