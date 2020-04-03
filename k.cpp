
#include <fstream>
#include <iostream>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib") 

using std::cout;
using std::fstream;
using std::endl;
using std::hex;
using std::dec;
using std::streampos;
using std::ios;
using std::string;



int main() {
    int original = 0x123456AB;
    int transf = htonl(original);//转成网络字节序，存入transf

    fstream out("out", ios::out | ios::binary | ios::trunc);

    printf("%#010X\n", original); 
    out.write((char*) &original, sizeof(int));

    printf("%#010X\n", transf);
    out.write((char*) &transf, sizeof(int));


    int a[5] = {0, 1, 2, 3, 4};
    for (int v : a)  printf("%#010X\n", v);
        
    out.write((char*) &a, sizeof(a));

    out.close();

    return 0;
}