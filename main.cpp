#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void show_help() {
    std::cout << "\n** List of Commands:             **" << std::endl;
    std::cout << "** e or encrypt - Encrypt a file **" << std::endl;
    std::cout << "** d or decrypt - Decrypt a file **" << std::endl;
    std::cout << "** q or quit - Quit the program  **" << std::endl;
    std::cout << "** h or help - Show help         **\n" << std::endl;
}

void encrypt_decrypt_data(std::vector<char>& buffer, const std::string& key) {
    for (size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] ^= key[i % key.size()];
    }
}

void encrypt_decrypt(const std::string& input_filename, const std::string& output_filename, const std::string& key) {
    std::ifstream input_file(input_filename, std::ios::binary);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    encrypt_decrypt_data(buffer, key);

    std::ofstream output_file(output_filename, std::ios::binary);
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return;
    }

    output_file.write(buffer.data(), buffer.size());
    output_file.close();

    std::cout << "Success: File encrypted/decrypted successfully." << std::endl;
}

void process_input(const std::string input) {
    if (input == "quit" || input == "q") return;

    if (input == "e" || input == "encrypt") {
        std::string input_filename = "";
        std::string output_filename = "";
        std::string key = "";

        std::cout << "Enter input filename: ";
        std::cin >> input_filename;

        std::cout << "Enter output filename: ";
        std::cin >> output_filename;

        std::cout << "Enter key: ";
        std::cin >> key;

        encrypt_decrypt(input_filename, output_filename, key);
    } else if (input == "d" || input == "decrypt") {
        std::string input_filename = "";
        std::string output_filename = "";
        std::string key = "";

        std::cout << "Enter input filename: ";
        std::cin >> input_filename;

        std::cout << "Enter output filename: ";
        std::cin >> output_filename;

        std::cout << "Enter key: ";
        std::cin >> key;

        encrypt_decrypt(input_filename, output_filename, key);
    } else if (input == "help" || input == "h") {
        show_help();
    } else {
        std::cout << "Error: Invalid input." << std::endl;
    }
}


int main() {

    std::string input = "";

    show_help();

    while (input != "quit" && input != "q") {
        std::cout << "> "; 
        std::cin >> input;
        process_input(input);
    }

    return 0;
}