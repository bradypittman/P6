#include "../includes/string_database.h"
using namespace std;
String_Database::String_Database(void) {

}
String_Database::~String_Database(void) {

}

//if not seen yet then add myString to myStrings
//otherwise increment the count for myString
void String_Database::add(std::string &myString) {
	lock_guard<std::mutex> m(mutex);
	bool isThere = false;
	String_Data dataString(myString);
	for (myStringsIter = myStrings.begin(); myStringsIter != myStrings.end();
			myStringsIter++) {
		if (*myStringsIter == dataString) {
			isThere = true;
			myStringsIter->increment();
			break;
		}
	}
	if (!isThere) {
		myStrings.push_back(dataString);
	}
}

//get number of times myString has been seen (or added with add)
int String_Database::getCount(std::string &myString) {
	lock_guard<std::mutex> m(mutex);
	String_Data dataString(myString);
	int x = 0;
	for (myStringsIter = myStrings.begin(); myStringsIter != myStrings.end();
			myStringsIter++) {
		if (*myStringsIter == dataString) {
			x = myStringsIter->getCount();
			break;
		}
	}
	return x;
}

//clear the myStrings vector
void String_Database::clear() {
	lock_guard<std::mutex> m(mutex);
	myStrings.clear();
}

//load from datastore, returns
//false if myDataStore = 0
//otherwise returns myDataStore->load results
bool String_Database::load(DataStore *myDataStore) {
	lock_guard<std::mutex> m(mutex);
	if (myDataStore == 0) {
		return false;
	}
	return myDataStore->load(myStrings);
}

//save to datastore,returns
//false if myDataStore = 0
//otherwise returns myDataStore->save results
bool String_Database::save(DataStore *myDataStore) {
	lock_guard<std::mutex> m(mutex);
	if (myDataStore == 0) {
		return false;
	}
	return myDataStore->save(myStrings);
}
