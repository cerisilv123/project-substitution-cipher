#include <iostream>
#include <string>

using namespace std;

int main () {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"};
    
    cout << "Enter a secret message: ";
    string secret_msg {};
    string encrypted_message {};
    string decrypted_message {};
    size_t position {};
    
    getline(cin, secret_msg); // User input 
    
    // =========== Encryption =========== // 
    
    for (auto j: secret_msg) { 
        if (isalpha(j)) {
              position = alphabet.find(j); 
              if (position != string::npos) { // npos = no position (not in the string) 
                  encrypted_message.push_back(key.at(position)); 
              }
              else {
                  encrypted_message.push_back(j); // adding alphabet not in list
              }
        }
        else {
           encrypted_message.push_back(j); // Pushing back whitespace
        }
    }  
    
    cout << "\nEncrypting message: " << endl; 
    cout << encrypted_message << endl; 
    
    // =========== Decryption =========== // 

    for (auto i: encrypted_message) { 
        if (isalpha(i)) {
              position = key.find(i); 
              if (position != string::npos) { // npos = no position (not in the string)  
                  decrypted_message.push_back(alphabet.at(position)); 
              }
              else {
                  decrypted_message.push_back(i); // adding alphabet not in list
              }
        }
        else {
           decrypted_message.push_back(i); // Pushing back whitespace and non alphabets
        }
    }  
    
    cout << "\nDecrypting message: " << endl; 
    cout << decrypted_message << endl; 
        
    
  cout << endl; 
  return 0;   
} 
