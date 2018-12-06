#include "../includes/data_store_file.h"
#include <fstream>

DataStore_File::DataStore_File(std::string fileName, Crypto* crypto) {

}
DataStore_File::~DataStore_File(void) {

}

//load from file myFileName, if present, use the crypto object to decrypt
//returns true on success, false otherwise
bool DataStore_File::load(std::vector<String_Data> &myVector) {
	std::fstream iFile;
	this->openFile(iFile, this->myFileName, std::ios_base::out);
	std::string data;
	int counter;

	for (std::string lines; getline(iFile, lines);) {
		if (decrypt(lines) == true) {
			String_Data::parseData(lines, data, counter);
			myVector.push_back(String_Data(data, counter));
		} else {
			return false;
			break;
		}
	}
	this->closeFile(iFile);
	return true;
}

//save to file myFileName, if present, use the crypto object to encrypt
//I extracted one entry of the vector at a time and then encrypted it
//if crypto object present, saved this to disk and then sent a std::endl
//so each entry is encrypted, but you can count the number of entries
//by the number of lines in the file
//returns true on success, false otherwise
bool DataStore_File::save(std::vector<String_Data> &myVector) {
	std::fstream oFile;
	this->openFile(oFile, this->myFileName, std::ios_base::out);

	for (String_Data data : myVector) {
		std::string s = data.serialize();
		encrypt(s);
		oFile << s << std::endl;
		if (!encrypt(s)) {
			return false;
			break;
		}
	}
	this->closeFile(oFile);
	return true;
}

bool DataStore_File::openFile(std::fstream& myfile,
		const std::string& myFileName, std::ios_base::openmode mode) {
	myfile = std::fstream(myFileName.c_str(), mode);
	if (!myfile) {
		return false;
	}
	return true;
}

void DataStore_File::closeFile(std::fstream& myfile) {
	myfile.close();
}
