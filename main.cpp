#include <iostream>
#include <string>

using namespace std;

// ======= Function Prototypes ======= //
void display_menu(); 
string enter_secret_message(string &s);
size_t enter_selection(size_t &n);

// ======= Main Function ======= //
int main () {
    
    string alphabet {"[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"[QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"};
    
    string secret_msg = enter_secret_message(secret_msg); // Storing secret message to secret_msg variable
    
    size_t selection {}; 
    
    string encrypted_message {};
    string decrypted_message {};
    size_t position {};
    
    do { 
        
    display_menu(); // Display menu function
    selection = enter_selection(selection); // Function to store selection
    
    if (selection == 1) { //========= Encrypting Message =========//
      for (auto j: secret_msg) { 
        if (isalpha(j)) {
              position = alphabet.find(j); 
              if (position != string::npos) { // npos = no position (not in the string) - != means we have found it 
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
              if (position != string::npos) { // npos = no position (not in the string) - != means we have found it 
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

// ======= Function Definitions ======= //

// Storing secret message to variable secret_msg
string enter_secret_message(string &s) {
    cout << "Enter a secret message: ";
    string secret_msg {};
    getline(cin, secret_msg);
    return secret_msg;
}

// Storing selection 
size_t enter_selection (size_t &n) {
    size_t selection {};
    cout << "Please enter a selection: "; 
    cin >> selection;
    return selection; 
}

// Display main menu 
void display_menu () {
    cout << "\n\\ ====== Menu ====== \\" << endl; // User menu 
    cout << "\n1 - Encrypt Message" << endl; 
    cout << "2 - Decrypt Message" << endl; 
    cout << "3 - Quit program" << endl; 
}