#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

void insert_product();                                  // Function prototypes
void update_attribute();
void delete_product();
void search_attribute();
void sort_products();
void display_products();

vector<vector<string>> matrix;                          // Declare a global 2D vector


std::string toLowercase(const std::string& str) {       // Function to convert a string to all lowercase, courtesy of ChatGPT.
    std::string result = str; // Make a copy of the original string

    // Convert each character to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return result;
}

int main()
{
    string line;                                        // String for storing a single line in the text file
    ifstream fin;                                       // Object for reading from and writing to files
    string attribute;                                   // String for temporarily storing an attribute
    int j = 0;

    fin.open("product_data.txt");                       // Open the text file

    while (getline(fin, line)) {    //

        vector<string> hello = {};                      // Initialize an empty string vector
        matrix.push_back(hello);                        // Push the empty string vector to the matrix

        for (int i = 0; i < line.length(); i++) {

            if (line[i] == ',') {
                                                        // Check for comma seperating each attribute
                matrix[j].push_back(attribute);         // Push the complete attribute to the vector indexed by j
                attribute.clear();
                i++;

            } else {

                attribute += line[i];                   // Concatenate the attribute with the character indexed by i
            }
        }

        matrix[j].push_back(attribute);                 // Push the last complete attribute to the vector
        attribute.clear();
        j++;
    }

    fin.close();                                        // Close the currently open text file

    while (true) {

        int user_option;

        cout << "Menu\n";
        cout << "(1) Insert" << '\n';
        cout << "(2) Update" << '\n';
        cout << "(3) Delete" << '\n';
        cout << "(4) Search" << '\n';
        cout << "(5) Bubble Sort" << '\n';
        cout << "(6) Display Products" << '\n';
        cout << "(7) Exit" << '\n';
        cout << "Please select an option: ";
        cin >> user_option;
        cout << '\n';

        switch (user_option) {                          // Call to each function managed by the switch
            case 1:
                insert_product();
                break;
            case 2:
                update_attribute();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                search_attribute();
                break;
            case 5:
                sort_products();
                break;
            case 6:
                display_products();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid option. Please try again. \n";
                break;
        }
    }
}

void insert_product() {

    int position;
    vector<string> new_product(5);                      // Declare new vector for new product attributes

    cout << '\n' << "Select the position: ";
    cin >> position;
    cin.ignore();

    cout << "ID: ";
    getline(cin, new_product[0]);

    cout << "Name: ";
    getline(cin, new_product[1]);

    cout << "Price: ";
    getline(cin, new_product[2]);

    cout << "Category: ";
    getline(cin, new_product[3]);
    cout << '\n';

    matrix.insert(matrix.begin() + position - 1, new_product);      // Inserts filled vector before the element at the specified position in matrix
}

void update_attribute() {

    int position, option;

    cout << "Enter the position of the product: ";
    cin >> position;                                                // Gets the position of the product as displayed using display_products()

    cout << "(1) ID\n";
    cout << "(2) Name\n";
    cout << "(3) Price\n";
    cout << "(4) Category\n";
    cout << "What would you like to edit?: ";
    cin >> option;
    cin.ignore();                                                   // Clears the input buffer from the newline character \n

    std::cout << "Enter the new attribute: ";
    getline(cin, matrix[position-1][option-1]);

    cout << '\n';
}

void delete_product() {

    int position;

    cout << "Enter the position of the product: ";
    cin >> position;

    matrix.erase(matrix.begin() + position - 1);

    cout << '\n';
}


void search_attribute() {

    int search_term;
    int result_count = 0;
    string content;

    cout << "(1) ID\n";
    cout << "(2) Name\n";
    cout << "(3) Price\n";
    cout << "(4) Category\n";

    cout << "Enter the search term: ";
    cin >> search_term;                                 // Asks the user if they're search with ID (1), name (2), price (3), or cateogry (4)
    cout << '\n';

    cout << "Enter its content: ";
    cin >> content;
    cout << '\n';

    for (int i = 0; i < matrix.size(); i++) {

        if (toLowercase( matrix[i][search_term - 1] ) == toLowercase(content)  ) {// Compares the search content to the queried content in their lowercase form

            result_count++;
            cout << matrix[i][0] << " ";
            cout << matrix[i][1] << " ";
            cout << matrix[i][2] << " ";
            cout << matrix[i][3] << "\n\n";
        }
    }

    if (result_count == 0)
        cout << "No results found.\n\n";
}


void sort_products() {

    bool swapped = false;

    for (int i = 0; i < matrix.size()-1; i++) {                     // Iterates over every element in the matrix except the last

        for (int j = 0; j < matrix.size()-i-1; j++) {               // Decreases the iteration range by i-1 because the largest largest unsorted element gets bubbled to the end

            if (stof(matrix[j][2]) > stof(matrix[j+1][2])) {       // Checks if the price of the vector indexed by j is greater than the vector indexed by j+1

                swapped = true;
                vector<string> temp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j + 1] = temp;                               // Swaps the vector indexed by j and the vector indexed by j+1
            }
        }
        if (!swapped) {                                             // Breaks the unnested loop if there were no swaps in the first pass
            break;
        }
    }
}


void display_products() {

    for (int i = 0; i < matrix.size(); i++) {

        cout << "(";

        if (i < 9)                                      // Prepends single digit 1-based indices with a 0

            cout << "0";

        cout << i+1 << ") ";

        for (int j = 0; j < matrix[j].size(); j++) {

            cout << matrix[i][j] << "  ";               // Adds a space between each attribute in the same product
        }
        cout << "\n";
    }

}

