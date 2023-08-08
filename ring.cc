//This program is an integer ring buffer which 
//either read or write to the buffer from 
//the standard input. The input bigger than zero
//writes to the buffer and a zero input read 
//from the buffer

#include <iostream>

//using namespace std;

class Ring   
{
public:

//  ring();
//  ~ring();
 void SetSize(int size);
 int GetSize();
 int* Init(int* buffer);
 int* Push(int* buf, int element);
 int* Pull(int* buf);
 int m_size;
 int m_write;
 int m_read;
 int new_element;
 //int  m_type; //char m_type=1
              //int m_type=2
	      //double m_type=3 
};

void 
Ring::SetSize (int size) 
{
 m_size = size;
}

int 
Ring::GetSize(){
 return m_size;
}

//void 
//Ring::Init(int* buffer){
int*
Ring::Init(int* buffer){

 srand((unsigned) time(NULL));
 int random;
 std::cout << "<<Writing on the Buffer>>\n Choose an Integer Number:  ";
 std::cin >> new_element ;
 m_write=rand()%m_size+1;
 m_read=m_write-1;
 buffer[m_write-1]=new_element;
 //m_write++;
 //std::cout <<"Write pointer is: "<< (m_write%m_size)<<"\nRead pointer is: "<< (m_read%m_size)<<"\n";
 for(int i=0;i<m_size;i++)
     {
          std::cout << buffer[i]<<' ';
     }
  std::cout <<"\n\n";
  return buffer;
}

int*
Ring::Push(int* buf, int element){
 

    if((m_write-m_read)<m_size){
    m_write++;
    buf[(m_write-1)%m_size]=element;
    }
    //std::cout <<"Write pointer is: "<< (m_write%m_size)<<"\nRead pointer is: "<< (m_read%m_size)<<"\n";
    for(int i=0;i<m_size; i++)
       {
         std::cout << buf[i]<<" ";
       }
    std::cout << "\n\n";
    return buf;
}

int*
Ring::Pull(int* buf){

    if(m_read<m_write){
            buf[(m_read)%m_size]=0;
	    m_read++;
          }
   // std::cout <<"Write pointer is: "<< (m_write%m_size)<<"\nRead pointer is: "<< (m_read%m_size)<<"\n";
    for(int i=0;i<m_size; i++)
       {
         std::cout << buf[i]<<" ";
       }
    std::cout << "\n\n";
    return buf;

}

int
main ()
{

 int ring_size;
 int* buf;
 int* init_buf;
 Ring ring;

 //std::cout << "Enter an ring type(integer=2, string=3, double=3): ";
 //std::cin >> ring.m_type ; //how to map the object type to the class??
 std::cout << "\n<<Initializing the Buffer>>  \n Choose the buffer size: "; 
 std::cin >> ring_size;
 ring.SetSize(ring_size);
 
 for(int i=0;i<ring_size;i++)
       {
         buf[i]=0;
         std::cout << buf[i]<<' ';
        }

 std::cout << "\n\n";

 // If the results of Init() isn't written to a pointer,
 // program results in segmentation fault. Segmentation Fault
 // is raised when the access to memory is not allowed, in this 
 // case we didn't try to get access to the wrong part of the memory. 
 // Alternatively when the Init is removed the error still exists. 
 // Therfore, the only possible way to solve this issue is to call 
 // Init() while return the pointer to the buffer 
 
 //ring.Init(buf);
 init_buf=ring.Init(buf);
 int element;
 while(1){
   std::cout <<"Use 0 to read and non-zero value to write: ";
   std::cin >> element ;
   if(!element){
      ring.Pull(buf);
   }
    else{
	    ring.Push(buf,element);
    }
 }


/*
switch(ring.m_type)
   {
    case 1: //integer
         int buf[ring.m_size];
	 int new_element;
	 break;
    case 2://string
         char buf[ring.m_size];
	 char new_element;
	 break;//double
    case 3:
         double buf[ring.m_size];
	 double new_element;
	 break;
   }
*/
 return 0;
}
