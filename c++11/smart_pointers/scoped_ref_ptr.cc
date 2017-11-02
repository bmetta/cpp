#include <iostream>

class RefCountedBase {
 public:
  RefCountedBase() : refCount_(0) {}
  ~RefCountedBase() {}

  void addRef() {
    refCount_++;
  }
  
  bool release(){
    if(--refCount_ == 0) {
      return true;
    }
    return false;
  }

 private:
  int refCount_;

};

class RefCounted : public RefCountedBase {
 public:
  void addRef() {
    RefCountedBase::addRef();
  }

  void release() {
    if(RefCountedBase::release()) {
      delete this;
    }
  }

 private:

};

template <class T>
class ScopedRefPtr {
 public:
  ScopedRefPtr() : ptr_(nullptr) { std::cout << "ScopedRefPtr ctr " << ptr_ << std::endl; }
  ScopedRefPtr(T *p) : ptr_(p) { 
    std::cout << "ScopedRefPtr ctr " << ptr_ << std::endl; 
    if(p) { p->addRef(); }
  }
  ~ScopedRefPtr() {
    std::cout << "ScopedRefPtr dtr " << ptr_ << std::endl; 
    ptr_->release();
  }

  T* operator=(ScopedRefPtr &p) {
    std::cout << "ScopedRefPtr operator=overloded " << std::endl; 
  }

 private:
  T* ptr_;
}

class Device : public RefCounted {
 public:
  
 private:

}
