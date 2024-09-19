//Caesar Cipher Program

#include <iostream>
#include <cctype> 
#include <string>

using namespace std;

int main() {
    cout << "Welcome to the Oscar Academy of Magic Caesar Cipher Program!" << endl;

    // Decrypt the acceptance letter with a shift value of 20
    cout << "Unraveling the secret acceptance decision letter from the Oscar Academy of Magic..." << endl;
    cout << "Using a shift value of 20..." << endl;

    string encryptedMessage = "Bottub! Alyyncham zlig nby nqchefcha niqylm iz nby Imwul Uwuxygs iz Guacw! Qy'ly vovvfcha ipyl qcnb yrwcnygyhn ni fyn sio ehiq nbun sio, sym, sio bupy yhwbuhnyx om uff uhx mywolyx u mjin un iol yhwbuhncha yhwfupy! Vyzily sio juwe siol vuam uhx mjyff viiem, lygygvyl ni vlcha hin domn nby womniguls ycabn quhxm zil iol mjyffvchxcha ijyhcha qyye wylygihcym von ufmi u nlomns wugyf! Nbymy guahczcwyhn wlyunolym ulyh'n domn zil mbiq, nbys'ly nby jylzywn jufm zil qctulxm qbcttcha uvion ih nblcffcha uxpyhnolym. Xoy ni u jozzs jozz iz chzfuncih nbun'm vyqcnwbyx iol ywihigs, nby nocncih zyy cm jyaayx un u guacwuf $50,000 jyl mygymnyl. Qy wuh'n qucn ni ombyl sio nblioab iol uhwcyhn, cps-wipylyx ulwbqusm uhx chni nby byuln iz guacw cnmyfz. Ayn lyuxs ni mncl jincihm, wbulg gsnbcwuf vyumnm, uhx jylbujm, wbuhay nby wiolmy iz nby wimgim!";
    string decryptedMessage = "";
    int shift = 20;

    for (char& ch : encryptedMessage) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decryptedMessage += (char)(((ch - base - shift + 26) % 26) + base);
        } else if (isdigit(ch)) {
            decryptedMessage += (char)(((ch - '0' - shift + 10) % 10 + 10) % 10 + '0');
        } else {
            decryptedMessage += ch;
        }
    }

    cout << "Drumroll please..." << endl;
    cout << "The acceptance letter says: " << decryptedMessage << endl;

    // Encryption/decryption loop
    while (true) {
        char choice;
        cout << "\nNow, let's start encoding and decoding some messages!" << endl;
        cout << "Do you want to encrypt or decrypt a message? (e/d): ";
        cin >> choice;

        cin.ignore();  // Ignore remaining characters in the input buffer

        if (choice != 'e' && choice != 'd') {
            cout << "Invalid choice. Please enter 'e' for encrypt or 'd' for decrypt." << endl;
            continue;
        }

        string message;
        int shift;

        cout << "Enter the message: ";
        getline(cin, message);

        while (true) {
            cout << "Enter the shift value (1-40): ";
            cin >> shift;

            if (shift >= 1 && shift <= 40) {
                break;
            } else {
                cout << "Invalid shift value. Please enter a number between 1 and 40." << endl;
            }
        }

        cin.ignore();

        string result = "";
        char base;

        // Encrypt or decrypt the message based on the user's choice
        for (char& ch : message) {
            if (isalpha(ch)) {
                if (isupper(ch)) {
                    base = 'A';
                } else {
                    base = 'a';
                }

                int newCh = ((ch - base + (choice == 'e' ? shift : -shift)) % 26 + 26) % 26 + base;
                result += (char)newCh;
            } else if (isdigit(ch)) {
                int newCh = ((ch - '0' + (choice == 'e' ? shift : -shift)) % 10 + 10) % 10 + '0';
                result += (char)newCh;
            } else {
                result += ch;
            }
        }

        // Output the result
        if (choice == 'e') {
            cout << "Encrypted message: " << result << endl;
        } else {
            cout << "Decrypted message: " << result << endl;
        }

        // Ask the user if they want to continue
        char continueChoice;
        cout << "Would you like to continue the program? (y/n): ";
        cin >> continueChoice;

        if (continueChoice != 'y') {
            break;
        }

        cin.ignore();
    }

    cout << "\nThanks for using the Oscar Academy of Magic Caesar Cipher Program!" << endl;
    cout << "Keep making magic!" << endl;

    return 0;
}
