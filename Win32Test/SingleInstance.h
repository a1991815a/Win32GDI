#ifndef __SINGLEINSTANCE__
#define __SINGLEINSTANCE__

template<typename T>
class SingleInstance{
public:
	static T* getInstance(){
		if (_instance == nullptr)
			_instance = new T();
		return _instance;
	}
	static void destroyInstance(){
		if (_instance != nullptr){
			delete _instance;
			_instance = nullptr;
		}
	}
private:
	static T* _instance;
};

template<typename T>
T* SingleInstance<T>::_instance = nullptr;

#endif