/*
 *  ofxJSONFile.h
 *  asift
 *
 *  Created by Jeffrey Crouse on 12/17/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef _OFX_JSON
#define _OFX_JSON

#include <iostream>
#include <fstream>
#include <json/json.h>
#include <curl/curl.h>
#include "ofMain.h"

using namespace Json;

class ofxJSONElement: public Value {
public:
	ofxJSONElement() {};
	ofxJSONElement(string jsonString);
	ofxJSONElement(Json::Value& v);
	
	bool parse(string jsonString);
	bool open(string filename);
	bool openLocal(string filename);
	bool openRemote(string filename, bool secure=false);
	bool save(string filename, bool pretty=false);
	string getRawString(bool pretty=true);
	string postTo(string url);
	
	// Utility CURL functions
	static string post(string url, string data, bool verbose=true);
	static string get(string url, bool verbose);
	static string curl(const char* method, const char* endpoint, const char* data, bool verbose=true);
	
protected:
	static int writeData(char *data, size_t size, size_t nmemb, std::string *buffer);
	
};

#endif