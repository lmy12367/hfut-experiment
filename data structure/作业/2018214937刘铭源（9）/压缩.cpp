#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <queue>  
#include <algorithm>  
#include <time.h>  
using namespace std;  
  
typedef long long LL;  
const int FILE_LENGTH = 1000;  
//maximal bytes which is read from file each time  
const long long MAX_MEMORY = 3 * 1024 * 1024;  
//number of kinds of character  
const int KIND_OF_CHARACTER = 260;  
//the maximal length of Huffman code  
const int HUFFMAN_CODE_LENGTH = 1000;  
//the position of the size of original file in compressed file  
const int OFFSET = 20;  
//store compress file in 8 bits  
const int nBits = 8;  
  
struct Node {  
    char c; // character  
    int parent, lChild, rChild;//children node  
    int iNode; //the serial number of node  
    LL number; //number of corresponding character  
    friend bool operator < (Node a, Node b) {  
        return a.number > b.number;  
    }  
}node[KIND_OF_CHARACTER];  
  
char HuffmanCode[KIND_OF_CHARACTER][HUFFMAN_CODE_LENGTH];  
//LL characters[KIND_OF_CHARACTER];  
  
void CountKinds(); //for test  
int BuildHuffmanTree();  
void CompressFile(const char *filePath, const char *outPutFilePath, int numberOfNode);  
void BitToInt(ofstream &outPut, char *HTstr, LL len);  
  
  
int main() {  
  
    //scan the file to count frequency of each character.  
    char filePath[FILE_LENGTH] = "graph.txt";   //"Aesop_Fables.txt"; "graph.txt";  "1.txt";  
    char compressFilePath[FILE_LENGTH] = "result.txt";  
  
    ifstream readIn;  
    readIn.open(filePath, ios::binary);  
    if (readIn.is_open() == 0) {  
        cout << "OPEN FAILED!" << endl;  
        exit(0);  
    }  
     //get size of file  
    readIn.seekg(0, ios::end);  
    LL fileSize = (LL)readIn.tellg();  
    readIn.seekg(0, ios::beg);  
    cout<<"fileSize" <<fileSize<<endl;  
    //read data in batches, each time read MAX_MEMORY characters  
    int nTimes = (int)(fileSize / MAX_MEMORY);  
    if (fileSize % MAX_MEMORY != 0) nTimes++;  
    int kindsOfCharacter = 0;  
    cout<<nTimes<<endl;  
    for (int i = 1; i <= nTimes; i++) {  
        char *str = (char *)calloc(1, (MAX_MEMORY+10)*sizeof(char));  
  
        LL numberOfCharacter = MAX_MEMORY;  
        if (i == nTimes) {  
            numberOfCharacter = fileSize % MAX_MEMORY;  
        }  
        readIn.read(str, numberOfCharacter * sizeof(char));  
        str[numberOfCharacter] = '\0';  
        cout<<strlen(str)<<endl;  
  
        //count the frequency of each character.  
        int lenStr = strlen(str);  
        for (LL j = 0; j < lenStr; j++) {  
            node[str[j]].number++;  
            node[str[j]].c = str[j];  
        }  
  
        free(str);  
    }  
   // CountKinds();  
  
    //build Huffman tree  
    int numberOfNode = BuildHuffmanTree();  
  
    //compress file using Huffman code  
    CompressFile(filePath, compressFilePath, numberOfNode);  
  
    //outPut.close();  
   // readIn.close();  
}  
  
int BuildHuffmanTree(){  
    //apply 2 * KIND_OF_CHARACTER to store nodes of the Huffman tree  
    Node* HT = (Node *)malloc((2 * KIND_OF_CHARACTER) * sizeof(Node));  
    //put all kinds of character into priority queue  
    priority_queue<Node> q;  
    int  numberOfNode = 0;  
    for (int i = 0; i < KIND_OF_CHARACTER; i++) {  
        if (node[i].number != 0) {  
            node[i].iNode = numberOfNode;  
            node[i].c = i;  
            q.push(node[i]);  
            HT[numberOfNode] = node[i];  
            numberOfNode++;  
        }  
    }  
    cout << numberOfNode << endl;  
    int jNode = numberOfNode;  
    while (q.size() > 1){  
        //get two minimal weight nodes and set their parent  
        Node leftNode = q.top();  
        q.pop();  
        Node rightNode = q.top();  
        q.pop();  
        //cout <<" ##"<< leftNode.number <<endl;  
        //cout <<" **"<< rightNode.number <<endl;  
        int l = leftNode.iNode;  
        int r = rightNode.iNode;  
        HT[l].parent = jNode;  
        HT[r].parent = jNode;  
        //set parent's  information  
        HT[jNode].c = ' ';  
        HT[jNode].iNode = jNode;  
        HT[jNode].lChild = l;  
        HT[jNode].rChild = r;  
        HT[jNode].number = leftNode.number + rightNode.number;  
        q.push(HT[jNode]);  
        jNode++;  
    }  
    HT[jNode-1].parent = -1;  
   /* for (int i = 0; i < jNode; i++){ 
        cout << i << " " << HT[i].c <<  " " << HT[i].number<< endl; 
    }*/  
    //get each character's Huffman code  
    for (int i = 0; i < numberOfNode; i++) {  
        int k = 0;  
        int l = i;  
        char ch = HT[i].c;  
        for (int j = HT[i].parent; j != -1; j = HT[j].parent) {  
            if (HT[j].lChild == l) {  
                HuffmanCode[ch][k] = '0';  
            }  
            else {  
                HuffmanCode[ch][k] = '1';  
            }  
            l = j;  
            k++;  
        }  
        //reverse the Huffman code  
        for (int j = 0; j < k / 2; j++) {  
            char temp = HuffmanCode[ch][j];  
            HuffmanCode[ch][j] = HuffmanCode[ch][k-1-j];  
            HuffmanCode[ch][k-1-j] = temp;  
        }  
        HuffmanCode[ch][k] = '\0';  
        cout << ch << " " <<HuffmanCode[ch] << endl;  
  
    }  
    cout<<numberOfNode<<endl;  
    free(HT);  
    return numberOfNode;  
}  
  
void CompressFile(const char *filePath, const char *outPutFilePath, int numberOfNode){  
    //scan characters in input file once more  
    ifstream readIn;  
    readIn.open(filePath, ios::binary);  
    if (readIn.is_open() == 0) {  
        cout << "OPEN FAILED!" << endl;  
        exit(0);  
    }  
  
    //write Huffman code file  
    //Information: number of bits added, OFFSET, size of original file. the number of kinds of character  
    ofstream outPut;  
    outPut.open(outPutFilePath, ios::binary);  
    if (outPut.is_open() == 0) {  
        cout << "OPEN FAILED!" << endl;  
        exit(0);  
    }  
  
    //get size of file  
    readIn.seekg(0, ios::end);  
    LL fileSize = (LL)readIn.tellg();  
    readIn.seekg(0, ios::beg);  
    //write some information in compressed file  
  
    outPut.seekp(OFFSET, ios::beg);  
    outPut.write((char *)&fileSize, sizeof(LL));  
    outPut.write((char *)&numberOfNode, sizeof(int));  
    //record the character and its Huffman code  
    for (int i = 0; i < KIND_OF_CHARACTER; i++) {  
        if (node[i].number != 0) {  
            outPut.write((char *)&i, sizeof(char));  
            int bits = strlen(HuffmanCode[i]);  
            outPut.write((char *)&bits, sizeof(int));  
            outPut.write((char *)&HuffmanCode[i], bits*sizeof(char));  
        }  
    }  
  
  
    //read data in batches, each time read MAX_MEMORY characters and encode  
    int nTimes = (int)(fileSize / MAX_MEMORY);  
    if (fileSize % MAX_MEMORY != 0) nTimes++;  
    int kindsOfCharacter = 0;  
    char *HTstr = (char *)calloc(1, (MAX_MEMORY+HUFFMAN_CODE_LENGTH)*sizeof(char));  
    int len = 0;  
    LL lenT = 0;  
    for (int i = 1; i <= nTimes; i++) {  
        char *str = (char *)calloc(1, (MAX_MEMORY+10)*sizeof(char));  
        LL numberOfCharacter = MAX_MEMORY;  
        if (i == nTimes) {  
            numberOfCharacter = fileSize % MAX_MEMORY;  
        }  
        readIn.read(str, numberOfCharacter * sizeof(char));  
        str[numberOfCharacter] = '\0';  
        for (LL j = 0; j < numberOfCharacter; j++) {  
            char ch = str[j];  
            lenT += strlen(HuffmanCode[ch]);  
            strcpy(HTstr+len, HuffmanCode[ch]);  
            len += strlen(HuffmanCode[ch]);  
  
            //write compressed file in batches  
            //when the length of encode string is greater than limited memory  
            if (len > MAX_MEMORY) {  
               // cout<<"****"<<endl;  
                LL leftBits = len % nBits;  
                LL changeLength = len - leftBits;  
                BitToInt(outPut, HTstr, changeLength);  
  
                //if no left bits, no need to keep it.  
                strcpy(HTstr,  HTstr+changeLength);  
                len = strlen(HTstr);  
            }  
        }  
        free(str);  
    }  
    //cout<<strlen(HTstr)<<" "<<HTstr<<endl;  
    //if there are left bits, change int integer  
    if (len != 0) {  
        BitToInt(outPut, HTstr, len);  
        //store tail???  
    }  
    free(HTstr);  
    readIn.close();  
    outPut.close();  
}  
  
void BitToInt(ofstream &outPut, char* HTstr, LL len) {  
    //add 0 to make the length of HTstr can be divide by 7  
    int k = 0;  
    if (len % nBits != 0) {  
        int bitsToAdd = nBits - (len % nBits);  
        streampos pos = outPut.tellp();  
        outPut.seekp(0, ios::beg);  
        outPut.write((char *)&bitsToAdd, sizeof(int));  
        outPut.write((char *)&OFFSET, sizeof(int));  
        outPut.seekp(pos, ios::beg);  
        for (; k < bitsToAdd; k++){  
            HTstr[len+k] = '0';  
        }  
        HTstr[len+k] = '\0';  
  
    }  

    int pow = 1<<(nBits - 1);  
    int sum = 0;  
    for (LL i = 0, j = 0; i < len+k && HTstr[i]; i++) {  
        if (j == nBits){  
            outPut.write((char *)&sum, sizeof(char));  
  
            j = 0;  
            sum = 0;  
        }  
        sum = sum + (HTstr[i]-'0') * (pow >> j);  
        j++;  
    }  
  
   // outPut.write(buf, strlen(buf) * sizeof(char));  
    outPut.write((char *)&sum, sizeof(char));  
   // free(buf);  
   // cout <<sum <<endl;  
}  
  
  
void CountKinds(){  
    int kinds = 0;  
    for (int i = 0; i < KIND_OF_CHARACTER; i++) {  
        if (node[i].number != 0) {  
                printf("%c ", node[i].c);  
            cout << node[i].c << " " << node[i].number<<endl;  
            kinds++;  
        }  
    }  
    cout << kinds << endl; //76  
}  
