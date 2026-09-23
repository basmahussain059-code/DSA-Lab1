#include <iostream>
#include <string>
using namespace std;

class StringPool {
private:
string* stringPool;
int currentSize; 
int maxSize;
public:
StringPool() // Constructor
{   
maxSize= 5;
currentSize= 0;
stringPool=new string[maxSize];
}
void addString(const string& str) {
    if(currentSize < maxSize) {
        stringPool[currentSize] = str;
        currentSize++;
    } else {
        cout << "String pool is full. Cannot add more strings." << endl;
    }
}
  void removeString(int index){
        if (index < 0 || index >= currentSize) {
            cout << "Invalid index for removal." << endl;
            return;
        }
        cout << "Removing \"" << stringPool[index] << "\" from the pool "
             << "(memory/slot not properly cleaned up)." << endl;
        for (int i = index; i < currentSize - 1; i++) {
            stringPool[i] = stringPool[i + 1];
        }
        currentSize--;
}
  void cleanupPool() {
        cout << "\nCleaning up pool..." << endl;
        for (int i = 0; i < currentSize; i++) {
            stringPool[i].clear();
        }
        cout << "Pool contents cleared." << endl;
    }
    void displayStatus() const {
        cout << "\n--- Pool Status ---" << endl;
        cout << "Current size: " << currentSize << " / " << maxSize << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << "  [" << i << "] " << stringPool[i] << endl;
        }
        cout << "-------------------" << endl;
    }
//destructor properly frees the dynamically allocated array
    ~StringPool() {
        delete[] stringPool;   // Fixes the memory leak of the array itself
        cout << "\nStringPool destroyed. Dynamic array freed." << endl;
    }
};
int main() {
    StringPool pool;
//add multiple strings to the pool
pool.addString("Alpha");
pool.addString("Beta");
pool.addString("Gamma");
pool.addString("Delta");
pool.addString("Epsilon");
 pool.displayStatus();
//remove strings without freeing memory
pool.removeString(1);   
pool.removeString(0);   
pool.displayStatus();
//detect and fix the memory leak, then display final pool status
pool.cleanupPool();
pool.displayStatus();
//destructor runs automatically here, freeing the dynamic array
    return 0;
}
