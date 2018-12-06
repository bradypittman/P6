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
#include "../../datastore/includes/data_store_file.h"
#include "../../crypto/includes/crypto_AES.h"

const int TOTAL_ADDED_PER_THREAD = 20;
const int TOTAL_THREADS = 20;
const std::string ENCRYPT_FILE1 = "Encryptfile1.txt";
const std::string ENCRYPT_FILE2 = "Encryptfile2.txt";

const std::string NO_ENCRYPT_FILE1 = "noEncryptfile1.txt";
const std::string NO_ENCRYPT_FILE2 = "noEncryptfile2.txt";

const int NUMBER_TIMES_TO_ADD_STRING = 20;

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database myGlobalCache;
Crypto_AES crypto("I like rollos too");
DataStore_File store(ENCRYPT_FILE1, &crypto);
DataStore_File aStore(NO_ENCRYPT_FILE1, NULL);

//will add myString numbTimes to myGlobalCache
void ThreadFunc(int numbTimes, std::string myString) {
	for (int i = 0; i < numbTimes; i++) {
		myGlobalCache.add(myString);
	}
	myGlobalCache.save(&store);

	std::cout
			<< ((myGlobalCache.getCount(myString) == numbTimes) ?
					"Pass" : "Fail") << std::endl;
}

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	myGlobalCache.save(&myDataStore_File1);

	//clear cache
	myGlobalCache.clear();

	//load it
	myGlobalCache.load(&myDataStore_File1);

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);

	//I use my own objects here to compare the files
	return true;
}
int main() {
	//I created and run a bunch(20) of threads that use ThreadFunc above
	std::thread t1(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test1");
	std::thread t2(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test2");
	std::thread t3(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test3");
	std::thread t4(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test4");
	std::thread t5(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test5");
	std::thread t6(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test6");
	std::thread t7(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test7");
	std::thread t8(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test8");
	std::thread t9(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test9");
	std::thread t10(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test10");
	std::thread t11(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test11");
	std::thread t12(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test12");
	std::thread t13(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test13");
	std::thread t14(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test14");
	std::thread t15(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test15");
	std::thread t16(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test16");
	std::thread t17(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test17");
	std::thread t18(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test18");
	std::thread t19(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test19");
	std::thread t20(ThreadFunc, NUMBER_TIMES_TO_ADD_STRING, "test20");
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
	//first without encryption,
	testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);

	//then with
	Crypto_AES myCrypto("I Like Rollos   ");
	testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);

}
