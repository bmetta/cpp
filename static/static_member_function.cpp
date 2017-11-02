/*static member functions do not have this pointer */
#include<iostream>
class Test {      
   static Test * fun() {
     return this; // compiler error
   }
};
  
int main()
{
   return 0;
}
