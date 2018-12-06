#include "../includes/data_store.h"

//ensures data is encrypted when stored
//will encrypt/decrypt if myCrypto is not null
//if myCrypto is null will store data in the clear
//think about what this means for the implementation of the following 2 functions
bool DataStore::decrypt(std::string &myString) {
	if (myCrypto != NULL) {
		return myCrypto->decrypt(myString);
	}
	return false;
}

bool DataStore::encrypt(std::string &myString) {
	if (myCrypto != NULL) {
		return myCrypto->encrypt(myString);
	}
	return false;
}

//force derived classes to implement load and store as appropriate
bool DataStore::load(std::vector<String_Data> &myVector) {
	for (std::vector<String_Data>::iterator myVec = myVector.begin();
			myVec != myVector.end(); myVec++) {
		std::string mystring = myVec->serialize();
		decrypt(mystring);
	}
	return true;
}

bool DataStore::save(std::vector<String_Data> &myVector) {
	for (std::vector<String_Data>::iterator myVec = myVector.begin();
			myVec != myVector.end(); myVec++) {
		std::string mystring = myVec->serialize();
		encrypt(mystring);
	}
	return true;
}

//pass in a crypto object and it will be used to encrypt
//data that is loaded or saved, otherwise data is stored in the clear
DataStore::DataStore(Crypto * pCrypt) {
	myCrypto = pCrypt;
}

//please do not delete any crypto pointers that were passed
//to this object, let the object creator manage them
DataStore::~DataStore(void) {

}
