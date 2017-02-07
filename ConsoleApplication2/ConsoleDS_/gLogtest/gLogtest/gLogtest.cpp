// gLogtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "glog\logging.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

//#include "base/commandlineflags.h"
#include "glog/logging.h"
#include "glog/raw_logging.h"
//#include "googletest.h"
using namespace std;

void TestLogString() {
	vector<string> errors;
	vector<string> *no_errors = NULL;

	LOG_STRING(INFO, &errors) << "LOG_STRING: " << "collected info";
	LOG_STRING(WARNING, &errors) << "LOG_STRING: " << "collected warning";
	LOG_STRING(ERROR, &errors) << "LOG_STRING: " << "collected error";

	LOG_STRING(INFO, no_errors) << "LOG_STRING: " << "reported info";
	LOG_STRING(WARNING, no_errors) << "LOG_STRING: " << "reported warning";
	LOG_STRING(ERROR, NULL) << "LOG_STRING: " << "reported error";

	for (size_t i = 0; i < errors.size(); ++i) {
		LOG(INFO) << "Captured by LOG_STRING:  " << errors[i];
	}
}


int main()
{
	google::InitGoogleLogging("Test");

	TestLogString();
	getchar();
    return 0;
}

