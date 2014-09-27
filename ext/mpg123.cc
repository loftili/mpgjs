#include <node.h>
#include <v8.h>
#include <mpg123.h>
#include <iostream>

using namespace v8;

std::string to_str(Handle<String> str) {
  String::Utf8Value utf(str);
  return std::string(*utf, utf.length());
}

Handle<Value> isValid(const Arguments& args) {
  HandleScope scope;
  int err = MPG123_OK;
  mpg123_handle* mh;

  if(args.Length() < 1 || !args[0]->IsString()) {
    ThrowException(Exception::TypeError(String::New("isValid expects the first argument to be a string")));
    return scope.Close(Undefined());
  }


  mh = mpg123_new(NULL, &err);
  mpg123_param(mh, MPG123_FLAGS, MPG123_QUIET, 0);
  if(mh == NULL) {
    ThrowException(Exception::TypeError(String::New("mpg123 unable to create a handle")));
    return scope.Close(Undefined());
  }

  std::string filepath = to_str(args[0]->ToString());
  err = mpg123_open(mh, filepath.c_str());
  if(err != MPG123_OK) {
    return scope.Close(Boolean::New(false));
  }

  int channels, encoding;
  long rate;
  err = mpg123_getformat(mh, &rate, &channels, &encoding);
  if(err != MPG123_OK){
    return scope.Close(Boolean::New(false));
  }

  return scope.Close(Boolean::New(true));
}

void Init(Handle<Object> exports) {
  int err = MPG123_OK;
  err = mpg123_init();
  if(err != MPG123_OK) {
    Local<Value> no_mpg123 = Exception::TypeError(String::New("mpg123 library failed initializing, make sure it is installed!"));
    ThrowException(no_mpg123);
    return;
  }
  exports->Set(String::NewSymbol("isValid"), FunctionTemplate::New(isValid)->GetFunction());
}

NODE_MODULE(mpg123, Init)
