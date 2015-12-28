/*
 * Manager.hh
 *
 *  Created on: Dec 28, 2015
 *      Author: meir
 */

#ifndef LIBGRIVE_SRC_BASE_MANAGER_HH_
#define LIBGRIVE_SRC_BASE_MANAGER_HH_

#include <string>
#include <queue>

#include "filewatcher/FileWatcher.hh"

using namespace std;

namespace gr {

enum TaskType {
	CREATED,
	DELETED,
	UPDATED
};

enum TaskDirection {
	remote_2_local,
	local_2_remote
};

struct Task {
	TaskType taskType;
	TaskDirection taskDirection;
	string file;
};

class Manager {

private:

	queue<Task> tasks;

	fw::FileWatcher* localWatcher;
	fw::FileWatcher* remoteWatcher;
	std::vector<boost::thread> workersPool;

	void initFromLastSync();
	void startRealTime();

public:
	Manager();
	void start();
	void pause();
	void stop();
	~Manager();

};


}



#endif /* LIBGRIVE_SRC_BASE_MANAGER_HH_ */
