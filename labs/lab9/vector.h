#include <stdlib.h>
#include <iostream>

template <class T>
class vector {
   private:
      T *v;  //a dynamic array of elements of type T
      int s; //size
   public:
      //default constructor
      vector(){
	     this->s = 0;
	     this->v = NULL;
      }

      // copy constructor
      vector(vector<T> &other) {
         this->s = other.s;
         this->v = new T[this->s];
         for(int i = 0; i < this->s; i++) {
            this->v[i] = other.v[i];
         }
      }

      //  assignment
      vector& operator=(vector<T> &other) {
         if (this != &other) {
            this->s = other.s;
            this->v = new T[this->s];
            for(int i = 0; i < this->s; i++) {
               this->v[i] = other.v[i];
            }
         }
         return *this;
      }

      // make a function to resize the vector
      void resize(int newSize) {
         T *temp = new T[newSize];
         for(int i = 0; i < newSize; i++) {
            temp[i] = this->v[i];
         }
         delete [] this->v;
         this->v = temp;
      }

      // make a function to reserve the vector
      void reserve(int newCapacity) {
         T *temp = new T[newCapacity];
         for(int i = 0; i < this->s; i++) {
            temp[i] = this->v[i];
         }
         delete [] this->v;
         this->v = temp;
      }

      //destructor	  
      ~vector(){
	     delete [] this->v;
	     this->v = NULL;
      }

      //only perform address arithmetic
      T operator[](int index) {
         return this->v[index];
      }

      //insert the given element at the given index
      void insert(int index, T element) {
         T *temp = new T[this->s + 1];
         for(int i = 0; i < index; i++) {
            temp[i] = this->v[i];
         }
         temp[index] = element;
         for(int i = index + 1; i < this->s + 1; i++) {
            temp[i] = this->v[i - 1];
         }
         delete [] this->v;
         this->v = temp;
         this->s = this->s + 1;
      }
	
      //size function	  
      int size() {
	     return this->s;
      }

      //push_back: add an element to the end	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++this->s];
	     for(int i = 0; i < this->s-1; i++)
	        temp[i] = this->v[i];

	     if (this->v != NULL)
	     	delete [] this->v;
	     this->v = temp;
	     this->v[s-1] = ele;
      }

};
