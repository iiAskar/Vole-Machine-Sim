#include "Machine.h"

void Machine::displayMenu() {
    cout << "\n=== Machine Simulator Menu ===\n";
    cout << "1. Load and run program (space-separated instructions)\n";
    cout << "2. Load and run program from file\n";
    cout << "3. Display current machine state\n";
    cout << "4. Reset memory and registers\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";}

vector<string> Machine::parseInstructions(const string& input) {
    vector<string> instructions;
    stringstream ss(input);
    string instruction;

    while (ss >> instruction) {
        if (instruction.length() != 4) {
            throw runtime_error("Invalid instruction format: " + instruction);
        }
        instructions.push_back(instruction);
    }
    return instructions;
}

vector<string> Machine::loadProgramFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file: " + filename);
    }

    string line;
    getline(file, line);
    return parseInstructions(line);
}
void Machine::resetSystem() {
    // Reset memory
    for(int i = 0; i < memory.getSize(); i++) {
        memory.setCellAddress(i, "00");
    }
    // Reset CPU (which includes registers)
    cpu.reset();
    cout << "\nMemory and registers have been reset to initial state.\n";
}
void Machine::displayFullState() {
    cout << "\n=== Machine State ===\n";
    cout << "\nMemory Contents:";
    memory.displayMemory();
    cpu.displayState();
}

void Machine::run() {
    string choice;
    vector<string> program;
    const int DEFAULT_START = 0x10; // Default start location is 16 (0x10)

    while (true) {
        displayMenu();
        getline(cin, choice);

        if (choice == "1") {
            cout << "\nEnter program instructions (space-separated, e.g., '2103 2204 5312 3300 C000'): \n";
            string input;
            getline(cin, input);

            cout << "Enter start location (hexadecimal) or press Enter for default (10): ";
            string startLocStr;
            getline(cin, startLocStr);

            int startLocation = DEFAULT_START;
            if (!startLocStr.empty()) {
                try {
                    startLocation = stoi(startLocStr, nullptr, 16);
                } catch (const exception& e) {
                    cout << "Invalid start location. Using default (10).\n";
                    startLocation = DEFAULT_START;
                }
            }

            try {
                program = parseInstructions(input);
                int address = startLocation;
                for (const auto& instr : program) {
                    // Split each 4-character instruction into two 2-character parts
                    memory.setCellAddress(address++, instr.substr(0, 2));
                    memory.setCellAddress(address++, instr.substr(2, 2));
                }

                cout << "Program loaded successfully at location " << hex << uppercase << startLocation << ".\n";
                cpu.reset();
                cpu.setProgramCounter(startLocation);

                cout << "\nPress Enter to execute each instruction...\n";
                displayFullState();

                string temp;
                while (!cpu.isHalted()) {
                    cout << "\nPress Enter to execute next instruction...";
                    cin.clear();
                    cin.ignore(1000,'\n');
                    // Show next instruction to be executed
                    cout << "\nNext instruction: " << memory.getCellAddress(cpu.getProgramCounter()) << endl;
                    cpu.executeInstruction();
                    displayFullState();
                }

                cout << "\nProgram execution completed.\n";
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == "2") {
            cout << "Enter filename: ";
            string filename;
            getline(cin, filename);

            cout << "Enter start location (hexadecimal) or press Enter for default (10): ";
            string startLocStr;
            getline(cin, startLocStr);

            int startLocation = DEFAULT_START;
            if (!startLocStr.empty()) {
                try {
                    startLocation = stoi(startLocStr, nullptr, 16);
                } catch (const exception& e) {
                    cout << "Invalid start location. Using default (10).\n";
                    startLocation = DEFAULT_START;
                }
            }

            try {
                program = loadProgramFromFile(filename);
                int address = startLocation;
                for (const auto& instr : program) {
                    // Split each 4-character instruction into two 2-character parts
                    memory.setCellAddress(address++, instr.substr(0, 2));
                    memory.setCellAddress(address++, instr.substr(2, 2));
                }
                cout << "Program loaded successfully at location " << hex << uppercase << startLocation << ".\n";
                cpu.reset();
                cpu.setProgramCounter(startLocation);
                cout << "\nPress Enter to execute each instruction...\n";
                displayFullState();
                string temp;
                while (!cpu.isHalted()) {
                    cout << "\nPress Enter to execute next instruction...";
                    cin.clear();
                    cin.ignore(1000,'\n');

                    // Show next instruction to be executed
                    cout << "\nNext instruction: " << memory.getCellAddress(cpu.getProgramCounter()) << endl;
                    cpu.executeInstruction();
                    displayFullState();
                }

                cout << "\nProgram execution completed.\n";
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == "3") {
            displayFullState();
        }
        else if (choice == "4") {
            resetSystem();
            displayFullState();
        }
        else if (choice == "5") {
            cout << "Exiting simulator.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}