#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <cstring>  
using namespace std;  
  
typedef long long  LL;  
const int FILE_LENGTH = 1000;  
//the maximal length of Huffman code  
const int HUFFMAN_CODE_LENGTH = 1000;  
//number of kinds of character  
const int KIND_OF_CHARACTER = 256;  
//maximal bytes which is read from file each time  
const long long MAX_MEMORY = 1 * 1024 * 1024;  
  
  
struct Node {  
    char c; //character  
    char Huffmancode[HUFFMAN_CODE_LENGTH]; //bits string  
}node[KIND_OF_CHARACTER]; //encoding information  
  
//store each nBits  
int  nBits = 8;  
LL originalFileSize; //the size of original file  
int numberOfNode;   //number of kind of character  
int bitsAdded;  
int OFFSET;  
  
int GetCompressInformation(ifstream &readIn);  
void DecompressFile(ifstream &readIn, ofstream &writeOut, int maxEncodingLength);  
  
int main() {  
    char compressFilePath[FILE_LENGTH] = "result.txt"; //graph.txt  "1.txt";  
    char decompressFilePath[FILE_LENGTH] = "decompressResult.txt";  
    ifstream readIn;  
    readIn.open(compressFilePath, ios::binary);  
    if (readIn.is_open() == 0) {  
        cout << "OPEN FAILED!" << endl;  
        exit(0);  
    }  
    ofstream writeOut;  
    writeOut.open(decompressFilePath, ios::binary);  
    if (writeOut.is_open() == 0) {  
        cout << "OPEN FAILED!" << endl;  
        exit(0);  
    }  
    //get information of compressed file  
    int maxEncodingLength = GetCompressInformation(readIn);  
    //decompress File  
    DecompressFile(readIn, writeOut, maxEncodingLength);  
    readIn.close();  
    writeOut.close();  
    return 0;  
}  
  
int GetCompressInformation(ifstream &readIn){  
    readIn.read((char *)&bitsAdded, sizeof(int));  
    readIn.read((char *)&OFFSET, sizeof(int));  
    readIn.seekg(OFFSET, ios::beg);  
    readIn.read((char *)&originalFileSize, sizeof(LL));  
    readIn.read((char *)&numberOfNode, sizeof(int));  
    cout << originalFileSize << " " << numberOfNode << endl;  
    //record the character and its Huffman code  
    int maxEncodingLength = 0;  
    for (int i = 0; i < numberOfNode; i++) {  
        readIn.read((char *)&node[i].c, sizeof(char));  
        int bits;  
        readIn.read((char *)&bits, sizeof(int));  
        readIn.read((char *)&node[i].Huffmancode, bits*sizeof(char));  
        node[i].Huffmancode[bits] = '\0';  
        cout << node[i].c << " " << node[i].Huffmancode << endl;  
        if (maxEncodingLength < strlen(node[i].Huffmancode)) {  
            maxEncodingLength = strlen(node[i].Huffmancode);  
        }  
    }  
    cout << " maxEncodingLength :" << maxEncodingLength << endl;  
    return maxEncodingLength;  
}  
  
void DecompressFile(ifstream &readIn, ofstream &writeOut, int maxEncodingLength){  
    //get size of compressed file  
    streampos curPos = readIn.tellg();  
    readIn.seekg(0, ios::end);  
    LL compressedFileSize = (LL)(readIn.tellg() - curPos);  
    readIn.seekg(curPos, ios::beg);  
    cout << "size of compressed file : " << compressedFileSize << endl;  
    //read data in batches, each time read MAX_MEMORY characters  
    int nTimes = (int)(compressedFileSize / MAX_MEMORY);  
    if (compressedFileSize % MAX_MEMORY != 0) nTimes++;  
    char *str = (char *)calloc(1, (MAX_MEMORY + HUFFMAN_CODE_LENGTH)* sizeof(char));  
    int lenOfChar = 0;  
    for (int j = 1; j <= nTimes; j++) {  
        LL numberOfCharacter = MAX_MEMORY;  
        if (j == nTimes) {  
            numberOfCharacter = compressedFileSize % MAX_MEMORY;  
        }  
        char *strTemp = (char *)calloc(1, (2*HUFFMAN_CODE_LENGTH) * sizeof(char));  
        char *buf = (char *)calloc(1, (MAX_MEMORY + HUFFMAN_CODE_LENGTH)* sizeof(char));  
  
        readIn.read(buf, numberOfCharacter * sizeof(char));  
        //cout<<buf<<endl;  
        //printf("%d\n", ascII);  
        int lenOfStrTemp = 0;  
        for (int k = 0; k < numberOfCharacter; k++) {  
            // convert it to binary bits  
            unsigned char ascII = buf[k];  
            char huffmanString[3*nBits];  
  
            for (int i = nBits - 1; i >= 0; i--) {  
                huffmanString[i] = ascII % 2 + '0';  
                ascII = ascII / 2;  
            }  
            //if read last character, then minus bits which is added  
            if ((j == nTimes) && (k == numberOfCharacter - 1)) {  
               // printf("ascII:%d\n", ascII);  
                nBits = nBits - bitsAdded;  
            }  
            huffmanString[nBits] = '\0';  
  
            // cout<<huffmanString<<endl;  
            strcpy(strTemp + lenOfStrTemp, huffmanString);  
            lenOfStrTemp += strlen(huffmanString);  
  
            //convert bit to char  
            LL comparePosition = 0;  
            while (1) {  
                bool flag = false;  
                for (int z = 0; z < numberOfNode; z++) {  
                    //if(strlen(node[z].Huffmancode) > strlen(strcmp)) continue;  
                    int lenHuffmanCode = strlen(node[z].Huffmancode);  
                    if (!memcmp(node[z].Huffmancode, strTemp, lenHuffmanCode)) {  
                        str[lenOfChar] = node[z].c;  
                        str[lenOfChar+1] = '\0';  
                        lenOfChar ++;  
                        //cout<<"strTempF:"<<strTemp<<endl;  
  
                        strcpy(strTemp, strTemp+lenHuffmanCode);  
                        lenOfStrTemp = strlen(strTemp);  
  
                        //cout<<"strTemp:"<<strTemp<<endl;  
                        flag = true;  
                        break;  
                        //comparePosition += lenHuffmanCode;  
                    }  
                }  
                if (!flag || (lenOfStrTemp == 0)) break;  
            }  
  
  
            //if length of str is larger than limited memory, write into decompressed file  
            if (lenOfChar > MAX_MEMORY) {  
                writeOut.write(str, lenOfChar * sizeof(char));  
                //apply a new memory will result in crash  
                //free(str);  
                //char *str = (char *)calloc(1, (MAX_MEMORY + HUFFMAN_CODE_LENGTH)* sizeof(char));  
                strcpy(str, "");  
                lenOfChar = 0;  
            }  
        }  
        free(buf);  
        free(strTemp);  
    }  
    //cout<<str<<endl;  
    if (lenOfChar != 0){  
        writeOut.write(str, lenOfChar * sizeof(char));  
        free(str);  
    }  
}  
