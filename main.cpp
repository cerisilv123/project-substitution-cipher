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
    size_t selection {};
    
    getline(cin, secret_msg); // User input 
    
    do { 
    cout << "\nMenu" << endl; // User menu 
    cout << "\n1 - Encrypt Message" << endl; 
    cout << "2 - Decrypt Message" << endl; 
    cout << "3 - Quit program" << endl; 
    cin >> selection; 
    
    if (selection == 1) { //========= Encrypting Message =========//
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
    }
    else if (selection == 2) { //========= Decrypting Message =========//
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
    }
    } while (selection != 3);
    
    cout << "\nProgram exited" << endl; 
        
  cout << endl; 
  return 0;   
} 
