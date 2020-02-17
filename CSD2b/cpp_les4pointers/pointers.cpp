#include <iostream>
#define BLOCKSIZE 1000

class Block{
public:
  double data [BLOCKSIZE];
};

int sumsquares(int *block)
{
  int total=0;

  for(int i=0; i<10; i++) total += block[i]*block[i];
  return total;
}

double sumsquares_copy(Block block)
{
  double total=0;

  for (unsigned long i=0; i<BLOCKSIZE; i++){
    total += block.data[i]*block.data[i];
  }
  return total;
}

double sumsquares_pointer(Block *block)
{
  double total=0;

  for (unsigned long i=0; i<BLOCKSIZE; i++){
    total += block->data[i]*block->data[i];
  }
  return total;
}


int main()
{

  char letter = 'a';  //maakt variable aan en plaatst deze;

  std::cout << letter << std::endl;

  char* letterPointer = &letter; //pointer wijst naar de variable letter

  std::cout << (unsigned long)letterPointer << std::endl; //unsigned long want plek in geheugen kan heel groot zijn

  *letterPointer = 'b'; //kan de info in het geheugen aanpassen vanuit de pointer

  std::cout << *letterPointer << std::endl; //kan ook de data ophalen via de pointer

  std::cout << "Volgend ding, lijsten:" << std::endl;

  //char lijst[10];

  char *lijst = new char[10]; //pointer naar een array

  for(int i=0; i<10; i++) lijst[i] = 'a' + i;

  for(int i=0; i<10; i++){
    std::cout << *(lijst+i); //pointer is gewoon een variabele dus kan je gebruiken om door de lijst te scrollen
  };
  std::cout << std::endl;

  for(int i=0; i<10; i++){
    std::cout << *lijst;
    lijst++;  //soms is het handig om de pointer zelf te veranderen voor snelheid
  };
  std::cout << std::endl;

  std::cout << "Volgend ding, functies:" << std::endl;

  int *lijst2 = new int[10];
  for(int i=0; i<10; i++) lijst2[i] = i;

  for(int i=0; i<10; i++) {
    std::cout << *(lijst2+i);
  }
  std::cout << std::endl;

  std::cout << sumsquares(lijst2) << std::endl;

  Block myblock;
  sumsquares_copy(myblock);
  sumsquares_pointer(&myblock);

  return 0;
};
