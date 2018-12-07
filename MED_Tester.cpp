//============================================================================
// Name        : MED_Tester.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include "../../stringdatabase/includes/string_database.h"
#include "../../crypto/includes/crypto.h"
#include "../../datastore/includes/data_store_file.h"
#include "../../crypto/includes/crypto_AES.h"

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database myGlobalCache;

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	myGlobalCache.save(&myDataStore_File1);

	//clear cache
	myGlobalCache.clear();
	std::cout << "Clearing Cache\n";

	//load it
	myGlobalCache.load(&myDataStore_File1);
	std::cout << "Loading from file " + MYFILE1 + " \n";

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	std::cout << "Saving to file " + MYFILE2 + " \n";

	//I use my own objects here to compare the files
	return true;
}

int main() {
	//I created and run a bunch(20) of threads that use ThreadFunc above

	string a = "baseball";
	string b = "basketball";
	string c = "golf";
	string d = "hockey";
	string e = "rugby";
	string f = "soccer";

	std::cout << myGlobalCache.getCount(a) << endl;

	std::vector<thread> threadVec;

	thread tA(&String_Database::add, &myGlobalCache, ref(a));
	thread tB(&String_Database::add, &myGlobalCache, ref(b));
	thread tC(&String_Database::add, &myGlobalCache, ref(c));
	thread tD(&String_Database::add, &myGlobalCache, ref(d));
	thread tE(&String_Database::add, &myGlobalCache, ref(e));
	thread tF(&String_Database::add, &myGlobalCache, ref(f));

	tA.join();
	tB.join();
	tC.join();
	tD.join();
	tE.join();
	tF.join();

	for (int i = 0; i < 25; i++) {
		string s = "sports" + to_string(i);
		threadVec.push_back(
				std::thread(&String_Database::add, &myGlobalCache, ref(s)));
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	for (auto& thread : threadVec) {
		thread.join();
	}

	//first without encryption,
	testSerialization("NO_ENCRYPT_FILE1", "NO_ENCRYPT_FILE2", 0);

	//then with
	Crypto_AES myCrypto("I Like Rollos   ");
	testSerialization("ENCRYPT_FILE1", "ENCRYPT_FILE2", &myCrypto);

}
